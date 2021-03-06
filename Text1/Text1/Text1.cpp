// zzy_housework.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "stdafx.h"
#include <iostream>
//题目一：输入1234，分开打印1234
//（1）递归方法
void Printnumber1_recursion(int a)
{
	if (a >= 1)
	{
		Printnumber1_recursion(a / 10);
		printf("%d \n", a % 10);
	}
}
//（2）非递归方法
void Printnumber1_norecursion(int a)
{
	int c[10];
	int b = 0;
	int len = 0;
	bool bo1 = true;
	bool bo2 = false;
	if (a < 10)
	{
		bo1 = false;
		bo2 = true;
		c[len] = a;
	}
	while (bo1)
	{
		b = a % 10;
		a = a / 10;
		c[len] = b;
		len++;
		if (a < 10)
		{
			bo1 = false;
			bo2 = true;
			c[len] = a;
		}
	}
	while (bo2)
	{
		if (c[len]<10)
		{
			printf("%d\n", c[len]);
			len--;
		}
		if (len<0)
		{
			bo2 = false;
		}
	}

}

//题目二：输入1234，输出4321
//（1）递归方法
void Printnumber2_recursion(int a)
{
	if (a >= 1)
	{
		printf("%d \n", a % 10);
		Printnumber2_recursion(a / 10);
	}
}
//（2）非递归方法
void Printnumber2_norecursion(int a)
{
	int b = 0;
	bool bo = true;
	if (a < 10)
	{
		bo = false;
		printf("%d \n", a);
	}
	while (bo)
	{
		b = a % 10;
		a = a / 10;
		printf("%d \n", b);
		if (a < 10)
		{
			printf("%d", a);
			bo = false;
		}
	}
}
int main()
{
	int a = 0;
	printf("Please input a number。 \n");
	scanf_s("%d", &a);

	Printnumber1_recursion(a);			//题目一：递归方法求解
	//Printnumber1_norecursion(a);			//题目一：非递归方法求解
	//Printnumber2_recursion(a);			//题目二：递归方法求解
	//Printnumber2_norecursion(a);			//题目二：非递归方法求解
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
