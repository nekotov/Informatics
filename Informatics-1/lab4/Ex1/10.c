//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>

int main() {
    int y1, y2, y;
    y = 8;
    y1 = y++ + 5;
    y=8;
    y2= ++y + 5;
    printf("y = %d y1 = %d y2 = %d", y, y1, y2);
}