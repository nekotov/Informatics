#include <iostream>
#include <cmath>

using namespace std;

// кількість цифр у числі N;
int CountOfDigits(int N) {
    int count = 0;
    while(N > 0) {
        count++;
        N /= 10; // N = N / 10; // 12 -> 1.2 -> 1 // /= - це те саме що і N = N / 10;
    }
    return count;
}

// організувати масив, елементами якого є цифри числа N;
int *ArrayFromNumber(int N) {
    int l = CountOfDigits(N); // 123 -> 3, 561423 -> 6
    int *A = new int[l];
    for(int i = 0; i < l; i++) {
        A[i] = N % 10; // 123%10 -> 3, 12%10 -> 2, 1%10 -> 1
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
    do {
        sum += A[i]; // sum = sum + A[i];
        i++; // i = i + 1;
    } while (i < l);
    return sum / l;
}

// середнє геометричне цифр числа N;
double GeometricMean(int N) {
    int l = CountOfDigits(N);
    int *A = ArrayFromNumber(N); // 123 -> [3, 2, 1]
    double mul = 1;
    int i = 0;
    while (i < l) {
        mul *= A[i]; // mul = mul * A[i];
        i++; // i = i + 1;
    }
    return pow(mul, 1.0 / l);
}

// факторіал N!;
int Factorial(int N) {
    int mul = 1;
    for(int i = 1; i <= N; i++) {
        mul *= i; // mul = mul * i;
    }
    return mul;
}

// суму всіх парних чисел від 1 до N;
int SumOfEven(int N) {
    int sum = 0;
    int i = 1;
    do {
        if (i % 2 == 0) {
            sum += i;
        }
        i++;
    } while (i <= N);
    return sum;
}

// суму всiх непарних чисел від 1 до N.
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

int SumOfOdd(int N,int M){
    return SumOfOdd(N+M);
}

int SumOfOdd(float N){
    cout << "float" << endl;
    return 0;
}

int main() {
    int N;
    cin >> N;
    cout << CountOfDigits(N) << endl;
    int *A = ArrayFromNumber(N);
    for(int i = 0; i < CountOfDigits(N); i++) {
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