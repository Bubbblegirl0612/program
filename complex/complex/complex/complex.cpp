#include<iostream>
using namespace std;

// 复数类
class CComplex
{
public:
	CComplex(int r = 0, int i = 0)
		:mreal(r), mimage(i)
	{
		cout << "CComplex(int r = 0, int i = 0)" << endl;
	}
	~CComplex() //没访问外部资源,析构这就啥也不干(有指针就有可能会访问外部资源就要析构掉)
	{
		cout << "~CComplex" << endl;
	}
	
	CComplex& operator++()//前置加加 
	{//自己加一遍 再把自己赋给别人 这个不产生临时对象 可以返回引用因为一直都用的是本身
		//返回的并不是临时量 所以子函数结束后return后面的值还在
		++mreal; 
		++mimage;
		return *this;
	}
	CComplex operator++(int)//后置加加 
	{
		return CComplex(mreal++, mimage++);//先构造临时对象=对象本身.然后再给对象本身++
		//所以一般我们会优先选择前置++来写
	}
	void operator=(const CComplex &src)//赋值
	{
		cout << "void operator=(const CComplex &src)" << endl;
		mreal = src.mreal;
		mimage = src.mimage;
	}//comp3 = 对象  opertor=(this(comp3),对象) 把等号后面的赋给前面的 所以不用返回值
	void operator+=(const CComplex &src)//a=a+b
	{
		mreal += src.mreal;
		mimage += src.mimage;
	}
	bool operator>(const CComplex &src)
	{
		return ((mreal>src.mreal)||((mreal == src.mreal)&&(mimage>src.mimage)));
	}
	bool operator<(const CComplex &src)
	{
		return ((mreal < src.mreal) || ((mreal == src.mreal) && (mimage < src.mimage)));
	}
	bool operator==(const CComplex &src)
	{
		return ((mreal == src.mreal) && (mimage == src.mimage));
	}

	void show()
	{
		cout << "real:" << mreal << " image:" << mimage << endl;
	}
	friend CComplex operator + (const CComplex & a, const CComplex & b);
	friend ostream& operator<<(ostream &out, const CComplex &src);
	friend istream& operator>>(istream &cin, const CComplex &src);
private:
	int mreal;//实数
	int mimage;//虚数
};
//双目运算符的函数参数只能有两个,一个this 一个是传进来的.(成员方法中)
//所以这个加号重载只能写在全局 不然写成成员方法的话会默认传一个this指针,会变成三个参数

CComplex operator+(const CComplex &a, const CComplex &b)
{
	cout << "CComplex operator+(const CComplex &a, const CComplex &b)" << endl;
	return CComplex(a.mreal + b.mreal, a.mimage + b.mimage); //返回一个临时对象
}
ostream& operator<<(ostream &out, const CComplex &src)
{
	out << "real:" << src.mreal << " image:" << src.mimage << endl;
	return out;
}
//cout << comp1 << endl;双目运算符有两个参数，一个是输出流 一个是对象
//istream& operator>>(istream &in, const CComplex &src)
//{
//	in >> src.mreal >> src.mimage;
//	return in;
//}



int main()
{
	CComplex comp1(10, 10);
	CComplex comp2(20, 20);
	
	cout << "=================" << endl;
	CComplex comp3 = comp1 + comp2;
	//临时对象构造对象直接变成对象的构造 临时对象的构造将不会产生
	comp3.show();
	cout << "============" << endl;
	
	// comp1.operator+(const CComplex &src)
	//comp3 = 对象  opertor=(this(comp3),对象)
	comp3 = comp1 + 20; // int => CComplex(int) 
	comp3.show();

	comp3 = 20 + comp1;//一个内置类型的数加上复数
	//1.20 构造类对象
	//2.构造临时对象
	//3.赋值重载
	comp3.show();

	cout << "============" << endl;
	comp2 = comp1++;//
	comp1.show();
	comp2.show();
	cout << "============" << endl;
	comp2 = ++comp1;
	comp1.show();
	comp2.show();

	comp2 += comp1;
	comp1.show();
	comp2.show();

	if (comp1 > comp2)
	{
		cout<<"cmp1大"<<endl;
	}
	cout << "============" << endl;
	//  ostream& out, const CComplex &src
	cout << comp1 << endl;//直接调用运算符重载函数 输出函数内的输出
	cout << "============" << endl;
	//cin >> comp1;
	//comp1.show();
	return 0;
}