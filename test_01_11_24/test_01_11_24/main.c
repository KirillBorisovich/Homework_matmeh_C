#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int readFromFile(char* filePath, char** data, int* numberOfLines) {
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
            data[linesRead] = buffer;
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

int removeDuplicateCharacters(char* string) {
    char arrayForUniqueElements[100];
    int index = 0;
    int stringLen = strlen(string);
    for (int i = 0; i < stringLen; ++i) {
        if (string[i] != string[i + 1]) {
            arrayForUniqueElements[index] = string[i];
            ++index;
        }
        string[i] = '\0';
    }
    for (int i = 0; i < index; ++i) {
        string[i] = arrayForUniqueElements[i];
    }
}

void printDatabase(char** data, int numberOfLines) {
    for (int i = 0; i < numberOfLines; i++) {
        removeDuplicateCharacters(data[i]);
        printf("%s\n", data[i]);
        free(data[i]);
    }
}

bool testReadFromFile() {
    char testString[] = "qweqwe";
    char* data[1];
    int numberOfRecordsInTheDatabase = 0;
    readFromFile("referenceFileForReading.txt", data, &numberOfRecordsInTheDatabase);
    if (!strcmp(data[0], testString)) {
        free(data[0]);
        return true;
    }
    return false;
}

bool testRemoveDuplicateCharacters() {
    char testString[] = "qqwweeqqwwee";
    char correctString[] = "qweqwe";
    removeDuplicateCharacters(testString);
    return !strcmp(testString, correctString);
}

bool testProgram() {
    return testRemoveDuplicateCharacters() && testReadFromFile();
}

int main() {
    if (!testProgram()) {
        printf("Test failed");
        return -123;
    }
    char *array[100];
    int numbersOfLines = 0;
    readFromFile("input.txt", array, &numbersOfLines);
    printDatabase(array, numbersOfLines);
}