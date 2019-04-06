#include <stdio.h>

int main()
{
    int c;

    while((c = getchar()) != EOF) {
        if (c == '\t') // checking tab
			printf("\\t"); // replacing it with string "\t"
		else if (c == ' ') // checking blank space
			printf("\\b"); // replacing it with "\b"
		else if (c == '\\') // checking "\"
			printf("\\\\"); // replacing it with "\\"
		else
        putchar(c); //printing rest of the character inputs as is back in output
    }
    return 0;
}

/*
$ ./exercise_1-10 
asdfasdf\asdfasdf
asdfasdf\\asdfasdf
asdfasdfasdf    asdfasdf
asdfasdfasdf\tasdfasdf
asdfasd asdfasdf asdfasdf
asdfasd\basdfasdf\basdfasdf
asfasdf\asdfasdf                asdfasdf asdfasdf
asfasdf\\asdfasdf\t\tasdfasdf\basdfasdf
*/