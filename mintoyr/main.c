#include <stdio.h>
#include <stdlib.h>

int main() {
    long minEntered = 0;
    double years = 0.0;
    double days = 0.0;
    double minInYr = 0.0;

    printf("Please enter the number of minutes: ");

    // get the input from user
    scanf("%ld", &minEntered);
    
    minInYr = (60 * 24 * 365.25);

    printf("Minutes in Year: %f\n", minInYr);

    years = (minEntered / minInYr);

    printf("%ld minutes counts to %f in year(s).\n", minEntered, years);

    days = (minEntered / 60.0 ) / 24.0;

    printf("And it converts to %f days.\n", days);

    return 0;
}

/*
$ ./mintoyr 
Please enter the number of minutes: 66666666666666666
Minutes in Year: 525960.000000
66666666666666666 minutes counts to 126752351256.115799 in year(s).
And it converts to 46296296296296.296875 days.

*/