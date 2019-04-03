#include <stdio.h>

/* count characters in input; 1st version */

int main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);

    return 0;
}

/*
$ ./char_count1 
home
case
true
asset
21
*/

//Press CTRL+D to end input = EOF