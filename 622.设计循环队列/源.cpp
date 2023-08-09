#include<iostream>
#include<assert.h>

typedef struct {
    int front;
    int rear;
    int k;
    int* nums;

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* con = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    con->front = con->rear = 0;
    con->k = k;
    con->nums = (int*)malloc(sizeof(int) * (k + 1));
    return con;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return 0;
    obj->nums[obj->rear] = value;
    obj->rear++;
    obj->rear %= (obj->k + 1);
    return 1;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return 0;
    obj->front++;
    obj->front %= (obj->k + 1);
    return 1;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->nums[obj->front];

}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->nums[(obj->rear + obj->k) % (obj->k + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->nums);
    free(obj);
}