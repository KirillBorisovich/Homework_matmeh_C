#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "readingFromFile.h"
#include "tests.h"
#include "testsList.h"

bool testReadingFromFile() {
    bool result = true;
    char* referenceNames[] = { "name3", "name2", "name1" };
    char* referencePhones[] = { "12345", "1234", "123" };
    int index = 0;
    int errorCode = 0;
    List* list = createList(&errorCode);
    readingFromFile("testForReadingFromFile.txt", list, &errorCode);
    for (Position i = firstElement(list); !isLast(list, i); i = next(i)) {
        char name[80] = { NULL };
        char phone[20] = { NULL };
        getValue(list, i, name, phone, &errorCode);
        if (strcmp(name, referenceNames[index]) || strcmp(phone, referencePhones[index])) {
            result = false;
        }
        ++index;
    }
    deleteList(list);
    return result && errorCode == 0;
}

bool testProgram() {
    return testList() && testReadingFromFile();
}

