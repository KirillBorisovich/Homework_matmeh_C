#include <stdio.h>
#include <stdbool.h>
#include "advancedBracketBalance.h"
#include "stack.h"

bool advancedBracketBalance(char* string) {
    Stack* stack = createStack();
    int indexCounter = 0;
    while (string[indexCounter] != '\0') {
        switch (string[indexCounter]) {
        case '(':
            push(stack, 1);
            break;
        case '{':
            push(stack, 2);
            break;
        case '[':
            push(stack, 3);
            break;
        default:
            break;
        }
        if ((string[indexCounter] == ')' || string[indexCounter] == '}' || string[indexCounter] == ']')
            && isEmpty(stack)) {
            return false;
        }
        else if (string[indexCounter] == ')' && getValue(stack) == 1 && !isEmpty(stack)) {
            pop(stack);
        }
        else if (string[indexCounter] == '}' && getValue(stack) == 2 && !isEmpty(stack)) {
            pop(stack);
        }
        else if (string[indexCounter] == ']' && getValue(stack) == 3 && !isEmpty(stack)) {
            pop(stack);
        }
        ++indexCounter;
    }
    return isEmpty(stack);
}