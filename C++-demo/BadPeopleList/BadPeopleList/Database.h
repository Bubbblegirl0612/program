#pragma once
#include<iostream>
class Database//功能函数在这个类里写着
{
public:
	static Database* getBase();//定义一个返回类型是指针的得到数据函数
	bool SelectRoot(const char*id, const char*pw);//定义bool类型 选择对了则是对的 选择错了则是错的
	bool InsertRoot(const char*id, const char*pw);
	
	bool InsertUser(const char*id, const char*name);
	bool SelectUser(const char*id);//定义bool类型 选择对了则是对的 选择错了则是错的
	bool DeleteUser(const char*id);
	~Database();
private:
	Database();
	static Database*_dataBase;
	class Root//Root类相当于一个链表 存的是管理员信息
	{
		char id[20];
		char pw[20];
		Root *next;//Root类有一个next指针
		friend Database;//database这个类可以访问Root类的数据
	};
	Root *RootListHead;//RootListHead是Root链表的头

private:
	class User//User类相当于一个链表 存的是黑名单用户信息
	{
		char name[20];
		char id[20];
		User *next;//User类有一个next指针
		friend Database;//database这个类可以访问User类的数据
	};
	User *UserListHead;//UserListHead是User链表的头
};
