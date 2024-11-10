#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
    NodeValue valueFromFirstNode = { 1, "" };
    Node* tree = createNode(valueFromFirstNode, &errorCode);
    int operationNumber = 9;
    while (operationNumber != 0) {
        printf("Enter operation number: ");
        scanf_s("%d", &operationNumber);
        getchar();
        if (operationNumber == 0) {
            deleteTree(tree);
            return 0;
        }
        else if (operationNumber == 1) {
            int key = 0;
            char value[100] = { '\0' };
            printf("Enter key: ");
            scanf_s("%d", &key);
            getchar();
            printf("Enter value: ");
            fgets(&value, 99, stdin);
            value[strcspn(value, "\n")] = 0;
            NodeValue nodeValue = { key, value };
            addElementToTree(tree, nodeValue, &errorCode);
            if (errorCode == 1) {
                printf("Memory allocation error");
                return 1;
            }
        }
        else if (operationNumber == 2) {
            int key = 0;
            printf("Enter key: ");
            scanf_s("%d", &key);
            printf("%s", getValue(findElementByKey(tree, key)).value);

        }
        else if (operationNumber == 3) {
            int key = 0;
            printf("Enter key: ");
            scanf_s("%d", &key);
            if (presenceOfElementByKey(tree, key)) {
                printf("The meaning is in the dictionary\n");
            }
            else {
                printf("The meaning is not in the dictionary");
            }
        }
        else if (operationNumber == 4) {
            int key = 0;
            printf("Enter key: ");
            scanf_s("%d", &key);
            deleteElementByKey(tree, key);
        }
        operationNumber = 9;
    }
}