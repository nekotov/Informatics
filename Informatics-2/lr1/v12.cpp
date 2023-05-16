#include <iostream>
#include <cmath>

using namespace std; // std::cout

// first function returns the number of digits in N
int first(int N) {
    int count = 0; // variable to store the number of digits
    do {
        N /= 10; // divide N by 10 to remove the last digit
        count++; // increment the count for each digit
    } while (N != 0); // repeat until N becomes 0
    return count; // return the number of digits
}

// second function returns an array of the individual digits of N
int *second(int N) {
    int *arr = new int[first(N)]; // allocate memory for the array
    int i = 0; // variable to keep track of the array index
    while (N != 0) {
        arr[i] = N % 10; // store the last digit of N in the array
        N /= 10; // divide N by 10 to remove the last digit
        i++; // move to the next array index
    }

    return arr; // return the array
}

// third function returns the average of the digits in N
double third(int N) {
    int *arr = second(N); // get the array of digits from second function
    int len = first(N); // get the number of digits from first function
    int sum = 0; // variable to store the sum of digits
    for (int i = 0; i < len; i++) {
        sum += arr[i]; // add the current digit to the sum
    }
    return sum / (double) len; // return the average
}

// fourth function returns the nth root of the product of the digits in N
double fourth(int N) {
    int *arr = second(N); // get the array of digits from second function
    int len = first(N); // get the number of digits from first function
    int product = 1; // variable to store the product of digits
    int i = 0; // variable to keep track of the array index
    do {
        product *= arr[i]; // multiply the current digit to the product
        i++; // move to the next array index
    } while (i < len); // repeat until all digits have been processed
    return pow(product, 1.0 / len); // return the nth root of the product
}

// fifth function returns the factorial of N
int fifth(int N) {
    int product = 1; // variable to store the factorial
    int i = 1; // variable to keep track of the factorial calculation
    do {
        product *= i; // multiply the current number to the factorial
        i++; // move to the next number
    } while (i <= N); // repeat until N has been reached
    return product; // return the factorial
}

int sixth(int N) {
// declare a variable to store the sum of even numbers
    int sum = 0;
// initialize a loop variable
    int i = 1;
// loop through all numbers from 1 to N
    while (i <= N) {
// check if the current number is even
        if (i % 2 == 0) {
// if it is, add it to the sum
            sum += i;
        }
// increment the loop variable
        i++;
    }
// return the sum of even numbers
    return sum;
}

int seventh(int N) {
// declare a variable to store the sum of odd numbers
    int sum = 0;
// loop through all numbers from 1 to N
    for (int i = 1; i <= N; i++) {
// check if the current number is odd
        if (i % 2 != 0) {
// if it is, add it to the sum
            sum += i;
        }
    }
// return the sum of odd numbers
    return sum;
}

int main() {
    int N = 16;

    cout << "first: " << first(N) << endl;
    cout << "second: ";
    int *arr = second(N);
    int len = first(N);
    for (int i = len - 1; i >= 0; i--) {
        cout << arr[i] << " "; // printing the array in reverse order
    }
    cout << endl;
    cout << "third: " << third(N) << endl;
    cout << "fourth: " << fourth(N) << endl;
    cout << "fifth: " << fifth(N) << endl;
    cout << "sixth: " << sixth(N) << endl;
    cout << "seventh: " << seventh(N) << endl;

    return 0;
}