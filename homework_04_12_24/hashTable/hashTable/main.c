#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

    char symbol = '\0';
    List** hashTable = calloc(100, sizeof(List*));
    char* buffer = calloc(1024, sizeof(char));
    if (buffer == NULL || hashTable == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }
    int counter = 0;
    while ((symbol = fgetc(file)) != EOF) {
        if (symbol != ' ') {
            buffer[counter] = symbol;
            ++counter;
        }
        else {

        }
    }
}