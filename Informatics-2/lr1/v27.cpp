#include <iostream>
#include <cmath>

using namespace std;

int len(int N) {
    int l = 0;
    do {
        l++;
        N /= 10;
    } while (N > 0);
    return l;
}

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

double ArithmeticMean(int N) {
    int l = len(N);
    int* A = ArrayFromNumber(N);
    double sum = 0;
    for (int i = 0; i < l; i++) {
        sum += A[i];
    }
    return sum / l;
}

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

int Factorial(int N) {
    int mul = 1;
    int i = 1;
    do {
        mul *= i;
        i++;
    } while (i <= N);
    return mul;
}

int SumOfEven(int N) {
    int sum = 0;
    while (N > 0) {
        if (N % 2 == 0) {
            sum += N;
        }
        N--;
    }
    return sum;
}

int SumOfEven(int N, int M){
    return SumOfEven(N) + SumOfEven(M);
}

float SumOfEven(float N) {
    cout << "float" << endl;
    return N;
}

int SumOfOdd(int N) {
    int sum = 0;
    for (int i = 1; i <= N; i += 2) {
        sum += i;
    }
    return sum;
}

int main(){
    int N;
    cout << "N = ";
    cin >> N;
    cout << "Len = " << len(N) << endl;
    cout << "ArrayFromNumber = ";
    int* A = ArrayFromNumber(N);
    for (int i = 0; i < len(N); i++) {
        cout << A[i] << " ";
    }
    cout << endl << "ArithmeticMean = " << ArithmeticMean(N) << endl;
    cout << "GeometricMean = " << GeometricMean(N) << endl;
    cout << "Factorial = " << Factorial(N) << endl;
    cout << "SumOfEven = " << SumOfEven(N) << endl;
    cout << "SumOfOdd = " << SumOfOdd(N) << endl;
    return 0;
}