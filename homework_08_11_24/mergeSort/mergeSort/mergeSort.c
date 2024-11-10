#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "mergeSort.h"

static List* merge(List* first, List* second, bool sortByName, int* errorCode) {
    List* result = createList(errorCode);
    Position i = firstElement(first);
    Position j = firstElement(second);
    char nameFirst[80] = { '\0' };
    char phoneFirst[20] = { '\0' };
    char nameSecond[80] = { '\0' };
    char phoneSecond[20] = { '\0' };
    getValue(first, i, nameFirst, phoneFirst, errorCode);
    getValue(second, j, nameSecond, phoneSecond, errorCode);
    char elementFirst[80] = { '\0' };
    char elementSecond[80] = { '\0' };
    while (next(i) != NULL || next(j) != NULL) {
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
        if (next(i) != NULL && next(j) != NULL) {
            if (strcmp(elementFirst, elementSecond) <= 0) {
                addInTail(result, nameFirst, phoneFirst, errorCode);
                i = next(i);
                if (next(i) != NULL) {
                    getValue(first, i, nameFirst, phoneFirst, errorCode);
                }
            }
            else {
                addInTail(result, nameSecond, phoneSecond, errorCode);
                j = next(j);
                if (next(j) != NULL) {
                    getValue(second, j, nameSecond, phoneSecond, errorCode);
                }
            }
        }
        else if (next(i) == NULL && next(j) != NULL) {
            addInTail(result, nameSecond, phoneSecond, errorCode);
            j = next(j);
            if (next(j) != NULL) {
                getValue(second, j, nameSecond, phoneSecond, errorCode);
            }
        }
        else if (next(i) != NULL && next(j) == NULL) {
            addInTail(result, nameFirst, phoneFirst, errorCode);
            i = next(i);
            if (next(i) != NULL) {
                getValue(first, i, nameFirst, phoneFirst, errorCode);
            }
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
            char name[80] = { '\0' };
            char phone[20] = { '\0' };
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


