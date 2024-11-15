#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "countingRhyme.h"
#include "testsList.h"

bool testCountingRhyme() {
    bool result = false;
    int errorCode = 0;
    List* list = createList(&errorCode);
    int testValues = 3;
    countingRhyme(list, 20, 7, &errorCode);
    Position position = first(list);
    if (getValue(list, first(list)) == 3) {
        result = true;
    }
    deleteList(list);
    return result;
}

bool testProgram() {
    return testList() && testCountingRhyme();
}