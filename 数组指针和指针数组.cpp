#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <string.h>


void SaveSplitRecord(char *result)
{
	FILE *fileSplit;
	if ((fileSplit = fopen("C:/Users/ranjiewen/Desktop/split.txt", "rb+")) == NULL)  //����ļ���д���󣬷���null
	{
		if ((fileSplit = fopen("C:/Users/ranjiewen/Desktop/split.txt", "wb")) == NULL)
			return;
	}

	fseek(fileSplit, 0L, SEEK_END);
	//fwrite(result, 1, sizeof(result), fileSplit);
	int a = sizeof(result);

	fwrite(result,strlen(result), 1,fileSplit);
	fclose(fileSplit);

	return;
}

int main()
{
	SaveSplitRecord("abcdefgdff!");
	int a[3][4] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11};
	int *b[3];//ָ������ 
	//��ʼ��
	for (int i = 0; i < 3;i++)
	{
		b[i] = a[i];
	}
	//ȡ�����Ԫ��  *(p[i]+j)��*(*(p+i)+j)��(*(p+i))[j]��p[i][j]
	cout << "b[i][j]�����" << endl;
	for (int i = 0; i < 3;i++)
	{
		for (int j = 0; j < 4;j++)
		{
			cout << b[i][j]<<" ";
		}
		cout << endl;
	}
	cout << "*(b[i]+j)"<<endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << *(b[i]+j)<<" ";
		}
		cout << endl;
	}

	cout << "---------------����ָ��-----------------" << endl;
	int   (*p)[4]; //ÿ�����ĸ�Ԫ��
	//��ʼ��
	p = a;         // p=a[0]; p=&a[0][0];
	cout << p << endl;
	for (int i = 0; i < 3;i++)
	{
		cout << p[i]<<" ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << *p[i] << " ";  //�����һ��
	}
	cout << "-----------------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << *p[i] << " ";  //���һ��
		cout << *(p[i]+1) << " ";  
		cout << *(p[i]+2) << " "; 
		cout << *(p[i]+3) << " "; 
	}

	cout << endl<<endl;

	p = p + 1; //�ƶ�һ�о���
	for (int i = 0; i < 3; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << *p[i] << " ";
	}
	cout << endl;

	return 0;
}

