#include <stdio.h>

int main () {

    double sum, v;

    sum = 0;
    while (scanf ("%1lf", &v) == 1) {
        printf ("\t%.2f\n", sum += v);
    }

    return 0;

}
