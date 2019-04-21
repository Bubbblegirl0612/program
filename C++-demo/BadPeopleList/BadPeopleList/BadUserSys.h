#pragma once
enum user { InsertUser = 10,DeleteUser = 11,SelectUser =12, UserExit =13};

class BadUserSys
{
public:
	BadUserSys();
	void run();//进入坏人管理界面
	void put();//选择要进行的操作
	~BadUserSys();

};

