#include<iostream>
#include<assert.h>

#define MaxSize 10

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;


void StackInit(Stack* ps);

// ��ջ 
void StackPush(Stack* ps, STDataType data);

// ��ջ 
void StackPop(Stack* ps);

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);

// ����ջ 
void StackDestroy(Stack* ps);

//��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_capacity = MaxSize;
	ps->_top = -1;
	STDataType* Array = (STDataType*)malloc(sizeof(STDataType) * MaxSize);
	assert(Array);
	ps->_a = Array;
}

//��ջ
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top + 1 == ps->_capacity)
	{
		STDataType* Array = (STDataType*)realloc(ps->_a, sizeof(STDataType) * (MaxSize + ps->_capacity));
		if (!Array)
		{
			perror("realloc fail");
			return;
		}
		ps->_a = Array;
		ps->_capacity += MaxSize;
	}
	ps->_a[++ps->_top] = data;
}

//��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	if (StackEmpty(ps))
	{
		return;
	}
	else
		ps->_top--;
}

//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	if (ps->_top == -1)
	{
		return 0;
	}
	else
	{
		return ps->_a[ps->_top];
	}
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top + 1;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return !StackSize(ps);
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	ps->_capacity = 0;
	ps->_top = 0;
	free(ps->_a);
	ps->_a = NULL;
}





//˫ջʵ��

typedef struct {
	Stack Pop_Stack;
	Stack Push_Stack;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&obj->Pop_Stack);
	StackInit(&obj->Push_Stack);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->Push_Stack, x);
}

int myQueuePop(MyQueue* obj) {
	int num = myQueuePeek(obj);
	StackPop(&obj->Pop_Stack);
	return num;
}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->Pop_Stack))
	{
		while (!StackEmpty(&obj->Push_Stack))
		{
			StackPush(&obj->Pop_Stack, StackTop(&obj->Push_Stack));
			StackPop(&obj->Push_Stack);
		}
	}
	return StackTop(&obj->Pop_Stack);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->Pop_Stack) && StackEmpty(&obj->Push_Stack);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->Pop_Stack);
	StackDestroy(&obj->Push_Stack);
	free(obj);
}