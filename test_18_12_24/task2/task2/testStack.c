#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

bool testCreateStack(int* errorCode) {
    return createStack(errorCode) != NULL;
}

bool testPushAndGetValue(int* errorCode) {
    Stack* stack = createStack(errorCode);
    push(stack, 1, errorCode);
    if (getValue(stack) == 1) {
        deleteStack(stack);
        return true;
    }
    return false;
}

bool testPop(int* errorCode) {
    Stack* stack = createStack(errorCode);
    push(stack, 1, errorCode);
    push(stack, 2, errorCode);
    push(stack, 3, errorCode);
    pop(stack);
    if (getValue(stack) == 2) {
        deleteStack(stack);
        return true;
    }
    return false;
}

bool testIsEmpty(int* errorCode) {
    Stack* stack1 = createStack(errorCode);
    push(stack1, 1, errorCode);
    Stack* stack2 = createStack(errorCode);
    push(stack1, 1, errorCode);
    pop(stack2);
    if (!isEmpty(stack1) && isEmpty(stack2)) {
        deleteStack(stack1);
        deleteStack(stack2);
        return true;
    }
    return false;
}

bool testStack() {
    int errorCode = 0;
    return testCreateStack(&errorCode) && testPushAndGetValue(&errorCode) 
        && testPop(&errorCode) && testIsEmpty(&errorCode) && errorCode == 0;
}