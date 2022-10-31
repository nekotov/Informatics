//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>

int main() {
    int radius = 1740;
    int square = 4 * 3.14 * radius * radius;
    int volume = 4 / 3 * 3.14 * radius * radius * radius;
    printf("The square of the moon is: %d km^2", square);
    printf("The volume of the moon is: %d km^3", volume);
    return 0;
}