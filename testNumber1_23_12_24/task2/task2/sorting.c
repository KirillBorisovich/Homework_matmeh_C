#include <stdio.h>

void swap(int* left, int* right) {
    if (left != right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
}

void selectionSort(int* array, int length, int* errorCode) {
    if (array == NULL) {
        *errorCode = 1;
        return;
    }
    for (int i = 0; i < length - 1; ++i) {
        int minElement = 999999999;
        int minElementIndex = 0;
        for (int j = i + 1; j < length; ++j) {
            if (array[j] < minElement) {
                minElement = array[j];
                minElementIndex = j;
            }
        }
        if (array[i] > array[minElementIndex]) {
            swap(&array[i], &array[minElementIndex]);
        }
    }
}