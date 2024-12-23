#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "hashTable.h"
#include "testsList.h"
#include "testsHashTable.h"


int main(void) {
    if (!testProgram()) {
        printf("Test failed!\n");
        return 123;
    }

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 3;
    }

    int errorCode = 0;
    char symbol = '\0';
    HashTable* hashTable = createHashTable(&errorCode);
    char* buffer = calloc(50, sizeof(char));
    if (buffer == NULL || hashTable == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }
    int counter = 0;
    while ((symbol = fgetc(file)) != EOF) {
        if (symbol != ' ' && symbol != '\n' && symbol != '.' && symbol != ',') {
            buffer[counter] = symbol;
            ++counter;
        }
        else {
            if (strcmp(buffer, "")) {
                char* textValue = calloc(50, sizeof(char));
                if (textValue == NULL) {
                    printf("Memory allocation error!\n");
                    return 1;
                }
                strcpy_s(textValue, 49, buffer);
                Value value = { textValue, 1 };
                addValueToHashTable(hashTable, value, &errorCode);
                int lenBuffer = strlen(buffer);
                for (int i = 0; i < lenBuffer; ++i) {
                    buffer[i] = '\0';
                }
                counter = 0;
            }
        }
    }
    fclose(file);
    free(buffer);
    printf("Fill factor: %f\n", getFillFactor(hashTable));
    printf("Average list length: %d\n", getAverageListLength(hashTable));
    printf("Maximum list length: %d\n\n", getMaxLenght(hashTable));
    printValuesOfTheEntireHashTable(hashTable);
    deleteHashTable(hashTable);
}