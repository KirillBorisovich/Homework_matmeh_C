#pragma once

typedef struct HashTable HashTable;

// Create hash table
HashTable* createHashTable(int* errorCode);

// Add value to hash table
void addValueToHashTable(HashTable* hashTable, Value value, int* errorCode);

// Get word frequency from hash table
int getWordFrequencyFromHashTable(HashTable* hashTable, char* key);

// Print values of the entire hash table 
void printValuesOfTheEntireHashTable(HashTable* hashTable);

// Delete hash table
void deleteHashTable(HashTable* hashTable);