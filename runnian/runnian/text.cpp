#include "stdafx.h"
#include "iostream"
//ʵ�ַ����������У�fib[i] = fib[i-1]+fib[i-2]
//int main()
//{
//	int fib[20] = { 1,1 };
//	for (int i = 2; i < 20; ++i)
//	{
//		fib[i] = fib[i - 1] + fib[i - 2];
//	}
//	for (int i = 3; i < 19; ++i)
//	{
//		printf("%d / %d = %f\n", fib[i],fib[i + 1],(double)fib[i] / fib[i + 1]);
//	}
//}
////ʵ�ֳ˷��ھ���
//int main()
//{
//	for (int i = 1; i <= 10; i++)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			printf("%d * %d = %d", i, j, i*j);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//ʵ�� 1   2   3  4  5  6
//     12  23  34 45 56
//     123 234 345
int main()
{
	for (int s = 1; s <= 4; ++s)
	{
		for (int i= 1; i <= 6; ++i)
			for (int j = 1; j <= s + i + 1; ++i)
			{

			printf("%d * %d = %d", i, j, i*j);
		}
		printf("\n");
	}
	printf("\n");
}