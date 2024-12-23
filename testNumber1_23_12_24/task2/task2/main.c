#include <stdio.h>
#include <stdbool.h>
#include "sorting.h"
#include "test.h"

int main() {
    if (!testProgram()) {
        printf("Test failed!\n");
        return 123;
    }
}