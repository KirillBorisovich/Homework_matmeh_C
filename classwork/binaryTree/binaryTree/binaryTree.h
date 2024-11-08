#pragma once

typedef struct Node Node;

typedef struct Tree Tree;

Tree* createTree(void);

Tree* createNode(int value);

Tree* addLeftChild(Node* node);