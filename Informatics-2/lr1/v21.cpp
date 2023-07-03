#include <cmath>
#include <iostream>

using namespace std;

//do while
int len(int n){
    int l = 0;
    do{
        n /= 10;
        l++;
    }while(n > 0);
    return l;
}

//for
int* to_array(int n){
    int l = len(n);
    int* arr = new int[l];
    for(int i = l - 1; i >= 0; i--){
        arr[i] = n % 10;
        n /= 10;
    }
    return arr;
}

//do while
double ArithmeticMean(int N){
    int l = len(N);
    int *A = to_array(N);
    double sum = 0;
    int i = 0;
    do {
        sum += A[i];
        i++;
    } while (i < l);
    return sum / l;
}

//do while
double GeometricMean(int N){
    int l = len(N);
    int *A = to_array(N);
    double mul = 1;
    int i = 0;
    do {
        mul *= A[i];
        i++;
    } while (i < l);
    return pow(mul, 1.0 / l);
}

//for
int Factorial(int N){
    int mul = 1;
    for (int i = 1; i <= N; i++) {
        mul *= i;
    }
    return mul;
}

//while
int SumOfEven(int N){
    int sum = 0;
    while (N > 0) {
        if (N % 2 == 0) {
            sum += N;
        }
        N--;
    }
    return sum;
}

//while
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

int SumOfOdd(int N, int M){
    return SumOfOdd(N) + SumOfOdd(M);
}

float SumOfOdd(float N){
    cout << "float" << endl;
    return N;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Len = " << len(n) << endl;
    int* arr = to_array(n);
    for(int i = 0; i < len(n); i++){
        cout << arr[i] << " ";
    }
    cout << endl << "ArithmeticMean = " << ArithmeticMean(n) << endl;
    cout << "GeometricMean = " << GeometricMean(n) << endl;
    cout << "Factorial = " << Factorial(n) << endl;
    cout << "SumOfEven = " << SumOfEven(n) << endl;
    cout << "SumOfOdd = " << SumOfOdd(n) << endl;
    return 0;
}