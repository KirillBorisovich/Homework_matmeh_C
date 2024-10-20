#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

void printArray(int array[], int lengh) {
    for (int i = 0; i < lengh; ++i) {
        printf("%d ", array[i]);
    }
}
bool arrayComparison(int array1[], int array2[], int lenghs) {
    for (int i = 0; i < lenghs; ++i) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}

void shellSorting(int array[], int lengh) {
    
}


bool testShellSorting() {
    int array[] = { 1, 3, 5, 8, 6, -2 };
    int sortedArray[] = { -2, 1, 3, 5, 6, 8 };
    shellSorting(array, 6);
    return arrayComparison(array, sortedArray, 6);
}

int main(void) {
    setlocale(LC_ALL, "Rus");
    if (!testShellSorting()) {
        printf("Test failed");
        return 1;
    }
    int array[] = { 5, 2, 3, 1, 4 };
    printf("Не отсортированный массив: ");
    printArray(array, 5);
    shellSorting(array, 5);
    printf("\nОтсортированный массив: ");
    printArray(array, 5);



}