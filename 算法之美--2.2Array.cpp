//#include "Array.h"
#include <stdio.h>

const int DefaultSize = 100;

template <class Type>
class Array
{
private:
	Type *elements;   //�����ŵĿռ�
	int ArraySize;    //��ǰ����
public:
	Array(int Size = DefaultSize);
	Array(const Array<Type>& x);   //���ƹ��캯��
	~Array(){ delete[] elements; }

	Array<Type>& operator =(const Array<Type>& rhs);  //���鸴��
	Type& operator [] (int i);                        //ȡԪ��ֵ
	int Length()const { return ArraySize; };
	void ReSize(int sz);
};

template <class Type>
Array<Type>& Array<Type>::operator =(const Array<Type>& rhs)
{
	int n = rhs.ArraySize; //ȡrhs�������С
	if(ArraySize!=n)
	{
		delete[] elements;
		elements = new Type[n];  //���·���n��Ԫ�ص��ڴ�
		if (elements==NULL)
		{
			ArraySize = 0;
			cerr << "�洢�������" << endl;
			exit(1);
		}
		ArraySize = n;
	}
	//��rhs�򱾶�����Ԫ��
	Type *destptr = elements;
	Type *srcptr = rhs.elements;
	while (n--)
	{
		*destptr++ = *srcptr++;
	}
	return *this;
}

template <class Type>
Array<Type>::Array(int sz)
{
	if (sz <= 0)
	{
		ArraySize = 0;
		cerr << "�Ƿ������С" << endl;
		return;
	}
	elements = new Type[sz];
	if (elements==NULL)
	{
		ArraySize = 0;
		cerr << "�洢�������" << endl;
		exit(1);
	}
	ArraySize = sz;
}

template <class Type>
Array<Type>::Array(const Array<Type>& x)
{
	int n = x.ArraySize;
	ArraySize = n;
	elements = new Type[n];
	if (elements==	NULL)
	{
		ArraySize = 0;
		cerr << "�洢�����"<<endl;
		exit(1);
	}
	Type* srcptr = x.elements;
	Type* destptr = elements;
	while (n--)
	{
		*destptr++ = *srcptr++;
	}
}

template<class Type>
Type& Array<Type>::operator [] (int i)
{
	if (i<0||i>ArraySize-1)
	{
		cerr << "�����±곬��" << endl;
		exit(1);
	}
	return elements[i];
}

template <class Type>
void Array<Type>::ReSize(int sz)
{
	if (sz>=0&&sz!=ArraySize)
	{
		Type *newArray = new Type[sz];
		if (newArray==NULL)
		{
			cerr << "�ڴ����ʧ�ܣ�" << endl;
			return;
		}
		int n = (sz <= ArraySize) ? sz : ArraySize;// �����µĴ�Сȷ���������ݵĸ���
		
		Type *srcptr = elements;
		Type *destptr = newArray;
		while (n--)
		{
			*destptr++ = *srcptr++;
		}
		delete[] elements;
		elements = newArray;
		ArraySize = sz;
	}
}


#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char ** argv)   
{
	Array<int> A(10);       //���������������
	int n;
	int primecount = 0, i, j;

	cout << "Enter a value>=2 as upper limit for prime numbers:";
	cin >> n;
	A[primecount++] = 2;   //2������
	for (int i = 3; i < n;i++)
	{
		if (primecount==A.Length())
		{
			A.ReSize(primecount + 10);
		}
		if (i%2==0)  //ż������
		{
			continue;
		}
		j = 3;
		while (j<=i/2&&i%j!=0)
		{
			j += 2;
		}
		if (j>i/2)
		{
			A[primecount++] = i;
		}
	}

	for (int i = 0; i < primecount;i++)
	{
		cout << setw(5) << A[i];
		if ((i+1)%10==0)
		{
			cout << endl;
		}
	}
	cout << endl;

	return 0;
}


