#pragma once
#include "Model.h"
//.h里写的是声明(只有函数名)  .cpp写的是定义(有函数体)
class Control
{
public:
	static Control* getControl();
	void process(int n);
private:
	static Control* _control;//私有的 要通过接口来访问
	static Model* pmodel;//参数传入控制层,通过control层去判断需要model里的哪个功能 所以需要定义model的对象
	Control();
	~Control();
};

