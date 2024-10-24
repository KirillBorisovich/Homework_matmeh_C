#pragma once

// Structure for head
typedef struct Stack Stack;

// Add a new element to the stack
void push(Stack* stack, int value);

// Remove top element from stack
void pop(Stack* stack);

// Ñreate a first element in the stack
Stack* createStack();

// Get the value of a stack element
int getValue(Stack* stack);

// Delete the entire stack
void deleteStack(Stack* stack);