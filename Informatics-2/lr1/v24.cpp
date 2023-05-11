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

// організувати масив, елементами якого є цифри числа N;
int *ArrayFromNumber(int N) {
    int l = CountOfDigits(N); // 123 -> 3, 561423 -> 6
    int *A = new int[l];
    int i = 0;
    while (N > 0) {
        A[i] = N % 10; //
        N /= 10; // N = N / 10; // 12 -> 1.2 -> 1
        i++;
    }
    return A;
}

// середнє арифметичне цифр числа N;
double ArithmeticMean(int N) {
    int l = CountOfDigits(N);
    int *A = ArrayFromNumber(N); // 123 -> [3, 2, 1]
    double sum = 0;
    int i = 0;
    while (i < l) {
        sum += A[i]; // sum = sum + A[i];
        i++; // i = i + 1;
    }
    return sum / l;
}

double ArithmeticMean(int N, int M) {
    return (N+M);
}

float ArithmeticMean(float N){
    cout << "float ArithmeticMean(float N)" << endl;
    return N;
}

// середнє геометричне цифр числа N;
long GeometricMean(int N){
    int l = CountOfDigits(N);
    int *A = ArrayFromNumber(N);
    long sum = 1;
    for (int i = 0; i < l; i++) {
        sum *= A[i];
    }
    return pow(sum, 1.0 / l);
}

// факторіал N!;
long Factorial(int N) {
    long fact = 1;
    do {
        fact *= N;
        N--;
    } while (N > 0);
    return fact;
}

// суму всіх парних чисел від 1 до N;
long SumOfEvenNumbers(int N) {
    long sum = 0;
    while (N > 0) {
        if (N % 2 == 0) {
            sum += N;
        }
        N--;
    }
    return sum;
}

// суму всiх непарних чисел від 1 до N.
long SumOfOddNumbers(int N) {
    long sum = 0;
    for (int i = 1; i <= N; i += 2) {
        sum += i;
    }
    return sum;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;
    cout << "Count of digits: " << CountOfDigits(N) << endl;
    int *A = ArrayFromNumber(N);
    cout << "Array from number: ";
    for (int i = 0; i < CountOfDigits(N); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "Arithmetic mean: " << ArithmeticMean(N) << endl;
    cout << "Geometric mean: " << GeometricMean(N) << endl;
    cout << "Factorial: " << Factorial(N) << endl;
    cout << "Sum of even numbers: " << SumOfEvenNumbers(N) << endl;
    cout << "Sum of odd numbers: " << SumOfOddNumbers(N) << endl;
    return 0;
}