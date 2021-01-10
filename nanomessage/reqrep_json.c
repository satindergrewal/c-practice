// https://nanomsg.org/gettingstarted/reqrep.html
// https://github.com/nanomsg/nng/blob/master/demo/reqrep/reqrep.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <nanomsg/nn.h>
#include <nanomsg/reqrep.h>
#include "../json_in_c/cJSON/cJSON.h"

#define SERVER "server"
#define CLIENT "client"
#define DATE "DATE"
#define MESG "MESG"

char *clonestr(char *str)
{
    char *clone;
    if ( str == 0 || str[0] == 0 )
    {
        printf("warning cloning nullstr.%p\n",str);
        //#ifdef __APPLE__
        //        while ( 1 ) sleep(1);
        //#endif
        str = (char *)"<nullstr>";
    }
    clone = (char *)malloc(strlen(str)+16);
    strcpy(clone,str);
    return(clone);
}

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

char * message(void) {
        cJSON *info;
        info = cJSON_CreateObject();
	cJSON_AddStringToObject(info, "method", "live");
	cJSON_AddStringToObject(info, "id", "19e6443f0fb3a7d30d9ff7e696320d509eb263270f36d8a968ea407012fc438a");
	char *info_to_string = NULL;
	info_to_string =  cJSON_Print(info);
	// printf("%s\n", info_to_string);
        return info_to_string;
}

int
server(const char *url)
{
        int sz_date = strlen(DATE) + 1; // '\0' too
        int32_t recvlen = 0, bytes;
        int sock;
        int rv;
        cJSON *argjson = NULL;

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
                // if ((recvlen = nn_recv(sock, &buf, NN_MSG, 0)) > 0) {
                //         printf("SERVER: RECEIVED MESSAGE REQUEST\n");
                //         char *tmp = clonestr(buf);
                //         if ((argjson = cJSON_Parse(tmp)) != 0) {
                //                 int sz_d = strlen(tmp) + 1; // '\0' too
                //                 printf("SERVER: SENDING DATE %s\n", tmp);
                //                 if ((bytes = nn_send(sock, tmp, sz_d, 0)) < 0) {
                //                         fatal("nn_send");
                //                 }
                //                 cJSON_Delete(argjson);
                //         }
                //         if (tmp)
                //                 free(tmp);
                        
                // }
                // nn_freemsg(buf);
                if ((bytes == (strlen(DATE) + 1)) && (strcmp(DATE, buf) == 0)) {
                        printf("SERVER: RECEIVED DATE REQUEST\n");
                        // char *d = date();
                        char *d = message();
                        int sz_d = strlen(d) + 1; // '\0' too
                        printf("SERVER: SENDING DATE %s\n", d);
                        if ((bytes = nn_send(sock, d, sz_d, 0)) < 0) {
                                fatal("nn_send");
                        }
                }
                nn_freemsg(buf);
        }
}

int
client(const char *url)
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
        printf("CLIENT: SENDING DATE REQUEST %s\n", DATE);
        if ((bytes = nn_send(sock, DATE, sz_date, 0)) < 0) {
                fatal("nn_send");
        }
        printf("client bytes: %d\n", bytes);
        printf("client nn_recv: %d\n", nn_recv(sock, &buf, NN_MSG, 0));
        if ((bytes = nn_recv(sock, &buf, NN_MSG, 0)) < 0) {
                fatal("nn_recv");
        }
        printf("CLIENT: RECEIVED DATE %s\n", buf);  
        nn_freemsg(buf);
        return (nn_shutdown(sock, 0));
}

int
main(const int argc, const char **argv)
{
        if ((argc > 1) && (strcmp(SERVER, argv[1]) == 0))
                return (server(argv[2]));

        if ((argc > 1) && (strcmp(CLIENT, argv[1]) == 0))
                return (client(argv[2]));

      fprintf(stderr, "Usage: reqrep %s|%s <URL> ...\n", SERVER, CLIENT);
      return (1);
}

// Compilation
// --------------
// gcc reqrep_json.c -I./nng/include/nng/compat/ /usr/local/lib/libnng.a ../json_in_c/cJSON/build/libcjson.dylib -o reqrep_json
// gcc reqrep.c -I./nng/include/nng/compat/ /usr/local/lib/libnng.a -pthread -o reqrep

// Execution
// --------------
// ./reqrep server ipc:///tmp/reqrep.ipc & server=$! && sleep 1
// ./reqrep client ipc:///tmp/reqrep.ipc
// kill $server



// Testing request/response between two nodes on server and client
// --------------
// Execute the following on server
// ./reqrep server tcp://139.59.97.207:8899 & server=$! && sleep 1
// 
// Execute the following on client
// ./reqrep client tcp://139.59.97.207:8899
// 
// Execute the following on server to kill the server process
// kill $server

