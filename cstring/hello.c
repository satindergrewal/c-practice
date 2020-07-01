#include <stdio.h>

void hello(const char *name);

int main() {
	char str[50] = "Hello World!";
	hello(str);
	return 0;
}

void hello(const char *name) {
	puts(name);
}