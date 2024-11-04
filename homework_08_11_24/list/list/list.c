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
    list->size = 0;
    return list;
}

Position first(List* list) {
    return list->head;
}

void add(List* list, int index, int value, int* errorCode) {
    Position position = getElement(list, index);
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        *errorCode = 1;
        return NULL;
    }
    element->value = value;
    assert(position != NULL);
    if (position != NULL) {
        element->next = position->next;
        position->next = element;
        ++list->size;
    }
}

void removeElement(List* list, int index) {
    Position position = getElement(list, index);
    ListElement* tmp = position->next;
    position->next = position->next->next;
    free(tmp);
    tmp = NULL;
    --list->size;
}

Position getElement(List* list, int index) { 
    ListElement* indexElement = list->head;
    for (int i = 0; i < index; ++i) {
        if (indexElement->next != NULL) {
            indexElement = indexElement->next;
        }
    }
    return indexElement;
}

Value getValue(List* list, int index) {
    Position position = getElement(list, index);
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

void push(List* list, int value, int* errorCode) {
    
}