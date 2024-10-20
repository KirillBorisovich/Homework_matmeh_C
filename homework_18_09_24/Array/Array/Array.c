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

int lenghArray(int array[]) {
    int counter = 0;
    while (array[counter] != '\0') {
        ++counter;
    }
    return counter;
}

void flippingAnArray(int array[], int arrayLen) {
    for (int i = 0; i < arrayLen / 2; ++i) {
        swap(&array[i], &array[arrayLen - 1 - i]);
    }
}

void changingArraySegments(int array[], int lengh, int m) {
    for (int i = 0; i < m / 2; ++i) {
        swap(&array[i], &array[m - 1 - i]);
    }
    for (int i = 0; i < (lengh - m) / 2; ++i) {
        swap(&array[m + i], &array[lengh - 1 - i]);
    }
    flippingAnArray(array, lengh);
    for (int i = 0; i < lengh; ++i) {
        printf("%d ", array[i]);
    }
}

int main(void) {
    setlocale(LC_ALL, "Rus");
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int arrayLen = lenghArray(array);
    printf("\Array:\n Output: ");
    changingArraySegments(array, 12, 5);
    printf("\n----------\n");
}