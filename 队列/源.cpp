#include<iostream>
#define Queuesize 5
typedef int Datatype;
typedef struct Queue   //队列结构体
{
	Datatype data[Queuesize];
	int front, rear;
}Queue;
                                                       //((Q->rear + 1) % Queuesize == Q->front)  判满 
                                                       //(Q->rear == Q->front)  //判空
void InitQueue(Queue* Q) //初始化队列
{
	Q->front =Q-> rear = -1;
	//或者为  Q->front =Q-> rear = Queuesize - 1  ;
}
int EnQueue(Queue* Q, Datatype x)  //插入队列，入队操作
{
	if ((Q->rear + 1)%Queuesize == Q->front)   //判断是否为满
	{
		std::cout << "队列已满，上溢错误，插入失败!" << std::endl;
		return 0;
	}
	Q->rear += 1 % Queuesize;     //加 1 取余，使其可以成为循环操作
	Q->data[Q->rear] = x;
	std::cout << "入队成功!" << std::endl;
	return 1;
}
int DeQueue(Queue* Q, Datatype* ptr)  //出队操作
{
	if (Q->rear == Q->front)
	{
		std::cout << "队列为空,下溢错误,出队失败!" << std::endl;
		return 0;
	}
	Q->front += 1 % Queuesize;     //加 1 取余，使其可以成为循环操作
	*ptr = Q->data[Q->front];
	std::cout << "出队成功!" << std::endl;
	return 1;
}
int GetHead(Queue* Q, Datatype* ptr)  //取队头操作
{
	if (Q->rear == Q->front)  //判空
	{
		std::cout << "队列为空,无队头!" << std::endl;
		return 0;
	}
	int i = (Q->front + 1) % Queuesize;    //加 1 取余，使其可以成为循环操作
	*ptr = Q->data[i];
	return 1;
}
int Empty(Queue* Q)  //判空操作
{
	if (Q->rear == Q->front)  //判空
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int arr[] = { 1,2,3,4 }, a;
	Queue con;
	InitQueue(&con);
	for (int i = 0; i < 4; i++)
	{
		EnQueue(&con, 4);
	}
	for (int i = 0; i < 4; i++)
	{
		DeQueue(&con, &a);
		std::cout << a << "  ";
	}
}