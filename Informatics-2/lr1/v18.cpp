#include <cmath>
#include <iostream>

using namespace std;

int CountOfDigits(int N) {
    int count = 0;
    do {
        count++;
        N /= 10;
    } while (N > 0);
    return count;
}

int *ArrayFromNumber(int N) {
    int l = CountOfDigits(N);
    int *A = new int[l];
    int i = 0;
    for (; N > 0; N /= 10) {
        A[i] = N % 10;
        i++;
    }
    return A;
}


double ArithmeticMean(int N) {
    int l = CountOfDigits(N);
    int *A = ArrayFromNumber(N);
    double sum = 0;
    int i = 0;
    while (i < l) {
        sum += A[i];
        i++;
    }
    return sum / l;
}

double GeometricMean(int N) {
    int l = CountOfDigits(N);
    int *A = ArrayFromNumber(N);
    double mul = 1;
    int i = 0;
    while (i < l) {
        mul *= A[i];
        i++;
    }
    return pow(mul, 1.0 / l);
}

double GeometricMean(int N, int M) {
    return GeometricMean(N + M);
}

double GeometricMean(float N) {
    std::cout << "float" << std::endl;
    return 0;
}

int Factorial(int N) {
    int mul = 1;
    do {
        mul *= N;
        N--;
    } while (N > 0);
    return mul;
}

int SumOfEven(int N) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    return sum;
}

int SumOfOdd(int N) {
    int sum = 0;
    int i = 1;
    while (i <= N) {
        if (i % 2 != 0) {
            sum += i;
        }
        i++;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    cout << CountOfDigits(N) << endl;
    int *A = ArrayFromNumber(N);
    for (int i = 0; i < CountOfDigits(N); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << ArithmeticMean(N) << endl;
    cout << GeometricMean(N) << endl;
    cout << Factorial(N) << endl;
    cout << SumOfEven(N) << endl;
    cout << SumOfOdd(N) << endl;
    return 0;
}