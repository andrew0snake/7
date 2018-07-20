#include <stdio.h>

#define MAX 100

int getline_my (char *);

int main () {

    int day = 0, month = 0, year = 0;
    char line [MAX], monthname [10];

    while (getline_my (line) > 0) {
        if (sscanf (line, "%d %s %d", &day, monthname, & year) == 3) {
            printf ("valid: %s;\n", line);
        }
        else {
            if (sscanf (line, "%d %d %d", &day, &month, & year) == 3) {
                printf ("valid: %s;\n", line);
            }
            else {
                printf ("invalid: %s;\n", line);
            }
        }
    }

    return 0;

}

int getline_my (char *line) {

    int i = 0;
    char c = 0;

    while ((c = getchar ()) != EOF && c != '\n') {
        * (line + i) = c;
        i ++;
    }
    * (line + i) = '\0'; 
    return i;

}
