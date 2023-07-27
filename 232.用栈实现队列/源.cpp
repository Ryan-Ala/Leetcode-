#include<iostream>
#include<assert.h>

#define MaxSize 10

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;


void StackInit(Stack* ps);

// 入栈 
void StackPush(Stack* ps, STDataType data);

// 出栈 
void StackPop(Stack* ps);

// 获取栈顶元素 
STDataType StackTop(Stack* ps);

// 获取栈中有效元素个数 
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);

// 销毁栈 
void StackDestroy(Stack* ps);

//初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_capacity = MaxSize;
	ps->_top = -1;
	STDataType* Array = (STDataType*)malloc(sizeof(STDataType) * MaxSize);
	assert(Array);
	ps->_a = Array;
}

//入栈
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

//出栈
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

//获取栈顶元素
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

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top + 1;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return !StackSize(ps);
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	ps->_capacity = 0;
	ps->_top = 0;
	free(ps->_a);
	ps->_a = NULL;
}





//双栈实现

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