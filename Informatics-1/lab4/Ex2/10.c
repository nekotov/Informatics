//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>

int main() {
    int a, b;
    printf("Enter the left border of the interval: ");
    scanf("%d", &a);
    printf("Enter the right border of the interval: ");
    scanf("%d", &b);
    for (int i = a; i <= b; i++) {
        printf("%d F = %.2f C\n", i, (i - 32) / 1.8);
    }
    return 0;
}
