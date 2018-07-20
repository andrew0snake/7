#include <stdio.h>

int main () {

    FILE * fp;
    char line [100], rez, exit = 1;

    fp = fopen ("1_test", "r");
    while (exit){
        rez = fgets (line, 100, fp);
        if (rez) {
            printf ("line = '%s';\n", line);
            printf ("rez = %d as digit and = %p as pointer;\n", rez, rez);
        }
        else {
            printf ("file ended.\n");
            exit = 0;
        }
    };
    fclose (fp);

    return 0;
}
