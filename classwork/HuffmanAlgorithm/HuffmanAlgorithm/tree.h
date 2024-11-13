#pragma once

typedef struct {
    char value;
    int frequency;
} NodeValue;

typedef struct Node Node;

// Create a node
Node* createNode(NodeValue value);

// Add left child
void addLeftChild(Node* node, Node* child);

// Add right child
void addRightChild(Node* node, Node* child);

// Get left child
Node* getLeftChild(Node* node);

// Get right child
Node* getRightChild(Node* node);

// Get value from node
NodeValue getValue(Node* node);

// Add values ​​to node
void setValue(Node* node, NodeValue value);

// Find the minimum element of the right subtree
Node* getTheMinimumElementOfTheRightNode(Node* node);

// Remove tree
void deleteTree(Node* node);