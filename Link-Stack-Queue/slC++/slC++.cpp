// slC++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
#include<stdlib.h>
//用oop实现一个顺序栈 (首先需要一个数组,需要长度,栈顶指针,入栈出栈)------------------------------------------------------------
class CSeqStack
{
public:
	CSeqStack(int size=10)//栈的初始化
	{
		msize = size;//用户可以传这个的所以我们就写size
		mpstack = new int[size];
		mtop = 0;
	}
	~CSeqStack()
	{
		delete []mpstack;
		mpstack = nullptr;
	}
	void push(int val);//入栈
	void pop();//出栈
	void show();//展示
	int top();//获取栈顶元素
	bool full();//判满
	bool empty();//判空
	bool select(int val);//查找元素
private:
	int *mpstack;//栈的数组空间
	int mtop;//栈顶位置
	int msize;//栈的总长度

	void resize();//栈的二倍扩容
};




void CSeqStack::push(int val)
{
	if (full())
	{
		resize();//满了扩容
	}
	mpstack[mtop++] = val;
}

void CSeqStack::pop()
{
	if (!empty())
	{
		mtop--;//出栈 栈顶指针向下走
	}
	else
	{
		return;
	}
}

int CSeqStack::top()
{
	if (empty())
	{
		throw"stack is empty!";
	}
	return mpstack[mtop-1];
}

bool CSeqStack::full()
{
	return mtop == msize;//如果栈满说明栈顶指针到达栈的最大值 满了以后成立 满了以后返回真值
}

bool CSeqStack::empty()
{
	return mtop == 0;//如果是空的话返回true 不然返回false
}
bool CSeqStack::select(int val)//查找栈内元素
{
	for (int i = 0; i < mtop; i++)
	{
		if (mpstack[i] == val)
		{
			cout << "查询成功!" << endl;
			return true;
		}
		cout << "查询失败!" << endl;
		return false;
	}
}

void CSeqStack::resize()
{
	int *ptmp = new int[2 * msize];//数组退化成指针
	for (int i = 0; i < msize; ++i)
	{
		ptmp[i] = mpstack[i];
	}
	delete[]mpstack;//释放原先的那个
	mpstack = ptmp;//指向mpstack的指针改为指向ptmp
	msize *= 2;//改成员msize
}

void CSeqStack::show()
{
	for (int i = 0; i < mtop; i++)//从0到栈顶指针遍历
	{
		cout << mpstack[i] << " ";
	}
	cout << endl;//打个回车 说明show这个功能已经显示完了
}

class CCircleQueue//实现循环队列------------------------------------------------------------
{
public:
	CCircleQueue(int size = 10)//构造函数
	{
		msize = size;
		mfront = mrear = 0;
		mpQue = new int[msize];//---
	}
	~CCircleQueue()//析构函数
	{
		delete []mpQue;//---
		mpQue = nullptr;//指针置空---
	}
	CCircleQueue(const CCircleQueue &src)//拷贝构造函数
	{
		this->mpQue = new int[src.msize];//建立与原数组大小一样的队列数组
		for (int i = src.mfront; i != src.mrear; i = (i + 1) % src.msize)
		{
			mpQue[i] = src.mpQue[i];//数组只需要下标就可以访问
		}
		mfront = src.mfront;
		mrear = src.mrear;
		msize = src.msize;
	}
	void operator=(const CCircleQueue &src)//赋值重载函数
	{
		if (this == &src)
		{
			return;
		}
		delete[]mpQue;//---
		this->mpQue = new int[src.msize];//建立与原数组大小一样的队列数组
		for (int i = src.mfront; i != src.mrear; i = (i + 1) % src.msize)
		{
			mpQue[i] = src.mpQue[i];//数组只需要下标就可以访问
		}
		mfront = src.mfront;
		mrear = src.mrear;
		msize = src.msize;
	}
	void addQue(int val) // 入队
	{
		if (full())
		{
			resize();
		}
		mpQue[mrear] = val;
		mrear = (mrear + 1) % msize;//范围是从（0，msize - 1）
	}
	void delQue()// 出队
	{
		if (empty())
		{
			return;
		}
		mfront = (mfront + 1) % msize;
	}
	void show()
	{
		for (int i = mfront; i != mrear; i = (i + 1) % msize)
		{
			cout << mpQue[i] << " ";
		}
		cout << endl;
	}
	bool select(int val)
	{
		for (int i = mfront; i < mrear; i = (i + 1) % msize)
		{
			if (mpQue[i] == val)
			{
				cout << "查询成功!" << endl;
				return true;
			}			
		}
		cout << "查询失败!" << endl;
		return false;
	}
	int front()// 返回队头元素
	{
		return mpQue[mfront];
	}
	int back()// 返回队尾元素
	{
		return mpQue[(mrear - 1+msize)%msize];//尾指针指向的内存不存值
	}

