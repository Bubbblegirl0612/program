#include "stdafx.h"
#include "Model.h"
#include "BadUserSys.h"
#include <iostream>
using namespace std;
//这些是业务函数 比如登录注册退出等等
void viewLogin()//登录
{
	char id[20], pw[20];
	cout << "登录 ID" << endl;
	cout << "登录 密码" << endl;
	cin >> id >> pw;
	cout << "你的id:" << id << "你的密码:" << pw << endl;
	if (Database::getBase()->SelectRoot(id, pw))
	{
		cout << "登陆成功" << endl;
		BadUserSys usersys;
		usersys.run();
	}
	else
	{
		cout << "登录错误" << endl;
	}
}
void viewRegister()//注册
{
	char id[20], pw[20];
	cout << "注册 ID" << endl;
	cout << "注册 密码" << endl;
	cin >> id >> pw;
	cout << "你的id:" << id << "你的密码:" << pw << endl;
	if (Database::getBase()->InsertRoot(id, pw))
	{
		cout << "注册成功" << endl;
		//BadUserSys usersys;
		//usersys.run();
	}
}
void viewSexit()
{
	exit(1);
}
void viewUserInsert()
{
	char id[20], name[20];
	cout << "/n 插入 ID" << endl;
	cout << "/n 插入 密码" << endl;
	cin >> id >> name;
	cout << "黑名单的id:" << id << "黑名单的名字:" << name << endl;
	if (Database::getBase()->InsertUser(id, name))
	{
		cout << "插入成功" << endl;
	}
}
void viewUserDelete()
{
	char id[20];
	cout << "/n 需要删除的 ID" << endl;
	cin >> id;
	if (Database::getBase()->DeleteUser(id))
	{
		cout << "删除成功" << endl;
	}

}
void viewUserSelect()
{
	char id[20];
	cout << "/n 需要查找的 ID" << endl;
	cin >> id;
	if (Database::getBase()->SelectUser(id))
	{
		cout << "查找成功" << endl;
	}
}
void viewUserExit()
{
	exit(1);

}
Model::Model()
{
	listHead = new Node();//Node是结点 listHead是链表的头结点
	listHead->next = NULL;
	Model::Insert(1, viewLogin);//对应的代号对应的办理什么业务
	Model::Insert(2, viewRegister);
	Model::Insert(3, viewSexit);
	Model::Insert(10, viewUserInsert);
	Model::Insert(11, viewUserDelete);
	Model::Insert(12, viewUserSelect);
	Model::Insert(13, viewUserExit);
}

//这些是功能函数 比如增删查改等
void Model::Insert(int type, View view)//头插
{
	Node *tmp = new Node();//tmp是新建的结点
	tmp->type = type;//把数据传入到节点中
	tmp->view = view;
	tmp->next = listHead->next;//把这个结点插入到链表中去
	listHead->next = tmp;//要插入的结点指向头结点下一个 头结点指向要插入的结点
}

void Model::Delete(int type)
{
	Node* left = listHead;
	Node* right = listHead->next;
	if (right->type != type)//如果不是要删除的结点
	{
		right = right->next;//就将这两个结点都向后移动
		left = left->next;
	}
	else {//如果是要删除的结点 就左边节点的下一个等于右边节点的下一个 从而将front本来指的节点删掉
		left->next = right->next;
		delete right;//把那个节点删掉
	}
}

View Model::select(int type)//遍历 用while 用这个选择业务
{
	Node* tmp = new Node();
	tmp = listHead->next;
	View view = NULL;
	while (tmp)
	{
		if (type == tmp->type)
		{
			view = tmp->view;
			break;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	return view;
}

void Model::update()
{
}

Model::~Model()
{
	delete(listHead);
	listHead = NULL;
}
