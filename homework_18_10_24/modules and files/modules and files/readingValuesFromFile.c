#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readingValuesFromFile.h"
#include "functionsFromPreviousTasks.h"

int readFromFile(FILE *file, int **array, size_t *length, int *errorCode) {
    int numberOfNumbers = 0;
    int counter = 0;
    char symbol = '\0';
    char buffer[50] = { '\0' };
    while ((symbol = fgetc(file)) != EOF) {
        if (symbol != ' ' && symbol != '\n') {
            buffer[counter] = symbol;
            ++counter;
        }
        else {
            if (strcmp(buffer, "")) {
                printf("%d", *array[numberOfNumbers]);
                *array[numberOfNumbers] = strtol(buffer, NULL, 10);
                ++numberOfNumbers;
                if (numberOfNumbers == *length - 1) {
                    int* tmp = realloc(*array, *length * 2 * sizeof(int));
                    if (*array == NULL) {
                        *errorCode = 1;
                        free(*array);
                        return;
                    }
                    *array = tmp;
                    *length *= 2;
                    printArray(array, numberOfNumbers);
                    printf("\n");
                }
                int lenBuffer = strlen(buffer);
                for (int i = 0; i < lenBuffer; ++i) {
                    buffer[i] = '\0';
                }
                counter = 0;
            }
        }
    }
    return numberOfNumbers;
}