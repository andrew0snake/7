#include <stdio.h>
#include <stdarg.h>

void minprintf (char * fmt, ...);

int main () {

    int i = 20;
    double f = 12.0;

    minprintf ("%d, %o, %x, %e, %f, %g, '%s', %c,\n", i, i, i, f, f, f, "string", 'e');


    return 0;

}

void minprintf (char * fmt, ...) {

    va_list ap;
    char *p, * sval;
    int ival; double dval;

    va_start (ap, fmt);
    for (p = fmt; *p; p ++) {
        if (*p != '%') {
            putchar (*p);
            continue;
        }
        switch (*++p){
        case 'd':
            ival = va_arg (ap, int);
            printf ("%d", ival);
            break;        
        case 'o':
            ival = va_arg (ap, int);
            printf ("%o", ival);
            break;        
        case 'x':
            ival = va_arg (ap, int);
            printf ("%x", ival);
            break;        
        case 'e':
            ival = va_arg (ap, double);
            printf ("%e", dval);
            break;        
        case 'f':
            dval = va_arg (ap, double);
            printf ("%f", dval);
            break;
        case 'g':
            dval = va_arg (ap, double);
            printf ("%g", dval);
            break;
        case 's':
            for (sval = va_arg (ap, char *); *sval; sval ++) {
                putchar (*sval);            
            }
            break;
        case 'c':
            dval = va_arg (ap, int);
            printf ("%c", ival);
            break;
        default:
            putchar (*p);
            break;
        }
    }
    va_end (ap);
}

