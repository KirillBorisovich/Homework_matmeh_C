#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "list.h"

typedef struct ListElement {
    char name[80];
    char phone[20];
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

int add(List* list, Position position, char* name, char* phone, int* errorCode) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        *errorCode = 1;
        return 0;
    }
    strcpy_s(element->name, 80, name);
    strcpy_s(element->phone, 20, phone);
    if (position != NULL) {
        element->next = position->next;
        position->next = element;
        ++list->size;
    }
}

void addInHead(List* list, char* name, char* phone, int* errorCode) {
    add(list, first(list), name, phone, errorCode);
}

void removeElement(List* list, Position position) {
    if (position != NULL && position->next != NULL) {
        ListElement* tmp = position->next;
        position->next = position->next->next;
        free(tmp);
        tmp = NULL;
        --list->size;
    }
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

char* getValue(List* list, Position position, int* errorCode) {
    char* nameAndPhone = (char*)calloc(101, sizeof(char));
    if (nameAndPhone == NULL) {
        *errorCode = 1;
        return NULL;
    }
    int nameLen = strlen(position->next->name);
    int phoneLen = strlen(position->next->phone);
    for (int i = 0; i < nameLen; ++i) {
        nameAndPhone[i] = position->next->name[i];
    }
    nameAndPhone[nameLen] = ' ';
    for (int i = 0; i < phoneLen; ++i) {
        nameAndPhone[nameLen + 1 + i] = position->next->phone[i];
    }
    return nameAndPhone;
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