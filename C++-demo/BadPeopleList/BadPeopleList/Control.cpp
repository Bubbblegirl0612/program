#include "stdafx.h"
#include <iostream>
#include "Control.h"


Control* Control::_control = NULL;
Model* Control::pmodel = NULL;

Control * Control::getControl()//要通过getControl来访问
{
	if (NULL == _control)
	{
		_control = new Control;//保证control对象只有一个
	}
	return _control;
}

void Control::process(int n)
{

	(*pmodel->select(n))();//选择需要的功能函数
						   //(*pmodel->select(n))返回一个函数指针 加上()就可以执行这个函数了
						   //select执行完返回一个需要的功能函数指针 加上()就可以执行这个功能函数了
}

Control::Control()
{
	if (NULL == pmodel)//在用pmodel之前就要把它构造出来 用 Control对象的时候调用了构造函数 所以可以选择在这里初始化pmodel
	{
		pmodel = new Model;
	}
}//构造函数没有返回值


Control::~Control()
{
}
