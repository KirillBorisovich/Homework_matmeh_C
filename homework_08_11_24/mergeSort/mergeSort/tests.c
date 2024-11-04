#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "readingFromFile.h"
#include "tests.h"
#include "testsList.h"

bool testReadingFromFile() {
    bool result = true;
    char* referenceValues[] = { "name3 12345", "name2 1234", "name1 123" };
    int index = 0;
    int errorCode = 0;
    List* list = createList(&errorCode);
    readingFromFile("testForReadingFromFile.txt", list, &errorCode);
    for (Position i = first(list); !isLast(list, i); i = next(i)) {
        char* string = getValue(list, i, &errorCode);
        if (strcmp(string, referenceValues[index])) {
            result = false;
        }
        free(string);
        ++index;
    }
    deleteList(list);
    return result && errorCode == 0;
}

bool testProgram() {
    return testList() && testReadingFromFile();
}

