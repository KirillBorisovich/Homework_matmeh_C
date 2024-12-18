#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "testStack.h"
#include "queue.h"
#include "testQueue.h"

int main(void) {
    if (!testQueue() || !testStack()) {
        printf("Test failed!");
        return 123;
    }
}