#include "stdafx.h"
#include "Model.h"
#include "BadUserSys.h"
#include <iostream>
using namespace std;
//��Щ��ҵ���� �����¼ע���˳��ȵ�
void viewLogin()//��¼
{
	char id[20], pw[20];
	cout << "��¼ ID" << endl;
	cout << "��¼ ����" << endl;
	cin >> id >> pw;
	cout << "���id:" << id << "�������:" << pw << endl;
	if (Database::getBase()->SelectRoot(id, pw))
	{
		cout << "��½�ɹ�" << endl;
		BadUserSys usersys;
		usersys.run();
	}
	else
	{
		cout << "��¼����" << endl;
	}
}
void viewRegister()//ע��
{
	char id[20], pw[20];
	cout << "ע�� ID" << endl;
	cout << "ע�� ����" << endl;
	cin >> id >> pw;
	cout << "���id:" << id << "�������:" << pw << endl;
	if (Database::getBase()->InsertRoot(id, pw))
	{
		cout << "ע��ɹ�" << endl;
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
	cout << "/n ���� ID" << endl;
	cout << "/n ���� ����" << endl;
	cin >> id >> name;
	cout << "��������id:" << id << "������������:" << name << endl;
	if (Database::getBase()->InsertUser(id, name))
	{
		cout << "����ɹ�" << endl;
	}
}
void viewUserDelete()
{
	char id[20];
	cout << "/n ��Ҫɾ���� ID" << endl;
	cin >> id;
	if (Database::getBase()->DeleteUser(id))
	{
		cout << "ɾ���ɹ�" << endl;
	}

}
void viewUserSelect()
{
	char id[20];
	cout << "/n ��Ҫ���ҵ� ID" << endl;
	cin >> id;
	if (Database::getBase()->SelectUser(id))
	{
		cout << "���ҳɹ�" << endl;
	}
}
void viewUserExit()
{
	exit(1);

}
Model::Model()
{
	listHead = new Node();//Node�ǽ�� listHead�������ͷ���
	listHead->next = NULL;
	Model::Insert(1, viewLogin);//��Ӧ�Ĵ��Ŷ�Ӧ�İ���ʲôҵ��
	Model::Insert(2, viewRegister);
	Model::Insert(3, viewSexit);
	Model::Insert(10, viewUserInsert);
	Model::Insert(11, viewUserDelete);
	Model::Insert(12, viewUserSelect);
	Model::Insert(13, viewUserExit);
}

//��Щ�ǹ��ܺ��� ������ɾ��ĵ�
void Model::Insert(int type, View view)//ͷ��
{
	Node *tmp = new Node();//tmp���½��Ľ��
	tmp->type = type;//�����ݴ��뵽�ڵ���
	tmp->view = view;
	tmp->next = listHead->next;//����������뵽������ȥ
	listHead->next = tmp;//Ҫ����Ľ��ָ��ͷ�����һ�� ͷ���ָ��Ҫ����Ľ��
}

void Model::Delete(int type)
{
	Node* left = listHead;
	Node* right = listHead->next;
	if (right->type != type)//�������Ҫɾ���Ľ��
	{
		right = right->next;//�ͽ���������㶼����ƶ�
		left = left->next;
	}
	else {//�����Ҫɾ���Ľ�� ����߽ڵ����һ�������ұ߽ڵ����һ�� �Ӷ���front����ָ�Ľڵ�ɾ��
		left->next = right->next;
		delete right;//���Ǹ��ڵ�ɾ��
	}
}

View Model::select(int type)//���� ��while �����ѡ��ҵ��
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
