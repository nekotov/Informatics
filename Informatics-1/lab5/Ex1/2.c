//
// Created by Pavlo Dembytskyi on 25/11/2022.
//
#include <math.h>
#include <stdio.h>

int main() {
    double a, b, c, d, y;
    a = 2.34;
    b = 0.756;
    c = 2.23;
    d = -1.653;

    y = ((exp(a) + 3 * log(c)) / sqrt(pow(b, c))) * fabs(atan(d));
    printf("y = %lf", y);
}