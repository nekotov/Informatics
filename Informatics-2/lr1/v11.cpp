//1. кількість цифр у числі N; while
//2. організувати масив, елементами якого є цифри числа N; for
//3. середнє арифметичне цифр числа N; do while
//4. середнє геометричне цифр числа N; do while
//5. факторіал N!;  while
//6. суму всіх парних чисел від 1 до N; for
//7. суму всiх непарних чисел від 1 до N. do while

#include <iostream>
#include <cmath>

using namespace std;

// кількість цифр у числі N;
int CountOfDigits(int N){
    int count = 0;
    while (N > 0) {
        count++;
        N /= 10; // N = N / 10; // 12 -> 1.2 -> 1
    }
    return count;
}


// організувати масив, елементами якого є цифри числа N;
int *ArrayFromNumber(int N) {
    int l = CountOfDigits(N); // 123 -> 3, 561423 -> 6
    int *A = new int[l];
    for (int i = 0; N > 0; i++) {
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
    do {
        sum += A[i]; // sum = sum + A[i];
        i++; // i = i + 1;
    } while (i < l);
    return sum / l;
}

// середнє геометричне цифр числа N;
long GeometricMean(int N){
    int l = CountOfDigits(N);
    int *A = ArrayFromNumber(N);
    long sum = 1;
    int i = 0;
    do {
        sum *= A[i];
        i++;
    } while (i < l);
    return pow(sum, 1.0 / l);
}

// факторіал N!;
long Factorial(int N){
    long fact = 1;
    while (N > 0) {
        fact *= N;
        N--;
    }
    return fact;
}

// N+M перевантаження функції
long Factorial(int N, int M){
    return Factorial(N+M);
}

// float перевантаження
long Factorial(float N){
    cout << "Factorial(float N)" << endl;
    return 0;
}

// суму всіх парних чисел від 1 до N;
int SumOfEvenNumbers(int N){
    int sum = 0;
    for (int i = 2; i <= N; i += 2) {
        sum += i;
    }
    return sum;
}

// суму всiх непарних чисел від 1 до N.
int SumOfOddNumbers(int N){
    int sum = 0;
    int i = 1;
    do {
        sum += i;
        i += 2;
    } while (i <= N);
    return sum;
}

int main() {
    int N = 16;
    std::cout << "CountOfDigits: " << CountOfDigits(N) << std::endl; // 321 -> 3
    std::cout << "ArithmeticMean: " << ArithmeticMean(N) << std::endl; // (1+6)/2 = 3.5
    std::cout << "GeometricMean: " << GeometricMean(N) << std::endl;
    std::cout << "Factorial: " << Factorial(N) << std::endl; // 16*15*14*13*12*11*10*9*8*7*6*5*4*3*2*1
    std::cout << "SumOfEvenNumbers: " << SumOfEvenNumbers(N) << std::endl; // 2+4+6+8+10+12+14+16
    std::cout << "SumOfOddNumbers: " << SumOfOddNumbers(N) << std::endl; // 1+3+5+7+9+11+13+15
    return 0;
}