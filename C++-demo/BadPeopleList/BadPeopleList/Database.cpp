#include "stdafx.h"
#include "Database.h"
#include <iostream>
#include <string>
using namespace std;

Database* Database::_dataBase = NULL;
Database::Database()
{
	RootListHead = new Root;
	RootListHead->next = NULL;
}

Database * Database::getBase()
{
	if (NULL == _dataBase)//初始化
	{
		_dataBase = new Database;
	}
	return _dataBase;
}
bool Database::SelectRoot(const char * id, const char * pw)
{
	Root* tmp = new Root();
	tmp = RootListHead->next;//tmp是头节点的下一个
	bool flag = false;
	while (tmp)//定义一个循环 没找到指定的root前就一直运行
	{
		if (id == tmp->id && pw == tmp->pw)
		{
			flag = true;//找到了flag变为true
			break;
		}
		else
		{
			tmp = tmp->next;//没找到就移到下一个节点
		}
	}
	return flag;
}
bool Database::InsertRoot(const char*id, const char*pw)//头插
{
	Root *tmp = new Root();
	strcpy_s(tmp->id, id);
	strcpy_s(tmp->pw, pw);
	tmp->next = RootListHead->next;
	RootListHead->next = tmp;
	return true;
}
bool Database::InsertUser(const char * id, const char * name)
{
	User *tmp = new User;
	strcpy_s(tmp->name, name);
	strcpy_s(tmp->id, id);
	tmp->next = UserListHead->next;
	UserListHead->next = tmp;
	return true;
}
bool Database::SelectUser(const char * id)
{
	User* tmp = new User();
	tmp = UserListHead->next;//tmp是头节点的下一个
	bool flag = false;
	while (tmp)//定义一个循环 没找到指定的root前就一直运行
	{
		if (id == tmp->id )
		{
			flag = true;//找到了flag变为true
		}
		else
		{
			tmp = tmp->next;//没找到就移到下一个节点
		}
	}
	return flag;
}
bool Database::DeleteUser(const char * id)
{
	User* left = UserListHead;
	User* right = UserListHead->next;
	if (right->id != id)//如果不是要删除的结点
	{
		right = right->next;//就将这两个结点都向后移动
		left = left->next;
	}
	else {//如果是要删除的结点 就左边节点的下一个等于右边节点的下一个 从而将front本来指的节点删掉
		left->next = right->next;
		delete(right);//把那个节点删掉
	}
	return false;
}
Database::~Database()
{

}