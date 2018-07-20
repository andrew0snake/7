#include <stdio.h>
#include <stdarg.h>

#define MAX 100

void f1 (char *, ...);

int main () {

    int i = 0;
    int a, b;
    float c, d;

    f1 ("%d %*f", &a, &c);
    printf ("getted in f1 a = %d; c = %f;\n", a, c);
    return 0;  

}

void f1 (char * f, ...) {

    va_list ap;
    char * p;
    int * a;
    float * b;

    va_start (ap, f);

    for (p = f; *p; *p ++) {
        switch (*p) {
        case 'd':
            a = va_arg (ap, int *);
            scanf ("%d", a);
            break;
        case 'f':
            b = va_arg (ap, float *);
            scanf ("%f", b);
            break;
        case '%':
            break;
        default:
            putchar (*p);
            break;
        }
    }



}

