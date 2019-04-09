#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getlin(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getlin(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)            /* there was a line */
        printf("\n\nLongest Line: %s\n", longest);
    return 0;
}

/* getlin: read a line into s, return length */
int getlin(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}

/*
$ ./section_1-9 
Johny, Johny!
Yes, Papa
Eating sugar?
No, Papa
Telling lies?
No, Papa
Open your mouth!
Ha! Ha! Ha!
^D

Longest Line: Open your mouth!

*/