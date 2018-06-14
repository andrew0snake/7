#include <stdio.h>
#include <ctype.h>

int main () {

    int i;

    for (i = 0; i < 255; i ++) {
        if (isprint (i)) {
            printf ("i = %d = %c;\n", i, i);
        }    
        else {
            printf ("i is NOT 'isprint' = %d = %c;\n", i, i);
        }
    }

}
