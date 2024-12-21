#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "graph.h"

typedef struct Node {
    int name;
    int stateNumber;
    List* matchList;
} Node;

typedef struct Graph {
    Node** peaks;
    size_t size;
    size_t numberOfCities;
} Graph;

Node* createNode(int name, int* errorCode) {
    Node* node = calloc(1, sizeof(Node));
    if (node == NULL) {
        *errorCode = 1;
        return NULL;
    }
    node->name = name;
    node->stateNumber = -1111;
    node->matchList = createList(errorCode);
    return node;
}

Graph* createGraph(int* errorCode) {
    Graph* graph = calloc(1, sizeof(Graph));
    graph->peaks = calloc(10, sizeof(Node*));
    graph->size = 10;
    graph->numberOfCities = 0;
    if (graph == NULL || graph->peaks == NULL) {
        *errorCode = 1;
        return NULL;
    }
    return graph;
}

void writeDownTheNumberOfCities(Graph* graph, size_t numberOfCities) {
    graph->numberOfCities = numberOfCities;
}

int getNodeName(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->name;
}

size_t getGraphSize(Graph* graph) {
    return graph->size;
}

void findNodeInGraph(Node* node, Node** findNode, int name, List* list, int* errorCode) {
    if (*findNode != NULL) {
        return;
    }
    Value value = { node, 0 };
    addInHead(list, value, errorCode);
    if (node->name == name) {
        *findNode = node;
        return;
    }
    if (isEmpty(node->matchList)) {
        return;
    }
    Position positon = first(node->matchList);
    while (next(positon) != NULL) {
        Node* valueNode = getValue(node->matchList, positon).node;
        if (!nodeInList(list, valueNode)) {
            findNodeInGraph(valueNode, findNode, name, list, errorCode);
        }
        positon = next(positon);
    }
}

Node* wrapFindNodeInGraph(Graph* graph, int name, int* errorCode) {
    if (graph->peaks[0] == NULL) {
        return NULL;
    }
    Node* findNode = NULL;
    List* list = createList(errorCode);
    findNodeInGraph(graph->peaks[0], &findNode, name, list, errorCode);
    deleteListWithoutErasingValues(list);
    return findNode;
}

void increaseGraphSize(Graph* graph, int index, int* errorCode) {
    Node** tmp = calloc(graph->size * 2, sizeof(Node*));
    if (tmp == NULL) {
        *errorCode = 1;
        return;
    }
    int i = 0;
    for (int i = 0; i < graph->size; ++i) {
        tmp[i] = graph->peaks[i];
    }
    free(graph->peaks);
    graph->peaks = tmp;
    graph->size *= 2;
}

void addElementToGraph(Graph* graph, Node* node, int* errorCode) {
    int index = 0;
    while (graph->peaks[index] != NULL && graph->size > index) {
        ++index;
    }
    if (graph->size > index) {
        graph->peaks[index] = node;
    }
    if (graph->size <= index) {
        increaseGraphSize(graph, index, errorCode);
        addElementToGraph(graph, node, errorCode);
    }
}

void createAPath(Graph* graph, int nameOfTheShipment, int arrivalName, 
    int length, int* errorCode) {
    Node* node = wrapFindNodeInGraph(graph, nameOfTheShipment, errorCode);
    if (node == NULL) {
        node = createNode(nameOfTheShipment, errorCode);
        addElementToGraph(graph, node, errorCode);
    }
    Node* childElement = wrapFindNodeInGraph(graph, arrivalName, errorCode);
    if (childElement == NULL) {
        childElement = createNode(arrivalName, errorCode);
    }
    if (nodeInList(node->matchList, childElement)) {
        return;
    }
    Value path1 = { childElement, length };
    Value path2 = { node, length };
    addInHead(node->matchList, path1, errorCode);
    addInHead(childElement->matchList, path2, errorCode);
}

Node* getTheNearestElement(Node* node) {
    if (node == NULL || isEmpty(node->matchList)) {
        return NULL;
    }
    int min = 100000;
    Node* result = NULL;
    Position position = first(node->matchList);
    while (next(position) != NULL) {
        Value value = getValue(node->matchList, position);
        if (value.length < min) {
            min = value.length;
            result = value.node;
        }
        position = next(position);
    }
    return result;
}

