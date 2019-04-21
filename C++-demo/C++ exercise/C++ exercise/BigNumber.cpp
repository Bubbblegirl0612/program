#include "stdafx.h"
#include "BigNumber.h"
#include <iostream>

using namespace std;
const int MAX_SIZE = 25;

void Count(BigNumber &src)//计算输入的数字是多少位 (长度)
{
	int i = 0;
	while (src.Num[i])
	{
		src.count++;
		i++;
	}
}
BigNumber::BigNumber()
{
	Num[25] = { 0 };
	count = 0;
}

BigNumber::BigNumber(const BigNumber & src)
{
	for (int i = 0; i < src.count; i++)//倒叙并储存 this.Num
	{
		Num[i] = src.Num[i];
	}
	count = src.count;
}

BigNumber::BigNumber(const char * src, int len)
{

	for (int i = 0; i < len; i++)//倒叙并储存 this.Num
	{
		Num[i] = Num[i];
	}
	count = len;
}

BigNumber BigNumber::operator+(const BigNumber & src)
{
	char ch1[MAX_SIZE] = { 0 };
	char ch2[MAX_SIZE] = { 0 };
	char tmp[MAX_SIZE] = { 0 };
	for (int i = count - 1, a = 0; i >= 0; i--)//倒叙并储存 this.Num
	{
		ch1[a] = Num[i];
		a++;
	}
	for (int i = src.count - 1, a = 0; i >= 0; i--)//倒叙并储存 src.Num
	{
		ch2[a] = src.Num[i];
		a++;
	}
	int pix = 0;//存进位
	int len = (count < src.count ? src.count : count);//循环次数
	int j = 0;
	for (int i = 0; i <  len; i++)
	{
		tmp[j++] = (ch1[i] - '0' + ch2[i] - '0' + pix) % 10;
		pix = (ch1[i] - '0' + ch2[i] - '0' + pix) / 10;
	}
	if (pix != 0)
	{
		tmp[j++] = pix;
	}
	
	//for (int i = 0, a = j-1; i < j/2; i++)
	//{
	//	char ch3 = tmp[a];
	//	tmp[a] = tmp[i];
	//	tmp[i] = ch3;
	//	a--;
	//}
	for (int i = 0, a = j - 1; i < j; i++)
	{
		Num[i] = tmp[a];
		a--;
	}
	return *this;
}

BigNumber BigNumber::operator-(const BigNumber & src)
{
	return BigNumber();
}

BigNumber BigNumber::operator=(const BigNumber & src)
{
	for (int i = 0; i < src.count; i++)//倒叙并储存 this.Num
	{
		Num[i] = src.Num[i];
	}
	count = src.count;
	return *this;
}

bool BigNumber::operator<(const BigNumber & src)
{
	if (count < src.count)
	{
		return true;
	}
	else if (count > src.count)
	{
		return false;
	}
	else {
		int len = src.count;
		int i = 0;
		while (len--)
		{
			if (Num[i] > src.Num[i])
			{
				return false;
				break;
			}
		}
	}	
	return true;
}

bool BigNumber::operator>(const BigNumber & src)
{
	if (count > src.count)
	{
		return true;
	}
	else if (count < src.count)
	{
		return false;
	}
	else {
		int len = src.count;
		int i = 0;
		while (len--)
		{
			if (Num[i] < src.Num[i])
			{
				return false;
				break;
			}
		}
	}
	return true;
}

bool BigNumber::operator==(const BigNumber & src)
{
	if (src.count != count)
	{
		return false;
	}
	for (int i = 0; i < src.count; i--)
	{
		if (Num[i] != src.Num[i])
		{
			return false;
		}
	}
	return true;
}


istream& operator>>(istream& in, BigNumber& src)
{
	in >> src.Num;
	return in;
}
ostream& operator<<(ostream& out, BigNumber& src)
{
	out << "this num: " << src.Num << endl;
	return out;
}


int main()
{
	BigNumber b1;
	cout << "输入第一个数:  ";
	cin >> b1;
	cout << b1;
	Count(b1);
	cout << "个数:" << b1.count << endl;
	BigNumber b2;
	cout << "输入第2个数:  ";
	cin >> b2;
	cout << b2;
	Count(b2);
	cout << "个数:" << b2.count << endl;
	cout << "第3个数:  ";
	BigNumber b3;
	b3 = b1; 
	b3 + b2;
	cout << b3;
	cout << "个数:" << b3.count << endl;
	
	system("pause");
	return 0;
}