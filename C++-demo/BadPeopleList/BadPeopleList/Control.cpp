#include "stdafx.h"
#include <iostream>
#include "Control.h"


Control* Control::_control = NULL;
Model* Control::pmodel = NULL;

Control * Control::getControl()//Ҫͨ��getControl������
{
	if (NULL == _control)
	{
		_control = new Control;//��֤control����ֻ��һ��
	}
	return _control;
}

void Control::process(int n)
{

	(*pmodel->select(n))();//ѡ����Ҫ�Ĺ��ܺ���
						   //(*pmodel->select(n))����һ������ָ�� ����()�Ϳ���ִ�����������
						   //selectִ���귵��һ����Ҫ�Ĺ��ܺ���ָ�� ����()�Ϳ���ִ��������ܺ�����
}

Control::Control()
{
	if (NULL == pmodel)//����pmodel֮ǰ��Ҫ����������� �� Control�����ʱ������˹��캯�� ���Կ���ѡ���������ʼ��pmodel
	{
		pmodel = new Model;
	}
}//���캯��û�з���ֵ


Control::~Control()
{
}
