#include <stdio.h>
#include "list.h"
#include "tests.h"

int main() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    int operationNumber = 9;
    while (operationNumber != 0) {
        printf("Enter operation number: ");
        scanf_s("%d", &operationNumber);
        getchar();
        if (operationNumber == 0) {
            return 0;
        }
        else if (operationNumber == 0) {
            int value = 0;
            printf("Enter value: ");
            scanf_s("%d", &value);
            Position position = first(list);
            
        }
        else if (operationNumber == 0) {

        }
        else if (operationNumber == 0) {

        }
    }
}