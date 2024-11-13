#include <stdio.h>
#include <stdlib.h>
#include "parseTree.h"
#include "testsParseTree.h"

int main() {
    if (!testTree()) {
        printf("Test failed");
        return 123;
    }
    int errorCode = 0;
    char* inputString = calloc(100, sizeof(char));
    if (inputString == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }
    FILE* file = fopen("input.txt", "r");
    if (fgets(inputString, 100, file) == NULL) {
        free(inputString);
        printf("The file is empty");
        return 0;
    }
    
}