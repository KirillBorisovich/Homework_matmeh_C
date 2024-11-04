#pragma once
#include <stdbool.h>

typedef struct ListElement ListElement;

typedef struct List List;

typedef ListElement* Position;

typedef int Value;

List* createList(int* errorCode);

Position first(List* list);
 
int add(List* list, Position position, int value, int* errorCode);

void removeElement(List* list, Position position);

Position getElement(List* list, Position position);

Value getValue(List* list, Position position);

bool isLast(List* list, Position position);

bool isValid(List* list, Position position);

Position next(Position position);

Value getSizeList(List* list);
