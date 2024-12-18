#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "readingFromFile.h"
#include "testsGraph.h"

int main(void) {
    if (!testGraph()) {
        printf("Test failed!\n");
        return 123;
    }

    int errorCode = 0;
    Graph* graph = createGraph(&errorCode);
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }
    readingFromFile(file, graph, errorCode);
    fclose(file);
    wrapDepthFirstTraversalOfAGraph((graph, 10, &errorCode), &errorCode);
}