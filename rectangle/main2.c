#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    // Declaring variables
    double width = atoi(argv[1]); // converting char argument values to integer/float using atoi function
    double height = atoi(argv[2]);
    double area = 0.0;
    double perimeter = 0.0;

    // Calculating perimeter and area of rectangle
    perimeter = 2.0 * (height + width);
    area = height * width;

    // Displaying the calculated numbers
    printf("Rectangle Height \t: %0.2f\n", height);
    printf("Rectangle Width \t: %0.2f\n", width);
    printf("Rectangle Area \t\t: %0.2f\n", area);
    printf("Rectangle Perimeter \t: %0.2f\n", perimeter);

    return 0;
}

/* OUTPUT
$ ./rectangle 13.4 33.2
Rectangle Height        : 33.00
Rectangle Width         : 13.00
Rectangle Area          : 429.00
Rectangle Perimeter     : 92.00
*/