#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "readingFromFile.h"
#include "mergeSort.h"
#include "tests.h"

int main() {
    if (!testProgram()) {
        printf("Test failed");
        return 123;
    }

    int errorCode = 0;
    List* list = createList(&errorCode);
    readingFromFile("phoneBook.txt", list, &errorCode);
    List* sortedList = mergeSorting(list, true, errorCode);
    deleteList(list);
    for (Position i = firstElement(sortedList); !isLast(sortedList, i); i = next(i)) {
        char name[80] = { NULL };
        char phone[20] = { NULL };
        getValue(sortedList, i, name, phone, &errorCode);
        printf("%s %s\n", name, phone);

    }
    deleteList(sortedList);
}