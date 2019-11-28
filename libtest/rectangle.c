#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

int main(void) {

    char *argv[] = {"0", "13.00", "33.00" };
    // argv[1] = "33.00";
    // argv[2] = "13.00";
    
    rectangle(0, argv);

    return 0;
}

/* OUTPUT
$ ./rectangle 13.4 33.2
Rectangle Height        : 33.00
Rectangle Width         : 13.00
Rectangle Area          : 429.00
Rectangle Perimeter     : 92.00
*/