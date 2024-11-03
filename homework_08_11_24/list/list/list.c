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
};

List* createList(int* errorCode) {
    List* list = malloc(sizeof(List));
    ListElement* head = calloc(1, sizeof(ListElement));
    if (list == NULL || head == NULL) {
        *errorCode = 1;
        return NULL;
    }
    list->head = head;
    return head;
}

Position first(List* list) {
    return list->head;
}

void add(List* list, Position position, int value, int* errorCode) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        *errorCode = 1;
        return NULL;
    }
    element->value = value;
    element->next = position->next;
    position->next = element;
}

void remove(List* list, Position position) {

}

Value getValue(List* list, Position position) {
    assert(position->next == NULL);
    return position->next->value;
}

bool isLast(List* list, Position position) {
    return position->next == NULL;
}

bool isValid(List* list, Position position) {
    return position != NULL;
}