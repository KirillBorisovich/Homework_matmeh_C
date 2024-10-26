#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef struct StackElement {
    int value;
    struct StackElement* next;
} StackElement;

struct Stack {
    StackElement* head;
};

Stack* createStack() {
    return (Stack*)calloc(1, sizeof(Stack));
}

void push(Stack* stack, int value) {
    StackElement* element = (StackElement*)calloc(1, sizeof(StackElement));
    if (element == NULL) {
        return -1;
    }
    element->value = value;
    element->next = stack->head;
    stack->head = element;
}

void pop(Stack* stack) {
    if (stack->head == NULL) {
        return;
    }
    Stack* tmp = stack->head;
    stack->head = stack->head->next;
    free(tmp);
}

void deleteStack(Stack* stack) {
    while (stack->head != NULL) {
        pop(stack);
    }
}

int getValue(Stack* stack) {
    if (stack->head == NULL) {
        return 1;
    }
    return stack->head->value;
}

bool isEmpty(Stack* stack) {
    return !(stack->head = NULL);
}