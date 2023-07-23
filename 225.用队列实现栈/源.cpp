#include<iostream>
#include<assert.h>

// 链式结构:表示队列
typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;


void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);


void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

// 队头入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newQNode = (QNode*)malloc(sizeof(QNode));
	if (!newQNode)
	{
		perror("malloc_error!");
		return;
	}
	newQNode->_data = data;
	newQNode->_next = NULL;
	if (!q->_front)
	{
		q->_front = q->_rear = newQNode;
	}
	else
	{
		q->_rear->_next = newQNode;
		q->_rear = q->_rear->_next;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_rear);
	QNode* s = q->_front;
	if (!q->_front->_next)
	{
		free(s);
		q->_front = q->_rear = NULL;
	}
	else
	{
		q->_front = s->_next;
		free(s);
	}
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	if (q->_front)
		return q->_front->_data;
	return 0;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (q->_rear)
		return q->_rear->_data;
	return 0;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QNode* s = q->_front;
	while (s)
	{
		count++;
		s = s->_next;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (!q->_front)
		return 1;
	return 0;
}


// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->_front, * s = NULL;
	while (cur)
	{
		s = cur->_next;
		free(cur);
		cur = s;
	}
}










typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&obj->q1);
	QueueInit(&obj->q2);
	return obj;
}

void myStackPush(MyStack* obj, int x) {
	if (QueueEmpty(&obj->q1))
		QueuePush(&obj->q2, x);
	else
		QueuePush(&obj->q1, x);
}

int myStackPop(MyStack* obj) {
	Queue* EmptyQueue = &obj->q1;
	Queue* NoEmptyQueue = &obj->q2;
	if (!QueueEmpty(EmptyQueue))
	{
		EmptyQueue = &obj->q2;
		NoEmptyQueue = &obj->q1;
	}
	while (QueueSize(NoEmptyQueue) > 1)
	{
		QueuePush(EmptyQueue, QueueFront(NoEmptyQueue));
		QueuePop(NoEmptyQueue);
	}
	int num = QueueFront(NoEmptyQueue);
	QueuePop(NoEmptyQueue);
	return num;
}

int myStackTop(MyStack* obj) {
	if (QueueEmpty(&obj->q1))
		return QueueBack(&obj->q2);
	else
		return QueueBack(&obj->q1);
	return 0;
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}