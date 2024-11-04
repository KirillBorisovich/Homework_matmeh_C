#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "testsList.h"
#include "list.h"

bool testCreateList() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, "kirill", "12341234", &errorCode);
    bool result = list != NULL ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetValueAndAddInHead() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, "kirill", "123", & errorCode);
    char* testString = getValue(list, first(list), &errorCode);
    bool result = !strcmp(testString, "kirill 123") ? true : false;
    free(testString);
    deleteList(list);
    return result && errorCode == 0;
}

bool testAdd() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = first(list);
    add(list, position, "kirill", "123", & errorCode);
    add(list, position, "name", "1234", &errorCode);
    char* testString1 = getValue(list, first(list), &errorCode);
    bool result = !strcmp(testString1, "name 1234") ? true : false;
    removeElement(list, position);
    char* testString2 = getValue(list, first(list), &errorCode);
    result = !strcmp(testString2, "kirill 123") ? true : false;
    free(testString1);
    free(testString2);
    deleteList(list);
    return result && errorCode == 0;
}

bool testRemoveElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = first(list);
    addInHead(list, "name1", "1234", & errorCode);
    addInHead(list, "name2", "12345", &errorCode);
    addInHead(list, "name3", "123456", &errorCode);
    removeElement(list, position);
    char* testString = getValue(list, position, &errorCode);
    bool result = !strcmp(testString, "name2 12345") ? true : false;
    free(testString);
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, "name1", "1234", &errorCode);
    addInHead(list, "name2", "12345", &errorCode);
    addInHead(list, "name3", "123456", &errorCode);
    char* testString = getValue(list, getElement(list, 1), &errorCode);
    bool result = !strcmp(testString, "name2 12345") ? true : false;
    free(testString);
    deleteList(list);
    return result && errorCode == 0;
}

bool testList() {
    return testCreateList() && testGetValueAndAddInHead() &&
        testAdd() && testRemoveElement() && testGetElement();
}




