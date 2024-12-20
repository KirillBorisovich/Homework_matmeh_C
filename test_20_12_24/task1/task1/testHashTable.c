#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"

char* createALine(char* string, int* errorCode) {
    char* line = calloc(100, sizeof(char));
    if (line == NULL) {
        *errorCode = 1;
        return NULL;
    }
    strcpy_s(line, 99, string);
    return line;
}

bool testHashTable() {
    bool result = false;
    int errorCode = 0;

    HashTable* hashTable = createHashTable(10, &errorCode);
    char* string1 = createALine("qweasdxzc", &errorCode);
    char* string2 = createALine("qweasdxzc1", &errorCode);
    char* string3 = createALine("qweasdxzc", &errorCode);

    addElement(hashTable, string1, &errorCode);
    addElement(hashTable, string2, &errorCode);
    addElement(hashTable, string3, &errorCode);

    if (findElement(hashTable, string1) &&
        findElement(hashTable, string2) &&
        findElement(hashTable, string3) &&
        !findElement(hashTable, "wqer")) {
        result = true;
    }

    deleteHahsTable(hashTable);
    return result && errorCode == 0;
}