#include <stdio.h>

int main (int argc, char * argv []) {

    char c = 0;
    int i = 0;    
    
    while (argc > 0) {
        printf ("argc = %d; * argv [%d] = %s;\n", argc, i, * ( argv + i ));
        argc --;
        i ++;
    }    

    c = getchar ();
    printf ("getted char = %c; %d;\n", c, c);

    return 0;

}
