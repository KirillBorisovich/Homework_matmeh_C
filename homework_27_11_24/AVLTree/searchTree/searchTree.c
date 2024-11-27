#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "searchTree.h"

typedef struct Node {
    NodeValue value;
    int height;
    Node* leftChild;
    Node* rightChild;
} Node;

int getHeight(Node* node) {
    return node == NULL ? -1 : node->height;
}

int updateHeight(Node* node) {
    if (getHeight(node->leftChild) > getHeight(node->rightChild)) {
        return getHeight(node->leftChild) + 1;
    }
    else {
        return getHeight(node->rightChild) + 1;
    }
}

Node* smallLeftTurn(Node** node) {
    Node* tmp = (*node)->rightChild->leftChild;
    Node* b = (*node)->rightChild;
    (*node)->rightChild->leftChild = (*node);
    (*node)->rightChild = tmp;
    return b;
}

Node* smallRightTurn(Node** node) {
    Node* tmp = (*node)->leftChild->rightChild;
    Node* b = (*node)->leftChild;
    (*node)->leftChild->rightChild = *node;
    (*node)->leftChild = tmp;
    return b;
}

Node* bigLeftTurn(Node** node) {
    Node* c = (*node)->rightChild->leftChild;
    (*node)->rightChild->leftChild = c->rightChild;
    c->rightChild = (*node)->rightChild;
    (*node)->rightChild = c->leftChild;
    c->leftChild = (*node);
    c->leftChild->height = updateHeight(c->leftChild);
    c->rightChild->height = updateHeight(c->rightChild);
    c->height = updateHeight(c);
    return c;
}

Node* bigRightTurn(Node** node) {
    Node* c = (*node)->leftChild->rightChild;
    (*node)->leftChild->rightChild = c->leftChild;
    c->leftChild = (*node)->leftChild;
    (*node)->leftChild = c->rightChild;
    c->rightChild = *node;
    c->leftChild->height = updateHeight(c->leftChild);
    c->rightChild->height = updateHeight(c->rightChild);
    c->height = updateHeight(c);
    return c;
}

void treeBalancing(Node** node) {
    if (getHeight((*node)->leftChild) - getHeight((*node)->rightChild) == -2 &&
        getHeight((*node)->rightChild->leftChild) <= getHeight((*node)->rightChild->rightChild)) {
        *node = smallLeftTurn(node);
    }
    else if (getHeight((*node)->leftChild) - getHeight((*node)->rightChild) == 2 &&
        getHeight((*node)->leftChild->rightChild) <= getHeight((*node)->leftChild->leftChild)) {
        *node = smallLeftTurn(node);
    }
    else if (getHeight((*node)->leftChild) - getHeight((*node)->rightChild) == -2 &&
        getHeight((*node)->rightChild->leftChild) > getHeight((*node)->rightChild->rightChild)) {
        *node = bigLeftTurn(node);
    }
    else if (getHeight((*node)->leftChild) - getHeight((*node)->rightChild) == 2 &&
        getHeight((*node)->leftChild->rightChild) > getHeight((*node)->leftChild->leftChild)) {
        *node = bigRightTurn(node);
    }

}

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

