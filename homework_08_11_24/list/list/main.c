#include <stdio.h>
#include "list.h"

int main() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    add(list, 0, 1, &errorCode);
    add(list, 1, 2, &errorCode);
    add(list, 2, 3, &errorCode);

    //removeElement(list, 1);
    for (int i = 0; i < getSizeList(list); ++i) {
        printf("%d", getValue(list, i));
    }
}