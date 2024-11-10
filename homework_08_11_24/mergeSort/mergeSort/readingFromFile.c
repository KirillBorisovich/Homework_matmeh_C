#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readingFromFile.h"
#include "list.h"

int readingFromFile(char* filePath, List* list, int* errorCode) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        *errorCode = 2;
        return 0;
    }
    int linesRead = 0;
    while (linesRead < 100) {
        char* buffer = malloc(sizeof(char) * 100);
        if (buffer == NULL) {
            *errorCode = 1;
            return 0;
        }

        if (fgets(buffer, 100, file) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;
            ListElement* element = malloc(sizeof(Position));
            if (element == NULL) {
                printf("Memory allocation failed!\n");
                return 1;
            }
            size_t spaceIndex = strcspn(buffer, " ");
            char* name = (char*)calloc(80, sizeof(char));
            char* phone = (char*)calloc(80, sizeof(char));
            if (name == NULL || phone == NULL) {
                *errorCode = 1;
                return 0;
            }
            for (int i = 0; i < spaceIndex; ++i) {
                name[i] = buffer[i];
            }
            int j = 0;
            for (size_t i = spaceIndex + 1; i < strlen(buffer); ++i) {
                phone[j] = buffer[i];
                ++j;
            }
            add(list, firstElement(list), name, phone, errorCode);
            free(buffer);
        }
        else {
            free(buffer);
            break;
        }
    }
    fclose(file);
    return 0;
}