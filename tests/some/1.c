#include <stdio.h>

int main (int argc, char *argv[]) {

    int a = 1, b = 0, i = 0;

    if (a) {
        printf ("a;\n");
    }
    if (b) {
        printf ("b;\n");
    }

    if (argc > 1) {
        while (argc > 0) {
            printf ("* argv = '%s';\n", *argv);
            i = 0;
            while (*(*argv + i) != '\0') {
//                printf ("*argv [%d] = '%c';\n", i, * argv [i]);
                printf ("*(*argv + %d ) = '%c';\n", i, *(* argv + i));
                i ++;
            }    
            argc --;
            * argv ++;
            putchar ('\n');
        }
    }

}
