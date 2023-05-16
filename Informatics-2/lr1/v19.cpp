#include <iostream>
#include <cmath>

using namespace std;

//while
int len(int N) {
    int l = 0;
    while (N > 0) {
        l++;
        N /= 10;
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

//while
double GeometricMean(int N) {
    int l = len(N);
    int* A = ArrayFromNumber(N);
    double mul = 1;
    int i = 0;
    while (i < l) {
        mul *= A[i];
        i++;
    }
    return pow(mul, 1.0 / l);
}

//while
int Factorial(int N) {
    int mul = 1;
    while (N > 0) {
        mul *= N;
        N--;
    }
    return mul;
}

int Factorial(int N, int M) {
    return Factorial(N) + Factorial(M);
}

float Factorial(float N) {
    cout << "Float" << endl;
    return N;
}

//do while
int SumOfEven(int N) {
    int sum = 0;
    do {
        if (N % 2 == 0) {
            sum += N;
        }
        N--;
    } while (N > 0);
    return sum;
}

//for
int SumOfOdd(int N) {
    int sum = 0;
    for (; N > 0; N--) {
        if (N % 2 != 0) {
            sum += N;
        }
    }
    return sum;
}

int main(){
    int N;
    cout << "N = ";
    cin >> N;
    cout << "ArithmeticMean: " << ArithmeticMean(N) << endl;
    cout << "GeometricMean: " << GeometricMean(N) << endl;
    cout << "Factorial: " << Factorial(N) << endl;
    cout << "SumOfEven: " << SumOfEven(N) << endl;
    cout << "SumOfOdd: " << SumOfOdd(N) << endl;
    return 0;
}