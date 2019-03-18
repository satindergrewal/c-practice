#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int numberOfArguments = argc;
    char *programName = argv[0];

    int l = (int)argv[1]; //Length
    int w = (int)argv[2]; //Width
    int area = l*w; //Length x Width
    int perimeter = 2.0 * (l * w);

    printf("Number of Arguments passed: %d\n", numberOfArguments);
    printf("Argument 1 is program name: %s\n", programName);
    
    printf("Rectangle Length: %d\n", l);
    printf("Rectangle Width: %d\n", w);
    printf("Rectangle Area: %d\n", area);
    printf("Rectangle Perimeter: %d\n", perimeter);

    return 0;
}