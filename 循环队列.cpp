/*!
 * \file ѭ������.cpp
 *
 * \author ranjiewen
 * \date 2017/02/25 20:23
 *
 * ѭ������������ʵ�֣��ﵽ�ڴ����ú�
 */

#include<stdio.h>
#include<stdlib.h>
#include "malloc.h"

#define  N  8

typedef struct queue
{
	int *pBase;  // ����ͷָ��
	int front;   //ָ����е�һ��Ԫ��
	int rear;    //ָ����е����һ��Ԫ�ص���һ��Ԫ��
	int maxsize;
	struct queue(){ pBase = nullptr, front = rear = maxsize = 0; }
}Queque,*LinkQueque;  


void CreateQueque(LinkQueque Q,int maxsize);
void TraverseQueque(LinkQueque Q);
bool FullQueque(LinkQueque Q);
bool EmptyQueque(LinkQueque Q);
bool EnQueque(LinkQueque Q, int val);
bool DeQueque(LinkQueque Q,int *val);


int main()
{
	Queque q; 
	LinkQueque Q=&q;    //��ʼ������
	CreateQueque(Q, N);
	for (int i = 1; i <= 6;i++)
	{
		EnQueque(Q, i);
	}
	TraverseQueque(Q);
	EnQueque(Q, 10);
	if (FullQueque(Q))
	{
		TraverseQueque(Q);
		printf("������...\n");
	}
	int del_data=0;
	if (DeQueque(Q,&del_data))
	{
		printf("�����гɹ�����ֵΪ��%d\n", del_data);
	}
	TraverseQueque(Q);

	return 0;
}

void CreateQueque(LinkQueque Q, int maxsize)
{
	Q->pBase = (int*)malloc(sizeof(int)*maxsize);
	if (Q->pBase==nullptr)
	{
		printf("Memory allocation failure...");
		exit(-1);
	}
	Q->front = 0; //��ʼ������
	Q->rear = 0;
	Q->maxsize = maxsize;
}

void TraverseQueque(LinkQueque Q)
{
	int i = Q->front;
	printf("�����е�Ԫ��Ϊ��\n");
	while (i%Q->maxsize!=Q->rear)
	{
		printf("%d ", Q->pBase[i]);
		i=(i+1)%Q->maxsize;
	}
	printf("\n");
}

bool FullQueque(LinkQueque Q)
{
	if (Q->front == (Q->rear + 1) % Q->maxsize)    //�ж�ѭ�������Ƿ�������һ��Ԥ���ռ䲻��
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EmptyQueque(LinkQueque Q)
{
	if (Q->rear==Q->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EnQueque(LinkQueque Q, int val)
{
	if (FullQueque(Q))
	{
		return false;
	}
	else
	{
		Q->pBase[Q->rear] = val;
		Q->rear = (Q->rear + 1) % Q->maxsize;
		return true;
	}
}

bool DeQueque(LinkQueque Q, int *val)
{
	if (EmptyQueque(Q))
	{
		return false;
	}
	else
	{
		*val = Q->pBase[Q->front];
		Q->front = (Q->front + 1) % Q->maxsize;
		return true;
	}
}