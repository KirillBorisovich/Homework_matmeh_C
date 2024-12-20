#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "queue.h"
#include "testQueue.h"

bool testQueue() {
    bool result = false;
    int errorCode = 0;
    Queue* queue = createQueue(&errorCode);
    Value value1 = { NULL, 1 };
    Value value2 = { NULL, 2 };
    Value value3 = { NULL, 3 };
    enqueue(queue, value1, &errorCode);
    enqueue(queue, value2, &errorCode);
    enqueue(queue, value3, &errorCode);
    if (dequeue(queue, &errorCode).length == 1 &&
        dequeue(queue, &errorCode).length == 2 &&
        dequeue(queue, &errorCode).length == 3 &&
        isEmptyQueue(queue)) {
        result = true;
    }
    deleteQueue(queue);
    return result && errorCode == 0;
}