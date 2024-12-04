#include <stdio.h>
#include <stdbool.h>
#include "Queue.h"
#include "test.h"

int main() {
    int errorCode = 0;
    if (!testProgram(&errorCode)) {
        printf("Test failed\n");
        return 123;
    }
    if (errorCode != 0) {
        printf("Memory allocation error\n");
        return 1;
    }
}