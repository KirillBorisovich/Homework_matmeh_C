#pragma once

typedef struct {
    const char* key;
    const char* value;
} NodeValue;

typedef struct Node Node;

// Create a node
Node* createNode(NodeValue value, int* errorCode);

// Add element to tree
void addElementToTree(Node** node, NodeValue value, int* errorCode);

// Add left child
void addLeftChild(Node* node, Node* child);

// Add right child
void addRightChild(Node* node, Node* child);

// Find element by key
Node* findElementByKey(Node* node, int key);

// Check if an element is present in a tree
bool presenceOfElementByKey(Node* node, int key);

// Get left child
Node* getLeftChild(Node* node);

// Get right child
Node* getRightChild(Node* node);

// Get value from node
NodeValue getValue(Node* node);

// Add values ​​to node
void setValue(Node* node, NodeValue value);

// Delete element by key
void deleteElementByKey(Node** node, int key);

// Remove tree
void deleteTree(Node* node);