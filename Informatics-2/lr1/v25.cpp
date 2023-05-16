#include <iostream>
#include <cmath>

using namespace std;

// for
int len(int N) {
    int l = 0;
    for (; N > 0; N /= 10) {
        l++;
    }
    return l;
}

//do while
int* ArrayFromNumber(int N) {
    int l = len(N);
    int* A = new int[l];
    int i = 0;
    do {
        A[i] = N % 10;
        N /= 10;
        i++;
    } while (N > 0);
    return A;
}

//while
double ArithmeticMean(int N) {
    int l = len(N);
    int* A = ArrayFromNumber(N);
    double sum = 0;
    int i = 0;
    while (i < l) {
        sum += A[i];
        i++;
    }
    return sum / l;
}

//while
double GeometricMean(int N) {
    int l = len(N);
    int* A = ArrayFromNumber(N);
    long mul = 1;
    int i = 0;
    while (i < l) {
        mul *= A[i];
        i++;
    }
    return pow(mul, 1.0 / l);
}

long GeometricMean(int N, int M){
    return GeometricMean(N) + GeometricMean(M);
}

float GeometricMean(float N){
    cout << "float" << endl;
    return N;
}

//for
int Factorial(int N) {
    long mul = 1;
    for (; N > 0; N--) {
        mul *= N;
    }
    return mul;
}

//do while
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

//while
int SumOfOdd(int N) {
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
    cout << "N = ";
    cin >> N;
    cout << "Len = " << len(N) << endl;
    cout << "ArithmeticMean = " << ArithmeticMean(N) << endl;
    cout << "GeometricMean = " << GeometricMean(N) << endl;
    cout << "Factorial = " << Factorial(N) << endl;
    cout << "SumOfEvenDigits = " << SumOfEven(N) << endl;
    cout << "SumOfOddDigits = " << SumOfOdd(N) << endl;
    return 0;
}