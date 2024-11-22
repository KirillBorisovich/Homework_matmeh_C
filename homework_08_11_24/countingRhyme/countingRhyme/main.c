#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "countingRhyme.h"
#include "tests.h"

int main() {
    if (!testProgram()) {
        printf("Test failed");
        return 123;
    }
    int n = 41;
    int m = 3;
    int errorCode = 0;
    List* list = createList(&errorCode);
    countingRhyme(list, n, m, &errorCode);
    if (errorCode == 0) {
        printf("The number will survive: %d\n", getValue(list, first(list)));
    }
    else if (errorCode == 1) {
        printf("Memory allocation error");
        deleteList(list);
        return 1;
    }
    deleteList(list);
}