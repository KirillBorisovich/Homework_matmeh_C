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

float bubbleSort(int array[], int lengh) {
    clock_t timeCounter = clock();
    for (int i = 0; i + 1 < lengh; ++i) {
        for (int j = 0; j + 1 < lengh; ++j) {
            if (array[j + 1] < array[j]) {
                swap(&array[j + 1], &array[j]);
            }
        }
    }
    timeCounter = clock() - timeCounter;
    return (float)timeCounter / CLOCKS_PER_SEC;
}
float countingSort(int array[], int lengh) {
    clock_t timeCounter = clock();
    int min = array[0], max = array[0], j = 0;
    for (int i = 0; i < lengh; ++i) {
        if (min > array[i]) {
            min = array[i];
        }
        if (max < array[i]) {
            max = array[i];
        }
    }
    int* auxiliaryArray = (int*)calloc(max - min + 1, sizeof(int));
    if (auxiliaryArray == NULL) {
        return -1;
    }
    for (int i = 0; i < lengh; ++i) {
        ++auxiliaryArray[array[i] - min];
    }
    for (int i = 0; i < max - min + 1; ++i) {
        while (auxiliaryArray[i] > 0) {
            array[j] = i + min;
            ++j;
            --auxiliaryArray[i];
        }
    }
    timeCounter = clock() - timeCounter;
    free(auxiliaryArray);
    return (float)timeCounter / CLOCKS_PER_SEC;
}
void bubbleAndCouting() {
    int lengh = 100000;
    int array[100000] = { 0 };
    fillArray(array, lengh);
    printf("\nBubble And Couting\n Bubble sort time: %fsec.\n Counting sort time: %fsec.\n----------",
        bubbleSort(array, lengh), countingSort(array, lengh));
}

// Tests
bool arrayComparison(int array1[], int array2[], int lenghs) {
    for (int i = 0; i < lenghs; ++i) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}
bool testBubbleSort() {
    int array[] = { -1, 4, 5, -3, 2 }, sortedArray[] = { -3, -1, 2, 4, 5 };
    bubbleSort(array, 5);
    return arrayComparison(array, sortedArray, 5);
}
bool testCoutingSort() {
    int array[] = { -1, 4, 5, -3, 2 }, sortedArray[] = { -3, -1, 2, 4, 5 };
    countingSort(array, 5);
    return arrayComparison(array, sortedArray, 5);
}


int main(void) {
    if (!testBubbleSort() && !testCoutingSort()) {
        printf("\nTest failed");
        return -1;
    }
    printf("\nPlease wait\n");
    bubbleAndCouting();
}