#pragma once

typedef struct Queue Queue;

// Create a queue
Queue* createQueue(int* errorCode);

// Add value to queue
void enqueue(Queue* queue, int value, int* errorCode);

// Get value from queue
int dequeue(Queue* queue, int* errorCode);

// Check if the queue is empty
bool isEmptyQueue(Queue* queue);

// Delete queue
void deleteQueue(Queue* queue);