//
// Created by Pavlo Dembytskyi on 31/10/2022.
//
#include <stdio.h>

int main() {
    double mass, height, velocity, kineticEnergy, potentialEnergy;
    printf("Enter the mass of the body: ");
    scanf("%lf", &mass);
    printf("Enter the height of the body: ");
    scanf("%lf", &height);
    printf("Enter the velocity of the body: ");
    scanf("%lf", &velocity);
    kineticEnergy = mass * velocity * velocity / 2;
    potentialEnergy = mass * 9.8 * height;
    printf("Kinetic energy: %f\nPotential energy: %f", kineticEnergy, potentialEnergy);
    return 0;
}