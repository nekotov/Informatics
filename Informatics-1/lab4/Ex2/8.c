//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>

int main() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            printf("%c ", i * 16 + j);
        }
        printf("\n");
    }
    return 0;
}