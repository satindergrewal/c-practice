// https://nanomsg.org/gettingstarted/reqrep.html
// https://github.com/nanomsg/nng/blob/master/demo/reqrep/reqrep.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <nanomsg/nn.h>
#include <nanomsg/reqrep.h>

#define NODE0 "node0"
#define NODE1 "node1"
#define DATE "DATE"

void
fatal(const char *func)
{
        fprintf(stderr, "%s: %s\n", func, nn_strerror(nn_errno()));
        exit(1);
}

char *
date(void)
{
        time_t now = time(&now);
        struct tm *info = localtime(&now);
        char *text = asctime(info);
        text[strlen(text)-1] = '\0'; // remove '\n'
        return (text);
}

int
node0(const char *url)
{
        int sz_date = strlen(DATE) + 1; // '\0' too
        int sock;
        int rv;

        if ((sock = nn_socket(AF_SP, NN_REP)) < 0) {
                fatal("nn_socket");
        }
          if ((rv = nn_bind(sock, url)) < 0) {
                fatal("nn_bind");
        }
        for (;;) {
                char *buf = NULL;
                int bytes;
                if ((bytes = nn_recv(sock, &buf, NN_MSG, 0)) < 0) {
                        fatal("nn_recv");
                }
                if ((bytes == (strlen(DATE) + 1)) && (strcmp(DATE, buf) == 0)) {
                        printf("NODE0: RECEIVED DATE REQUEST\n");
                        char *d = date();
                        int sz_d = strlen(d) + 1; // '\0' too
                        printf("NODE0: SENDING DATE %s\n", d);
                        if ((bytes = nn_send(sock, d, sz_d, 0)) < 0) {
                                fatal("nn_send");
                        }
                }
                nn_freemsg(buf);
        }
}

int
node1(const char *url)
{
        int sz_date = strlen(DATE) + 1; // '\0' too
        char *buf = NULL;
        int bytes = -1;
        int sock;
        int rv;

        if ((sock = nn_socket(AF_SP, NN_REQ)) < 0) {
                fatal("nn_socket");
        }
        printf("client sock: %d\n", sock);
        if ((rv = nn_connect (sock, url)) < 0) {
                fatal("nn_connect");
        }
        printf("client rv: %d\n", rv);
        printf("NODE1: SENDING DATE REQUEST %s\n", DATE);
        if ((bytes = nn_send(sock, DATE, sz_date, 0)) < 0) {
                fatal("nn_send");
        }
        printf("client bytes: %d\n", bytes);
        // printf("client nn_recv: %d\n", nn_recv(sock, &buf, NN_MSG, 0));
        if ((bytes = nn_recv(sock, &buf, NN_MSG, 0)) < 0) {
                fatal("nn_recv");
        }
        printf("client buf: %s\n", buf);
        printf("NODE1: RECEIVED DATE %s\n", buf);  
        nn_freemsg(buf);
        return (nn_shutdown(sock, 0));
}

int
main(const int argc, const char **argv)
{
        if ((argc > 1) && (strcmp(NODE0, argv[1]) == 0))
                return (node0(argv[2]));

        if ((argc > 1) && (strcmp(NODE1, argv[1]) == 0))
                return (node1(argv[2]));

      fprintf(stderr, "Usage: reqrep %s|%s <URL> ...\n", NODE0, NODE1);
      return (1);
}

// Compilation
// --------------
// gcc node_reqrep.c -I./nng/include/nng/compat/ /usr/local/lib/libnng.a -o node_reqrep
// gcc node_reqrep.c -I./nng/include/nng/compat/ /usr/local/lib/libnng.a -pthread -o node_reqrep

// Execution
// --------------
// ./node_reqrep node0 ipc:///tmp/node_reqrep.ipc & node0=$! && sleep 1
// ./node_reqrep node1 ipc:///tmp/node_reqrep.ipc
// kill $node0


// ./node_reqrep node0 ipc:///tmp/node_reqrep.ipc & node0=$! && sleep 1 && ./node_reqrep node1 ipc:///tmp/node_reqrep.ipc 
// pkill node_reqrep
