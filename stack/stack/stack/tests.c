#include <stdio.h>
#include <stdbool.h>
#include "tests.h"
#include "stack.h"

bool testCreateStack() {
    return createStack() != NULL;
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

bool testIsEmpty() {
    Stack* stack1 = createStack();
    push(stack1, 1);
    Stack* stack2 = createStack();
    push(stack1, 1);
    pop(stack2);
    if (!isEmpty(stack1) && isEmpty(stack2)) {
        deleteStack(stack1);
        deleteStack(stack2);
        return true;
    }
    return false;
}

bool testStack() {
    return testCreateStack() && testPushAndGetValue() && testPop() && testIsEmpty();
}
