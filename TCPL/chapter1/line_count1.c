#include <stdio.h>

/* count lines in input */
int main()
{
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);

    return 0;
}

/*

$ ./line_count1 
aaa
bbb
ccc
ddd
4D

*/