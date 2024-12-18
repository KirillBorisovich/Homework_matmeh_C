#pragma once

#include "list.h"

typedef struct Node Node;

typedef struct Graph Graph;

// Create a node
Node* createNode(int name, int* errorCode);

// Create a graph
Graph* createGraph(int* errorCode);

// Get node name
int getNodeName(Node* node);

// Get graph size
int getGraphSize(Graph* graph);

// Find a node in a graph
Node* wrapFindNodeInGraph(Graph* graph, int name, int* errorCode);

// Add element to graph
void addElementToGraph(Graph* graph, Node* node, int* errorCode);

// Create a path
void createAPath(Graph* graph, int nameOfTheShipment, int arrivalName, int length, int* errorCode);

// Get the nearest element
Node* getTheNearestElement(Node* node);

void wrapDepthFirstTraversalOfAGraph(Node* node, int* errorCode);

// Delete graph
void wrapDeleteGraph(Graph* graph, int* errorCode);