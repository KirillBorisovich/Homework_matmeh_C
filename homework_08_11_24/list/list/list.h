#pragma once
#include <stdbool.h>

typedef struct ListElement ListElement;

typedef struct List List;

typedef ListElement* Position;

typedef int Value;

List* createList(int* errorCode);

Position first(List* list);
 
void add(List* list, int index, int value, int* errorCode);

void removeElement(List* list, int index);

Position getElement(List* list, int index);

Value getValue(List* list, int index);

bool isLast(List* list, Position position);

bool isValid(List* list, Position position);

void push(List* list, int value, int* errorCode);

Value getSizeList(List* list);
