#pragma once

typedef struct HashTable HashTable;

// Create hash table
HashTable* createHashTable(int* errorCode);

// Add value to hash table
void addValueToHashTable(HashTable* hashTable, Value value, int* errorCode);

// Get word frequency from hash table
int getWordFrequencyFromHashTable(HashTable* hashTable, char* key);

// Get fill factor
float getFillFactor(HashTable* hashTable);

// Get the maximum length of lists
int getMaxLenght(HashTable* hashTable);

// Get average list length
int getAverageListLength(HashTable* hashTable);

// Print values of the entire hash table 
void printValuesOfTheEntireHashTable(HashTable* hashTable);

// Delete hash table
void deleteHashTable(HashTable* hashTable);