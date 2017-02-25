
/*!
 * \file �㷨֮��--4.3.3 Լɪ������.cpp
 *
 * \author ranjiewen
 * \date 2017/02/25 14:31
 *
 * ��ѭ�������ʹ��
 */

#include<stdio.h>
#include <malloc.h>

#include <iostream>
using namespace std;
#include <list>

//ʹ��STL��׼��
int Josephusproblem(int n, int m)
{
	if (n<1||m<1)
	{
		return -1;
	}
	list<int> listInt;
	for (int i = 0; i < n;i++)
	{
		listInt.push_back(i+1);
	}
	list<int>::iterator iteCur = listInt.begin();
	while (listInt.size()>1)
	{
		//ǰ��m-1��
		for (int i = 0; i < m - 1;i++)  //0��ʼ
		{
			iteCur++;
			if (iteCur==listInt.end())
			{
				iteCur = listInt.begin();// ѭ������
			}
		}
		//��ʱ����ɾ���Ľڵ�
		list<int>::iterator iteDel = iteCur;
		if (++iteCur==listInt.end())
		{
			iteCur = listInt.begin();
		}
		cout << *iteDel << " ";
		listInt.erase(iteDel);
	}
	cout << endl;
	return *iteCur;
}



typedef struct List
{
	int data;
	struct List* pNext;

	struct List(int data_ = 0, struct List* pNext_ = nullptr){ data = data_; pNext = pNext_; }

}CirSinglist;


int main()
{
	CirSinglist *pHead, *pCur, *pTemp;
	pHead = (CirSinglist*)malloc(sizeof(CirSinglist));
	pCur = pHead;
	int n, m;
	printf("����� n��m��ֵ��\n");
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n;i++) //��������
	{
		pTemp = (CirSinglist*)malloc(sizeof(CirSinglist));
		pTemp->data = i;
		pTemp->pNext = nullptr;
		pCur->pNext = pTemp;
		pCur = pTemp;
	}
	pCur->pNext = pHead->pNext;

	//��ʼģ����Ϸ
	CirSinglist *p;
	p = pHead->pNext;
	while (p->pNext!=p)
	{
		for (int i = 1; i < m - 1;i++) //ɾ���ڵ��ǰһ�ڵ�
		{
			p = p->pNext;
		}
		//����ɾ������
		printf("%d ", p->pNext->data);

		p->pNext = p->pNext->pNext;
		//�ƶ�ָ��p
		p = p->pNext;
	}
	printf("\nlast win num:%d \n", p->data);

	cout << "ʹ�ñ�׼�⺯����" << endl;
	cout << "last win :"<<Josephusproblem(n, m) << endl;

	return 0;
}

