#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "parseTree.h"
#include "testsParseTree.h"

bool testCreateNode(Node* node) {
    return node != NULL;
}

bool testAddLeftChildAndGetLeftChild() {
    int errorCode = 0;
    char* textValue1 = calloc(20, sizeof(char));
    char* textValue2 = calloc(20, sizeof(char));
    if (textValue1 == NULL || textValue2 == NULL) {
        return false;
    }
    strcpy_s(textValue1, 19, "qweasd");
    strcpy_s(textValue2, 19, "qweaqw");
    Node* node = createNode(textValue1, &errorCode);
    Node* child = createNode(textValue2, &errorCode);
    addLeftChild(node, child);
    bool result = getLeftChild(node) == child ? true : false;
    deleteTree(node);
    return result && errorCode == 0;
}

bool testAddRightChildAndGetRightChild() {
    int errorCode = 0;
    char* textValue1 = calloc(20, sizeof(char));
    char* textValue2 = calloc(20, sizeof(char));
    if (textValue1 == NULL || textValue2 == NULL) {
        return false;
    }
    strcpy_s(textValue1, 19, "qweasd");
    strcpy_s(textValue2, 19, "qweaqw");
    Node* node = createNode(textValue1, &errorCode);
    Node* child = createNode(textValue2, &errorCode);
    addRightChild(node, child);
    bool result = getRightChild(node) == child ? true : false;
    deleteTree(node);
    return result && errorCode == 0;
}

bool testGetValue(Node* node) {
    return strcmp(getValue, "qweasd1");
}

bool testAddElementToTree(Node* node, int* errorCode) {
    bool result = false;
    Node* child1 = getRightChild(node);
    Node* child2 = getLeftChild(child1);
    Node* child3 = getRightChild(child2);
    
    if (!strcmp(getValue(node), "qweasd1") && !strcmp(getValue(child1), "qweasd5") &&
        !strcmp(getValue(child2), "qweasd3") && strcmp(getValue(child3), "qweasd4")) {
        result = true;
    }
    return result;
}

bool testTree() {
    bool result = false;
    int errorCode = 0;
    char* textValue1 = calloc(20, sizeof(char));
    if (textValue1 == NULL) {
        return false;
    }
    strcpy_s(textValue1, 19, "qweasd1");
    Node* node = createNode(textValue1, &errorCode);
    if (testCreateNode(node) && testAddLeftChildAndGetLeftChild() &&
        testAddRightChildAndGetRightChild() && testGetValue(node)) {
        result = true;
    }
    deleteTree(node);
    return result;
}