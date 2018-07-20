#include <stdio.h>

int main () {

    char a = 'a';
//    char *b = &a;
    char *b;    
    b = &a;

    printf ("a  = %c;\n", a);
    printf ("*b = %c;\n", *b);

    printf ("\n&a = %p;\n", &a);
    printf ("b  = %p;\n", b);


}
