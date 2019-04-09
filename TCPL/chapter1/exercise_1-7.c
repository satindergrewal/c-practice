#include <stdio.h>

/*
Added this line after I got following error on compiling:
$ gcc exercise_1-7.c -o exercise_1-7
exercise_1-7.c:9:33: warning: implicit declaration of function 'power' is invalid in C99 [-Wimplicit-function-declaration]
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
                                ^
1 warning generated.
*/
int power(int base, int n);

/* test power function */
int main()
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
    
    return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    
    return p;
}

/*
$ ./exercise_1-7 
0 1 1
1 2 -3
2 4 9
3 8 -27
4 16 81
5 32 -243
6 64 729
7 128 -2187
8 256 6561
9 512 -19683
*/