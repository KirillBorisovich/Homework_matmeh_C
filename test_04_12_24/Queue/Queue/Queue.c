#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "Queue.h"

typedef struct Queue {
    int* array;
    int head;
    int tail;
    int maxSize;
} Queue;

Queue* createQueue(int* errorCode) {
    Queue* result = calloc(1, sizeof(Queue));
    if (result == NULL) {
        *errorCode = 1;
        return NULL;
    }
    result->array = calloc(2, sizeof(int));
    if (result->array == NULL) {
        *errorCode = 1;
        return NULL;
    }
    result->head = 0;
    result->tail = 0;
    result->maxSize = 2;
    return result;
}

void deleteQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

int dequeue(Queue* queue) {
    int element = queue->array[queue->head % queue->maxSize];
    ++queue->head;
    return element;
}

void enqueue(Queue* queue, int value, int* errorCode) {
    if (queue->tail - queue->head == queue->maxSize) {
        int* tmp = realloc(queue->array, 2 * sizeof(int));
        queue->maxSize *= 2;
        if (tmp != NULL) {
            queue->array = tmp;
        }
        else {
            *errorCode = 1;
            deleteQueue(queue);
            return;
        }
    }
    queue->array[queue->tail % queue->maxSize] = value;
    ++queue->tail;
}





