
#include <iostream>
#include <iomanip>

using namespace std;

#define  SIZE 8
int main(int argc, char **argv[])
{
	int matrix[SIZE][SIZE] = {0};
	int a[SIZE][SIZE] = { 0 };
 
	int *p = nullptr;
	p = &matrix[0][0];
	//��ʼ������
	for (int k = 0; k < SIZE*SIZE; k++)
	{
		*p++ = k;
	}
	//��ӡԭʼ����
	cout << "ԭʼ�������£�" << endl;
	for (int k= 0;k < SIZE;k++)
	{
		for (int h = 0; h < SIZE;h++)
		{
			cout << setw(4) << *(*(matrix + k) + h);
		}
		cout << endl;
	}

	//Z���α���
	int i = 0, j = 0;  //���������ظ�
	for (int x = 0; x < SIZE;x++)
	{
		for (int y = 0; y < SIZE;y++)
		{
			*(*(a + i) + j) = *(*(matrix + x) + y);

			if((i==SIZE-1||i==0)&&j%2==0)  //ˮƽ����
			{
				j++;
				continue;
			}
			if ((j==0||j==SIZE-1)&&i%2==1) //��ֱ����
			{
				i++;
				continue;
			}
			if ((i+j)%2==0)        //����
			{
				i--; 
				j++;
			}
			else if ((i+j)%2==1)   //����
			{
				i++;
				j--;
			}
		}
	}
	cout << endl << "����Z���α��ź�ľ������£�" << endl;
	for (int i = 0; i < SIZE;i++)
	{
		for (int j = 0; j < SIZE;j++)
		{
			cout << setw(4) << *(*(a + i) + j);
		}
		cout << endl;
	}
	return 0;
}