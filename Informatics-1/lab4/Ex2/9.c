//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, d, x1, x2;
    printf("Enter the first coefficient: ");
    scanf("%lf", &a);
    printf("Enter the second coefficient: ");
    scanf("%lf", &b);
    printf("Enter the third coefficient: ");
    scanf("%lf", &c);
    d = b * b - 4 * a * c;
    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("The first root is: %f", x1);
        printf("The second root is: %f", x2);
    } else if (d == 0) {
        x1 = -b / (2 * a);
        printf("The root is: %f", x1);
    } else {
        printf("There are no roots");
    }
    return 0;
}