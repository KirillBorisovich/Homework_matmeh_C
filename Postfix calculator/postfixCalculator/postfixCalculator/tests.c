#include <stdio.h>
#include <stdbool.h>
#include "tests.h"
#include "stack.h"
#include "postfixCalculator.h"

bool testPostfixCalculator() {
    int errorCode = 0;
    return postfixCalculator("1 2 +", &errorCode) == 3 &&
        postfixCalculator("1   25 + +", &errorCode) == 8 &&
        postfixCalculator("96 -12+*", &errorCode) == 9 &&
        postfixCalculator("8 2 /", &errorCode) == 4 && errorCode == 0 &&
        postfixCalculator("8 2 + +", &errorCode) == 0 && errorCode == 1 &&
        postfixCalculator("8 0 /", &errorCode) == 0 && errorCode == 2;
}

bool testProgram() {
    return testPostfixCalculator() && createStack();
}