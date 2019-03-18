#include <stdio.h>

int main(int argc, char *argv[]) {
    int numberOfArguments = argc;
    char *argument1 = argv[0];
    char *argument2 = argv[1];

    printf("Number of Arguments: %d\n", numberOfArguments);
    printf("Argument 1 is program name: %s\n", argument1);
    printf("Argument 2 is the command line argument: %s\n", argument2);

    return 0;
}

/* OUTPUT
$ ./args satinder
Number of Arguments: 2
Argument 1 is program name: ./args
Argument 2 is the command line argument: satinder
*/