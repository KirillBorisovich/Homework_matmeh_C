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
    char name[80] = { NULL };
    char phone[20] = { NULL };
    getValue(list, firstElement(list), name, phone, &errorCode);
    bool result = !strcmp(name, "kirill") && !strcmp(phone, "123") ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testAdd() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    add(list, position, "kirill", "123", & errorCode);
    position = next(firstElement(list));
    add(list, position, "name", "1234", &errorCode);
    char name1[80] = { NULL };
    char phone1[20] = { NULL };
    getValue(list, firstElement(list), name1, phone1, &errorCode);
    bool result = !strcmp(name1, "kirill") && !strcmp(phone1, "123") ? true : false;
    char name2[80] = { NULL };
    char phone2[20] = { NULL };
    getValue(list, next(firstElement(list)), name2, phone2, &errorCode);
    result = !strcmp(name2, "name") && !strcmp(phone2, "1234") ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddInTail() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    addInTail(list, "name1", "123", &errorCode);
    position = next(firstElement(list));
    addInTail(list, "name2", "1234", &errorCode);
    char name1[80] = { NULL };
    char phone1[20] = { NULL };
    getValue(list, firstElement(list), name1, phone1, &errorCode);
    bool result = !strcmp(name1, "name1") && !strcmp(phone1, "123") ? true : false;
    getValue(list, next(firstElement(list)), name1, phone1, &errorCode);
    result = !strcmp(name1, "name2") && !strcmp(phone1, "1234") ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testRemoveElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    addInHead(list, "name1", "1234", & errorCode);
    addInHead(list, "name2", "12345", &errorCode);
    addInHead(list, "name3", "123456", &errorCode);
    removeElement(list, position);
    char name[80] = { NULL };
    char phone[20] = { NULL };
    getValue(list, firstElement(list), name, phone, &errorCode);
    bool result = !strcmp(name, "name2") && !strcmp(phone, "12345") ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, "name1", "1234", &errorCode);
    addInHead(list, "name2", "12345", &errorCode);
    addInHead(list, "name3", "123456", &errorCode);
    char name[80] = { NULL };
    char phone[20] = { NULL };
    getValue(list, getElement(list, 1), name, phone, &errorCode);
    bool result = !strcmp(name, "name2") && !strcmp(phone, "12345") ? true : false;
    deleteList(list);
    return result && errorCode == 0;
}

bool testList() {
    return testCreateList() && testGetValueAndAddInHead() &&
        testAdd() && testAddInTail() && testRemoveElement() && testGetElement();
}




