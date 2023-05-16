#include <iostream>
#include <cmath>

using namespace std;

int len(int N) {
    int l = 0;
    while (N > 0) {
        l++;
        N /= 10;
    }
    return l;
}

int len(int N, int M){
    return len(N) + len(M);
}

float len(float N) {
    cout << "float" << endl;
    return N;
}

int *ArrayFromNumber(int N){
    int l = len(N);
    int *A = new int[l];
    for (int i = 0; i < l; i++) {
        A[i] = N % 10;
        N /= 10;
    }
    return A;
}

double ArithmeticMean(int N){
    int l = len(N);
    int *A = ArrayFromNumber(N);
    double sum = 0;
    int i = 0;
    do {
        sum += A[i];
        i++;
    } while (i < l);
    return sum / l;
}

double GeometricMean(int N){
    int l = len(N);
    int *A = ArrayFromNumber(N);
    double mul = 1;
    int i = 0;
    while (i < l) {
        mul *= A[i];
        i++;
    }
    return pow(mul, 1.0 / l);
}

long Factorial(int N){
    long mul = 1;
    for (int i = 1; i <= N; i++) {
        mul *= i;
    }
    return mul;
}

int SumOfEven(int N){
    int sum = 0;
    do {
        if (N % 2 == 0) {
            sum += N;
        }
        N--;
    } while (N > 0);
    return sum;
}

int SumOfOdd(int N){
    int sum = 0;
    while (N > 0) {
        if (N % 2 == 1) {
            sum += N;
        }
        N--;
    }
    return sum;
}

int main(){
    int N;
    cout << "Enter N: ";
    cin >> N;
    cout << "Arithmetic mean: " << ArithmeticMean(N) << endl;
    cout << "Geometric mean: " << GeometricMean(N) << endl;
    cout << "Factorial: " << Factorial(N) << endl;
    cout << "Sum of even: " << SumOfEven(N) << endl;
    cout << "Sum of odd: " << SumOfOdd(N) << endl;
    return 0;
}