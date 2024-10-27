#include <stdio.h>
#include <stdbool.h>
#include "advancedBracketBalance.h"
#include "C:\Users\Kiril\OneDrive\Рабочий стол\Homework_matmeh_C\stack\stack\stack\stack.h"



bool advancedBracketBalance(char* string) {
    Stack* stack = createStack();
    int indexCounter = 0;
    while (string[indexCounter] != '\0') {
        if (string[indexCounter] == '(') {
            push(stack, 1);
        }
        else if (string[indexCounter] == '{') {
            push(stack, 2);
        }
        else if (string[indexCounter] == '[') {
            push(stack, 3);
        }
    }
}