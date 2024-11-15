#pragma once

typedef struct Node Node;

// Create a node
Node* createNode(char* value, int* errorCode);

// Add left child
void addLeftChild(Node* node, Node* child);

// Add right child
void addRightChild(Node* node, Node* child);

// Get left child
Node* getLeftChild(Node* node);

// Get right child
Node* getRightChild(Node* node);

// Get value from node
const char* getValue(Node* node);

// Add values ​​to node
void setValue(Node* node, char* value);

// Remove tree
void deleteTree(Node* node);

// Fill a parse tree with an arithmetic expression
Node* splitArithmeticExpression(char* string, int* index, int* errorCode);