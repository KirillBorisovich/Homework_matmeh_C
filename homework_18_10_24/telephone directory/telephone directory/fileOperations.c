#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fileOperations.h"
#include "structure.h"

int readFromFile(char* filePath, NameAndPhoneNumber** data, int* numberOfLines) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    int linesRead = 0;
    while (linesRead < 100) {
        char* buffer = malloc(sizeof(char) * 100);
        if (buffer == NULL) {
            printf("Memory allocation failed!\n");
            return 2;
        }

        if (fgets(buffer, 100, file) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;
            NameAndPhoneNumber* temporaryVariable = malloc(sizeof(NameAndPhoneNumber));
            if (temporaryVariable == NULL) {
                printf("Memory allocation failed!\n");
                return 2;
            }
            size_t spaceIndex = strcspn(buffer, " ");
            for (int i = 0; i < spaceIndex; ++i) {
                temporaryVariable->name[i] = buffer[i];
            }
            int j = 0;
            for (int i = spaceIndex + 1; i < strlen(buffer); ++i) {
                temporaryVariable->phone[j] = buffer[i];
                ++j;
            }
            temporaryVariable->name[spaceIndex] = '\0';
            temporaryVariable->phone[j] = '\0';
            data[linesRead] = temporaryVariable;
            ++linesRead;
        }
        else {
            free(buffer);
            break;
        }
    }
    fclose(file);
    *numberOfLines = linesRead;
    return 0;
}
int writeToFile(char* filePath, NameAndPhoneNumber** data, int numberOfLines, bool* changeData) {
    if (!*changeData) {
        return 4;
    }
    FILE* file = fopen(filePath, "w");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    for (int i = 0; i < numberOfLines; ++i) {
        fprintf(file, "%s %s\n", data[i]->name, data[i]->phone);
    }
    fclose(file);
    *changeData = false;
    return 0;
}