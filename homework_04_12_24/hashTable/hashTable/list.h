#pragma once

typedef struct ListElement ListElement;

typedef struct List List;

typedef ListElement* Position;

typedef int Value;

// Create a list
List* createList(int* errorCode);

// Position of the first element
Position first(List* list);

// Add element by position
int add(List* list, Position position, int value, int* errorCode);

// Add element to head
void addInHead(List* list, int value, int* errorCode);

// Add element to tail
void addInTail(List* list, int value, int* errorCode);

// Delete element by position
void removeElement(List* list, Position position);

// Get element address by position
Position getElement(List* list, int index);

// Get the value of an element
Value getValue(List* list, Position position);

// Returns true if this is the last element
bool isLast(List* list, Position position);

// Returns true if this is an existing element
bool isValid(List* list, Position position);

// Getting the next element
Position next(Position position);

// Get the size of an list
Value getSizeList(List* list);

// Delete list
void deleteList(List* list);