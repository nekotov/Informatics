//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>

int main() {
    int speed = 299792;
    int hour = 3600;
    int day = 24;
    printf("The distance that the light wave travels in 1 hour is: %d km", speed * hour);
    printf("The distance that the light wave travels in 1 day is: %d km", speed * hour * day);
    return 0;
}