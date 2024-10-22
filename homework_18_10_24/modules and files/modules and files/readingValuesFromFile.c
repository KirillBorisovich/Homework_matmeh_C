#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readingValuesFromFile.h"

int readFromFile(char *filePath, int *array, int lengh) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    int linesRead = 0;
    while (linesRead < lengh) {
        char buffer[100];
        if (buffer == NULL) {
            printf("Memory allocation failed!\n");
            return 2;
        }

        if (fgets(buffer, 100, file) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;
            array[linesRead] = atoi(buffer);
            ++linesRead;
        }
        else {
            break;
        }
    }
    fclose(file);
    return 0;
}