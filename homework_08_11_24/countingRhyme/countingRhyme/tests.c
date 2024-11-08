#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "countingRhyme.h"
#include "testsList.h"

bool testCountingRhyme() {
    bool result = true;
    int errorCode = 0;
    List* list = createList(&errorCode);
    int testValues[] = { 11, 17 };
    int index = 0;
    countingRhyme(list, 20, 3, &errorCode);
    Position position = first(list);
    while (next(position) != first(list)) {
        if (getValue(list, position) != testValues[index]) {
            result = false;
        }
        position = next(position);
        ++index;
    }
    return result;
}

bool testProgram() {
    return testCountingRhyme();
}