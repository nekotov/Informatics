//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>
#include <math.h>

int main() {
    double w1, w2, w;
    w1 = 118.6;
    w2 = 1.52 * pow(10, 2); // 152
    w = w1 + (int)w2;
    printf("w1 = %f w2 = %f w = %f", w1, w2, w);
    return 0;
}
