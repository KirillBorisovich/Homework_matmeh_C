#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "searchTree.h"
#include "testsSearchTree.h"

int main() {
    if (!testTree()) {
        printf("Test failed");
        return 123;
    }
    printf("Operation values\n");
    printf("Exit: 0\n");
    printf("Add a value to a dictionary by a given key: 1\n");
    printf("Get value by given key from dictionary: 2\n");
    printf("Check if the given key is in the dictionary: 3\n");
    printf("Remove the given key and its associated value from the dictionary: 3\n");

    int errorCode = 0;
    Node* tree = NULL;
    int operationNumber = 9;
    while (operationNumber != 0) {
        printf("Enter operation number: ");
        scanf_s("%d", &operationNumber);
        if (operationNumber == 0) {
            deleteTree(tree);
            return 0;
        }
        else if (operationNumber == 1) {
            const char* key = calloc(30, sizeof(char));
            char* value = calloc(100, sizeof(char));
            printf("Enter key: ");
            scanf_s("%s", key, 29);
            getchar();
            printf("Enter value: ");
            fgets(value, 99, stdin);
            value[strcspn(value, "\n")] = 0;
            NodeValue nodeValue = { key, value };
            addElementToTree(&tree, nodeValue, &errorCode);
            if (errorCode == 1) {
                printf("Memory allocation error\n");
                return 1;
            }
        }
        else if (operationNumber == 2) {
            const char key[30] = { '\0' };
            printf("Enter key: ");
            scanf_s("%s", key, 29);
            Node* elementByKey = findElementByKey(tree, key);
            if (elementByKey != NULL) {
                printf("%s\n", getValue(elementByKey).value);
            }
            else {
                printf("There is no such element in the dictionary\n");
            }

        }
        else if (operationNumber == 3) {
            const char key[30] = { '\0' };
            printf("Enter key: ");
            scanf_s("%s", key, 29);
            if (presenceOfElementByKey(tree, key)) {
                printf("The meaning is in the dictionary\n");
            }
            else {
                printf("The meaning is not in the dictionary\n");
            }
        }
        else if (operationNumber == 4) {
            const char key[30] = { '\0' };
            printf("Enter key: ");
            scanf_s("%s", key, 29);
            deleteElementByKey(&tree, key);
        }
        operationNumber = 9;
    }
}