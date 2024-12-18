#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "graph.h"
#include "readingFromFile.h"

bool testGraph() {
    int errorCode = 0;
    bool result = false;
    Graph* graph = createGraph(&errorCode);

    FILE* file = fopen("testReadingFromFile.txt", "r");
    readingFromFile(file, graph, &errorCode);
    fclose(file);

    createAPath(graph, 1, 2, 5, &errorCode);
    createAPath(graph, 1, 4, 10, &errorCode);
    createAPath(graph, 2, 4, 123, &errorCode);
    createAPath(graph, 2, 1, 5, &errorCode);

    for (int i = 0; i < 15; ++i) {
        Node* node = createNode(i, &errorCode);
        addElementToGraph(graph, node, &errorCode);
    }

    if (getNodeName(getTheNearestElement(wrapFindNodeInGraph(graph, 1, &errorCode))) == 2 &&
        getNodeName(getTheNearestElement(wrapFindNodeInGraph(graph, 2, &errorCode))) == 1 &&
        getGraphSize(graph) == 20 &&
        getNodeName(getTheNearestElement(wrapFindNodeInGraph(graph, 10, &errorCode))) == 54) {
        result = true;
    }

    deleteGraph(graph);
    return result && errorCode == 0;
}