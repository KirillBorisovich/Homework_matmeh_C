#pragma once

// Structure for the abstract data type "Queue"
typedef struct Queue Queue;

// Create a queue
Queue* createQueue(int* errorCode);

// Get element from head
int dequeue(Queue* queue);

// Add an element to the tail
void enqueue(Queue* queue, int value, int* errorCode);

// Delete queue
void deleteQueue(Queue* queue);