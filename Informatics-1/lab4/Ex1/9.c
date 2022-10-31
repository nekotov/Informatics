//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>
#include <math.h>

int main() {
    double d1, d2, d;
    d1 = 18.3;
    d2 = 4.8;
    d = fmod(d1,d2); //(int)d1 % (int)d2
    printf("d1 = %f d2 = %f d = %f", d1, d2, d);
    return 0;
}