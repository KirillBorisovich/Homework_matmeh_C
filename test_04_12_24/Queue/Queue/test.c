#include <stdio.h>
#include <stdbool.h>
#include "test.h"
#include "Queue.h"

bool testProgram(int* errorCode) {
    bool result = false;
    Queue* queue = createQueue(errorCode);
    enqueue(queue, 1, errorCode);
    enqueue(queue, 2, errorCode);
    enqueue(queue, 3, errorCode);
    if (dequeue(queue) == 1 && dequeue(queue) == 2 && 
        dequeue(queue) == 3 && *errorCode == 0) {
        result = true;
    }
    deleteQueue(queue);
    return result;
}