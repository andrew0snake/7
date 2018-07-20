#include <stdio.h>

void f1 (int *);

int main () {

    int a = 9;
    int * b;
    
    b = &a;
    printf ("in main a = %d, b =     %p, *b = %d;\n", a, b, *b);
    f1 (b);



}

void f1 (int * pointer) {

    int * p2;

    printf ("in f1 getted pointer = %p;\n", pointer);
    p2 = pointer;
    printf ("in f1 p2 =             %p;\n", p2);

}
