#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "transformTheFormOfExpression.h"
#include "stack.h"

bool recognizeTheNumber(char element) {
    return element == '0' || element == '1' || element == '2' || element == '3' || element == '4' ||
        element == '5' || element == '6' || element == '7' || element == '8' || element == '9';
}

char meaningTranslated(int number) {
    switch (number) {
    case 0:
        return '+';
    case 1:
        return '-';
    case 2:
        return '*';
    case 3:
        return '/';
    case 4:
        return '(';
    case 5:
        return ')';
    }
}

char* transformTheFormOfExpression(char* string, int* errorCode) {
    Stack* stack = createStack();
    char* resultString = (char*)calloc(strlen(string) + 1, sizeof(char));
    if (resultString == NULL) {
        *errorCode = 1;
        return NULL;
    }
    int numberCounter = 0;
    int operationCounter = 0;
    int index = 0;
    int indexResultString = 0;
    while (string[index] != '\0') {
        while (string[index] == ' ') {
            ++index;
        }
        if (recognizeTheNumber(string[index])) {
            resultString[indexResultString] = string[index];
            indexResultString += 2;
            ++numberCounter;
        } 
        else if (string[index] == '+' || string[index] == '-' || string[index] == '*' ||
            string[index] == '/' || string[index] == '(' || string[index] == ')') {
            switch (string[index]) {
            case '+':
                if (!isEmpty(stack) && getValue(stack) != 4) {
                    resultString[indexResultString] = meaningTranslated(getValue(stack));
                    indexResultString += 2;
                    pop(stack);
                    push(stack, 0);
                }
                else {
                    push(stack, 0);
                }
                break;
            case '-':
                if (!isEmpty(stack) && getValue(stack) != 4) {
                    resultString[indexResultString] = meaningTranslated(getValue(stack));
                    indexResultString += 2;
                    pop(stack);
                    push(stack, 1);
                }
                else {
                    push(stack, 1);
                }
                break;
            case '*':
                push(stack, 2);
                break;
            case '/':
                push(stack, 3);
                break;
            case '(':
                push(stack, 4);
                break;
            case ')':
                while (getValue(stack) != 4) {
                    char operation = meaningTranslated(getValue(stack));
                    if (operation != '(') {
                        resultString[indexResultString] = operation;
                        indexResultString += 2;
                    }
                    pop(stack);
                    if (isEmpty(stack) && operation != '(') {
                        *errorCode = 2;
                        return NULL;
                    }
                }
                pop(stack);
                break;
            default:
                break;
            }
            if (string[index] != '(' && string[index] != ')') {
                ++operationCounter;
            }
        }
        ++index;
    }
    if (operationCounter != numberCounter - 1) {
        *errorCode = 2;
        return NULL;
    }
    while (!isEmpty(stack)) {
        if (getValue(stack) == 4) {
            *errorCode = 2;
            return NULL;
        }
        resultString[indexResultString] = meaningTranslated(getValue(stack));
        pop(stack);
        indexResultString += 2;
    }
    for (int i = 1; i < indexResultString - 2; i += 2) {
        resultString[i] = ' ';
    }
    return resultString;
}