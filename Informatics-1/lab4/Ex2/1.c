//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>
#include <math.h>

int main() {
    double r, l, s;
    printf("Enter radius: ");
    scanf("%lf", &r);
    l = 2 * M_PI * r;
    s = M_PI * pow(r, 2);
    printf("Length: %f\n", l);
    printf("Square: %f\n", s);
    return 0;
}