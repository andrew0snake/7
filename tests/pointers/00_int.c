#include <stdio.h>

int main () {

    int b = 9;
    int * a = &b;

//    a = &b;

    printf ("b  = %d;\n", b);
    printf ("a = &b;\n");    
    printf ("*a = %d;\n\n", *a);
    
    printf ("&b = %p;\n", &b);
    printf ("a  = %p;\n", a);
    

}
