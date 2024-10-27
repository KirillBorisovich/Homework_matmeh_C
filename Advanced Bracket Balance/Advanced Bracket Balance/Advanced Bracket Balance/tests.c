#include <stdio.h>
#include <stdbool.h>
#include "C:\Users\Kiril\OneDrive\Рабочий стол\Homework_matmeh_C\stack\stack\stack\tests.h"
#include "advancedBracketBalance.h"
#include "tests.h"

bool testAdvancedBracketBalance() {
    return advancedBracketBalance("({[]})") && advancedBracketBalance("(){}[]")
        && !advancedBracketBalance("({)}") && !advancedBracketBalance("([]");
}

bool testProgram() {
    return testAdvancedBracketBalance() && testStack();
}

