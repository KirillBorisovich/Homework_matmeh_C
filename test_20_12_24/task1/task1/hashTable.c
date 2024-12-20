#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashTable.h"

typedef struct HashTable {
    char** array;
    size_t size;
    size_t numberOfElements;
} HashTable;

HashTable* createHashTable(size_t size, int* errorCode) {
    HashTable* hashTable = calloc(1, sizeof(HashTable));
    if (hashTable == NULL) {
        *errorCode = 1;
        return NULL;
    }
    hashTable->array = calloc(size, sizeof(char*));
    if (hashTable->array == NULL) {
        *errorCode = 1;
        return NULL;
    }
    hashTable->size = size;
    hashTable->numberOfElements = 0;
    return hashTable;
}

int hashFunction(char* key) {
    int result = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        result += key[i];
    }
    return result;
}

bool hashCountSearchFunction(HashTable* hashTable, int hash, char* string) {
    int originalIndex = hash % hashTable->size;
    int index = originalIndex;
    while (hashTable->array[index] != NULL && strcmp(hashTable->array[index], string)) {
        index = (index + 1) % hashTable->size;
        if (index == originalIndex) {
            return false;
        }
    }
    if (hashTable->array[index] == NULL) {
        return false;
    }
    return true;
}

void addElement(HashTable* hashTable, char* string, int* errorCode) {
    if (hashTable->size == hashTable->numberOfElements) {
        *errorCode = 2;
        return;
    }
    int hash = hashFunction(string);
    if (hashCountSearchFunction(hashTable, hash, string)) {
        return;
    }
    int index = hash % hashTable->size;
    while (hashTable->array[index] != NULL) {
        index = (index + 1) % hashTable->size;
    }
    hashTable->array[index] = string;
    ++hashTable->numberOfElements;
}

bool findElement(HashTable* hashTable, char* string) {
    return hashCountSearchFunction(hashTable, hashFunction(string), string);
}

void deleteHahsTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; ++i) {
        if (hashTable->array[i] != NULL) {
            free(hashTable->array[i]);
        }
    }
    free(hashTable->array);
    free(hashTable);
}