	bool full() // 判满
	{
		if (((mrear + 1) % msize) == mfront)//当头尾指针即将相撞时 就说明即将满了
		{
			return true;
		}
		return false;
	}
	bool empty() // 判空
	{
		if (mfront == mrear)
		{
			return true;
		}
		return false;
	}

private:
	int *mpQue;//保存队列元素的数据结构
	int mfront;//队头下标
	int mrear;//队尾下标
	int msize;//扩容的总长度

	void resize() 
	{
		int *ptmp = new int[msize * 2];
		int j = 0;
		for (int i = mfront; i != mrear; i = (i + 1) % msize)
		{
			ptmp[i] = mpQue[i];//数组只需要下标就可以访问
		}
		delete[]mpQue;
		mpQue = ptmp;
		mfront = 0;
		mrear = j;
		msize *= 2;
	}
};
// OOP实现一个链表结构------------------------------------------------------------
class Link
{
public:
	Link() // 构造函数
	{
		mphead = new Node(); // new Node;
	}
	~Link() // 析构函数
	{
		Node *pcur = mphead;
		while (pcur != nullptr)
		{
			mphead = mphead->mpnext;//不停地删除头结点 然后头节点的指针继续指向头节点的下一个结点
			delete pcur;//继续删除头结点
			pcur = mphead;
		}
	}
	void insertHead(int val)//头插法
	{
		Node *ptmp = new Node(val);//新建一个结点 ptmp指向新结点
		ptmp->mpnext = mphead->mpnext;
		mphead->mpnext = ptmp;
	}
	void insertTail(int val)
	{
		Node *pcur = mphead;
		while (pcur->mpnext != nullptr)
		{
			pcur = pcur->mpnext;
		}
		pcur->mpnext = new Node(val);
	}
	void remove(int val) // 删除所有值为val的节点
	{
		Node *ppre = mphead;
		Node *pcur = mphead->mpnext;

		while (pcur != nullptr)
		{
			if (pcur->mdata == val)
			{
				ppre->mpnext = pcur->mpnext;
				delete pcur;
				pcur = ppre->mpnext;
			}
			else
			{
				ppre = pcur;
				pcur = pcur->mpnext;
			}
		}
	}
	int back()
	{
		return mphead->mpnext->mdata;
	}
	void remove()
	{
		Node *tmp = mphead->mpnext;
		mphead->mpnext = tmp->mpnext;
		delete tmp;
	}
	bool select(int val)//查找
	{
		Node*pcur = mphead->mpnext;
		while (pcur != nullptr)
		{
			if (pcur->mdata == val)
			{
				cout << "查询成功!" << endl;
				return true;
			}
			pcur = pcur->mpnext;
		}
		cout << "查询失败!" << endl;
		return false;

	}
	bool empty()
	{
		if (mphead->mpnext == NULL)
		{
			return true;
		}
		return false;
	}
	void show()
	{
		Node *pcur = mphead->mpnext;
		while (pcur != nullptr)
		{
			cout << pcur->mdata << " ";
			pcur = pcur->mpnext;
		}
		cout << endl;
	}


private:
	// 节点类型
	struct Node
	{
		Node(int data = 0)
		{
			mdata = data;
			mpnext = nullptr;
		}
		int mdata;
		Node *mpnext;
	};
	Node *mphead;//Link的成员对象 结点类的指针
	// private化拷贝构造和赋值重载函数
	Link(const Link&);
	void operator=(const Link&);

	
};
/*
软件运行如下：
加载数据当中...加载完成！
-------------
1.单链表
2.栈
3.队列
4.退出系统 => 保存内存数据
-------------
请选择：1

-------------
当前数据结构是：xxx
1.查看
2.增加
3.删除
4.查询
5.返回上一级菜单
-------------
请选择：
*/
// 数据结构系统类
class DSSystem
{
public:
	void run() // 系统的启动函数
	{
		// 1.加载文件中的数据
		loaddata();
		// 2.显示主菜单
		cout << "-------------" << endl;
		cout << "1.单链表" << endl;
		cout << "2.栈" << endl;
		cout << "3.队列" << endl;
		cout << "4.退出系统" << endl;
		cout << "-------------" << endl;
		cout << "请选择:";
		cin >> mDsChoice;//成员 所以在整个类内都可以看到

		switch (mDsChoice)
		{
		case 1:
		case 2:
		case 3:
			runChild();
			break;
		case 4:
			cout << "保存数据中...";
			// 保存数据，写入文件
			savedata();
			cout << "保存成功！欢迎下次使用！" << endl;
			return;
		}
	}

