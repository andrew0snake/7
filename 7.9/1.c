#include <stdio.h>
 #include <ctype.h>
 #include <string.h>
 #include <time.h>

 #define my_isupper3(c) (c >= 'A' && c <= 'Z')

 int my_isupper1(char );
 int my_isupper2(char );

 int main(void)
 {
    int i, count, num = 20000000;
    double t1, t2;
    char line[20] = "My sample String";

    t1 = clock();
    while (--num)
        for (i=0; line[i]; i++)
            if (my_isupper3(line[i]))
                count++;
    t2 = (clock() - t1)/CLOCKS_PER_SEC;
    printf("%lf\n", t2);

    return 0;
 }

 int my_isupper1(char c) {
    return (c >= 'A' && c <= 'Z');
 }

 int my_isupper2(char c) {
    return (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ",c) != NULL);
 }

