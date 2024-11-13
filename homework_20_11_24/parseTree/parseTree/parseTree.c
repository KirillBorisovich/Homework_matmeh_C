#include <stdio.h>
#include <stdlib.h>
#include "parseTree.h"

typedef struct Node {
    char* value;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
} Node;

Node* createNode(char* value, int* errorCode) {
    Node* node = calloc(1, sizeof(Node));
    if (node == NULL) {
        *errorCode = 1;
        return NULL;
    }
    node->value = value;
    return node;
}

void addLeftChild(Node* node, Node* child) {
    node->leftChild = child;
    child->parent = node;
}

void addRightChild(Node* node, Node* child) {
    node->rightChild = child;
    child->parent = node;
}

Node* getLeftChild(Node* node) {
    return node->leftChild;
}

Node* getRightChild(Node* node) {
    return node->rightChild;
}

char* getValue(Node* node) {
    return node->value;
}

void setValue(Node* node, char* value) {
    node->value = value;
}

void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    char* value = node->value;
    free(value);
    free(node);
}