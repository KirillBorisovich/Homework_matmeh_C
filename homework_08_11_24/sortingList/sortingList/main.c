#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "testsList.h"

int main() {
    if (!testList()) {
        printf("Test falied");
        return 123;
    }
    int errorCode = 0;
    List* list = createList(&errorCode);
    int operationNumber = 9;
    while (operationNumber != 0) {
        printf("Enter operation number: ");
        scanf_s("%d", &operationNumber);
        getchar();
        if (operationNumber == 0) {
            deleteList(list);
            return 0;
        }
        else if (operationNumber == 1) {
            int value = 0;
            printf("Enter value: ");
            scanf_s("%d", &value);
            Position position = first(list);
            if (getSizeList(list) == 0) {
                addInTail(list, value, &errorCode);
            }
            else {
                while (getValue(list, position) < value) {
                    position = next(position);
                }
                add(list, position, value, &errorCode);
            }  
        }
        else if (operationNumber == 2) {
            if (getSizeList(list) > 0) {
                removeElement(list, first(list));
            }
            else {
                printf(" There are no elements in the array\n");
            }
        }
        else if (operationNumber == 3) {
            printf("Sorted array:\n");
            if (getSizeList(list) == 0) {
                printf(" The list is empty\n");
            }
            else {
                for (Position i = first(list); !isLast(list, i); i = next(i)) {
                    printf("%d ", getValue(list, i));
                }
                printf("\n");
            }
        }
    }
}