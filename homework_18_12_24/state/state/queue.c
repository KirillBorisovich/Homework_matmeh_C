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

void enqueue(Queue* queue, Value value, int* errorCode) {
    push(queue->stack1, value, errorCode);
}

Value dequeue(Queue* queue, int* errorCode) {
    if (isEmptyStack(queue->stack2)) {
        while (!isEmptyStack(queue->stack1)) {
            push(queue->stack2, getValueFromStack(queue->stack1), errorCode);
            pop(queue->stack1);
        }
    }
    Value result = getValueFromStack(queue->stack2);
    pop(queue->stack2);
    return result;
}

bool isEmptyQueue(Queue* queue) {
    return isEmptyStack(queue->stack1) && isEmptyStack(queue->stack2);
}

void deleteQueue(Queue* queue) {
    deleteStack(queue->stack1);
    deleteStack(queue->stack2);
    free(queue);
}