#include <stdio.h>
#include <stdbool.h>
#include "list.h"

bool testCreateList() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, 1, &errorCode);
    bool result = list != NULL ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetValue() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, 1, &errorCode);
    bool result = getValue(list, first(list)) == 1 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddInHead() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, 1, &errorCode);
    bool result = getValue(list, first(list)) == 1 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddInTail() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = first(list);
    addInTail(list, 1, &errorCode);
    addInTail(list, 2, &errorCode);
    addInTail(list, 3, &errorCode);
    bool result = getValue(list, first(list)) == 1 ? true : false;
    removeElement(list, position);
    result = getValue(list, first(list)) == 2 ? true : false;
    removeElement(list, position);
    result = getValue(list, first(list)) == 3 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testAdd() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = first(list);
    add(list, position, 1, &errorCode);
    add(list, position, 2, &errorCode);
    bool result = getValue(list, first(list)) == 2 ? true : false;
    removeElement(list, position);
    result = getValue(list, first(list)) == 1 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testRemoveElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = first(list);
    addInHead(list, 3, &errorCode);
    addInHead(list, 2, &errorCode);
    addInHead(list, 1, &errorCode);
    removeElement(list, position);
    bool result = getValue(list, position) == 2 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, 1, &errorCode);
    addInHead(list, 2, &errorCode);
    addInHead(list, 3, &errorCode);
    bool result = getValue(list, getElement(list, 1)) == 2 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testList() {
    return testCreateList() && testGetValue() && testAddInHead() && testAddInTail() &&
        testAdd() && testRemoveElement() && testGetElement();
}