void addElementToTree(Node** node, NodeValue value, int* errorCode) {
    if (!strcmp((*node)->value.key, value.key)) {
        deleteElementByKey(node, strtol(value.key, NULL, 10));
        addElementToTree(node, value, errorCode);
    }
    Node* leftChild = (*node)->leftChild;
    Node* rightChild = (*node)->rightChild;
    if (strtol((*node)->value.key, NULL, 10) > strtol(value.key, NULL, 10) && (*node)->leftChild == NULL) {
        Node* element = createNode(value, errorCode);
        addLeftChild(*node, element);
        (*node)->leftChild->height = 0;
    }
    else if (strtol((*node)->value.key, NULL, 10) < strtol(value.key, NULL, 10) && (*node)->rightChild == NULL) {
        Node* element = createNode(value, errorCode);
        addRightChild(*node, element);
        (*node)->rightChild->height = 0;
        (*node)->height = updateHeight(*node);
    }
    else if (strtol((*node)->value.key, NULL, 10) > strtol(value.key, NULL, 10)) {
        addElementToTree(&leftChild, value, errorCode);
    }
    else if (strtol((*node)->value.key, NULL, 10) < strtol(value.key, NULL, 10)) {
        addElementToTree(&rightChild, value, errorCode);
    }
    (*node)->height = updateHeight(*node);
    if (abs(getHeight((*node)->leftChild) - getHeight((*node)->rightChild)) >= 2) {
        treeBalancing(node);
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
    if (node->leftChild != NULL && node->leftChild->leftChild != NULL) {
        getTheMinimumElementOfTheRightNode(node->leftChild);
    }
    else {
        Node* tmp = node->leftChild;
        node->leftChild = node->leftChild->rightChild;
        node->height = updateHeight(node);
        return tmp;
    }
    node->height = updateHeight(node);
}

Node* findElementByKey(Node* node, int key) {
    if (strtol(node->value.key, NULL, 10) == key) {
        return node;
    }
    if (strtol(node->value.key, NULL, 10) > key && node->leftChild != NULL) {
        findElementByKey(node->leftChild, key);
    }
    else if (strtol(node->value.key, NULL, 10) < key && node->rightChild != NULL) {
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
    if (strtol(node->value.key, NULL, 10) == key || node == NULL) {
        return node;
    }
    else if ((node->leftChild != NULL && strtol(node->leftChild->value.key, NULL, 10) == key) || 
        (node->rightChild != NULL && strtol(node->rightChild->value.key, NULL, 10) == key)) {
        return node;
    }
    else if (strtol(node->value.key, NULL, 10) > key && node->leftChild != NULL) {
        findElementByKey(node->leftChild, key);
    }
    else if (strtol(node->value.key, NULL, 10) < key && node->rightChild != NULL) {
        findElementByKey(node->rightChild, key);
    }
    else {
        return NULL;
    }
}

void deleteElementByKey(Node** node, int key) {
    Node* leftChild = (*node)->leftChild;
    Node* rightChild = (*node)->rightChild;
    if (((*node)->leftChild != NULL && strtol((*node)->leftChild->value.key, NULL, 10) == key) ||
        ((*node)->rightChild != NULL && strtol((*node)->rightChild->value.key, NULL, 10) == key)) {
        Node* result = NULL;
        Node* elementParent = *node;
        Node* element = (*node)->leftChild != NULL && 
            strtol(elementParent->leftChild->value.key, NULL, 10) == key ?
            elementParent->leftChild : elementParent->rightChild;
        if (element != NULL) {
            if (element->leftChild == NULL && element->rightChild == NULL) {
                result = NULL;
            }
            else if (element->leftChild != NULL && element->rightChild == NULL) {
                result = element->leftChild;
            }
            else if (element->leftChild == NULL && element->rightChild != NULL) {
                result = element->rightChild;
            }
            else if (element->leftChild != NULL && element->rightChild != NULL) {
                Node* elementReplacement = NULL;
                if (element->rightChild->leftChild != NULL) {
                    elementReplacement = getTheMinimumElementOfTheRightNode(element->rightChild);
                }
                else {
                    elementReplacement = element->rightChild;
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
            if (result != NULL) {
                result->height = updateHeight(result);
            }
            --elementParent->height;
            const char* textKey = element->value.key;
            const char* textValue = element->value.value;
            free(textKey);
            free(textValue);
            free(element);
        }
    }
    else if (strtol((*node)->value.key, NULL, 10) > key && (*node)->leftChild != NULL) {
        deleteElementByKey(&leftChild, key);
    }
    else if (strtol((*node)->value.key, NULL, 10) < key && (*node)->rightChild != NULL) {
        deleteElementByKey(&rightChild, key);
    }
    (*node)->height = updateHeight(*node);
    if (abs(getHeight((*node)->leftChild) - getHeight((*node)->rightChild)) >= 2) {
        treeBalancing(node);
    }
}

void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    const char* textValue = node->value.value;
    const char* textKey = node->value.key;
    free(textKey);
    free(textValue);
    free(node);
}