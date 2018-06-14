#include <stdio.h>
int main () {

    char string1 [100] = "string1 is not too much long %%";

    printf ("\n:%s:\n", string1);
    printf (":%10s:\n", string1);
    printf (":%.10s:\n", string1);
    printf (":%-10s:\n", string1);
    printf (":%.33s:\n", string1);
    printf (":%-33s:\n", string1);
    printf (":%33.10s:\n", string1);
    printf (":%-33.10s:\n", string1);

    printf (string1);

    printf ("\n------------\n\n");

}
