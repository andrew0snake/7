#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int main (int argc, char * argv []) {

    FILE * fp;
    char * prog_name = argv [0];
    char line [MAXLINE];
    char * linep;
    int rez = 0;

    if (argc > 1) {
        fp = fopen (* ++ argv, "r");
        if (fp == NULL) {
            fprintf (stderr, "%s cannot open %s;\n", prog_name, * argv );
            exit (1);
        }
        else {
            while ((linep = fgets (line, MAXLINE, fp)) != NULL) {
                rez = fputs (line, stdout);
            }
        }
        fclose (fp);
    }
 
    return 0;
}
