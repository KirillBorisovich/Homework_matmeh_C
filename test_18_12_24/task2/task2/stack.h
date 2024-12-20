#pragma once

// Structure for head
typedef struct Stack Stack;

// Add a new element to the stack
void push(Stack* stack, int value, int* errorCode);

// Remove top element from stack
void pop(Stack* stack);

// Create a first element in the stack
Stack* createStack(int* errorCode);

// Get the value of a stack element
int getValue(Stack* stack);

// Delete the entire stack
void deleteStack(Stack* stack);

// Check for value presence
bool isEmpty(Stack* stack);