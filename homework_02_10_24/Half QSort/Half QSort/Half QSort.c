#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void swap(int* left, int* right) {
    if (left != right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
}

void printArray(int array[], int lengh) {
    for (int i = 0; i < lengh; ++i) {
        printf("%d ", array[i]);
    }
}

void fillArray(int array[], int lengh) {
    for (int i = 0; i < lengh; ++i) {
        array[i] = rand();
    }
}
void halfQSort(int array[], int lengh) {
    int supportingElement = array[0], i = 0, j = lengh - 1;
    while (i <= j) {
        while ((array[i] < supportingElement) && (i <= j)) {
            ++i;
        }
        while ((supportingElement <= array[j]) && (i <= j)) {
            --j;
        }
        if (i <= j) {
            swap(&array[i], &array[j]);
            ++i;
            --j;
        }
    }
}
void wrapperHalfQSort() {
    int array[10] = { 0 };
    fillArray(array, 10);
    int supportingElement = array[0];
    halfQSort(array, 10);
    printf("----------\nHalfQSort\n Supporting element: %d\n", supportingElement);
    printArray(array, 10);
    printf("\n----------");
}

bool testHalfQSort() {
    int array[] = { 3, 5, 2, 1, 4 };
    int supportingElement = array[0];
    halfQSort(array, 5);
    return (array[0] < supportingElement) && (array[1] < supportingElement) && (array[2] >= supportingElement)
        && (array[3] >= supportingElement) && (array[4] >= supportingElement);
}

int main(void) {
    if (!testHalfQSort()) {
        printf("Test failed");
        return -1;
    }
    wrapperHalfQSort();
}