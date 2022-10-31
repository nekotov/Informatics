//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>

int main() {
    int t, t1, t2;
    t = 14;
    t1 = t-- + 7;
    t=14;
    t2 = --t + 7;
    printf("t = %d t1 = %d t2 = %d", t, t1, t2);
}