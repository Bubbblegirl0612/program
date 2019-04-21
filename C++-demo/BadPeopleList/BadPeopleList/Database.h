#pragma once
#include<iostream>
class Database//���ܺ������������д��
{
public:
	static Database* getBase();//����һ������������ָ��ĵõ����ݺ���
	bool SelectRoot(const char*id, const char*pw);//����bool���� ѡ��������ǶԵ� ѡ��������Ǵ��
	bool InsertRoot(const char*id, const char*pw);
	
	bool InsertUser(const char*id, const char*name);
	bool SelectUser(const char*id);//����bool���� ѡ��������ǶԵ� ѡ��������Ǵ��
	bool DeleteUser(const char*id);
	~Database();
private:
	Database();
	static Database*_dataBase;
	class Root//Root���൱��һ������ ����ǹ���Ա��Ϣ
	{
		char id[20];
		char pw[20];
		Root *next;//Root����һ��nextָ��
		friend Database;//database�������Է���Root�������
	};
	Root *RootListHead;//RootListHead��Root�����ͷ

private:
	class User//User���൱��һ������ ����Ǻ������û���Ϣ
	{
		char name[20];
		char id[20];
		User *next;//User����һ��nextָ��
		friend Database;//database�������Է���User�������
	};
	User *UserListHead;//UserListHead��User�����ͷ
};
