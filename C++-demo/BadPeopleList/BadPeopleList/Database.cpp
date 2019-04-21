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
	if (NULL == _dataBase)//��ʼ��
	{
		_dataBase = new Database;
	}
	return _dataBase;
}
bool Database::SelectRoot(const char * id, const char * pw)
{
	Root* tmp = new Root();
	tmp = RootListHead->next;//tmp��ͷ�ڵ����һ��
	bool flag = false;
	while (tmp)//����һ��ѭ�� û�ҵ�ָ����rootǰ��һֱ����
	{
		if (id == tmp->id && pw == tmp->pw)
		{
			flag = true;//�ҵ���flag��Ϊtrue
			break;
		}
		else
		{
			tmp = tmp->next;//û�ҵ����Ƶ���һ���ڵ�
		}
	}
	return flag;
}
bool Database::InsertRoot(const char*id, const char*pw)//ͷ��
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
	tmp = UserListHead->next;//tmp��ͷ�ڵ����һ��
	bool flag = false;
	while (tmp)//����һ��ѭ�� û�ҵ�ָ����rootǰ��һֱ����
	{
		if (id == tmp->id )
		{
			flag = true;//�ҵ���flag��Ϊtrue
		}
		else
		{
			tmp = tmp->next;//û�ҵ����Ƶ���һ���ڵ�
		}
	}
	return flag;
}
bool Database::DeleteUser(const char * id)
{
	User* left = UserListHead;
	User* right = UserListHead->next;
	if (right->id != id)//�������Ҫɾ���Ľ��
	{
		right = right->next;//�ͽ���������㶼����ƶ�
		left = left->next;
	}
	else {//�����Ҫɾ���Ľ�� ����߽ڵ����һ�������ұ߽ڵ����һ�� �Ӷ���front����ָ�Ľڵ�ɾ��
		left->next = right->next;
		delete(right);//���Ǹ��ڵ�ɾ��
	}
	return false;
}
Database::~Database()
{

}