#include <stdio.h>

#define MAX 100

void getline_my (char *);

int main () {
    
    char line [MAX], *linep [MAX];
    int i;
    for (i = 0; i < 5; i ++) {    
        getline_my (linep [i]);
        printf ("getted line:'%s';\n", linep [i]);
    }

    return 0;
}

void getline_my (char * line) {

    int i, c;

    while ((c = getchar ()) != EOF && c != '\n') {
        * (line + i++) = c;
    }
}


