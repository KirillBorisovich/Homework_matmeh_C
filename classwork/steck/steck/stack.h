#pragma once

// Structure for head
typedef struct Stack Stack;

// Add a new element to the stack
void push(Stack* stack, int value);

// Remove top element from stack
void pop(Stack* head2);

// Ñreate a first element in the stack
Stack* createStack();