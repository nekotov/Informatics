//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>

int main() {
    double max, number;
    printf("Enter the first number: ");
    scanf("%lf", &max);
    for (int i = 1; i < 10; i++) {
        printf("Enter the next number: ");
        scanf("%lf", &number);
        if (number > max) {
            max = number;
        }
    }
    printf("The biggest number is: %f", max);
    return 0;
}