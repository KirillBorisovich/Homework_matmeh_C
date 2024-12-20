#pragma once

typedef struct ListElement ListElement;

typedef struct List List;

typedef struct Node Node;

typedef ListElement* Position;

typedef struct {
    Node* node;
    int length;
} Value;

// Create a list
List* createList(int* errorCode);

// Position of the first element
Position first(List* list);

// Position of the last element
Position last(List* list);

// Add element by position
int add(List* list, Position position, Value value, int* errorCode);

// Add element to head
void addInHead(List* list, Value value, int* errorCode);

// Add element to tail
void addInTail(List* list, Value value, int* errorCode);

// Delete element by position
void removeElement(List* list, Position position);

// Delete element without erasing values
void removeElementWithoutErasingValues(List* list, Position position);

// Get element address by position
Position getElement(List* list, int index);

// Get the value of an element
Value getValue(List* list, Position position);

// Returns true if this is the last element
bool isLast(List* list, Position position);

// Returns true if this is an existing element
bool isValid(List* list, Position position);

// Check if an item is in a list
bool nodeInList(List* list, Node* node);

// Checks if a list contains elements. If empty, then true
bool isEmpty(List* list);

// Getting the next element
Position next(Position position);

// Get the size of an list
int getSizeList(List* list);

// Delete list
void deleteList(List* list);

// Delete list without erasing values
void deleteListWithoutErasingValues(List* list);