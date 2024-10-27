#include <stdio.h>
#include <stdbool.h>
#include "advancedBracketBalance.h"
#include "testStack.h"
#include "tests.h"

bool testAdvancedBracketBalance() {
    return advancedBracketBalance("({[]})") && advancedBracketBalance("(){}[]")
        && !advancedBracketBalance("({)}") && !advancedBracketBalance("([]");
}

bool testProgram() {
    return testAdvancedBracketBalance() && testStack();
}

