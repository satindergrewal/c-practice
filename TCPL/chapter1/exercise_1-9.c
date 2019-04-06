#include <stdio.h>

int main()
{
    int c;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
			putchar(' ');
			while ((c = getchar()) != EOF && c == ' ')
				;
		}
		if (c != EOF)
            putchar(c);
    }
    return 0;
}

/*
$ ./exercise_1-9
asdfasdf      asdfasdfasdfaasdf   asfasdfasdf  asdfasdfasdf 
asdfasdf asdfasdfasdfaasdf asfasdfasdf asdfasdfasdf
*/