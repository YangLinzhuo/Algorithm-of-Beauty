/*!
 * \file �㷨֮��--����.cpp
 *
 * \author ranjiewen
 * \date 2016/11/29 21:18
 *
 * 
 */

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	//һά����Ĳ��������±����Ԫ��
	int a[10] = {1,32,65,2,100,34,33,21,10,1};
	int sum = 0;
	for (int i = 0; i < 10;i++)
	{
		sum += a[i];
	}
	cout << "������Ԫ�صĺ�Ϊ��" << sum << endl;

	//C++���ṩ������߽�ļ�飬Խ�����
	int b[5] = {6,7,8,9,10};
	cout << b[6] << endl;   //���-858993460�����򲢲������

	//��ά����Ĳ���
	int c[][3] = { { 0, 1, 2 }, { 3, 4, 5 }, {6,7,8} }; //�ڶ�ά�ĳ��Ȳ���ʡ��

	//ʹ��ָ���Ч�ķ���һ����ά����Ԫ�ز�����
	int *p = &a[0];
	cout << a[0] << endl;
	cout << *p << endl;
	cout << a << endl;
	cout << &a << endl; //ע�����a�ĵ�ַ
	cout << &a[0] << endl;
	cout << p << endl;
	cout << *(p + 4) << endl;  //ָ�������ƫ�Ʋ���
	cout << *(a + 4) << endl;
	p++;
	cout << p << endl;
	(*p)++;
	cout << *p << endl;

	//����*p++,*(p++),*(++p
	//*��++���������ȼ���ͬ����Ϸ���Ϊ��������
	p = a;  //p����++����������a����++������aΪ����Ԫ�ص��׵�ַ��Ϊ����ָ��
	cout << *p++ << endl;  
	cout << p << endl;
	cout << *(p++) << endl;
	cout << *(++p) << endl;

	return 0;
}

