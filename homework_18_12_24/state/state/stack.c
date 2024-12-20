#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "stack.h"

typedef struct Node {
    int name;
    int stateNumber;
    List* matchList;
} Node;

typedef struct StackElement {
    Value value;
    struct StackElement* next;
} StackElement;

struct Stack {
    StackElement* head;
};

Stack* createStack(int* errorCode) {
    Stack* stack = calloc(1, sizeof(Stack));
    if (stack == NULL) {
        *errorCode = 1;
        return NULL;
    }
    return stack;
}

void push(Stack* stack, Value value, int* errorCode) {
    StackElement* element = (StackElement*)calloc(1, sizeof(StackElement));
    if (element == NULL) {
        *errorCode = 1;
        return;
    }
    element->value = value;
    element->next = stack->head;
    stack->head = element;
}

void pop(Stack* stack) {
    if (stack->head == NULL) {
        return;
    }
    StackElement* tmp = stack->head;
    stack->head = stack->head->next;
    free(tmp);
}

void deleteStack(Stack* stack) {
    while (stack->head != NULL) {
        pop(stack);
    }
    free(stack);
}

Value getValueFromStack(Stack* stack) {
    return stack->head->value;
}

bool isEmptyStack(Stack* stack) {
    return stack->head == NULL;
}