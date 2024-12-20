#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

bool testStack() {
    bool result = false;
    int errorCode = 0;
    Stack* stack = createStack(&errorCode);
    Node* node = NULL;
    Value value1 = { node, 1 };
    Value value2= { node, 2 };
    Value value3 = { node, 3 };
    push(stack, value1, &errorCode);
    push(stack, value2, &errorCode);
    push(stack, value3, &errorCode);
    int getValue1 = getValueFromStack(stack).length;
    pop(stack);
    int getValue2 = getValueFromStack(stack).length;
    pop(stack);
    int getValue3 = getValueFromStack(stack).length;
    pop(stack);
    if (isEmptyStack(stack) && getValue1 == 3 &&
        getValue2 == 2 && getValue3 == 1) {
        result = true;
    }
    deleteStack(stack);
    return result && errorCode == 0;
}