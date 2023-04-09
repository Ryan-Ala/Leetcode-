#include<iostream>
#define Queuesize 5
typedef int Datatype;
typedef struct Queue   //���нṹ��
{
	Datatype data[Queuesize];
	int front, rear;
}Queue;
                                                       //((Q->rear + 1) % Queuesize == Q->front)  ���� 
                                                       //(Q->rear == Q->front)  //�п�
void InitQueue(Queue* Q) //��ʼ������
{
	Q->front =Q-> rear = -1;
	//����Ϊ  Q->front =Q-> rear = Queuesize - 1  ;
}
int EnQueue(Queue* Q, Datatype x)  //������У���Ӳ���
{
	if ((Q->rear + 1)%Queuesize == Q->front)   //�ж��Ƿ�Ϊ��
	{
		std::cout << "����������������󣬲���ʧ��!" << std::endl;
		return 0;
	}
	Q->rear += 1 % Queuesize;     //�� 1 ȡ�࣬ʹ����Գ�Ϊѭ������
	Q->data[Q->rear] = x;
	std::cout << "��ӳɹ�!" << std::endl;
	return 1;
}
int DeQueue(Queue* Q, Datatype* ptr)  //���Ӳ���
{
	if (Q->rear == Q->front)
	{
		std::cout << "����Ϊ��,�������,����ʧ��!" << std::endl;
		return 0;
	}
	Q->front += 1 % Queuesize;     //�� 1 ȡ�࣬ʹ����Գ�Ϊѭ������
	*ptr = Q->data[Q->front];
	std::cout << "���ӳɹ�!" << std::endl;
	return 1;
}
int GetHead(Queue* Q, Datatype* ptr)  //ȡ��ͷ����
{
	if (Q->rear == Q->front)  //�п�
	{
		std::cout << "����Ϊ��,�޶�ͷ!" << std::endl;
		return 0;
	}
	int i = (Q->front + 1) % Queuesize;    //�� 1 ȡ�࣬ʹ����Գ�Ϊѭ������
	*ptr = Q->data[i];
	return 1;
}
int Empty(Queue* Q)  //�пղ���
{
	if (Q->rear == Q->front)  //�п�
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