//
// Created by Pavlo Dembytskyi on 25/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        int random = rand() % 6 + 1;
        if (random == 6) {
            count++;
        }
    }
    printf("Frequency of falling out of the number 6 on 1000 Tests: %d", count);
}