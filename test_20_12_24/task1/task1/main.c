#include <stdio.h>
#include <stdbool.h>
#include "hashTable.h"
#include "testHashTable.h"

int main() {
    if (!testHashTable()) {
        printf("Test failed!\n");
        return 123;
    }
}