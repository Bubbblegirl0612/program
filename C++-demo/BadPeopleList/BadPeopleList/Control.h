#pragma once
#include "Model.h"
//.h��д��������(ֻ�к�����)  .cppд���Ƕ���(�к�����)
class Control
{
public:
	static Control* getControl();
	void process(int n);
private:
	static Control* _control;//˽�е� Ҫͨ���ӿ�������
	static Model* pmodel;//����������Ʋ�,ͨ��control��ȥ�ж���Ҫmodel����ĸ����� ������Ҫ����model�Ķ���
	Control();
	~Control();
};

