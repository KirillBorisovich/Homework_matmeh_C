#include <stdio.h>
#include <stdbool.h>
#include "searchTree.h"
#include "testsSearchTree.h"

bool testCreateNode(Node* node) {
    return node != NULL;
}

bool testAddLeftChildAndGetLeftChild() {
    int errorCode = 0;
    NodeValue value1 = { 1, "qweasd" };
    NodeValue value2 = { 2, "qweaqw" };
    Node* node = createNode(value1, &errorCode);
    Node* child = createNode(value2, &errorCode);
    addLeftChild(node, child);
    bool result = getLeftChild(node) == child ? true : false;
    deleteTree(node);
    return result && errorCode == 0;
}

bool testAddRightChildAndGetRightChild() {
    int errorCode = 0;
    NodeValue value1 = { 1, "qweasd" };
    NodeValue value2 = { 2, "qweaqw" };
    Node* node = createNode(value1, &errorCode);
    Node* child = createNode(value2, &errorCode);
    addRightChild(node, child);
    bool result = getRightChild(node) == child ? true : false;
    deleteTree(node);
    return result && errorCode == 0;
}

bool testGetValue(Node* node) {
    return getValue(node).key == 1;
}

bool testAddElementToTree(Node* node, int* errorCode) {
    bool result = false;
    Node* child1 = getRightChild(node);
    Node* child2 = getLeftChild(child1);
    Node* child3 = getRightChild(child2);
    if (getValue(node).key == 1 && getValue(child1).key == 5 &&
        getValue(child2).key == 3 && getValue(child3).key == 4) {
        result = true;
    }
    return result;
}

bool testFindElementByKey(Node* node, int* errorCode) {
    bool result = false;
    Node* child1 = getRightChild(node);
    Node* child2 = getLeftChild(child1);
    Node* child3 = getRightChild(child2);
    if (findElementByKey(node, 1) == node && findElementByKey(node, 5) == child1 &&
        findElementByKey(node, 3) == child2 && findElementByKey(node, 4) == child3 &&
        findElementByKey(node, 123) == NULL) {
        result = true;
    }
    return result;
}

bool testGetTheMinimumElementOfTheRightNode(Node* node, int* errorCode) {
    return getValue(getTheMinimumElementOfTheRightNode(node)).key == 3;
}

bool testDeleteElementByKey(Node* node) {
    deleteElementByKey(node, 5);
    Node* child1 = getRightChild(node);
    Node* child2 = getRightChild(child1);

    return getValue(child1).key == 3 && getValue(child2).key == 4;
}

bool testTree() {
    int errorCode = 0;
    NodeValue value1 = { 1, "qweasd1" };
    Node* node = createNode(value1, &errorCode);
    NodeValue value2 = { 5, "qweasd2" };
    NodeValue value3 = { 3, "qweasd3" };
    NodeValue value4 = { 4, "qweasd4" };
    addElementToTree(node, value2, &errorCode);
    addElementToTree(node, value3, &errorCode);
    addElementToTree(node, value4, &errorCode);
    return testCreateNode(node) && testAddLeftChildAndGetLeftChild() &&
        testAddRightChildAndGetRightChild() && testGetValue(node) && testAddElementToTree(node, &errorCode) &&
        testFindElementByKey(node, &errorCode) && 
        testGetTheMinimumElementOfTheRightNode(node, &errorCode) &&
        testDeleteElementByKey(node) && errorCode == 0;
}