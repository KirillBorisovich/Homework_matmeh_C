#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

typedef struct ListElement {
    Value value;
    ListElement* next;
}ListElement;

typedef struct List {
    ListElement* head;
    ListElement* tail;
    int size;
} List;

List* createList(int* errorCode) {
    List* list = malloc(sizeof(List));
    ListElement* head = calloc(1, sizeof(ListElement));
    ListElement* tail = calloc(1, sizeof(ListElement));
    if (list == NULL || head == NULL || tail == NULL) {
        *errorCode = 1;
        return NULL;
    }
    list->head = head;
    list->head->next = NULL;
    list->tail = head;
    list->tail->next = NULL;
    list->size = 0;
    return list;
}

Position first(List* list) {
    return list->head;
}

int add(List* list, Position position, Value value, int* errorCode) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        *errorCode = 1;
        return 0;
    }
    element->value = value;
    if (position != NULL) {
        element->next = position->next;
        position->next = element;
        if (list->size == 0) {
            list->tail = element;
            list->head->next = element;
        }
        ++list->size;
    }
}

void addInHead(List* list, Value value, int* errorCode) {
    add(list, first(list), value, errorCode);
}

void addInTail(List* list, Value value, int* errorCode) {
    Position position = list->tail;
    add(list, position, value, errorCode);
    list->tail = next(position);
}

void removeElement(List* list, Position position) {
    ListElement* tmp = position->next;
    position->next = position->next->next;
    free(tmp->value.key);
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

void addOneToTheCounter(Position position) {
    ++position->value.counter;
}

int getSizeList(List* list) {
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