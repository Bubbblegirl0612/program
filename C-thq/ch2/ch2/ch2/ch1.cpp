#include<stdio.h>
#include<iostream>
using namespace std;
//a,b交换
/*void swap(int &m, int &n)//c语言没有引用 
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
	system("pause");//让系统暂停
	return 0;
} */
/*
//三个数从大到小输出
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
//输出1+...100之和
int main()
{
	int sum = 0;
	for (int i = 1; i < 101; i++)
	{
		sum = i + sum;
	}
	printf("sum = %d\n", sum);
	system("pause");//让系统暂停
	return 0;
}
//将100~200之间的素数输出
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
	system("pause");//让系统暂停
	return 0;
}

//求m和n的最大公约数
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
	system("pause");//让系统暂停
	return 0;
}

//输出1900~2000年中是闰年的年份,符合下面两个条件之一的年份是闰年
//被4整除但不能被100整除 能被100整除且能被400整除
int main()
{
	for (int year = 1900; year <= 2000; year++)
	{
		if (year % 4 == 0 && year % 100 != 0 ||  year % 400 == 0)//能被400整除也能被100整除 可以少写一个条件
		{
			cout << "" << year << endl;
		}
	}
	system("pause");//让系统暂停
	return 0;
}
*/
//输入十个数 输出其中最大的一个数
int main()
{
	int ar[] = { 12,34,45,67,55,78,99,23,100,22 };

		
}