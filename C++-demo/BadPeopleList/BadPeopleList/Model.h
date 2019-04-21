#pragma once
#include <iostream>
#include "Database.h"
using namespace std;
//enum root { LOGIN = 1, REGISTER = 2, SEXIT = 3 };
/////       viewLogin  viewRegister  viewSexit
typedef void(*View)();
//void(�޷���ֵ��)���͵ĺ����˻���view���͵�ָ��
//��Ŀ��Ķ��õĵ���ģʽ�ķ���
class Model
{
public://��������Ҫ�Ĺ��ܺ���
	Model();
	void Insert(int type, View view);
	void Delete(int type);
	View select(int n);
	void update();
	~Model();
private:
	class Node//�൱��һ������ ����ǰ�ʲôҵ��
	{
		int type;    // LOGIN = 1,  REGISTER = 2,  SEXIT = 3
		View view;   // viewLogin   viewRegister   viewSexit
		Node *next;
		friend class Model;
	};
	Node* listHead;//ͷ��� 
};
