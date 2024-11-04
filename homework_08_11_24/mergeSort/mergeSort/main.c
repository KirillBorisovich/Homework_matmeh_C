#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "readingFromFile.h"
#include "tests.h"

int main() {
    if (!testProgram()) {
        printf("Test failed");
        return 123;
    }

    int errorCode = 0;
    List* list = createList(&errorCode);
    readingFromFile("phoneBook.txt", list, &errorCode);
    for (Position i = first(list); !isLast(list, i); i = next(i)) {
        char* string = getValue(list, i, &errorCode);
        printf("%s\n", string);
        free(string);
    }
    deleteList(list);
}