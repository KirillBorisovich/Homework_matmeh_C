#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "tests.h"

int main() {
    if (!testStack()) {
        printf("Test failed\n");
        return 123;
    }
    Stack* stack = createStack();
    push(stack, 1);
}