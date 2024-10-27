#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "postfixCalculator.h"
#include "tests.h"

int main() {
    if (!testProgram()) {
        printf("Test failed");
        return -123;
    }
    char string[100];
    printf("Enter expression:\n");
    fgets(string, 100, stdin);
    string[strcspn(string, "\n")] = 0;
    int errorCode = 0;
    int result = postfixCalculator(string, &errorCode);
    switch (errorCode) {
    case 0:
        printf("Answer: %d\n", result);
        break;
    case 1:
        printf("Incorrect input\n");
        break;
    case 2:
        printf("It is impossible to divide by zero\n");
        break;
    default:
        break;
    }
}