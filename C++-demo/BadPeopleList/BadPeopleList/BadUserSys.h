#pragma once
enum user { InsertUser = 10,DeleteUser = 11,SelectUser =12, UserExit =13};

class BadUserSys
{
public:
	BadUserSys();
	void run();//���뻵�˹������
	void put();//ѡ��Ҫ���еĲ���
	~BadUserSys();

};

