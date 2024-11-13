#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

typedef struct Node {
    NodeValue value;
    Node* parent;
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

void deleteElementByKey(Node* node) {
    Node* element = node;
    if (element != NULL) {
        if (element->leftChild == NULL && element->rightChild == NULL) {
            if (element->parent->leftChild == element) {
                element->parent->leftChild = NULL;
            }
            else {
                element->parent->rightChild = NULL;
            }
        }
        else if (element->leftChild != NULL && element->rightChild == NULL) {
            if (element->parent->leftChild == element) {
                element->parent->leftChild = element->leftChild;
            }
            else {
                element->parent->rightChild = element->leftChild;
            }
        }
        else if (element->leftChild == NULL && element->rightChild != NULL) {
            if (element->parent->leftChild == element) {
                element->parent->leftChild = element->rightChild;
            }
            else {
                element->parent->rightChild = element->rightChild;
            }
        }
        else if (element->leftChild != NULL && element->rightChild != NULL) {
            Node* elementReplacement = getTheMinimumElementOfTheRightNode(element);
            if (elementReplacement->parent->leftChild == elementReplacement) {
                elementReplacement->parent->leftChild = elementReplacement->rightChild != NULL ?
                    elementReplacement->rightChild : NULL;
            }
            else {
                elementReplacement->parent->rightChild = elementReplacement->rightChild != NULL ?
                    elementReplacement->rightChild : NULL;
            }
            elementReplacement->parent = element->parent;
            if (element->parent->leftChild == element) {
                element->parent->leftChild = elementReplacement;
            }
            else {
                element->parent->rightChild = elementReplacement;
            }
            elementReplacement->leftChild = element->leftChild;
            elementReplacement->rightChild = element->rightChild;
        }
        free(element);
    }
}

void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    free(node);
}