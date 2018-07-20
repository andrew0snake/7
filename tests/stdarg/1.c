#include <stdio.h>
#include <stdarg.h>

void f1 (int, ...);

int main () {

    int a = 10, c = 35.5; //b = 4294976298;
    char x = 'x', y = 'y', z = 'z';
//    float b = 4294976298;
    float b = 5;
    f1 (a, b, c, x, y, z, -1);

}

void f1 (int a, ...) {
    
    va_list arg1;
    int i = 0, sum = 0;    

    va_start (arg1, a);
    for (i = a; i > 0; i = va_arg (arg1, int)) {
        printf ("getted argument = %d, as char = %c;\n", i, i);
        sum += i;
    }
    printf ("in the end sum = %d;\n", sum);
    
    va_end (arg1);
}


