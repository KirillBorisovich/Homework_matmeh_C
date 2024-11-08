#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

typedef struct ListElement {
    int value;
    ListElement* next;
}ListElement;

typedef struct List {
    ListElement* head;
    int size;
};

List* createList(int* errorCode) {
    List* list = malloc(sizeof(List));
    ListElement* head = calloc(1, sizeof(ListElement));
    if (list == NULL || head == NULL) {
        *errorCode = 1;
        return NULL;
    }
    list->head = head;
    list->head->next = NULL;
    list->size = 0;
    return list;
}

Position first(List* list) {
    return list->head;
}

int add(List* list, Position position, int value, int* errorCode) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        *errorCode = 1;
        return 0;
    }
    element->value = value;
    if (position != NULL) {
        element->next = position->next;
        position->next = element;
        ++list->size;
    }
}

void addInHead(List* list, int value, int* errorCode) {
    add(list, first(list), value, &errorCode);
}

void addInTail(List* list, int value, int* errorCode) {
    Position position = getElement(list, getSizeList(list));
    add(list, position, value, errorCode);
}

void removeElement(List* list, Position position) {
    ListElement* tmp = position->next;
    position->next = position->next->next;
    free(tmp);
    tmp = NULL;
    --list->size;
}

void removeInHead(List* list) {
    ListElement* element = calloc(1, sizeof(ListElement));

}

Position getElement(List* list, int index) {
    ListElement* indexElement = list->head;
    for (int i = 0; i < index; ++i) {
        if (indexElement->next != NULL) {
            indexElement = indexElement->next;
        }
        else {
            break;
        }
    }
    return indexElement;
}

Value getValue(List* list, Position position) {
    if (position->next != NULL) {
        return position->next->value;
    }
}

Value getSizeList(List* list) {
    return list->size;
}

bool isLast(List* list, Position position) {
    return position->next == NULL;
}

bool isValid(List* list, Position position) {
    return position != NULL;
}

bool isEmpty(List* list) {
    return list->head->next == NULL;
}

Position next(Position position) {
    return position->next;
}

void deleteList(List* list) {
    while (list->head->next != NULL) {
        removeElement(list, first(list));
    }
    free(list->head);
    free(list);
    list = NULL;
}