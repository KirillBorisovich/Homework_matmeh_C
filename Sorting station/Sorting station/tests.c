#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "transformTheFormOfExpression.h"
#include "testsStack.h"
#include "tests.h"

bool testTransformTheFormOfExpression() {
    int errorCode1 = 0;
    int errorCode2 = 0;
    int errorCode3 = 0;
    int errorCode4 = 0;
    char* testString1 = transformTheFormOfExpression("(1 + 1) * 2", &errorCode1);
    char* testString2 = transformTheFormOfExpression("2 * (1 + 1)", &errorCode2);
    char* testString3 = transformTheFormOfExpression("(1 + 1) * 2)", &errorCode3);
    char* testString4 = transformTheFormOfExpression("(1 + 1) 8 2", &errorCode4);
    if ((!strcmp(testString1, "1 1 + 2 *") && errorCode1 == 0) &&
        (!strcmp(testString2, "2 1 1 + *") && errorCode2 == 0) &&
        (testString3 == NULL && errorCode3 == 2) &&
        (testString4 == NULL && errorCode4 == 2)) {

    }
}

bool testProgram() {
    return testStack() && testTransformTheFormOfExpression;
}



