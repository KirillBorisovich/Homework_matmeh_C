#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "searchTree.h"

typedef struct Node {
    NodeValue value;
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
}

void addRightChild(Node* node, Node* child) {
    node->rightChild = child;
}

void addElementToTree(Node* node, NodeValue value, int* errorCode) {
    if (node->value.key == value.key) {
        char* tmp = node->value.value;
        node->value = value;
        free(tmp);
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
    Node* minElementParent = node->rightChild;
    Node* minElement = minElementParent->leftChild == NULL ? minElementParent : minElementParent->leftChild;
    while (minElement->leftChild != NULL) {
        minElementParent = minElement;
        minElement = minElement->leftChild;
    }
    minElementParent->leftChild = minElement->rightChild == NULL ? NULL : minElement->rightChild;
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

Node* findByKeyByRemove(Node* node, int key) {
    if (node->value.key == key || node == NULL) {
        return node;
    }
    else if ((node->leftChild != NULL && node->leftChild->value.key == key) || 
        (node->rightChild != NULL && node->rightChild->value.key == key)) {
        return node;
    }
    else if (node->value.key > key && node->leftChild != NULL) {
        findElementByKey(node->leftChild, key);
    }
    else if (node->value.key < key && node->rightChild != NULL) {
        findElementByKey(node->rightChild, key);
    }
    else {
        return NULL;
    }
}

void deleteElementByKey(Node* node, int key) {
    Node* result = NULL;
    Node* elementParent = findByKeyByRemove(node, key);
    Node* element = NULL;
    if (elementParent != NULL) {
        element = node->leftChild != NULL && elementParent->leftChild->value.key == key ?
            elementParent->leftChild : elementParent->rightChild;
    }
    if (element != NULL) {
        if (element->leftChild == NULL && element->rightChild == NULL) {
            result = NULL;
        }
        else if (element->leftChild != NULL && element->rightChild == NULL) {
            result = element->leftChild;
        }
        else if (element->leftChild == NULL && element->rightChild != NULL) {
            result =  element->rightChild;
        }
        else if (element->leftChild != NULL && element->rightChild != NULL) {
            Node* elementReplacement = getTheMinimumElementOfTheRightNode(element);
            if (element->rightChild == elementReplacement) {
                element->rightChild = NULL;
            }
            elementReplacement->leftChild = element->leftChild;
            elementReplacement->rightChild = element->rightChild;
            result = elementReplacement;
        }
        if (elementParent->leftChild == element) {
            elementParent->leftChild = result;
        }
        else {
            elementParent->rightChild = result;
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