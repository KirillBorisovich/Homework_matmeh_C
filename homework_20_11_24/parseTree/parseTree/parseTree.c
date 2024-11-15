#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parseTree.h"

typedef struct Node {
    const char* value;
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

const char* getValue(Node* node) {
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

Node* splitArithmeticExpression(char* string, int* index, int* errorCode) {
    if (string[*index] == '\0') {
        return NULL;
    }
    while (string[*index] == '(' || string[*index] == ')' || string[*index] == ' ') {
        ++*index;
    }
    char* value = calloc(2, sizeof(char));
    if (value == NULL) {
        *errorCode = 1;
        return NULL;
    }
    value[0] = string[*index];
    if (48 <= string[*index] && string[*index] <= 57) {
        ++*index;
        return createNode(value, errorCode);
    }
    else if (string[*index] == '*' || string[*index] == '-' ||
        string[*index] == '+' || string[*index] == '/') {
        Node* node = createNode(value, errorCode);
        ++*index;
        node->leftChild = splitArithmeticExpression(string, index, errorCode);
        node->rightChild = splitArithmeticExpression(string, index, errorCode);
        return node;
    }
}