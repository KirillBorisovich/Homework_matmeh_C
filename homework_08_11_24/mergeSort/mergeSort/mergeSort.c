#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "mergeSort.h"

List* merge(List* first, List* second, bool sortByName, int* errorCode) {
    List* result = createList(&errorCode);
    Position i = firstElement(first);
    Position j = firstElement(second);
    char nameFirst[80] = { NULL };
    char phoneFirst[20] = { NULL };
    char nameSecond[80] = { NULL };
    char phoneSecond[20] = { NULL };
    getValue(first, i, nameFirst, phoneFirst, errorCode);
    getValue(second, j, nameSecond, phoneSecond, errorCode);
    char elementFirst[80] = { NULL };
    char elementSecond[80] = { NULL };
    switch (sortByName) {
    case true:
        strcpy_s(elementFirst, 80, nameFirst);
        strcpy_s(elementSecond, 80, nameSecond);
        break;
    case false:
        strcpy_s(elementFirst, 80, phoneFirst);
        strcpy_s(elementSecond, 80, phoneSecond);
        break;
    }
    while (next(i) != NULL || next(j) != NULL) {
        if (next(i) != NULL && next(j) != NULL) {
            if (elementFirst <= elementSecond) {
                addInHead(result, nameFirst, phoneFirst, errorCode);
                i = next(i);
            }
            else {
                addInHead(result, nameSecond, phoneSecond, errorCode);
                j = next(j);
            }
        }
        else if (next(i) == NULL && next(j) != NULL) {
            addInHead(result, nameSecond, phoneSecond, errorCode);
            j = next(j);
        }
        else if (next(i) != NULL && next(j) == NULL) {
            addInHead(result, nameFirst, phoneFirst, errorCode);
            i = next(i);
        }
    }
    deleteList(first);
    deleteList(second);
    return result;
}

List* mergeSorting(List* list, bool sortByName, int* errorCode) {
    if (getSizeList(list) <= 1) {
        return list;
    }
    else {
        List* first = createList(errorCode);
        List* second = createList(errorCode);
        Position position = firstElement(list);
        int listLen = getSizeList(list);
        int index = 0;
        while (next(position) != NULL) {
            char name[80] = { NULL };
            char phone[20] = { NULL };
            getValue(list, position, name, phone, errorCode);
            if (index < listLen / 2) {
                addInHead(first, name, phone, errorCode);
            }
            else {
                addInHead(second, name, phone, errorCode);
            }
            ++index;
            position = next(position);
        }
        return merge(
            mergeSorting(first, sortByName, errorCode), 
            mergeSorting(second, sortByName, errorCode), 
            sortByName, errorCode);
    }
}


