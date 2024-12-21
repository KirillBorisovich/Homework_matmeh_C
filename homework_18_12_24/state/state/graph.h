#pragma once

#include "list.h"

typedef struct Node Node;

typedef struct Graph Graph;

// Create a node
Node* createNode(int name, int* errorCode);

// Create a graph
Graph* createGraph(int* errorCode);

// Write down the number of cities
void writeDownTheNumberOfCities(Graph* graph, size_t numberOfCities);

// Get node name
int getNodeName(Node* node);

// Get graph size
size_t getGraphSize(Graph* graph);

// Find a node in a graph
Node* wrapFindNodeInGraph(Graph* graph, int name, int* errorCode);

// Add element to graph
void addElementToGraph(Graph* graph, Node* node, int* errorCode);

// Create a path
void createAPath(Graph* graph, int nameOfTheShipment, int arrivalName, int length, int* errorCode);

// Get the nearest element
Node* getTheNearestElement(Node* node);

// Find the nearest unoccupied city
void wrapFindTheNearestUnoccupiedCity(Node* node, int* errorCode);

// Distribute cities by states
void assignCitiesToStates(Graph* graph, Graph* captails, int* errorCode);

// Print states
void printStates(Graph* graph, int* errorCode);

// Delete graph
void wrapDeleteGraph(Graph* graph, int* errorCode);

void deleteGraphWithoutContent(Graph* graph);