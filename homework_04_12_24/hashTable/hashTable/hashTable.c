#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "hashTable.h"

typedef struct HashTable {
    List** array;
    int size;
    int numberOfElementsInTheTable;
    int maxLenght;
    int numberOfLists;
} HashTable;

HashTable* createHashTable(int* errorCode) {
    HashTable* result = calloc(1, sizeof(HashTable));
    if (result == NULL) {
        *errorCode = 1;
        return NULL;
    }
    result->array = calloc(2, sizeof(List*));
    if (result->array == NULL) {
        *errorCode = 1;
        return NULL;
    }
    result->size = 2;
    result->numberOfElementsInTheTable = 0;
    result->numberOfLists = 0;
    result->maxLenght = 0;
    return result;
}

float getFillFactor(HashTable* hashTable) {
    return (float)hashTable->numberOfElementsInTheTable / hashTable->size;
}

int getMaxLenght(HashTable* hashTable) {
    return hashTable->maxLenght;
}

int getAverageListLength(HashTable* hashTable) {
    return hashTable->numberOfElementsInTheTable / hashTable->numberOfLists;
}

int hashFunction(char* key) {
    int result = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        result += key[i];
    }
    return result;
}

void addValueToHashTable(HashTable* hashTable, Value value, int* errorCode) {
    int index = hashFunction(value.key) % hashTable->size;
    if (hashTable->array[index] == NULL) {
        hashTable->array[index] = createList(errorCode);
        ++hashTable->numberOfLists;
    }
    Position position = next(first(hashTable->array[index]));
    if (isEmpty(hashTable->array[index]) || (next(position) == NULL &&
        strcmp(getValue(hashTable->array[index], position).key, value.key))) {
        addInHead(hashTable->array[index], value, errorCode);
        ++hashTable->numberOfElementsInTheTable;
        if (hashTable->maxLenght < getSizeList(hashTable->array[index])) {
            hashTable->maxLenght = getSizeList(hashTable->array[index]);
        }
        //Adding memory
        if (((float)hashTable->numberOfElementsInTheTable / (float)hashTable->size) * 10 > 6) {
            List** tmp = hashTable->array;
            int oldSize = hashTable->size;
            hashTable->array = calloc(2 * hashTable->size, sizeof(List*));
            hashTable->size *= 2;
            hashTable->numberOfElementsInTheTable = 0;
            hashTable->numberOfLists = 0;
            hashTable->maxLenght = 0;
            if (hashTable->array == NULL) {
                *errorCode = 1;
                return;
            }
            for (int i = 0; i < oldSize; ++i) {
                if (tmp[i] == NULL) {
                    continue;
                }
                Position positionForAddingMemory = first(tmp[i]);
                do {
                    addValueToHashTable(hashTable, getValue(tmp[i], positionForAddingMemory), errorCode);
                    positionForAddingMemory = next(positionForAddingMemory);
                } while (next(positionForAddingMemory) != NULL);
                deleteListWithoutErasingValues(tmp[i]);
            }
            free(tmp);
        }
    }
    else {
        while (strcmp(getValue(hashTable->array[index], position).key, value.key) &&
            next(position) != NULL) {
            position = next(position);
        }
        if (!strcmp(getValue(hashTable->array[index], position).key, value.key)) {
            free(value.key);
            addOneToTheCounter(position);
        }
    }
}

int getWordFrequencyFromHashTable(HashTable* hashTable, char* key) {
    int index = hashFunction(key) % hashTable->size;
    if (hashTable->array[index] == NULL) {
        return 0;
    }
    if (isEmpty(hashTable->array[index])) {
        return 0;
    }
    Position position = first(hashTable->array[index]);
    while (strcmp(getValue(hashTable->array[index], position).key, key) &&
        next(position) != NULL) {
        position = next(position);
    }
    if (!strcmp(getValue(hashTable->array[index], position).key, key)) {
        return getValue(hashTable->array[index], position).counter;
    }
    else if (next(position) == NULL) {
        return 0;
    }
    else {
        return 0;
    }
}

void printValuesOfTheEntireHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; ++i) {
        if (hashTable->array[i] == NULL) {
            continue;
        }
        Position position = first(hashTable->array[i]);
        do {
            Value value = getValue(hashTable->array[i], position);
            printf("Key: %s\nFrequency: %d\n\n", value.key, value.counter);
            position = next(position);
        } while (next(position) != NULL);
    }
}

void deleteHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; ++i) {
        if (hashTable->array[i] != NULL) {
            deleteList(hashTable->array[i]);
        }
    }
    free(hashTable);
}