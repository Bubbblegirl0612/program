#pragma once
#include <iostream>
#include "Database.h"
using namespace std;
//enum root { LOGIN = 1, REGISTER = 2, SEXIT = 3 };
/////       viewLogin  viewRegister  viewSexit
typedef void(*View)();
//void(无返回值的)类型的函数退化成view类型的指针
//项目里的都用的单例模式的方法
class Model
{
public://声明所需要的功能函数
	Model();
	void Insert(int type, View view);
	void Delete(int type);
	View select(int n);
	void update();
	~Model();
private:
	class Node//相当于一个链表 存的是办什么业务
	{
		int type;    // LOGIN = 1,  REGISTER = 2,  SEXIT = 3
		View view;   // viewLogin   viewRegister   viewSexit
		Node *next;
		friend class Model;
	};
	Node* listHead;//头结点 
};
