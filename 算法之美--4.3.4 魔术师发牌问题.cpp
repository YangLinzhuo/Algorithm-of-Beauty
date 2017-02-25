/*!
 * \file �㷨֮��--4.3.4 ħ��ʦ��������.cpp
 * \date 2017/02/25 15:58
 *
 * \author ranjiewen
 *
 * \brief ������д������
			 ħ��ʦ������A��2��3����J��Q��Kʮ���ź����˿��ơ��ڱ���ħ��ǰ��ħ��ʦ�Ѿ�����������һ����˳����źã��л�ɫ��һ�泯�£���
			 ħ�����ݹ���Ϊ��һ�_ʼ��ħ��ʦ��1��Ȼ���������������Ʒ��������Ǻ���A��Ȼ����ŵ������ϣ��ڶ���,ħ��ʦ��1��2��
			 ����һ���Ʒŵ���Щ�Ƶ������£����ڶ����Ʒ�ת�����������Ǻ���2�������Σ�ħ��ʦ��1��2��3������1��2�������ηŵ���Щ�Ƶ������£����������Ʒ����������Ǻ���3��
			 ����ֱ����ȫ�����ƶ�������Ϊֹ����ԭ���Ƶ�˳���������ġ�
 *
 * TODO: long description
 *
 * \note
*/

#include <iostream>
using namespace std;

#define N 13

typedef struct Node
{
	int data;
	Node* pNext;
	Node(int data_ = 0, Node* pNext_ = nullptr) :data(data_), pNext(pNext_){}
}Node,*LinkList;




void InitLinkList(LinkList&L,int n) //��������ʼ��ѭ������L��ʾ��ͷ�ڵ㣬n�����ڵ�Ԫ�صĸ���
{
	L = (Node*)malloc(sizeof(Node));
	L->pNext = L; //ͷ���ѭ��
	LinkList p;
	for (int j = 0; j < n; j++)  //һֱ��ͷ������
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = 0;
		p->pNext = L->pNext;//����ڵ�ָ��ͷ���
		L->pNext = p; //ͷ���ָ���µĽڵ�
	}
	return;
}

void Magician(LinkList& L, int n) //ħ��ʦ�������
{
	LinkList p = L->pNext;
	p->data = 1;//��һ��Ϊ1��
	for (int num = 2; num <= n;num++) //�����ҵ�2-n�Ƶ�λ��
	{
		int i = 0;
		while (i<num)
		{
			p = p->pNext;
			if (p->data==0) //�������Ƶ�λ�ã�û���ƵĲż�1
			{
				i++;
			}
		}
		p->data = num;
	}
}

void Print(LinkList&L)
{
	LinkList p = L->pNext;
	cout << "Print:";
	while (p!=L)
	{
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}

int main()
{
	LinkList L;
	InitLinkList(L,N);
	Magician(L,N);
	Print(L);
	return 0;
}