#include "stdafx.h"
#include "Plex.h"
#include <iostream>
using namespace std;

Plex::Plex()
{
}

Plex::Plex(int _m, int _n)
{
	m = _m;
	n = _n;
}

Plex & Plex::operator=(const Plex & src)
{
	if (this == &src)
	{
		return *this;
	}
	m = src.m;//src是传进来的值
	n = src.n;
	return *this;
}

Plex Plex::operator+(const Plex & src)
{
	return Plex(m+src.m,n+src.n);
}
Plex Plex::operator+(int m)
{
	return Plex(m+m,n);
}

Plex Plex::operator-(const Plex & src)
{
	return Plex(m-src.m,n-src.n);
}

bool Plex::operator==(const Plex & src)
{
	if (m == src.m && n == src.n)
	{
		return true;
	}
	return false;
}

bool Plex::operator<(const Plex & src)
{
	if (m < src.m)
	{
		return true;
	}
	else if (m == src.m)
	{
		return n < src.n; //如果小于的话 就返回true 不是的话就false
	}
	return false;
}

bool Plex::operator>(const Plex & src)
{
	if (m > src.m)
	{
		return true;
	}
	else if (m == src.m)
	{
		return n > src.n;
	}
	return false;
}
ostream& operator<<(ostream& out, Plex src)// 输出<<运算符重载
{
	out << "m:" << src.m << endl << "" << "n:" << src.n << endl;
	return out;
}
istream& operator>>(istream& in, Plex &src)//如果写src的话 相当于在这个函数新开辟了空间 那么这个函数执行完销毁掉就没有这个src空间了
{//所以要写&src 就是别名 相当于直接指向了传入值的地址 改的时候就直接改源地址 也不会随着函数销毁所消失
	in >> src.m >> src.n;
	return in;
}

void Plex::show()
{
	cout << "m:" << m << endl;
	cout << "n:" << n << endl;
}


int main1()
{
	Plex p1(1, 2),p2(2,3),p3;
	//p3 = p1 + p2;
	//cin >> p3; 
	//cout << p3<<endl;//调用的是重载的运算符函数<<
	//if (p1 == p2)
	//{
	//	cout<<"相等"<<endl;//调用的是本身自有的输出功能 因为本身有的
	//}
	//else 
	//{
	//	cout << "不相等" << endl;
	//}
	cout << (p1 - p2) << endl;
	system("pause");
	return 0;
}