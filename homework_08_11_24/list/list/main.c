#include <stdio.h>
#include "list.h"

int main() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = first(list);
    add(list, position, 1, &errorCode);
    add(list, position, 2, &errorCode);
    add(list, position, 3, &errorCode);
    removeElement(list, getElement(list, 1));
    for (Position i = first(list); !isLast(list, i); i = next(i)) {
        printf("%d", getValue(list, i));
    }
}