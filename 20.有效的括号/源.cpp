#include<iostream>
#include<assert.h>

#define MaxSize 10
// ֧�ֶ�̬������ջ
typedef char STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;

// ��ʼ��ջ 
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
