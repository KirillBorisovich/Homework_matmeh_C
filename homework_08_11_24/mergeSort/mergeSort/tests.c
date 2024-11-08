#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "readingFromFile.h"
#include "mergeSort.h"
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

bool testMergeSorting() {
    bool result = true;
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInTail(list, "name5", "123123", &errorCode);
    addInTail(list, "name1", "1233", &errorCode);
    addInTail(list, "name0", "1231567", &errorCode);
    char* testStringByName[] = { "name0", "name1", "name5" };
    char* testStringByPhone[] = { "123123", "1231567", "1233" };
    List* sortedListByName = mergeSorting(list, true, &errorCode);
    List* sortedListByPhone = mergeSorting(list, false, &errorCode);
    Position positionByName = firstElement(sortedListByName);
    Position positionByPhone = firstElement(sortedListByPhone);
    for (int i = 0; i < getSizeList(list); ++i) {
        char name[80] = { '\0' };
        char phone[80] = { '\0' };
        getValue(sortedListByName, positionByName, name, phone, &errorCode);
        if (strcmp(name, testStringByName[i])) {
            result = false;
        }
        getValue(sortedListByPhone, positionByPhone, name, phone, &errorCode);
        if (strcmp(phone, testStringByPhone[i])) {
            result = false;
        }
        positionByName = next(positionByName);
        positionByPhone = next(positionByPhone);
    }
    deleteList(list);
    deleteList(sortedListByName);
    deleteList(sortedListByPhone);
    return result && errorCode == 0;
}

bool testProgram() {
    return testList() && testReadingFromFile() && testMergeSorting();
}

