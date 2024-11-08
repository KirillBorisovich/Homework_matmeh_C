#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "readingFromFile.h"
#include "mergeSort.h"
#include "tests.h"

int main() {
    if (!testProgram()) {
        printf("Test failed");
        return 123;
    }
    int operationNumber = 0;
    int errorCode = 0;
    List* list = createList(&errorCode);
    readingFromFile("phoneBook.txt", list, &errorCode);

    printf("To sort by name enter 0\nTo sort by phone number enter 1\n");
    printf("Enter operation number: ");
    scanf_s("%d", &operationNumber);

    List* sortedList = operationNumber == 0 ? mergeSorting(list, true, &errorCode) : mergeSorting(list, false, &errorCode);
    deleteList(list);
    for (Position i = firstElement(sortedList); !isLast(sortedList, i); i = next(i)) {
        char name[80] = { '\0' };
        char phone[20] = { '\0' };
        getValue(sortedList, i, name, phone, &errorCode);
        printf("%s %s\n", name, phone);
    }
    deleteList(sortedList);
}