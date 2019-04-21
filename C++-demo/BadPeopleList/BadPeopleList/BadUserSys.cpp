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
		this->put();//直接调用put()
		int n;
		cin >> n;//输入n 然后通过n来对应服务
		if (n < 10 || n > 13)//如果n>13 则说明错误
		{
			cout << "input error!" << endl;
			//continue;
		}
		else//否则 正确即继续运行 将n传入到控制层
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
