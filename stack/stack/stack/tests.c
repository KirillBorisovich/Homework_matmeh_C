#include <stdio.h>
#include <stdbool.h>
#include "tests.h"
#include "stack.h"

bool testCreateStack() {
    Stack* stack = createStack();
    if (stack != NULL) {
        free(stack);
        return true;
    }
    return false;
}

bool testPushAndGetValue() {
    Stack* stack = createStack();
    push(stack, 1);
    if (getValue(stack) == 1) {
        deleteStack(stack);
        return true;
    }
    return false;
}

bool testPop() {
    Stack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    pop(stack);
    if (getValue(stack) == 2) {
        deleteStack(stack);
        return true;
    }
    return false;
}

bool testDeleteStack() {
    Stack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    deleteStack(stack);
    return stack == NULL;
}

bool testProgram() {
    return testCreateStack() && testPushAndGetValue() && testPop() && testDeleteStack();
}
