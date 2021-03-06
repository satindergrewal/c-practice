#include <stdio.h>
#include <stdlib.h>

int main() {
    
    double height = 32.3;
    double width = 15.3;
    double area = 0.0;
    double perimeter = 0.0;

    perimeter = 2.0 * (height + width);
    area = height * width;

    printf("Rectangle Height \t: %0.2f\n", height);
    printf("Rectangle Width \t: %0.2f\n", width);
    printf("Rectangle Area \t\t: %0.2f\n", area);
    printf("Rectangle Perimeter \t: %0.2f\n", perimeter);

    return 0;
}

/* OUTPUT
$ ./rectangle
Rectangle Height        : 32.30
Rectangle Width         : 15.30
Rectangle Area          : 494.19
Rectangle Perimeter     : 95.20
*/