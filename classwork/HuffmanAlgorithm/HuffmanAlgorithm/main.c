#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

typedef struct {
    bool code[256];
    int length;
} CodeEntry;

NodeValue createValue(char value, int frequency) {
    NodeValue nodeValue = { .value = value, .frequency = frequency };
    return nodeValue;
}

void printNode(Node* node) {
    NodeValue value = getValue(node);
    printf("'%c': %d\n", value.value, value.frequency);
}

void fillOfArrayOfFrequencies(int arrayOfFrequencies[], char* string) {
    for (int i = 0; i < strlen(string); ++i) {
        unsigned char index = string[i];
        ++arrayOfFrequencies[index];
    }
}


int fillOfArrayOfNode(Node* arrayOfNode[], int arrayOfFrequencies[]) {
    int notNull = 0;
    for (int i = 0; i < 256; ++i) {
        if (arrayOfFrequencies[i] == 0) {
            continue;
        }
        NodeValue value = createValue(i, arrayOfFrequencies[i]);
        arrayOfNode[i] = createNode(value);
        ++notNull;
    }
    return notNull;
}

int getMinIndex(Node** arrayOfNode) {
    int minIndexElement = -1;
    for (int i = 0; i < 256; ++i) {
        if (arrayOfNode[i] == NULL) {
            continue;
        }
        int frequency = getValue(arrayOfNode[i]).frequency;
        if (minIndexElement == -1) {
            minIndexElement = i;
            continue;
        }
        if (frequency < getValue(arrayOfNode[minIndexElement]).frequency) {
            minIndexElement = i;
        }
    }
    return minIndexElement;
}

Node* getRootNode(Node* arrayOfNode[], int notNull) {
    while (notNull > 1) {
        const int firstIndexMinElement = getMinIndex(arrayOfNode);
        Node* firstMinNode = arrayOfNode[firstIndexMinElement];
        arrayOfNode[firstIndexMinElement] = NULL;

        const int secondIndexMinElement = getMinIndex(arrayOfNode);
        Node* secondMinNode = arrayOfNode[secondIndexMinElement];

        const int newFrequency = getValue(firstMinNode).frequency + getValue(secondMinNode).frequency;
        Node* newNode = createNode(createValue('\0', newFrequency));
        addLeftChild(newNode, firstMinNode);
        addRightChild(newNode, secondMinNode);
        arrayOfNode[secondIndexMinElement] = newNode;

        --notNull;
    }

    Node* rootNode = NULL;
    for (int i = 0; i < 256; ++i) {
        if (arrayOfNode[i] == NULL) {
            continue;
        }
        rootNode = arrayOfNode[i];
        break;
    }

    return rootNode;
}

void writeToCodeTable(Node* currentNode, bool currentCode[], int currentCodeLength, CodeEntry codeTable[]) {
    if (getLeftChild(currentNode) == NULL && getRightChild(currentNode) == NULL) {
        const unsigned char value = getValue(currentNode).value;
        for (int i = 0; i < currentCodeLength; ++i) {
            codeTable[value].code[i] = currentCode[i];
        }
        codeTable[value].length = currentCodeLength;
        return;
    }
    currentCode[currentCodeLength] = false;
    writeToCodeTable(getLeftChild(currentNode), currentCode, currentCodeLength + 1, codeTable);
    currentCode[currentCodeLength] = true;
    writeToCodeTable(getRightChild(currentNode), currentCode, currentCodeLength + 1, codeTable);
}

int main(void) {
    const char* string = "abccccccdeeee";
    int arrayOfFrequencies[256] = { 0 };
    fillOfArrayOfFrequencies(arrayOfFrequencies, string);

    Node* arrayOfNode[256] = { NULL };
    int notNull = fillOfArrayOfNode(arrayOfNode, arrayOfFrequencies);

    Node* rootNode = getRootNode(arrayOfNode, notNull);

    printNode(rootNode);

    CodeEntry codeTable[256] = { 0 };
    bool currentCode[256] = { false };
    writeToCodeTable(rootNode, currentCode, 0, codeTable);
    for (int i = 0; i < 256; ++i) {
        if (codeTable[i].length == 0) {
            continue;
        }
        printf("value: %c; ", (char)i);
        for (int j = 0; j < codeTable[i].length; ++j) {
            printf("%d ", codeTable[i].code[j] ? 1 : 0);
        }
        printf("\n");
    }
}