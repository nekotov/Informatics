//
// Created by Dembytskyi Paulo on 07/02/2023.
//
#include <iostream>
#include <cmath>

using std::cout;
using std::string;

void first(float n) {
    cout << "введене число не цілого типу\n";
}

int first(int n) {
    int count = 0;
    do {
        n /= 10;
        count++;
    } while (n != 0);
    return count;
}

int first(int n, int m) {
    return first(n + m);
}

string array2str(int *arr, int size) {
    string str;
    for (int i = size - 1; i >= 0; i--) { // inverted order
        str += std::to_string(arr[i]) + ", ";
    }
    str = str.substr(0, str.length() - 2);
    return str;
}

int *second_imp(int n) {
    int *arr = new int[first(n)];
    int i = 0;
    while (n != 0) {
        arr[i] = n % 10;
        n /= 10; // n = n/10; 123/10 = 12
        i++;
    }
    return arr;
}

void second(float n) {
    cout << "введене число не цілого типу\n";
}

std::string second(int N) {
    return array2str(second_imp(N), first(N));
}

std::string second(int N, int M) {
    return array2str(second_imp(N + M), first(N + M));
}

double third(int N) {
    int *arr = second_imp(N);
    int len = first(N);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return double(sum) / double(len);
}

double third(int N, int M) {
    return third(N + M);
}

void third(float N) {
    cout << "введене число не цілого типу\n";
}

double fourth(int N) {
    int *arr = second_imp(N);
    int len = first(N);
    int product = 1;
    int i = 0;
    do {
        product *= arr[i];
        i++;
    } while (i < len);
    return pow(product, 1.0 / len);
}

double fourth(int N, int M) {
    return fourth(N + M);
}

void fourth(float N) {
    cout << "введене число не цілого типу\n";
}

int fifth(int N) {
    int product = 1;
    for (int i = 1; i <= N; i++) {
        product *= i;
    }
    return product;
}

int fifth(int N, int M) {
    return fifth(N + M);
}

void fifth(float N) {
    cout << "введене число не цілого типу\n";
}

int sixth(int N) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    return sum;
}

int sixth(int N, int M) {
    return sixth(N + M);
}

void sixth(float N) {
    cout << "введене число не цілого типу\n";
}

int seventh(int N) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            sum += i;
        }
    }
    return sum;
}

int seventh(int N, int M) {
    return seventh(N + M);
}

void seventh(float N) {
    cout << "введене число не цілого типу\n";
}

int main() {
    int N = 321;
    cout << first(N) << "\n";
    cout << second(N) << "\n";
    cout << third(N) << "\n";
    cout << fourth(N) << "\n";
    cout << fifth(N) << "\n";
    cout << sixth(N) << "\n";
    cout << seventh(N) << "\n";

    cout << first(N, N) << "\n";
    cout << second(N, N) << "\n";
    cout << third(N, N) << "\n";
    cout << fourth(N, N) << "\n";
    cout << fifth(N, N) << "\n";
    cout << sixth(N, N) << "\n";
    cout << seventh(N, N) << "\n";

    first(0.0f);
    second(0.0f);
    third(0.0f);
    fourth(0.0f);
    fifth(0.0f);
    sixth(0.0f);
    seventh(0.0f);

    return 0;
}