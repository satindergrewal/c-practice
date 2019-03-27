#include <stdio.h>
#include <stdlib.h>

int main() {
    
    printf("Variable of type char occupy: \t%zd\n", sizeof(char));
    printf("Variable of type short occupy: \t%zd\n", sizeof(short));
    printf("Variable of type int occupy: \t%zd\n", sizeof(int));
    printf("Variable of type long occupy: \t%zd\n", sizeof(long));
    printf("Variable of type long long occupy: \t%zd\n", sizeof(long long));
    printf("Variable of type float occupy: \t%zd\n", sizeof(float));
    printf("Variable of type double occupy: \t%zd\n", sizeof(double));
    printf("Variable of type long double occupy: \t%zd\n", sizeof(long double));
    
    return 0;
}

/*
$ ./sizeofexample 
Variable of type char occupy:   1
Variable of type short occupy:  2
Variable of type int occupy:    4
Variable of type long occupy:   8
Variable of type long long occupy:      8
Variable of type float occupy:  4
Variable of type double occupy:         8
Variable of type long double occupy:    16
*/