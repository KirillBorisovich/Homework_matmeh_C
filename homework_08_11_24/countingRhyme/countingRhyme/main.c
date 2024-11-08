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
    int n = 20;
    int m = 3;
    int errorCode = 0;
    List* list = createList(&errorCode);
    countingRhyme(list, n, m, &errorCode);
    Position position = first(list);
    while (next(position) != first(list)) {
        printf("%d ", getValue(list, position));
        position = next(position);
    }
}