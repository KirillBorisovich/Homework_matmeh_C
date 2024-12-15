#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "testsGraph.h"

int main(void) {
    if (!testGraph()) {
        printf("Test failed!\n");
        return 123;
    }
}