#include <stdio.h>

#define MAX 100

int main (int argc, char * argv []) {
    
    FILE * fp [MAX];
    int i = 0;

    --argc;
    *++argv;

    while (--argc >= 0) {
        if ((fp [i] = fopen (*argv, "r")) != NULL) {
            printf ("Opened file:'%s'\n", *argv);
            fclose (fp[i]);
        }
        else {
            printf ("File '%s' not found.\n", *argv);
        }
        * argv ++;
        i ++;
    }

    return 0;
}