	void runChild() // 系统二级菜单的启动函数
	{
		int choice = 0;

		int linkadd = 0;
		int stackadd = 0;
		int queueadd = 0;

		int linkselect = 0;
		int stackselect = 0;
		int queueselect = 0;
		cout << "-------------" << endl;
		cout << "当前选择的数据结构是:" << "xxx" << endl;
		cout << "1.查看" << endl;
		cout << "2.增加" << endl;
		cout << "3.删除" << endl;
		cout << "4.查询" << endl;
		cout << "5.返回" << endl;
		cout << "-------------" << endl;
		cout << "请选择:";
		cin >> choice;
		switch (choice)//选择的功能
		{
		case 1://选择查看功能
			if (mDsChoice == 1)
			{
				mlink.show();
			}
			else if (mDsChoice == 2)
			{
				mstack.show();
			}
			else if (mDsChoice == 3)
			{
				mqueue.show();
			}
			runChild();
			break;
		case 2://选择增加功能
			if (mDsChoice == 1)
			{
				cout << "请输入要增加到单链表的元素---" << endl;
				cin >> linkadd;
				mlink.insertHead(linkadd);
			}
			else if (mDsChoice == 2)
			{
				cout << "请输入要增加到栈的元素---" << endl;
				cin >> stackadd;
				mstack.push(stackadd);
			}
			else if (mDsChoice == 3)
			{
				cout << "请输入要增加到队列的元素--- :" ;
				cin >> queueadd;
				mqueue.addQue(queueadd);
			}
			runChild();
			break;
		case 3://删除
			if (mDsChoice == 1)
			{
				mlink.remove(1);
			}
			else if (mDsChoice == 2)
			{
				mstack.pop();
			}
			else if (mDsChoice == 3)
			{
				mqueue.delQue();
			}
			runChild();
			break;
		case 4://查询
			if (mDsChoice == 1)
			{
				cout << "请输入要查找的单链表的元素---" << endl;
				cin >> linkselect;
				mlink.select(linkselect);
				
			}
			else if (mDsChoice == 2)
			{
				cout << "请输入要查找的栈的元素---" << endl;
				cin >> stackselect;
				mstack.select(stackselect);
			}
			else if (mDsChoice == 3)  
			{
				cout << "请输入要查找的队列的元素---" << endl;
				cin >> queueselect;
				mqueue.select(queueselect);
			}
			runChild();
			break;
		case 5:
			{
				run();
			}
			return;
		}
	}


private:
	CSeqStack mstack;
	CCircleQueue mqueue;
	Link mlink;
	FILE *mfile;
	int mDsChoice; // 表示主菜单选择的数据结构 成员变量
	
