#include <stdio.h>
#include <string.h>
#include <time.h>

#define isupper_def(c) (c >= 'A' && c <= 'Z')

int isupper_time (char);
int isupper_space (char);

int main () {

    int n = 10000000, i = 0, j = 0, count = 0;
//    clock_t t_start, t_end, t_diff;
    double t_start, t_end, t_diff;
    clock_t t_example;
    char string [20] = "This tesT String";
    
    t_start = clock ();
    while ((n - i) > 0) {
        for (j = 0; string [j]; j ++) {
            if (isupper_def(string [j])) {
                count ++;
            }
        }
        i ++;
    }
    t_end = clock();
    t_diff = (t_end - t_start) / CLOCKS_PER_SEC;
    printf ("Total time taken by CPU with isupper_def: %f;\n", t_diff);

    i = 0; j = 0; count = 0;
    t_start = clock ();
    while ((n - i) > 0) {
        for (j = 0; string [j]; j ++) {
            if (!isupper_time(string [j])) {
                count ++;
            }
        }
        i ++;
    }
    t_end = clock();
    t_diff = (t_end - t_start) / CLOCKS_PER_SEC;
    printf ("Total time taken by CPU with isupper_time: %f;\n", t_diff);

    i = 0; j = 0; count = 0;
    t_start = clock ();
    while ((n - i) > 0) {
        for (j = 0; string [j]; j ++) {
            if (!isupper_space(string [j])) {
                count ++;
            }
        }
        i ++;
    }
    t_end = clock();
    t_diff = (t_end - t_start) / CLOCKS_PER_SEC;
    printf ("Total time taken by CPU with isupper_space: %f;\n", t_diff);


    t_example = clock() / CLOCKS_PER_SEC;
    printf ("t_example = %f;\n", t_example);

}

int isupper_time (char c) {

    if (c >= 'A' && c <= 'Z') {
        return 0;
    }   
    else {
        return 1;
    }
}

int isupper_space (char c) {

    if (strchr ("ABCDEFGHIJKLMNOPQRSTUVWXYZ",c)) {
        return 0;
    }
    else {
        return 1;
    }

}



