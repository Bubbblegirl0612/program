#include "stdafx.h"
#include "BadUserSys.h"
#include "Control.h"
#include <iostream>
using namespace std;

BadUserSys::BadUserSys()
{
}

void BadUserSys::run()
{
	while (1)
	{
		this->put();//ֱ�ӵ���put()
		int n;
		cin >> n;//����n Ȼ��ͨ��n����Ӧ����
		if (n < 10 || n > 13)//���n>13 ��˵������
		{
			cout << "input error!" << endl;
			//continue;
		}
		else//���� ��ȷ���������� ��n���뵽���Ʋ�
		{
			Control::getControl()->process(n);
		}
	}
}

void BadUserSys::put()
{
	cout << InsertUser << ".InsertUser" << endl;
	cout << DeleteUser << ".DeleteUser" << endl;
	cout << SelectUser << ".SelectUser" << endl;
	cout << UserExit << ".UserExit" << endl;
}


BadUserSys::~BadUserSys()
{
}
