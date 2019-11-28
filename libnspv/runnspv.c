#include <stdio.h>
#include <stdlib.h>
#include "nspv.h"

int main(void) {

    char *argv[] = {"0", "KMD" };
    // argv[1] = "KMD";
    // argv[2] = "13.00";
    
    startnspv(0, argv);

    return 0;
}