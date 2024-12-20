#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "graph.h"
#include "readingFromFile.h"

bool testGraph() {
    int errorCode = 0;
    bool result = false;
    Graph* graph = createGraph(&errorCode);
    Graph* capitals = createGraph(&errorCode);

    FILE* file = fopen("testReadingFromFile.txt", "r");
    readingFromFile(file, graph, capitals, &errorCode);
    fclose(file);

    createAPath(graph, 1, 2, 5, &errorCode);
    createAPath(graph, 1, 4, 10, &errorCode);
    createAPath(graph, 2, 4, 123, &errorCode);
    createAPath(graph, 2, 1, 5, &errorCode);

    for (int i = 0; i < 15; ++i) {
        Node* node = createNode(i, &errorCode);
        addElementToGraph(graph, node, &errorCode);
    }

    if (getNodeName(getTheNearestElement(wrapFindNodeInGraph(capitals, 10, &errorCode))) == 54 &&
        getNodeName(getTheNearestElement(wrapFindNodeInGraph(graph, 10, &errorCode))) == 54 &&
        getNodeName(getTheNearestElement(wrapFindNodeInGraph(graph, 1, &errorCode))) == 2 &&
        getNodeName(getTheNearestElement(wrapFindNodeInGraph(graph, 2, &errorCode))) == 1 &&
        getGraphSize(graph) == 20 &&
        getNodeName(getTheNearestElement(wrapFindNodeInGraph(graph, 10, &errorCode))) == 54) {
        result = true;
    }
    wrapFindTheNearestUnoccupiedCity(wrapFindNodeInGraph(graph, 1, &errorCode), &errorCode);
    wrapDeleteGraph(graph, &errorCode);
    return result && errorCode == 0;
}