#include <stdio.h>

/* count number of lines, number of tabs, number of blanks and print */
int main()
{
    int c, nl, b, t;

    nl = 0; // newlines
    b = 0; // blanks
    t =0; // tabs

    while((c = getchar()) != EOF) {

        if (c == '\n')
            ++nl;
        if (c == '\t') {
            ++t;
        }
        if (c == ' ') {
            ++b;
        }
        
    }
    printf("New Lines: \t%d\n", nl);
    printf("Blanks: \t%d\n", b);
    printf("Tabs: \t\t%d\n", t);

    return 0;
}

/*

$ ./exercise1_8 
;lasjdf ;as;flajs;kdfja;lskdj f;kashjdf kjahskdfjh kasd
i2yu3fgou23fvl23v 2g 2pig2i 2 2g 2      1iug2uyg2yukg2k
l                               i       iu      kjhgjkasdf
                ilguhluig       l       g

        li      g       lug             l
asfasdfsa

as
fd
asdf
asd
fsfasdf


asfdasdfasdf
New Lines:      16
Blanks:         9
Tabs:           21

*/