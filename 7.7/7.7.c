#include <stdio.h>
#include <string.h>

#define MAXLEN 100
#define LEN 100
#define MAXLINE 1000

int getline_my ( char * line, int len );
void clear_line (char *);
int find_pattern (char *, char *);    

char progname [MAXLEN];

/* find: print lines that match pattern from 1st arg */
int main ( int argc, char *argv [] ) {

    char line [ MAXLINE ], exit, args [MAXLEN], pattern [MAXLEN], files [MAXLEN] [MAXLEN];
    long lineno = 0;
    int c = 0, except, number, found, i, f_count = 0;

    strcpy (progname, argv [0]);
    exit = 1;
    if (argc > 1) {
        argc --;
        *argv ++;
        except = number = found = 0;
        while (exit && argc > 0) {
            if (strcmp (*argv, "-x") == 0 || strcmp (*argv, "-n") == 0) {
                if (strcmp (*argv, "-x") == 0) {
                    except = 1;
                }
                if (strcmp (*argv, "-n") == 0) {
                    number = 1;
                }
            }
            if (**argv == '-') {
                if (*(*argv + 1) != 'n' && *(*argv + 1) != 'x') {
                    printf ("Wrong argument '%c'.\n", *(*argv + 1));
                    exit = 0;
                }                    
            }        
            else {
                strcpy (pattern, *argv);
                *argv ++;
                argc --;
                exit = 0;
            }            
            if (exit != 0) {
                *argv ++;
                argc --;
            }
        }
        if (except) {
            printf ("except;\n");
        }
        if (number) {
            printf ("number;\n");
        }
    }
    else {
        printf ( "Usage: find -x -n pattern file1 file2 ....\n" );
    }

    printf ("pattern = '%s'; argc = %d;\n", pattern, argc);

    if (strlen (pattern)) {
        if (argc >= 1) {
            i = 0;
            while (argc > 0) {
                strcpy (files [i], *argv);
                argc --;
                *argv ++; 
                i ++;
            }
            f_count = i;
        }
        else {
            printf ("Enter please files to open and search for pattern:\n");
            i = 0;    
            clear_line (line);
            while (getline_my (line, MAXLINE)) {
                strcpy (files [i], line);
                i ++;
                clear_line (line);
            }
            f_count = i;
        }
    }

    for (i = 0; i < f_count; i ++) {
        printf ("file to open and compare = '%s';\n", files [i]);
        find_pattern (files [i], pattern);
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

    while (i < MAXLINE) {
        * (line + i) = 0;
        i ++;
    }

}

int find_pattern (char *filename, char *pattern) {

    FILE * fp;    
    char line [MAXLEN], found = 0;

    putchar ('\n');    
    fp = fopen (filename, "r");
    if (fp == NULL) {
        fprintf (stderr, "%s: error while opening file %s;\n", progname, filename);
    }
    else {      
        printf ("file '%s' successfully opened.\n", filename);
        while (fgets (line, MAXLEN, fp) != NULL && found == 0) {
            if (strstr (line, pattern) != NULL) {
                printf ("pattern found!\n");
                found = 1;
            }
        }
        if (found == 0) {
            printf ("Sorry, pattern not found in file %s;\n", filename);
        }    
        fclose (fp);
        printf ("file %s successfully closed\n\n", filename);
    }
    
    return (found == 1)? 1:0;

}

