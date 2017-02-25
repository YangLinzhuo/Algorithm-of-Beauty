/*!
 * \file �㷨֮��--4.3.5 ������������.cpp
 *
 * \author ranjiewen
 * \date 2017/02/25 17:02
 *
 * 
 */

/************************************************************************/
/* ������������
 ������д������
 ����������һ��n��n�ķ��󣬷�����ǡ��n�ֲ�ͬ��Ԫ�أ�ÿ��Ԫ��ǡ��n��������ÿ��Ԫ����һ�к�һ���� ǡ�ó���һ�Ρ�
 ������ѧ�Һ�����ѧ��ŷ��ʹ��������ĸ����Ϊ����������Ԫ�صķ��ţ�����������˶�������
 ����:
 1      2      3
 2      3      1
 3      1      2
 ���⣺��������N����������                                              */               
/************************************************************************/

////��ͨ����,��N��ȫ����������
//#include <iostream>
//using namespace std;
//
//#define N 6
//int main()
//{
//	int i, j, k, t;
//	printf("The possible Latin Squares of order %d are:\n", N);
//	for (j = 0; j < N;j++) /*����N����ͬ����������*/
//	{
//		for (i = 0; i < N;i++)
//		{
//			t = (i + j) % N; /*ȷ�������������i �еĵ�һ��Ԫ�ص�ֵ*/
//			for (k = 0; k < N; k++) /*���ջ�����ʽ��������еĸ���Ԫ��*/
//				cout << (k + t) % N + 1;
//			cout << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
}Node;

typedef struct Node* LinkList;

//����һ������N���ڵ��ѭ������
Node* CreateList(Node* L, int n)
{
	Node *pCur, *pTemp;
	L = (LinkList)malloc(sizeof(Node));
	L->pNext = nullptr;
	pCur = L;//��ǰ�ڵ�ָ���ͷ
	for (int i = 1; i <= n;i++)
	{
		pTemp = (LinkList)malloc(sizeof(Node));
		pTemp->data = i;
		pTemp->pNext = pCur->pNext;
		pCur->pNext = pTemp;
		pCur = pTemp;  //��β������
	}
	pCur->pNext = L->pNext; //ѭ���ṹ
	return L->pNext;
}

//ʵ��������������
void print(struct Node *La, int n)
{
	int i, j;
	struct Node *p, *q;
	p = La;
	for (i = 1; i <= n; i++)
	{
		q = p;
		for (j = 1; j <= n; j++)
		{
			printf("%3d", q->data);
			q = q->pNext;
		}
		printf("\n");
		p = p->pNext;
	}
}

int main(int argc, char* argv[])
{
	int m;
	struct Node *L=nullptr, *t=nullptr;
	//while (1)
	{
		printf("****************************************************\n");
		printf("*****          ESC����    �˳�����             *****\n");
		printf("*****                                          *****\n");
		printf("*****          �������������ӡdf��������        *****\n");
		printf("****************************************************\n");
		/*	if (_getch() == 27)
				break;
				else*/
		{
			printf("\n��������Ҫ��ӡ�����������ģ��Ҫ��ӡ����������\n\n");
			scanf("%d", &m);
			L = CreateList(L, m);
			printf("\n������Ĺ�ģΪ%d����ӡ�ķ������£�\n\n", m);
			print(L, m);
			printf("\n�����������������\n");
			_getch();
			system("cls");
		}
	}
	return 0;
}






