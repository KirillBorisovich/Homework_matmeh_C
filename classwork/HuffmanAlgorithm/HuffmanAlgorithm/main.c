#include <stdio.h>
#include "tree.h"

NodeValue createValue(char value, int frequency) {
    NodeValue nodeValue = { .value = value, .frequency = frequency };
    return nodeValue;
}

void printNode(Node* node) {
    NodeValue value = getValue(node);
    printf("'%c': %d\n", value.value, value.frequency);
}

int main(void) {
    Node* root = createNode(createValue('\0', -1));
    Node* left = createNode(createValue('b', 2));
    Node* right = createNode(createValue('c', 5));

    addLeftChild(root, left);
    addRightChild(root, right);

    setValue(root, createValue('P', getValue(left).frequency + getValue(right).frequency));

    printf("all characters:\n");
    printNode(root);
    printNode(getLeftChild(root));
    printNode(getRightChild(root));

    deleteTree(root);
}