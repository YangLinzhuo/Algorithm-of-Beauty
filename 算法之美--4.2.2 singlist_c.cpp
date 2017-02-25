/*!
 * \file singlist_c.cpp
 *
 * \author ranjiewen
 * \date 2017/02/25 12:15
 *
 * 
 */


/*********************************************************************************************************
����Ϊ����������㷨��������Ϊ������
������ͷָ��Ϊ������ͷָ��ָ��ͷ�ڵ㣬ͷ�ڵ�ָ���׽ڵ㣬�Դ����ƣ�ֱ��β�ڵ㡣
ͷ�ڵ��в�������ݣ�ֻ���ָ���׽ڵ��ָ�룬
����ͷ�ڵ��Ŀ����Ϊ�˷��������Ĳ��������������ͷ�ڵ㣬����ֱ����ͷָ��ָ���׽ڵ㣬
�����ڶ�ͷָ���Ľڵ���в���ɾ������ʱ�ͻ��������ڵ���иò���ʱ������ͬ����Ҫ��Ϊһ���������������
**********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
	Node(int data_, Node* pNext_) :data(data_), pNext(pNext_){}

}Node,*pNode;

pNode CreateList();
void TraverseList(pNode);
bool IsEmpty(pNode);
int LengthList(pNode);
void SortList(pNode);
bool InsertList(pNode, int, int);
bool DeleteList(pNode, int, int*);
void ClearList(pNode);

int main()
{
	int len = 0;
	int data_del;
	pNode pHead = nullptr;
	//���������������
	pHead = CreateList();
	TraverseList(pHead);

	//�������Ȳ����
	len = LengthList(pHead);
	if (!IsEmpty(pHead))
	{
		printf("This list's length is: %d\n", len);
	}

    //�������в������ݲ����±������
	if (InsertList(pHead,3,78))
	{
		printf("Insert successful!");
	}
	else
	{
		printf("Insert failed!");
	}
	TraverseList(pHead);

	//��������ɾ�����ݲ����±������
	if (DeleteList(pHead,3,&data_del))
	{
		printf("delete succeed,the deleted data is : %d\n", data_del);
	}
	else
	{
		printf("delete failed!");
	}
	TraverseList(pHead);

	//�������������±������
	SortList(pHead);
	printf("After sorted:");
	TraverseList(pHead);

	//��������������
	ClearList(pHead);
	printf("After cleared:");
	TraverseList(pHead);
	
	return 0;
}

//������������ͷָ��
pNode CreateList()
{
	int value;
	pNode pHead = (pNode)malloc(sizeof(Node));
	pNode pCur = pHead;
	pCur->pNext = nullptr;
	if (pHead==nullptr)
	{
		printf("pHead malloc failed!");
		exit(-1);
	}
	printf("Input the first data(q to quit):");
	while (scanf("%d",&value)==1)
	{
		pNode pNew = (pNode)malloc(sizeof(Node));
		if (pNew==nullptr)
		{
			printf("pNew malloc failed!");
			exit(-1);
		}
		pNew->data = value;
		pNew->pNext = nullptr;
		pCur->pNext = pNew;
		pCur = pNew;  //�ƶ���ǰ�ڵ㵽��һλ��
		printf("Input next data(q to quit):");
	}
	return pHead;
}

//��������
void TraverseList(pNode pHead)
{
	pNode pCur = pHead->pNext;
	printf("Now datas in the list are:\n");
	while (pCur!=nullptr)
	{
		printf(" %d  ", pCur->data);
		pCur = pCur->pNext;
	}
	printf("\n");
	return;
}

//�ж������Ƿ�Ϊ��
bool IsEmpty(pNode pHead)
{
	if (pHead->pNext!=nullptr)
	{
		return false;
	}
	return true;
}

//������ĳ��ȣ�������ͷ��㣩
int LengthList(pNode pHead)
{
	int len = 0;
	while (pHead->pNext!=nullptr)
	{
		len++;
		pHead = pHead->pNext;
	}
	return len;
}

//ð�ݷ�����������
void SortList(pNode pHead)
{
	pNode q, p;
	int temp;
	for (p = pHead->pNext; p != nullptr;p=p->pNext)
	{
		for (q = p->pNext; q != nullptr;q=q->pNext)
		{
			if (p->data>q->data) //��С��������
			{
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
	return;
}

//�ڵ�pos���ڵ�ĺ������һ���µĽڵ㣬�ýڵ�����Ϊval
bool InsertList(pNode pHead, int pos, int val)
{
	if (pHead==nullptr)
	{
		return false; //����pos����������
	}
	pNode pNew = (pNode)malloc(sizeof(Node));
	if (pNew==nullptr)
	{
		printf("new malloc failed!");
		exit(-1);
	}
	pNew->data = val;

	pNode pCur = pHead;
	while (--pos)
	{
		pCur = pCur->pNext;
	}
	pNew->pNext = pCur->pNext;
	pCur->pNext = pNew;

	return true;
}

//ɾ����pos���ڵ㣬����ɾ�������ݱ�����pData��ָ���λ��
bool DeleteList(pNode pHead, int pos, int* pdata)
{
	pNode pCur = pHead;
	int i = 0;
	while (i<pos-1&&pCur->pNext!=nullptr)
	{
		pCur = pCur->pNext;
		i++;
	}

	if (pHead==nullptr||i>pos-1)
	{
		return false;
	}

	pNode pDel = pCur->pNext;
	pCur->pNext = pDel->pNext;
	*pdata = pDel->data;
	free(pDel);
	pDel = nullptr;

	return true;
}

//���������ֻʣ��ͷ��㣬ͷ���û������
void ClearList(pNode pHead)
{
	pNode pCur=pHead->pNext;
	pNode ptemp=nullptr;
	while (pCur)
	{
		ptemp = pCur->pNext;  //��һ���µ�ָ���������
		free(pCur);
		pCur = ptemp;
	}
	pHead->pNext = nullptr;
	return;
}

