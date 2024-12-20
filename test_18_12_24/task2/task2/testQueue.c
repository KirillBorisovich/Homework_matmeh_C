#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "testQueue.h"

bool testQueue() {
    bool result = false;
    int errorCode = 0;
    Queue* queue = createQueue(&errorCode);
    enqueue(queue, 1, &errorCode);
    enqueue(queue, 2, &errorCode);
    enqueue(queue, 3, &errorCode);
    if (dequeue(queue, &errorCode) == 1 && 
        dequeue(queue, &errorCode) == 2 && 
        dequeue(queue, &errorCode) == 3 &&
        isEmptyQueue(queue)) {
        result = true;
    }
    deleteQueue(queue);
    return result && errorCode == 0;
}