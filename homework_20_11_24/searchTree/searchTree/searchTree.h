#pragma once

typedef struct {
    int key;
    char* value;
} NodeValue;

typedef struct Node Node;

Node* createNode(NodeValue value, int* errorCode);

void addElementToTree(Node* node, NodeValue value, int* errorCode);

void addLeftChild(Node* node, Node* child);

void addRightChild(Node* node, Node* child);

Node* findElementByKey(Node* node, int key);

bool presenceOfElementByKey(Node* node, int key);

Node* getLeftChild(Node* node);

Node* getRightChild(Node* node);

NodeValue getValue(Node* node);

void setValue(Node* node, NodeValue value);

Node* getTheMinimumElementOfTheRightNode(Node* node);

void deleteElementByKey(Node* node, int key);

void deleteTree(Node* node);