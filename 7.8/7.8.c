#include <stdio.h>
#include <string.h>

#define MAXLEN 100
#define LEN 100
#define MAXLINE 1000

int getline_my ( char * line, int len );
void clear_line (char *);
void print_file (char *);
void print_file_2 (char *);
//void print_file (char arr [LEN]);

char progname [MAXLEN];

/* find: print lines that match pattern from 1st arg */
int main ( int argc, char *argv [] ) {

    int i = 0, f_amount = 0;
    char filename [LEN] [LEN];

    strcpy (progname, argv [0]);

    if (argc > 1) {
        * argv ++;
        argc --;
        while (argc > 0) {
            strcpy (filename [i], *argv);
            i ++;
            * argv ++;    
            argc --;
        }
        f_amount = i;
    }
    else {
        printf ("Usage:%s file1 file2 file3 ...\n", progname);
    }

    for (i = 0; i < f_amount; i ++) {
        printf ("filename [%d] = '%s';\n", i, filename [i]);
        print_file (filename [i]);
    }    

    return 0;

}

int getline_my ( char * line, int len ) {

    int i = 0;
    char c = 0;

    while ( len > 0 && ( ( c = getchar () ) != EOF && c != '\n') ) {
        * line ++ = c;
        i ++;
        len --;
    };
    
    if (c == EOF) {
        return 0;
    }

    if ( * line == '\n' ) {
        * line ++ = '\n';
        i ++;
    };

    * line = '\0';
    
    return i;
}

void clear_line (char * line) {

    int i = 0;

    while (i < LEN) {
        * (line + i) = 0;
        i ++;
    }

}

void print_file (char * filename) {
//void print_file (char filename [LEN]) {

    FILE * fp;
    int line_counter = 0, page_counter = 1;
    char line [MAXLEN], rez, exit, *rez2;

    fp = fopen (filename, "r");    
    if (fp == NULL) {
        fprintf (stderr, "%s: cannot open file %s\n", progname, filename);
    }
    else {
        printf ("--------------===============HEADER===============--------------\n");
        exit = 1;
        while (exit) {
            clear_line (line);
            rez2 = fgets (line, 10, fp); 
            if (rez2 != NULL) {
                fputs (line, stdout);
                exit = 1;
                line_counter ++;
            }
            else {
                exit = 0;
            }
            if (line_counter == 80) {
                line_counter = 0;
                page_counter ++;
            }
        }
        printf ("--------------===============TAIL================--------------\n");
        printf ("Theres are in file '%s' %d pages;\n", filename, page_counter);
    }
    fclose (fp);

}

void print_file_2 (char * filename) {

    FILE * fp;
    char line [LEN], *rez, exit;

    fp = fopen (filename, "r");
    if (fp != NULL) {
        printf ("---===HEADER===---\n");
        exit = 1;
        while (exit) {
            clear_line (line);
            rez = fgets (line, LEN, fp);
            printf ("line = '%s'; rez = %d;\n", line, rez);
            if (rez == NULL) {
                exit = 0;
            }
        }
        printf ("---====TAIL====---\n");
    }
    else {
        fprintf (stderr, "%s: cannot open file %s;\n", progname, filename);
    }
    fclose (fp);



}



