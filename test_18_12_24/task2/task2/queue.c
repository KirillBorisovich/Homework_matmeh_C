#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "queue.h"

typedef struct Queue {
    Stack* stack1;
    Stack* stack2;
} Queue;

Queue* createQueue(int* errorCode) {
    Queue* queue = calloc(1, sizeof(Queue));
    if (queue == NULL) {
        *errorCode = 1;
        return NULL;
    }
    queue->stack1 = createStack(errorCode);
    queue->stack2 = createStack(errorCode);
    return queue;
}

void enqueue(Queue* queue, int value, int* errorCode) {
    push(queue->stack1, value, errorCode);
}

int dequeue(Queue* queue, int* errorCode) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, getValue(queue->stack1), errorCode);
            pop(queue->stack1);
        }
    }
    int result = getValue(queue->stack2);
    pop(queue->stack2);
    return result;
}

bool isEmptyQueue(Queue* queue) {
    return isEmpty(queue->stack1) && isEmpty(queue->stack2);
}

void deleteQueue(Queue* queue) {
    deleteStack(queue->stack1);
    deleteStack(queue->stack2);
    free(queue);
}