//1

#include <iostream>
#include <cmath>

using namespace std;

//do while
int len(int N) {
    int l = 0;
    do {
        l++;
        N /= 10;
    } while (N > 0);
    return l;
}

int len(int N, int l) {
    if (N > 0) {
        return len(N / 10, l + 1);
    }
    return l;
}

float len(float N) {
    cout << "float len(float N)" << endl;
    return N;
}

//while
int* ArrayFromNumber(int N) {
    int l = len(N);
    int* A = new int[l];
    int i = 0;
    while (N > 0) {
        A[i] = N % 10;
        N /= 10;
        i++;
    }
    return A;
}

//for
double ArithmeticMean(int N) {
    int l = len(N);
    int* A = ArrayFromNumber(N);
    double sum = 0;
    for (int i = 0; i < l; i++) {
        sum += A[i];
    }
    return sum / l;
}

//do while
double GeometricMean(int N) {
    int l = len(N);
    int* A = ArrayFromNumber(N);
    double mul = 1;
    int i = 0;
    do {
        mul *= A[i];
        i++;
    } while (i < l);
    return pow(mul, 1.0 / l);
}

//while
int Factorial(int N) {
    long mul = 1;
    int i = 1;
    while (i <= N) {
        mul *= i;
        i++;
    }
    return mul;
}

//for
int SumOfEven(int N) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    return sum;
}

//do while
int SumOfOdd(int N) {
    int sum = 0;
    int i = 1;
    do {
        if (i % 2 != 0) {
            sum += i;
        }
        i++;
    } while (i <= N);
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
    cout << "SumOfEven = " << SumOfEven(N) << endl;
    cout << "SumOfOdd = " << SumOfOdd(N) << endl;
    return 0;
}