#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000

typedef struct {
    int s1[SIZE];
    int s2[SIZE];
    int top1;
    int top2;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

/** Move elements from s1 to s2 */
void transfer(MyQueue* obj) {
    while (obj->top1 != -1) {
        obj->s2[++obj->top2] = obj->s1[obj->top1--];
    }
}

/** Removes the element from front of queue */
int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        transfer(obj);
    }
    return obj->s2[obj->top2--];
}

/** Get the front element */
int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        transfer(obj);
    }
    return obj->s2[obj->top2];
}

/** Check if queue is empty */
bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

/** Free memory */
void myQueueFree(MyQueue* obj) {
    free(obj);
}
