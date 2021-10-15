package main

/*

#if defined(_WIN64)
	#define LIB_PATH "lib/win64"
#elif defined(__linux__)
	#define LIB_PATH "lib/linux"
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
	#define LIB_PATH "lib/darwin"
#endif

#cgo CFLAGS: -I./include
#cgo LDFLAGS: -L./${LIB_PATH} -lsaplinglib -lpthread -ldl

#include "saplinglib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Return a name of platform, if determined, otherwise - an empty string
const char *get_platform_name() {
    return (LIB_PATH == NULL) ? "" : LIB_PATH;
}

int test() {
    puts(get_platform_name());
    return 0;
}

*/
import "C"

import (
	"fmt"
)

func main() {
	fromC := C.int(0)
	fromC = C.test()
	fmt.Println(C.int(fromC))
}