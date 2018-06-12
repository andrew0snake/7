#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int getline_my (char * line);
void clear_string (char * line);

int main ( int argc, char * argv [] ) {

    int i = 0;
    char string [MAX];
    char tmp = 0, check = 0;

    strcpy (string, argv [0]);
    printf ("string = %s;\n", string);

    while (! isalpha (*(argv [0] + i))) {
        printf ("* (argv [0] + i) is not letter and = %c;\n", * (argv [0] + i));
        i ++;
    }
    putchar ('\n');

    tmp = * ( argv [0] + i);
    if (tmp >= 'A' && tmp <= 'Z') {
        printf ("First letter in the name of this program is in upper case, \nthan program will convert lower case of inputed strings to upper.");
        check = 1;
    }
    else {
        printf ("First letter in the name of this program is in lower case, \nthan program will convert upper case of inputed strings to lower.");
        check = 0;
    }
    putchar ('\n');

    while ((tmp = getline_my (string)) != -1) {
        i = 0;
        if (!check) {
            while (*(string +i) != '\0') {
                printf ("%c", tolower(*(string + i)));
                i ++;
            }
            printf ("\n");
        }
        else {
            while (*(string +i) != '\0') {
                printf ("%c", toupper(*(string + i)));
                i ++;
            }
            printf ("\n");

        }
    }


}


int getline_my (char * line) {

    int i = 0;
    char c = 0;

    while ((c = getchar ()) != EOF && c != '\n') {
        * (line + i) = c;
        i ++;
    }
    * (line + i) = '\0';

    if (c == EOF && i == 0) {
        return -1;
    } 

    

}

void clear_string (char * line) {

    int i;

    for (i = 0; i < MAX; i ++) {
        * (line + i) = 0;
    }

}



