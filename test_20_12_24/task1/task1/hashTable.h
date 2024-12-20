#pragma once

typedef struct HashTable HashTable;

// Create a hashtable
HashTable* createHashTable(size_t size, int* errorCode);

// Add element to hashtable
void addElement(HashTable* hashTable, char* string, int* errorCode);

// Find an element in a hashtable
bool findElement(HashTable* hashTable, char* string);

// Delete hashtable
void deleteHahsTable(HashTable* hashTable);