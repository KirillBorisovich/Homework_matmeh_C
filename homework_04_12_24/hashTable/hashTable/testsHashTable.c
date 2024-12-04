#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "hashTable.h"
#include "testsHashTable.h"
#include "testsList.h"

bool testProgram() {
    int errorCode = 0;

    HashTable* hashTable = createHashTable(&errorCode);
    char* testText1 = calloc(20, sizeof(char));
    char* testText2 = calloc(20, sizeof(char));
    char* testText3 = calloc(20, sizeof(char));
    char* testText4 = calloc(20, sizeof(char));
    if (testText1 == NULL && testText2 == NULL &&
        testText3 == NULL && testText4 == NULL) {
        return false;
    }
    strcpy_s(testText1, 19, "testText1");
    strcpy_s(testText2, 19, "testText2");
    strcpy_s(testText3, 19, "testText1");
    strcpy_s(testText4, 19, "testText4");
    Value value1 = { testText1, 1 };
    Value value2 = { testText2, 1 };
    Value value3 = { testText3, 1 };
    Value value4 = { testText4, 1 };

    addValueToHashTable(hashTable, value1, &errorCode);
    addValueToHashTable(hashTable, value2, &errorCode);
    addValueToHashTable(hashTable, value3, &errorCode);
    addValueToHashTable(hashTable, value4, &errorCode);

    printValuesOfTheEntireHashTable(hashTable);
}