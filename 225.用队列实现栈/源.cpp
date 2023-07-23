#include<iostream>
#include<assert.h>

// ��ʽ�ṹ:��ʾ����
typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;


void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);


void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

// ��ͷ����� 
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

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	if (q->_front)
		return q->_front->_data;
	return 0;
}

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (q->_rear)
		return q->_rear->_data;
	return 0;
}

// ��ȡ��������ЧԪ�ظ��� 
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (!q->_front)
		return 1;
	return 0;
}


// ���ٶ��� 
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