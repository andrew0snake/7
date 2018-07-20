#include <stdio.h>

#define MAX 100

void getline_my (char *);
void clear_line (char *);

int main () {

    FILE * fn1, *fn2;
    char fname1 [MAX], fname2 [MAX],line1 [MAX], line2 [MAX], exit = 1, *strp1, *strp2, rez;    

    printf ("Input first filename to open:");
    getline_my (fname1);
    printf ("Input second filename to open:");
    getline_my (fname2);

    fn1 = fopen (fname1, "r");
    fn2 = fopen (fname2, "r");
    while (exit) {
        clear_line (line1);
        clear_line (line2);
        strp1 = fgets (line1, MAX, fn1);
        strp2 = fgets (line2, MAX, fn2);
        if (strp1 == NULL || strp2 == NULL) {
            exit = 0;
        }
        else {
            rez = strcmp (line1, line2);
            if (rez != 0) {
                printf ("This files differ in this lines:\n");
                fputs (strp1, stdout);
                fputs (strp2, stdout);
                exit = 0;
            }
        }
    }
    fclose (fn1);
    fclose (fn2);

    return 0;

}

void getline_my (char * line) {

    char c;
    int i = 0;

    while (i < MAX && (c = getchar ()) != EOF && c != '\n') {
        * (line + i) = c;
        i ++;    
    }
    * (line + i) = '\0';

}

void clear_line (char * line) {
    
    int i = 0;

    while ( i < MAX) {
        * (line + i) = 0;
        i ++;
    }
}

