#include "stdafx.h"
#include "Sys.h"
#include <iostream>
#include "Control.h"
using namespace std;
void Sys::put()
{
	cout << LOGIN << ".login  " << endl;//���1.login 
	cout << REGISTER << ".register  " << endl;//���2.register
	cout << SEXIT << ".exit  " << endl;//���3.exit
}

void Sys::run()
{
	while (1)
	{
		this->put();//ֱ�ӵ���put()
		int n;
		cin >> n;//����n Ȼ��ͨ��n����Ӧ����
		if (n > 3)//���n>3 ��˵������
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