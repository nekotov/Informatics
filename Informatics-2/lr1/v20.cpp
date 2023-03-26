#include <iostream> //cout
#include <cmath> // pow

using namespace std; // std::cout

int len(int N) {
    int l = 0;
    for (; N > 0; N /= 10) {
        l++;
    }
    return l;
}

int *ArrayFromNumber(int N) {
    int l = len(N);
    int *A = new int[l];
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
    int *A = ArrayFromNumber(N);
    double sum = 0;
    do {
        sum += A[l - 1];
        l--;
    } while (l > 0);
    return sum / len(N);
}

double GeometricMean(int N) {
    int l = len(N);
    int *A = ArrayFromNumber(N);
    double mul = 1;
    for (int i = 0; i < l; i++) {
        mul *= A[i];
    }
    return pow(mul, 1.0 / l);
}

int Factorial(int N) {
    int mul = 1;
    while (N > 0) {
        mul *= N;
        N--;
    }
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

int SumOfEven(int N, int M) {
    SumOfEven(N + M);
}

void SumOfEven(float N) {
    std::cout << "введене число не цілого типу" << std::endl;
}

int SumOfOdd(int N) {
    int sum = 0;
    do {
        if (N % 2 != 0) {
            sum += N;
        }
        N--;
    } while (N > 0);
    return sum;
}

int main() {
    int N = 321;
    std::cout << "кількість цифр у числі N: " << len(N) << std::endl;
    std::cout << "середнє арифметичне цифр числа N: " << ArithmeticMean(N) << std::endl;
    std::cout << "середнє геометричне цифр числа N: " << GeometricMean(N) << std::endl;
    std::cout << "факторіал N!: " << Factorial(N) << std::endl;
    std::cout << "суму всіх парних чисел від 1 до N: " << SumOfEven(N) << std::endl;
    std::cout << "суму всіх непарних чисел від 1 до N: " << SumOfOdd(N) << std::endl;
    return 0;
}