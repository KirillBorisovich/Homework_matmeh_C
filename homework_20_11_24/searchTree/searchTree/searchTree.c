#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "searchTree.h"

typedef struct Node {
    NodeValue value;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
} Node;

Node* createNode(NodeValue value, int* errorCode) {
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

void addElementToTree(Node* node, NodeValue value, int* errorCode) {
    if (node->value.key == value.key) {
        node->value = value;
        return;
    }
    if (node->value.key > value.key && node->leftChild == NULL) {
        Node* element = createNode(value, errorCode);
        addLeftChild(node, element);
    }
    else if (node->value.key < value.key && node->rightChild == NULL) {
        Node* element = createNode(value, errorCode);
        addRightChild(node, element);
    }
    else if (node->value.key > value.key) {
        addElementToTree(node->leftChild, value, errorCode);
    }
    else if (node->value.key < value.key) {
        addElementToTree(node->rightChild, value, errorCode);
    }
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

Node* findElementByKey(Node* node, int key) {
    if (node->value.key == key) {
        return node;
    }
    if (node->value.key > key && node->leftChild != NULL) {
        findElementByKey(node->leftChild, key);
    }
    else if (node->value.key < key && node->rightChild != NULL) {
        findElementByKey(node->rightChild, key);
    }
    else {
        return NULL;
    }
}

bool presenceOfElementByKey(Node* node, int key) {
    return findElementByKey(node, key) != NULL;
}

void deleteElementByKey(Node* node, int key) {
    Node* element = findElementByKey(node, key);
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
        char* textValue = element->value.value;
        free(textValue);
        free(element);
    }
}

void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    char* textValue = node->value.value;
    free(textValue);
    free(node);
}