void depthFirstTraversalOfAGraph(Node* node, int stateNumber, List* list, int* errorCode) {
    if (nodeInList(list, node)) {
        return;
    }
    Value value = { node, 0 };
    addInHead(list, value, errorCode);
    if (node->stateNumber == stateNumber) {
        printf("%d ", node->name);
    }
    if (isEmpty(node->matchList)) {
        return;
    }
    Position positon = first(node->matchList);
    while (next(positon) != NULL) {
        Node* valueNode = getValue(node->matchList, positon).node;
        if (!nodeInList(list, valueNode)) {
            depthFirstTraversalOfAGraph(valueNode, stateNumber, list, errorCode);
        }
        positon = next(positon);
    }
}

void wrapDepthFirstTraversalOfAGraph(Node* node, int* errorCode) {
    int stateNumber = node->stateNumber;
    List* list = createList(errorCode);
    depthFirstTraversalOfAGraph(node, stateNumber,list, errorCode);
    deleteListWithoutErasingValues(list);
}

void findTheNearestUnoccupiedCity(Value value, int stateNumber, List* visited,
    List* queue, int* errorCode) {
    removeElementWithoutErasingValues(queue, last(queue));
    if (nodeInList(visited, value.node)) {
        return;
    }
    Value valueVisited = value;
    addInHead(visited, valueVisited, errorCode);
    if (value.node->stateNumber != stateNumber) {
        return;
    }
    Position position = first(value.node->matchList);
    while (next(position) != NULL) {
        Value tmp = getValue(value.node->matchList, position);
        Value valueFromQueue = { tmp.node, 1000000 };
        if (valueFromQueue.length > tmp.length + value.length) {
            valueFromQueue.length = tmp.length + value.length;
        }
        if (!nodeInList(visited, valueFromQueue.node) && 
            (valueFromQueue.node->stateNumber == -1111 || 
                valueFromQueue.node->stateNumber == value.node->stateNumber)) {
            addInHead(queue, valueFromQueue, errorCode);
        }
        position = next(position);
    }
}

void nodeWithMinimumLength(List* list, Node* parent) {
    int min = 100000000;
    Node* result = NULL;
    Position position = first(list);
    while (next(position) != NULL) {
        Value tmp = getValue(list, position);
        if (tmp.length < min && tmp.node->stateNumber == -1111 &&
            parent != tmp.node) {
            min = tmp.length;
            result = tmp.node;
        }
        position = next(position);
    }
    if (result == NULL) {
        return NULL;
    }
    result->stateNumber = parent->name;
    return result;
}

void wrapFindTheNearestUnoccupiedCity(Node* node, int* errorCode) {
    node->stateNumber = node->name;
    int stateNumber = node->stateNumber;
    List* visited = createList(errorCode);
    List* queue = createList(errorCode);
    Value value = { node, 0 };
    addInHead(queue, value, errorCode);
    while (!isEmpty(queue)) {
        Value tmp = getValue(queue, last(queue));
        findTheNearestUnoccupiedCity(tmp, stateNumber, visited, queue, errorCode);
    }
    nodeWithMinimumLength(visited, node);
    deleteListWithoutErasingValues(visited);
    deleteListWithoutErasingValues(queue);
}

void deleteGraph(Node* node, List* list, int* errorCode) {
    if (nodeInList(list, node)) {
        return;
    }
    Value value = { node, 0 };
    addInHead(list, value, errorCode);
    if (isEmpty(node->matchList)) {
        deleteList(node->matchList);
        free(node);
        return;
    }
    Position positon = first(node->matchList);
    while (next(positon) != NULL) {
        Node* valueNode = getValue(node->matchList, positon).node;
        if (!nodeInList(list, valueNode)) {
            deleteGraph(valueNode, list, errorCode);
        }
        positon = next(positon);
    }
    deleteListWithoutErasingValues(node->matchList);
    free(node);
}

void assignCitiesToStates(Graph* graph, Graph* captails, int* errorCode) {
    for (int i = 0; i < graph->numberOfCities / captails->numberOfCities; ++i) {
        for (int j = 0; j < captails->numberOfCities; ++j) {
            wrapFindTheNearestUnoccupiedCity(captails->peaks[j], errorCode);
        }
    }
}

void printStates(Graph* graph, int* errorCode) {
    for (int i = 0; i < graph->numberOfCities; ++i) {
        printf("State number: %d\n Cities: ", graph->peaks[i]->name);
        wrapDepthFirstTraversalOfAGraph(graph->peaks[i], errorCode);
        printf("\n");
    }
}

void wrapDeleteGraph(Graph* graph, int* errorCode) {
    List* list = createList(errorCode);
    deleteGraph(graph->peaks[0], list, errorCode);
    deleteListWithoutErasingValues(list);
}

void deleteGraphWithoutContent(Graph* graph) {
    free(graph->peaks);
    free(graph);
}