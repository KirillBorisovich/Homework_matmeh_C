#include <stdio.h>

void swap(int* left, int* right) {
    if (left != right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
}

void changingArraySegments(int array[], int firstIndex, int secondIndex) {
    while (firstIndex <= secondIndex) {
        swap(&array[firstIndex], &array[secondIndex]);
        ++firstIndex;
        --secondIndex;
    }
}

int main(void) {
    int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int m = 6;
    int n = 7;
    printf("\Array:\n Output: ");
    changingArraySegments(array, 0, m - 1);
    changingArraySegments(array, m, m + n - 1);
    changingArraySegments(array, 0, m + n - 1);
    for (int i = 0; i < 13; ++i) {
        printf("%d ", array[i]);
    }
}