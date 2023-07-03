//2

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

int* ArrayFromNumber(int N, int M){
    return ArrayFromNumber(N+M);
}

float ArrayFromNumber(float N){
    cout << "float" << endl;
    return N;
}

//do while
double ArithmeticMean(int N) {
    int l = len(N);
    int* A = ArrayFromNumber(N);
    double sum = 0;
    int i = 0;
    do {
        sum += A[i];
        i++;
    } while (i < l);
    return sum / l;
}

//for
double GeometricMean(int N) {
    int l = len(N);
    int* A = ArrayFromNumber(N);
    long mul = 1;
    for (int i = 0; i < l; i++) {
        mul *= A[i];
    }
    return pow(mul, 1.0 / l);
}

//while
long Factorial(int N) {
    long mul = 1;
    int i = 1;
    while (i <= N) {
        mul *= i;
        i++;
    }
    return mul;
}

//do while
int SumOfEven(int N){
    int sum = 0;
    int i = 2;
    do {
        sum += i;
        i += 2;
    } while (i <= N);
    return sum;
}


//for
int SumOfOdd(int N){
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
    cout << "ArithmeticMean = " << ArithmeticMean(N) << endl;
    cout << "GeometricMean = " << GeometricMean(N) << endl;
    cout << "Factorial = " << Factorial(N) << endl;
    cout << "SumOfEven = " << SumOfEven(N) << endl;
    cout << "SumOfOdd = " << SumOfOdd(N) << endl;
    return 0;
}
