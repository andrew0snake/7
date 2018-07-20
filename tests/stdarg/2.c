#include <stdio.h>
#include <stdarg.h>

#define MAX 100

//void f1 ("%d %f", int, double);
void f1 (char *, ...);

int main () {

    int a = 5;
    double b = 13.0; 
    
    f1 ("%d %f", a, b);

    return 0;

}

void f1 (char * qwe, ...) {

    va_list ap;
    char * p;
    int i_arg;
    double d_arg;

    va_start (ap, qwe);

    for (p = qwe; *p; p ++) {
        if (*p != '%') {
            printf ("\nsymbol is not equal %% and = '%c';\n", *p);
//            putchar (*p);
            continue;
        }
        switch (*(p + 1)){
        case 'd':
            i_arg = va_arg (ap, int);
            printf ("%d", i_arg);
            break;
        case 'f':
            d_arg = va_arg (ap, double);
            printf ("%f", d_arg);
            break;
        default:
            break;
        }
    }
    putchar ('\n');
    va_end (ap);
    
}


