#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int A[10];
    double B[10];
    int min = 10;
    int i;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        A[i] = rand() % 10 + 1;
        printf("%d ", A[i]);
        if (A[i] < min) {
            min = A[i];
        }
    }
    printf("\n");
    for (i = 0; i < 10; i++) {
        if (min == 0) {
            B[i] = -10;
        } else {
            B[i] = (double) A[i] / min;
        }
        printf("%f ", B[i]);
    }
    printf("\n");
    return 0;
}