#include<iostream>
#include<assert.h>

#define MaxSize 10
// 支持动态增长的栈
typedef char STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

// 初始化栈 
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


bool isValid(char* s) {
	Stack st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
		}
		else
		{
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return 0;
			}
			char temp = StackTop(&st);
			StackPop(&st);
			if ((temp == '(' && *s == ')') || (temp == '[' && *s == ']') || (temp == '{' && *s == '}'))
			{
				;
			}
			else
			{
				StackDestroy(&st);
				return 0;
			}
		}
		s++;
	}
	if (StackEmpty(&st))
		return 1;
	StackDestroy(&st);
	return 0;
}
