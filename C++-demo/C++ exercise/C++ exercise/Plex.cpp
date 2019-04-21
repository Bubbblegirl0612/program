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
	m = src.m;//src�Ǵ�������ֵ
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
		return n < src.n; //���С�ڵĻ� �ͷ���true ���ǵĻ���false
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
ostream& operator<<(ostream& out, Plex src)// ���<<���������
{
	out << "m:" << src.m << endl << "" << "n:" << src.n << endl;
	return out;
}
istream& operator>>(istream& in, Plex &src)//���дsrc�Ļ� �൱������������¿����˿ռ� ��ô�������ִ�������ٵ���û�����src�ռ���
{//����Ҫд&src ���Ǳ��� �൱��ֱ��ָ���˴���ֵ�ĵ�ַ �ĵ�ʱ���ֱ�Ӹ�Դ��ַ Ҳ�������ź�����������ʧ
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
	//cout << p3<<endl;//���õ������ص����������<<
	//if (p1 == p2)
	//{
	//	cout<<"���"<<endl;//���õ��Ǳ������е�������� ��Ϊ�����е�
	//}
	//else 
	//{
	//	cout << "�����" << endl;
	//}
	cout << (p1 - p2) << endl;
	system("pause");
	return 0;
}