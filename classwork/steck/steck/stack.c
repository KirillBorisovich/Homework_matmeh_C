#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct StackElement {
    int value;
    struct Element* next;
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
    Stack* tmp = stack->head;
    stack->head = stack->head->next;
    free(tmp);
}