#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define MAX 100

void f1 (char *, ...);    
int getline_my (char *);

int main () {
    
    int int_d = 0, int_o = 0;
    float fl1, fl2;
    char str_orig [MAX];
    char * str = str_orig;

    f1 ("%d %d %f %d %s", &int_d, &int_o, &fl1, &fl2, str_orig);

    printf ("int_d = %d; int_o = %o; fl1 = %f; fl2 = %g; str = '%s';\n", int_d, int_o, fl1, fl2, str);

    return 0;

}

void f1 (char *fmt, ...) {

    int i = 0, j = 0;
    int * i_arg;
    double * f_arg;
    char * c_arg, *p, *s_arg;
    va_list ap;
    char str [MAX], check = 1;

    va_start (ap, fmt);
    for (p = fmt; *(p + i); i++) {
        switch (*(p + i + 1)) {
        case 'd':
            i_arg = va_arg (ap, int *);
            scanf ("%d", i_arg);
            i++;
            break;
        case 'f':
            f_arg = va_arg (ap, float *);
            scanf ("%f", f_arg);
            i ++;
            break;
        case 'g':
            f_arg = va_arg (ap, float *);
            scanf ("%g", f_arg);
            i ++;
            break;
        case 's':
            s_arg = va_arg (ap, char *);
            scanf ("%s", s_arg);
            i ++;
            break;
        default:     
            break;
        }
    }

    va_end (ap);

}


int getline_my (char *line) {

    int i = 0;
    char c = 0;
    
    while ((c = getchar ()) != EOF && c != '\n') {
        * (line + i) = c;
        i ++;
    }
    * (line + i) = '\0';
    return i;
}



