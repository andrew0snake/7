#include <stdio.h>
#include <ctype.h>

#define MAX 100

void edit_line (char * line);
int getline_my (char * line);
void clear_line (char * line);

int main () {

    char c = 0;
    char line [MAX];
    int n = 0, rez = 0;

    clear_line (line);
    while ((rez = getline_my (line)) != -1) {
        printf ("source line:%s;\n", line);        
        printf ("edited line:\n");
        edit_line (line);
        clear_line (line);        
    }   
    return 0;
}

void edit_line (char * line) {
    
    int i = 0;
    unsigned char step = 0;

    while (* (line + i) != '\0') {
        if (! isprint (* (line + i))) {
            printf ("%x", * (line + i));
        }
        else {
            printf ("%c", * (line + i));
        }
        i ++;
        step ++;
        if (step == 60) {
            printf ("\n");
            step = 0;
        }
    }
    putchar ('\n');

}

int getline_my (char * line) {

    int i = 0;
    char c = 0;

    while ((c = getchar ()) != EOF && c != '\n') {
        * (line + i) = c;
        i ++;
    }
    if (c == EOF && i == 0) {
        return -1;
    }
    * (line + i) = '\0';
    return i;

}

void clear_line (char *line) {

    int i;

    for (i = 0; i < MAX; i ++) {
        * (line + i) = 0;
    }

}


