#include <stdio.h>
#include "stdbool.h"
#include "transformTheFormOfExpression.h"
#include "stack.h"

bool recognizeTheNumber(char element) {
    return element == '0' || element == '1' || element == '2' || element == '3' || element == '4' ||
        element == '5' || element == '6' || element == '7' || element == '8' || element == '9';
}

void transformTheFormOfExpression(char* string) {
    Stack* stack = createStack();
    int index = 0;
    while (string[index] != '\0') {
        while (string[index] != ' ') {
            ++index;
        }
        if (recognizeTheNumber(string[index])) {
            ++index;
        }
    }
}