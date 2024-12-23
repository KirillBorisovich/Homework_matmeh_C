#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** readingFromFile(FILE* file, int* numberOfVertices, int* errorCode) {
    if (file == NULL) {
        *errorCode = 2;
        return NULL;
    }
    fscanf(file, "%d", numberOfVertices);
    int** array = calloc(*numberOfVertices, sizeof(int*));
    for (int i = 0; i < *numberOfVertices; ++i) {
        array[i] = calloc(*numberOfVertices, sizeof(int));
        if (array[i] == NULL) {
            for (int j = 0; array[j] != NULL; ++j) {
                free(array[j]);
            }
            free(array);
            *errorCode = 1;
            return NULL;
        }
        for (int k = 0; k < *numberOfVertices; ++k) {
            fscanf(file, "%d", &array[i][k]);
        }
    }
    return array;
}

void floydAlgorithm(int** array, int numberOfVertices) {
    for (int k = 0; k < numberOfVertices; ++k) {
        for (int i = 0; i < numberOfVertices; ++i) {
            for (int j = 0; j < numberOfVertices; ++j) {
                if (array[i][j] > array[i][k] + array[k][j]) {
                    array[i][j] = array[i][k] + array[k][j];
                }
            }
        }
    }
}

void getAccessVertices(int** array, int numberOfVertices, int* resultArray,
    int* numberOfAnswers, int* errorCode) {
    if (array == NULL || resultArray == NULL) {
        *errorCode = 2;
        return;
    }
    size_t indexResultArray = 0;
    for (int i = 0; i < numberOfVertices; ++i) {
        int counter = 0;
        for (int j = 0; j < numberOfVertices; ++j) {
            if (array[i][j] == 0) {
                ++counter;
            }
        }
        if (counter == 1) {
            resultArray[indexResultArray] = i;
            ++(*numberOfAnswers);
            ++indexResultArray;
        }
    }
}

void deleteArray(int** array, int numberOfVertices) {
    for (int i = 0; i < numberOfVertices; ++i) {
        free(array[i]);
    }
    free(array);
}

bool testProgram() {
    bool result = true;
    int referenceArray[] = { 0, 3 };
    int errorCode = 0;
    int numberOfVertices = 0;
    FILE* file = fopen("testInput.txt", "r");
    int** testArray = readingFromFile(file, &numberOfVertices, &errorCode);
    fclose(file);
    int numberOfAnswers = 0;
    int* resultArray = calloc(numberOfVertices, sizeof(int));
    if (resultArray == NULL) {
        errorCode = 1;
        deleteArray(testArray, numberOfVertices);
        return false;
    }
    floydAlgorithm(testArray, numberOfVertices);
    getAccessVertices(testArray, numberOfVertices, resultArray, &numberOfAnswers, &errorCode);
    for (int i = 0; i < numberOfAnswers; ++i) {
        if (referenceArray[i] != resultArray[i]) {
            result = false;
        }
    }
    deleteArray(testArray, numberOfVertices);
    free(resultArray);
    return result && errorCode == 0;
}

int main() {
    if (!testProgram()) {
        printf("Test failed!\n");
        return 123;
    }
    int errorCode = 0;
    int numberOfVertices = 0;
    FILE* file = fopen("input.txt", "r");
    int** array = readingFromFile(file, &numberOfVertices, &errorCode);
    fclose(file);
    int numberOfAnswers = 0;
    int* resultArray = calloc(numberOfVertices, sizeof(int));
    if (resultArray == NULL) {
        deleteArray(array, numberOfVertices);
        return 1;
    }
    floydAlgorithm(array, numberOfVertices);
    getAccessVertices(array, numberOfVertices, resultArray, &numberOfAnswers, &errorCode);
    if (errorCode != 0) {
        deleteArray(array, numberOfVertices);
        free(resultArray);
        return errorCode;
    }
    for (int i = 0; i < numberOfAnswers; ++i) {
        printf("%d\n", resultArray[i]);
    }
    deleteArray(array, numberOfVertices);
    free(resultArray);
}