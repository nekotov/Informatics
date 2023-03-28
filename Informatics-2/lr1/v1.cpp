//1. кількість цифр у числі N; for
//2. організувати масив, елементами якого є цифри числа N; while
//3. середнє арифметичне цифр числа N; do while
//4. середнє геометричне цифр числа N; for
//5. факторіал N!; while
//6. суму всіх парних чисел від 1 до N; do while
//7. суму всiх непарних чисел від 1 до N. for
#include <iostream>
#include <cmath>

using namespace std;

// кількість цифр у числі N;
int CountOfDigits(int N) {
    int count = 0;
    for(int i = 0; N > 0; i++) {
        count++;
        N /= 10;
    }
    return count;
}

int CountOfDigits(int N, int M) { // N+M, перевантажена функція
    return CountOfDigits(N + M);
}

int CountOfDigits(float N) { // float
    std::cout << "not int" << std::endl;
    return 0;
}

// організувати масив, елементами якого є цифри числа N;
int *ArrayFromNumber(int N) {
    int l = CountOfDigits(N);
    int *A = new int[l];
    int i = 0;
    while (N > 0) {
        A[i] = N % 10;
        N /= 10;
        i++;
    }
    return A;
}

// середнє арифметичне цифр числа N;
double ArithmeticMean(int N) {
    int l = CountOfDigits(N);
    int *A = ArrayFromNumber(N);
    double sum = 0;
    int i = 0;
    do {
        sum += A[i];
        i++;
    } while (i < l);
    return sum / l;
}

// середнє геометричне цифр числа N;
double GeometricMean(int N) {
    int l = CountOfDigits(N);
    int *A = ArrayFromNumber(N);
    double mul = 1;
    for(int i = 0; i < l; i++) {
        mul *= A[i];
    }
    return pow(mul, 1.0 / l);
}

// факторіал N!;
int Factorial(int N) {
    int mul = 1;
    int i = 1;
    while (i <= N) {
        mul *= i;
        i++;
    }
    return mul;
}

// суму всіх парних чисел від 1 до N;
int SumOfEvenNumbers(int N) {
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
int SumOfOddNumbers(int N) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int N = 16;
    std::cout << "CountOfDigits: " << CountOfDigits(N) << std::endl;
    std::cout << "ArithmeticMean: " << ArithmeticMean(N) << std::endl;
    std::cout << "GeometricMean: " << GeometricMean(N) << std::endl;
    std::cout << "Factorial: " << Factorial(N) << std::endl;
    std::cout << "SumOfEvenNumbers: " << SumOfEvenNumbers(N) << std::endl;
    std::cout << "SumOfOddNumbers: " << SumOfOddNumbers(N) << std::endl;
    return 0;
}