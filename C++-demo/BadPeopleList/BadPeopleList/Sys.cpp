#include "stdafx.h"
#include "Sys.h"
#include <iostream>
#include "Control.h"
using namespace std;
void Sys::put()
{
	cout << LOGIN << ".login  " << endl;//输出1.login 
	cout << REGISTER << ".register  " << endl;//输出2.register
	cout << SEXIT << ".exit  " << endl;//输出3.exit
}

void Sys::run()
{
	while (1)
	{
		this->put();//直接调用put()
		int n;
		cin >> n;//输入n 然后通过n来对应服务
		if (n > 3)//如果n>3 则说明错误
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