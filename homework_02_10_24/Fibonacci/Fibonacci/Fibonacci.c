#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int recursivelyFibonacci(int number) {
    if (number == 0) {
        return 0;
    }
    else if (number <= 2) {
        return 1;
    }
    return (recursivelyFibonacci(number - 1) + recursivelyFibonacci(number - 2));
}
int iterativelyFibonacci(int number) {
    if (number == 0) {
        return 0;
    }
    else if (number <= 2) {
        return 1;
    }
    int fib1 = 1, fib2 = 1, c = 0;
    for (int i = 3; i <= number; ++i) {
        c = fib1 + fib2;
        fib1 = fib2;
        fib2 = c;
    }
    return fib2;
}
void fibonacci() {
    int number = 45;
    clock_t timeCounter1 = clock();
    recursivelyFibonacci(number);
    timeCounter1 = clock() - timeCounter1;
    clock_t timeCounter2 = clock();
    iterativelyFibonacci(number);
    timeCounter2 = clock() - timeCounter2;
    printf("\nFibonacci\n Recursively, number 45: %fsec.\n Iteratively, number 45: %fsec.\n----------",
        (float)timeCounter1 / CLOCKS_PER_SEC,
        (float)timeCounter2 / CLOCKS_PER_SEC);
}

bool arrayComparison(int array1[], int array2[], int lenghs) {
    for (int i = 0; i < lenghs; ++i) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}
bool testRecursivelyFibonacci() {
    int array[10] = { 0 }, arrayFibonacciNumbers[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
    for (int i = 0; i < 10; ++i) {
        array[i] = recursivelyFibonacci(i);
    }
    return arrayComparison(array, arrayFibonacciNumbers, 10);
}
bool testIterativelyFibonacci() {
    int array[10] = { 0 }, arrayFibonacciNumbers[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
    for (int i = 0; i < 10; ++i) {
        array[i] = iterativelyFibonacci(i);
    }
    return arrayComparison(array, arrayFibonacciNumbers, 10);
}

int main(void) {
    if (!testRecursivelyFibonacci() && !testIterativelyFibonacci()) {
        printf("Tesr failed");
        return -1;
    }
    printf("\nPlease wait");
    fibonacci();
}