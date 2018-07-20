#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define MAX 100

char * arr [MAX];

void f1 (char * [MAX]);

int main () {
   
    char string0 [MAX] = "zyxwvu";
    char string1 [MAX] = "utsrpo";
    char string2 [MAX] = "654321";

    char * p;

    p = string0;
    printf ("p = '%s';\n", p);  
    printf ("*p = %c;\n", *p);
    printf ("* ++p = %c;\n", * ++ p);
    printf ("*p = %c;\n", *p);
    printf ("* (p + 1) = %c;\n", * (p + 1));

    arr [0] = string0;
    arr [1] = string1;
    arr [2] = string2;
    printf ("arr [0] = '%s';\n", arr [0]);
    printf ("arr [1] = '%s';\n", arr [1]);
    printf ("arr [2] = '%s';\n", arr [2]);
  
    f1 (arr);

}

void f1 (char * str [3]) {

    printf ("\nin f1:\n");
    
    printf ("str [0] = %s;\n", str [0]);
    printf ("* str = %s;\n", * str);
    printf ("* * str = %c;\n", **str);
    printf ("* ++ str = %s;\n", * ++ str);
    printf ("* str = %s;\n", * str);
    printf ("* (str + 1) = %s;\n", * (str + 1));


}