	void loaddata()
	{
		cout << "数据加载中" << endl;
		mfile=fopen("Stack.txt", "r");
		if (mfile == nullptr)
		{
			cout << "加载失败" << endl;
		}
		
		fseek(mfile, 0, SEEK_END);//将指针指向文件尾部
		int size = ftell(mfile);//返回当前文件位置
		rewind(mfile);//将文件指针重新指向开头
		//申请一块能装得下整个文件的空间
		char *ar = new char[size+1];//char'1'/1? /' '?2 3//1 2 3
		//读文件                        a[0] a[1]
		fread(ar, 1, size, mfile);//每次读一个 共读size次
		ar[size] = ' ';
		int num = 0;
		for (int i =0;i<size;i++)
		{
			if (ar[i] != ' ')
			{
				num *= 10;//14=10+4
				num += (ar[i] - 48);//4的ASCII码-零的ASCII
			}
			else
			{
				mstack.push(num);//一组数字全部压进去以后再置为零
				num = 0;
			}
			
		}
		mstack.show();
		cout << "Stack加载完成!" << endl;
		fclose(mfile);
		mfile = nullptr;
		delete[]ar;
		ar = nullptr;


		mfile = fopen("Queue.txt", "r");
		if (mfile == nullptr)
		{
			cout << "加载失败" << endl;
		}

		fseek(mfile, 0, SEEK_END);//将指针指向文件尾部
		size = ftell(mfile);//返回当前文件位置
		rewind(mfile);//将文件指针重新指向开头
		//申请一块能装得下整个文件的空间
		ar = new char[size + 1];//char'1'/1? /' '?2 3//1 2 3
		//读文件                        a[0] a[1]
		fread(ar, 1, size, mfile);//每次读一个 共读size次
		ar[size] = ' ';
		num = 0;
		for (int i = 0; i < size; i++)
		{
			if (ar[i] != ' ')
			{
				num *= 10;//14=10+4
				num += (ar[i] - 48);//4的ASCII码-零的ASCII
			}
			else
			{
				mqueue.addQue(num);//一组数字全部压进去以后再置为零
				num = 0;
			}

		}
		mqueue.show();
		cout << "Queue加载完成!" << endl;
		fclose(mfile);
		mfile = nullptr;
		delete[]ar;//把ar占的内存释放掉
		ar = nullptr;//防止野指针


		mfile = fopen("Link.txt", "r");
		if (mfile == nullptr)
		{
			cout << "加载失败" << endl;
		}

		fseek(mfile, 0, SEEK_END);//将指针指向文件尾部
		size = ftell(mfile);//返回当前文件位置
		rewind(mfile);//将文件指针重新指向开头
		//申请一块能装得下整个文件的空间
		ar = new char[size + 1];//char'1'/1? /' '?2 3//1 2 3
		//读文件                        a[0] a[1]
		fread(ar, 1, size, mfile);//每次读一个 共读size次
		ar[size] = ' ';
		num = 0;
		for (int i = 0; i < size; i++)
		{
			if (ar[i] != ' ')
			{
				num *= 10;//14=10+4
				num += (ar[i] - 48);//4的ASCII码-零的ASCII
			}
			else
			{
				mlink.insertHead(num);//一组数字全部压进去以后再置为零
				num = 0;
			}

		}
		mlink.show();
		cout << "Link加载完成!" << endl;
		fclose(mfile);
		mfile = nullptr;
		delete[]ar;//把ar占的内存释放掉
		ar = nullptr;//防止野指针
	}
	void savedata()
	{
		mfile=fopen("Stack.txt","w");
		while (!mstack.empty())
		{
			char ar[20];
			_itoa(mstack.top(), ar, 10);//获取栈顶元素 每次只获取一个
			fputs(ar, mfile);//把数字写进文件里
			fputc(' ', mfile);//用空格把数字隔开
			mstack.pop();//获取一个让她出一个 获取一个让她出一个
		}
		fclose(mfile);
		mfile = nullptr;

		mfile = fopen("Queue.txt", "w");
		while (!mqueue.empty())
		{
			char ar[20];
			//mstack[i]里的成员都是私有的在类外无法访问 所以用类的方法
			_itoa(mqueue.back(), ar, 10);//获取栈顶元素 每次只获取一个
			fputs(ar, mfile);//把数字写进文件里
			fputc(' ', mfile);//用空格把数字隔开
			mqueue.delQue();//获取一个让她出一个 获取一个让她出一个
		}
		fclose(mfile);
		mfile = nullptr;

		mfile = fopen("Link.txt", "w");
		while (!mlink.empty())
		{
			char ar[20];
			_itoa(mlink.back(), ar, 10);//获取栈顶元素 每次只获取一个
			fputs(ar, mfile);//把数字写进文件里
			fputc(' ', mfile);//用空格把数字隔开
			mlink.remove();//获取一个让她出一个 获取一个让她出一个
		}
		fclose(mfile);
		mfile = nullptr;

	}
};

int main()
{

	DSSystem ds;
	ds.run();
}
//int sum(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int array[] = { 12,3,4,5,6 };
//	int *p = array;
//
//    std::cout << "Hello World!\n"; 
//	//引用函数
//	int (&q)(int, int) = sum;
//	//请在内存0x0018ff44写一个四字节的整数10
//	//用指针做
//	int *n = (int *)0x0018ff44;
//	*n = 10;
//	//用引用做
//	int *const &n=(int *)0x0018ff44;//不用const的话 右边不能为常量 const得加在中间
//
//}
/*



*/


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

