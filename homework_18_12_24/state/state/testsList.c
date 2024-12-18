#include <stdio.h>
#include <stdbool.h>
#include "testsList.h"
#include "list.h"

bool testCreateList() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Value value = { NULL, 1 };
    addInHead(list, value, &errorCode);
    bool result = list != NULL ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetValue() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Value value = { NULL, 1 };
    addInHead(list, value, &errorCode);
    bool result = getValue(list, first(list)).length == 1 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddInHead() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Value value = { NULL, 1 };
    addInHead(list, value, &errorCode);
    bool result = getValue(list, first(list)).length == 1 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddInTail() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Value value1 = { NULL, 1 };
    Value value2 = { NULL, 2 };
    Value value3 = { NULL, 3 };
    addInTail(list, value1, &errorCode);
    addInTail(list, value2, &errorCode);
    addInTail(list, value3, &errorCode);
    bool result = getValue(list, first(list)).length == 1 ? true : false;
    removeElement(list, first(list));
    result = getValue(list, first(list)).length == 2 ? true : false;
    removeElement(list, first(list));
    result = getValue(list, first(list)).length == 3 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testAdd() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = first(list);
    Value value1 = { NULL, 1 };
    Value value2 = { NULL, 2 };
    add(list, position, value1, &errorCode);
    add(list, position, value2, &errorCode);
    bool result = getValue(list, first(list)).length == 2 ? true : false;
    removeElement(list, position);
    result = getValue(list, first(list)).length == 1 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testRemoveElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = first(list);
    Value value1 = { NULL, 1 };
    Value value2 = { NULL, 2 };
    Value value3 = { NULL, 3 };
    addInHead(list, value3, &errorCode);
    addInHead(list, value2, &errorCode);
    addInHead(list, value1, &errorCode);
    removeElement(list, position);
    bool result = getValue(list, position).length == 2 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Value value1 = { NULL, 1 };
    Value value2 = { NULL, 2 };
    Value value3 = { NULL, 3 };
    addInHead(list, value1, &errorCode);
    addInHead(list, value2, &errorCode);
    addInHead(list, value3, &errorCode);
    bool result = getValue(list, getElement(list, 1)).length == 2 ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testList() {
    return testCreateList() && testGetValue() && testAddInHead() && testAddInTail() &&
        testAdd() && testRemoveElement() && testGetElement();
}