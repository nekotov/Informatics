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
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    return 0;
}