//2

#include <iostream>
#include <cmath>

using namespace std;

//for
int len(int n) {
    int l = 0;
    for (int i = n; i > 0; i /= 10) {
        l++;
    }
    return l;
}

//for
int* ArrayFromNumber(int n) {
    int l = len(n);
    int *A = new int[l];
    for (int i = 0; i < l; i++) {
        A[i] = n % 10;
        n /= 10;
    }
    return A;
}

int* ArrayFromNumber(int n, int m){
    int l = len(n) + len(m);
    int *A = new int[l];
    for (int i = 0; i < len(n); i++) {
        A[i] = n % 10;
        n /= 10;
    }
    for (int i = len(n); i < l; i++) {
        A[i] = m % 10;
        m /= 10;
    }
    return A;
}

float ArrayFromNumber(float n){
    cout << "float ArrayFromNumber(float n)" << endl;
    return n;
}

//while
double ArithmeticMean(int N) {
    int l = len(N);
    int *A = ArrayFromNumber(N);
    double sum = 0;
    int i = 0;
    while (i < l) {
        sum += A[i];
        i++;
    }
    return sum / l;
}

//do while
long GeometricMean(int N) {
    int l = len(N);
    int *A = ArrayFromNumber(N);
    double sum = 1;
    int i = 0;
    do {
        sum *= A[i];
        i++;
    } while (i < l);
    return pow(sum, 1.0 / l);
}

//for
long Factorial(int N) {
    long fact = 1;
    for (int i = 1; i <= N; i++) {
        fact *= i;
    }
    return fact;
}

//while
int SumOfOddDigits(int N) {
    int sum = 0;
    while (N > 0) {
        int d = N % 10;
        if (d % 2 == 1) {
            sum += d;
        }
        N /= 10;
    }
    return sum;
}

//do while
int SumOfEvenDigits(int N) {
    int sum = 0;
    do {
        int d = N % 10;
        if (d % 2 == 0) {
            sum += d;
        }
        N /= 10;
    } while (N > 0);
    return sum;
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    cout << "Len = " << len(n) << endl;
    cout << "ArithmeticMean = " << ArithmeticMean(n) << endl;
    cout << "GeometricMean = " << GeometricMean(n) << endl;
    cout << "Factorial = " << Factorial(n) << endl;
    cout << "SumOfOddDigits = " << SumOfOddDigits(n) << endl;
    cout << "SumOfEvenDigits = " << SumOfEvenDigits(n) << endl;
    return 0;
}