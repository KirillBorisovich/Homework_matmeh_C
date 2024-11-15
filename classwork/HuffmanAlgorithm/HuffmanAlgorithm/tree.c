#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

typedef struct Node {
    NodeValue value;
    Node* leftChild;
    Node* rightChild;
} Node;

Node* createNode(NodeValue value) {
    Node* node = calloc(1, sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    return node;
}

void addLeftChild(Node* node, Node* child) {
    node->leftChild = child;
}

void addRightChild(Node* node, Node* child) {
    node->rightChild = child;
}

Node* getLeftChild(Node* node) {
    return node->leftChild;
}

Node* getRightChild(Node* node) {
    return node->rightChild;
}

NodeValue getValue(Node* node) {
    return node->value;
}

void setValue(Node* node, NodeValue value) {
    node->value = value;
}

Node* getTheMinimumElementOfTheRightNode(Node* node) {
    Node* minElement = node->rightChild;
    while (minElement->leftChild != NULL) {
        minElement = minElement->leftChild;
    }
    return minElement;
}

void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    free(node);
}