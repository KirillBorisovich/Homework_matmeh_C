#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "advancedBracketBalance.h"
#include "tests.h"

int main() {
    if (!testProgram()) {
        printf("Test failed");
        return -1;
    }
    char* string = "((()))";
}