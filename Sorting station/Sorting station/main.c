#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "transformTheFormOfExpression.h"
#include "tests.h"

int main() {
    if (!testProgram()) {
        printf("Test failed");
        return 123;
    }
    char string[] = "(1 + 1) * 2";
    int errorCode = 0;
    char* resultString = transformTheFormOfExpression(string, &errorCode);
    switch (errorCode) {
    case 1:
        printf("Memory allocation error\n");
        return 1;
        break;
    case 2:
        printf("Invalid expression entry\n");
        return 2;
        break;
    default:
        break;
    }
    printf("%s\n", resultString);
    free(resultString);
}