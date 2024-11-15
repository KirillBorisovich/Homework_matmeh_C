#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    
    int index = 0;
    Node* parseTree = splitArithmeticExpression(inputString, &index, &errorCode);
    int result = calculateTheValueOfTheTree(parseTree, &errorCode);
    switch (errorCode) {
    case 0:
        printf("Parse tree: ");
        printTree(parseTree);
        printf("\n");
        printf("The calculated value of the tree expression: %d\n", result);
        return 0;
    case 1:
        printf("Memory allocation error");
        return 1;
    case 2:
        printf("Division by zero is not possible");
        return 2;
    }
}