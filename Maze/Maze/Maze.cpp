// Maze.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
//常量定义存储方向
const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;
const int WAY_NUM = 4;//定义行走状态
const int YES = 5;
const int NO = 6;

//c抽象迷宫节点类型
class MazeNode
{
public:

private:
	int mval;//存储数据 节点值
	int mx, my;//存储坐标
	int mstate[WAY_NUM];//节点四个方向的状态


};
class CStack
{
public:

private:
	MazeNode *mpstack;
	int mtop;
	int msize;

};
//动态开辟二维数组用二级指针

class Maze
{
public:
	Maze(int row, int col)
	{

	}
	~Maze()
	{

	}

private:
	int mrow;//行
	int mcol;//列
	MazeNode **mpMaze;
};
int main0()
{
	cout << "请输入迷宫路径的行列数" << endl;
	int row, col;
	cin >> row >> col;
	Maze maze(row, col);

	cout << "请输入迷宫的具体路径" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int data;
			cin >> data;
			
		}
	}
	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
