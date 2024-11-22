#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "searchTree.h"

typedef struct Node {
    NodeValue value;
    int height;
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
        if (node->value.value != NULL) {
            free(node->value.value);
        }
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
    while (minElement->leftChild != NULL && minElement->leftChild->leftChild != NULL) {
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

Node* findElementByKeyFromRemove(Node* node, int key) {
    if (node->leftChild != NULL && node->leftChild->value.key == key) {
        return node;
    }
    else if (node->rightChild != NULL && node->rightChild->value.key == key) {
        return node;
    }
    else if (node->value.key > key && node->leftChild != NULL) {
        findElementByKeyFromRemove(node->leftChild, key);
    }
    else if (node->value.key < key && node->rightChild != NULL) {
        findElementByKeyFromRemove(node->rightChild, key);
    }
    else {
        return NULL;
    }
}
void deleteElementByKey(Node* node, int key) {
    Node* elementParent = findElementByKeyFromRemove(node, key);
    bool right = false;
    Node* element = NULL;
    if (elementParent->leftChild != NULL && elementParent->leftChild->value.key == key) {
        element = elementParent->leftChild;
    }
    else if (elementParent->rightChild != NULL && elementParent->rightChild->value.key == key) {
        element = elementParent->rightChild;
        right = true;
    }
    if (element != NULL) {
        if (element->leftChild == NULL && element->rightChild == NULL) {
            if (right) {
                elementParent->rightChild = NULL;
            }
            else {
                elementParent->leftChild = NULL;
            }
        }
        else if (element->leftChild != NULL && element->rightChild == NULL) {
            if (right) {
                elementParent->rightChild = element->leftChild;
            }
            else {
                elementParent->leftChild = element->leftChild;
            }
        }
        else if (element->leftChild == NULL && element->rightChild != NULL) {
            if (right) {
                elementParent->rightChild = element->rightChild;
            }
            else {
                elementParent->leftChild = element->rightChild;
            }
        }
        else if (element->leftChild != NULL && element->rightChild != NULL) {
            Node* elementParentReplacement = getTheMinimumElementOfTheRightNode(element);
            if (elementParentReplacement->leftChild == NULL) {
                elementParentReplacement->leftChild = element->leftChild;
                if (right) {
                    elementParent->rightChild = elementParentReplacement;
                }
                else {
                    elementParent->leftChild = elementParentReplacement;
                }
            }
            else {
                Node* elementReplacement = elementParentReplacement->leftChild;
                elementParentReplacement->rightChild = elementReplacement->rightChild;
                elementReplacement->leftChild = element->leftChild;
                elementReplacement->rightChild = element->rightChild;
                if (right) {
                    elementParent->rightChild = element;
                }
                else {
                    elementParent->leftChild = element;
                }
            }
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