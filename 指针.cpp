
#include <iostream>
#include <ctime>
using namespace std;

void fun(int _x); //��ֵ���ݣ������޸��ⲿ�����������ڲ��Բ������б��ݣ�Ч�ʵ�
void fun(int *_p);
void fun1(int &_r);//���ô��ݣ����ݴ����ʱ��Ч��ע���ڴ�������ʱ����Ϊconst����
void first_bigger(int *p, int threshold);
void first_bigger1(int *&p, int threshold);
int main()
{
	/************************************************************************/
	/*ָ�������ʹ��                                                         */
	/************************************************************************/
	unsigned int a = 5;
	unsigned int *pint = NULL;
	
	cout << "&a=" << &a << endl << "a=" << a << endl;
	cout << "&pint=" << &pint << endl << "pint=" << pint << endl;
	cout << "&(*pint)=" << &(*pint) << endl << endl;

	pint = &a;
	cout << "&a=" << &a << endl << "a=" << a << endl;
	cout << "&pint=" << &pint << endl << "pint=" << pint << endl;
	cout << "&(*pint)=" << &(*pint) << endl << endl;
	 
	*pint = 10;   //�ı�ָ��ָ��ı�����ֵ
	cout << "&a=" << &a << endl << "a=" << a << endl;
	cout << "&pint=" << &pint << endl << "pint=" << pint << endl;
	cout << "&(*pint)=" << &(*pint) << endl << endl;

	/************************************************************************/
	/*������������                                                           */
	/************************************************************************/
	//��ֵ����
	int x = 10;
	cout << "x=" << x << endl;
	fun(x);
	cout << "x=" << x << endl;
	//��ָ�봫��
	int y = 5;
	cout << "y=" << y << endl;
	fun(&y);
	cout << "y=" << y << endl;
	//�����ô���
	int z = 0;
	cout << "z=" << z << endl;
	fun1(z);
	cout << "z=" << z << endl;

	/************************************************************************/
	/* �������ô��ݷ�ʽ������һ��ָ��,�����ݵ�ָ����Ҫ�����ض���ʱ����           */
	/************************************************************************/
	int numbers[] = {0,12,32,44,35,5,85,45,100,75};
	int *result = &numbers[0];
	cout << "Begin at:" << *result << endl;
	first_bigger(result, 60);
	cout << "Result is:" << *result << endl;  //���0

	cout << "Begin at:" << *result << endl;
	first_bigger1(result, 60);
	cout << "Result is:" << *result << endl;  //���85
	return 0;
}

void fun(int _x)
{
	cout << "x=" << _x << endl;
	_x++;
	cout << "x=" << _x << endl;
}

void fun(int *_p)
{
	cout << "*_p=" << *_p << endl;
	(*_p)++;
	cout << "*_p=" << *_p << endl;
}

void fun1(int &_r)
{
	cout << "_r=" << _r << endl;
	_r++;
	cout << "_r=" << _r << endl;
}

void first_bigger(int *p, int threshold)
{
	while (*p<=threshold)
	{
		p++;
	}
}

void first_bigger1(int *&p, int threshold)
{
	while (*p <= threshold)
	{
		p++;
	}
}