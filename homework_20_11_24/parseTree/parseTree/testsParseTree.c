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

bool testSplitArithmeticExpression(int* errorCode) {
    bool result = false;
    char* testString = calloc(20, sizeof(char));
    if (testString == NULL) {
        *errorCode = 1;
        return false;
    }
    strcpy_s(testString, 20, "( * ( + 1 2 ) 2 )");
    int index = 0;
    Node* node = splitArithmeticExpression(testString, &index, errorCode);
    if (!strcmp(getValue(node), "*") && !strcmp(getValue(getLeftChild(node)), "+") &&
        !strcmp(getValue(getLeftChild(getLeftChild(node))), "1") &&
        !strcmp(getValue(getRightChild(getLeftChild(node))), "2") &&
        !strcmp(getValue(getRightChild(node)), "2")) {
        result = true;
    }
    deleteTree(node);
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
        testAddRightChildAndGetRightChild() && testGetValue(node) && 
        testSplitArithmeticExpression(&errorCode)) {
        result = true;
    }
    deleteTree(node);
    return result && errorCode == 0;
}