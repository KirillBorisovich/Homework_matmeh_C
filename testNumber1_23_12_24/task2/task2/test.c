#include <stdio.h>
#include <stdbool.h>
#include "sorting.h"

bool arrayComparison(int* array1, int* array2, int length, int* errorCode) {
    if (array1 == NULL || array2 == NULL) {
        *errorCode = 1;
        return false;
    }
    for (int i = 0; i < length; ++i) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}

bool testProgram() {
    int errorCode = 0;
    int array[] = { 10, 7, 6, 8, 2, 4, 6, 4, 8, 1 };
    int sortedArray[] = { 1, 2, 4, 4, 6, 6, 7, 8, 8, 10 };
    int arrayOfOneElement[] = { 1 };
    int length = 10;
    selectionSort(array, length, &errorCode);
    selectionSort(arrayOfOneElement, 1, &errorCode);
    selectionSort(NULL, 1, &errorCode);
    return arrayComparison(array, sortedArray, length, &errorCode) && errorCode == 1;
}