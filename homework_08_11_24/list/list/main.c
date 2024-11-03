#include <stdio.h>
#include "list.h"

int main() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = first(list);
    add(list, position, 1, &errorCode);
    //printf("%d", getValue(list, position));
}