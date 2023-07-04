#pragma once
typedef unsigned int T;

class Stack
{
private:
	enum {MAX=10};
	T stack[MAX];
	int p=0;

public:
	bool isempty();  //jia
	bool isfull();
	void push(T &a);
	void pop(T &a);
};