#include<stdio.h>
#include<iostream>
using namespace std;
//a,b����
/*void swap(int &m, int &n)//c����û������ 
{
	int k = m;
	m = n;
	n = k;
}
int main()
{
	int a=2, b=3;
	scanf_s("%d %d", &a, &b);
	swap(&a, &b);
	printf("a = %d,b = %d", b, a);	
	system("pause");//��ϵͳ��ͣ
	return 0;
} */
/*
//�������Ӵ�С���
void sort(int &a,int &b,int &c)
{
	
	if (a < b)
	{
		swap(a, b);
	}
	if (b < c)
	{
		swap(b, c);
	}
	if (a < b)
	{
		swap(a, b);
	}
}
int main()
{
	int a = 20, b = 5, c = 12;
	sort(a, b, c);
	printf("a = %d,b = %d,c = %d\n", a, b, c);
}*/
/*
//���1+...100֮��
int main()
{
	int sum = 0;
	for (int i = 1; i < 101; i++)
	{
		sum = i + sum;
	}
	printf("sum = %d\n", sum);
	system("pause");//��ϵͳ��ͣ
	return 0;
}
//��100~200֮����������
int main()
{	
	for (int a = 10; a <= 20; a++)
	{
		int flag = 1;
		for (int b = 2; b < a - 1; b++)
		{
			if (a%b == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			printf("%d\n", a);
		}
	}
	system("pause");//��ϵͳ��ͣ
	return 0;
}

//��m��n�����Լ��
int wbd(int m,int n)
{
	int c;
	for (int b = 1; b < n + 1;b++ )
	{
		if (m%b == 0 && n%b == 0)
		{
			c = b;
		}
	}
	return c;
}
int main()
{
	int m = 10, n = 20;
	int m_max = 0;
	if (m > n)
	{
		m_max = wbd(m, n);	
	}
	else
	{
		m_max = wbd(n, m);
	}
	cout << "" <<m_max<< endl;
	system("pause");//��ϵͳ��ͣ
	return 0;
}

//���1900~2000��������������,����������������֮һ�����������
//��4���������ܱ�100���� �ܱ�100�������ܱ�400����
int main()
{
	for (int year = 1900; year <= 2000; year++)
	{
		if (year % 4 == 0 && year % 100 != 0 ||  year % 400 == 0)//�ܱ�400����Ҳ�ܱ�100���� ������дһ������
		{
			cout << "" << year << endl;
		}
	}
	system("pause");//��ϵͳ��ͣ
	return 0;
}
*/
//����ʮ���� �����������һ����
int main()
{
	int ar[] = { 12,34,45,67,55,78,99,23,100,22 };

		
}