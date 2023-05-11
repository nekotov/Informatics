#include <iostream>
#include <cmath>

using namespace std;

// кількість цифр у числі N;
int CountOfDigits(int N){
    int count = 0;
    do {
        count++;
        N /= 10; // N = N / 10; // 12 -> 1.2 -> 1
    } while (N > 0);
    return count;
}

// організувати масив, елементами якого є цифри числа N; for
int *ArrayFromNumber(int N) {
    int l = CountOfDigits(N); // 123 -> 3, 561423 -> 6
    int *A = new int[l];
    int i = 0;
    for(; N > 0; i++) {
        A[i] = N % 10; //
        N /= 10; // N = N / 10; // 12 -> 1.2 -> 1
    }
    return A;
}

// середнє арифметичне цифр числа N;
double ArithmeticMean(int N) {
    int l = CountOfDigits(N);
    int *A = ArrayFromNumber(N); // 123 -> [3, 2, 1]
    double sum = 0;
    int i = 0;
    for (; i < l; i++) {
        sum += A[i]; // sum = sum + A[i];
    }
    return sum / l;
}

// Перевантаження функції ArithmeticMean
double ArithmeticMean(int N, int M) {
    return (N+M);
}

// Перевантаження функції ArithmeticMean
float ArithmeticMean(float N){
    cout << "float ArithmeticMean(float N)" << endl;
    return N;
}

// середнє геометричне цифр числа N;
long GeometricMean(int N){
    int l = CountOfDigits(N);
    int *A = ArrayFromNumber(N);
    long sum = 1;
    int i = 0;
    while (i < l) {
        sum *= A[i];
        i++;
    }
    return pow(sum, 1.0 / l);
}

// факторіал N!;
long Factorial(int N){
    long fact = 1;
    do {
        fact *= N;
        N--;
    } while (N > 0);
    return fact;
}

// суму всіх парних чисел від 1 до N;
int SumOfEven(int N) {
    int sum = 0;
    for (int i = 2; i <= N; i += 2) {
        sum += i;
    }
    return sum;
}

// суму всiх непарних чисел від 1 до N.
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
    cout << "N: ";
    cin >> N;
    cout << "CountOfDigits: " << CountOfDigits(N) << endl;
    cout << "ArithmeticMean: " << ArithmeticMean(N) << endl;
    cout << "GeometricMean: " << GeometricMean(N) << endl;
    cout << "Factorial: " << Factorial(N) << endl;
    cout << "SumOfEven: " << SumOfEven(N) << endl;
    cout << "SumOfOdd: " << SumOfOdd(N) << endl;
    return 0;
}