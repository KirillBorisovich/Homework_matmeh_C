#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void swap(int* left, int* right) {
    if (left != right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
}

void twoVariables() {
    int a = 1, b = 3;
    swap(&a, &b);
    printf("\nTwo variables:\n Input data: a = 1, b = 3\n Outpu data: a = %d, b = %d\n----------", a, b);
}

int main(void) {
    twoVariables();
}