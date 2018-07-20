#include <stdio.h>

#define MAXLINE 100

char * fgets_ex (char *, int, FILE *);

int main (int argc, char * argv []) {

    FILE * fp;
    char * progname = argv [0];
    char line [MAXLINE], * linep;

    if (argc > 1) {
        while ( argc -- > 1) {
            fp = fopen (* ++ argv, "r");
            if (fp == NULL) {
                fprintf (stderr, "%s cannot open %s;\n", progname, *argv);
            }
            else {
                while ((linep = fgets_ex (line, MAXLINE, fp)) != NULL) { 
                    if (line != NULL) {
                        fputs (line, stdout);
                    }
                }
            }
            fclose (fp);
        }
    }   


    return 0;

}

char * fgets_ex (char * s, int n, FILE * iop) {

    register int c;
    register char * cs;

    cs = s;
    while (--n > 0 && (c = getc (iop)) != EOF) {
        if ((*cs++ = c) == '\n') {
            break;
        }
    }    
    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;

}

