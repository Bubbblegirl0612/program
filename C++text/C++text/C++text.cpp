// C++text.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <functional> // 函数对象
#include <algorithm> // 泛型算法 =  template + 迭代器 + 函数对象
#include <queue>
using namespace std;

template<typename K, typename Compare>
class MySet
{
public:
	MySet(Compare comp = Compare())
		:_comp(comp)
	{
		_root = nullptr;
	}
	~MySet()
	{
		// 释放所有的节点
	}
	void insert(const K &key)
	{
		if (_root == nullptr)//如果根节点没有
		{
			_root = new Node(key);//新建一个根节点
			return;
		}
		if (key > _root._data)
		{
			ptmp = _root._data;

		}
	}
private:
	struct Node
	{
		Node(K data = K())
			:_data(data), _left(nullptr), _right(nullptr) {}
		K _data;
		Node *_left;
		Node *_right;
	};

	Node *_root;
	Compare _comp; // 自定义函数对象
};
int main()
{

	return 0;
#if 0
int main()
{
	FILE *pf = fopen("data.dat", "wb");
	for (int i = 0; i < 100000; ++i)
	{
		int data = rand() % 65535;
		fwrite(&data, 4, 1, pf);
	}
	fclose(pf);
	 
	FILE *pf = fopen("data.dat", "rb");//
	FILE *pfArr[11];//文件数组 但是没有指向文件空间
	char buf[20];//创建存文件名的数组
	for (int i = 0; i < 11; ++i)
	{
		sprintf(buf, "data%d.dat", i + 1);//用buf接收小文件的名字,
		pfArr[i] = fopen(buf, "wb+");//打开我们刚起好名字的文件,因为没有所以会新创建文件出来.
		//小文件得可读可写
		//1.打开文件  用文件中每个数模上11,看这个数去哪个文件
		//2.进行top-k比较  看那个数字出现的次数最多
		int data = 0;
		while(!feof(pf))//当文件指针没有到末尾的时候
		{
			fread(&data, 4, 1, pf);
			int index = data % 11;//确定这个data到底存到哪个小文件里
			fwrite(&data, 4, 1, pfArr[index]);//把这个数据写入到指定的小文件
	}
		fclose(pf);
		//for (int i = 0; i < 11; ++i)
		//{
		//	fseek(pfArr[i], 0, SEEK_SET);//把pfArr[i]这个指针移到文件刚开始
		//}
		//对每个文件进行重复次序的排序
		for (int i = 0; i < 11; ++i)
		{
			//fseek(pfArr[i], 0, SEEK_END);//把pfArr[i]这个指针移到文件刚开始
			int length = ftell(pfArr[i]);//当前文件的长度
			int size = length / sizeof(int);
			fseek(pfArr[i], 0, SEEK_SET);
			int *pbuf = new int[size];
			fread(pbuf, size, 1, pfArr[i]);
			for(int j=0;j<size;++j)
			{
				map[pbuf[j]]++;

		}

#endif

}


#if 0
/*
实现一个链式哈希表
*/
template<typename K>
class CHashTable
{
public:
	CHashTable(double loadFactor = 0.75)
		:muse_bucket_num(0)
		, mloadFactor(loadFactor)
	{
		mhashTable.resize(mprimeTable[0]);
	}

	void insert(const K &key) // 哈希表增加元素
	{//1.给桶里添加值,
		int index = getHash(key) % mhashTable.size();
		list<K> &mylist = mhashTable(index);
		double lf = muse_bucket_num * 1.0 / mall_bucket_num;
		if (lf > mloadFactor)
		{
			resize();
		}
		if (mylist.empty())
		{
			mylist.push_back(key);
			muse_bucket_num++;
		}
		else
		{
			auto it = mylist.begin();
		/*	for (; it != mylist.end(); ++it)
			{
				if (key == *it)
				{
					return;
				}
			}*/
			
		 
		}
	}
	void erase(const K &key)  // 哈希表删除元素
	{
		int index = mhashTable.getHash(key) % mhashTable.size();
		list<K> &mylist = mhashTable[index];
		for (K &val : mylist)
		{
			if (val == key)
			{
				mylist.erase(key);
				return;
			}
		}

	}
	bool query(const K &key)  // 哈希表查找元素
	{

	}
private:
	vector<list<K>> mhashTable; // 链式哈希表
	int muse_bucket_num; // 已使用的桶数量
	double mloadFactor; // 加载因子
	static int mprimeTable[4]; // 素数表
	static int mprimeIndex; // 素数表的下标

	void resize() // 哈希表扩容函数
	{//扩容扩的是list

	}

	int getHash(const K &key)
	{
		// 通用的计算key散列码的方式
		int size = sizeof(K);
		int sum = 0;
		char *p = (char*)&key;
		for (int i = 0; i < size; ++i)
		{
			sum += (p[i] << i);  // hello olleh
		}
		return sum;
	}
};
// {3, 7, 23, 53}
template<typename K, typename Hash>
int CHashTable<K, Hash>::mprimeTable[4] = { 3, 7, 23, 53 };

template<typename K, typename Hash>
int CHashTable<K, Hash>::mprimeIndex = 0;

int main()
{
	return 0;
}
#endif

#if 0
//正确的
// 默认的计算哈希的实现类
template<typename K>
class default_hash
{
public:
	int getHash(const K &key)
	{
		// 通用的计算key散列码的方式
		int size = sizeof(K);
		int sum = 0;
		char *p = (char*)&key;
		for (int i = 0; i < size; ++i)
		{
			sum += (p[i] << i);  // hello olleh
		}
		return sum;
	}
};

#if 0
template<>
class default_hash<string>
{
public:
	//??????为啥不一样
	int getHash(const string &key)
	{
		int hash = 0;
		for (int i = 0; i < key.length(); ++i)
		{
			hash += (key[i] << i);
		}
		return hash;
	}
};
#endif

template<typename K, typename Hash = default_hash<K>>
class CHashTable
{
public:
	CHashTable(double loadFactor = 0.75)
		:mpTable(new Node[mprimeTable[0]])
		, mall_bucket_num(mprimeTable[0])
		, muse_bucket_num(0)
		, mloadFactor(loadFactor)
	{}

	~CHashTable()
	{
		delete[]mpTable;
		mpTable = nullptr;
	}

	void insert(const K &key) // 哈希表增加元素
	{
		double lf = muse_bucket_num * 1.0 / mall_bucket_num;
		cout << "loadfactor:" << lf << endl;
		if (lf > mloadFactor)
		{
			resize();
		}

		int index = mhash.getHash(key) % mall_bucket_num;
		int index_stat = index;
		do
		{
			if (USING != mpTable[index].mstate)
			{
				mpTable[index].mdata = key;
				mpTable[index].mstate = USING;
				muse_bucket_num++;
				return;
			}
			index = (index + 1) % mall_bucket_num;
		} while (index_stat != index);
	}
	void erase(const K &key)  // 哈希表删除元素
	{
		int index = mhash.getHash(key) % mall_bucket_num;
		int index_stat = index;

		do
		{
			if (UNUSE == mpTable[index].mstate)
			{
				return;
			}
			if (USING == mpTable[index].mstate
				&& key == mpTable[index].mdata)
			{
				mpTable[index].mstate = USED;  //析构
				muse_bucket_num--;
				return;
			}
			index = (index + 1) % mall_bucket_num;
		} while (index_stat != index);
	}
	bool query(const K &key)  // 哈希表查找元素
	{
		int index = mhash.getHash(key) % mall_bucket_num;
		int index_stat = index;

		do
		{
			if (USING == mpTable[index].mstate
				&& key == mpTable[index].mdata)
			{
				return true;
			}
			if (UNUSE == mpTable[index].mstate)
			{
				return false;
			}
			index = (index + 1) % mall_bucket_num;
		} while (index_stat != index);

		return false;
	}
private:
	enum STATE { USING, USED, UNUSE }; // 枚举桶的状态
	struct Node // 桶元素的类型
	{
		Node(K data = K())   // int double int() = 0 
			:mstate(UNUSE)
			, mdata(data) {}
		STATE mstate;
		K mdata;
	};
	Node *mpTable; // 桶的数组
	int mall_bucket_num; // 桶的总数量
	int muse_bucket_num; // 已使用的桶数量
	double mloadFactor; // 加载因子
	Hash mhash; // 计算散列码的对象
	static int mprimeTable[4]; // 素数表
	static int mprimeIndex; // 素数表的下标

	void resize() // 哈希表扩容函数
	{
		mprimeIndex += 1;
		Node *ptmp = new Node[mprimeTable[mprimeIndex]];

		for (int i = 0; i < mall_bucket_num; i++)
		{
			if (USING == mpTable[i].mstate)
			{
				int index = mhash.getHash(mpTable[i].mdata) % mprimeTable[mprimeIndex];
				int index_stat = index;

				do
				{
					if (UNUSE == ptmp[index].mstate)
					{
						ptmp[index].mdata = mpTable[i].mdata;
						ptmp[index].mstate = USING;
						break;
					}
					index = (index + 1) % mprimeTable[mprimeIndex];
				} while (index_stat != index);
			}
		}
		delete[]mpTable;
		mpTable = ptmp;
		mall_bucket_num = mprimeTable[mprimeIndex];
	}
};
// {3, 7, 23, 53}
template<typename K, typename Hash> //3：模板类型在类外的使用
int CHashTable<K, Hash>::mprimeTable[4] = { 3, 7, 23, 53 };

template<typename K, typename Hash>
int CHashTable<K, Hash>::mprimeIndex = 0;

int main()
{
#if 0
	CHashTable<int> hashTable;

	for (int i = 0; i < 20; ++i)
	{
		hashTable.insert(rand() % 100);
	}
#endif

	CHashTable<string>  strHash;
	strHash.insert("aaa");
	strHash.insert("bbb");
	strHash.insert("ccc");
	strHash.insert("dda");

	class Student
	{
	public:
		Student(string name = "", double score = 0.0)
			:_name(name), _score(score) {}
		bool operator==(const Student &stu)const
		{
			return _name == stu._name;
		}
	private:
		string _name;
		double _score;
	};
	CHashTable<Student> studentHash;
	studentHash.insert(Student("张三", 98.5));
	studentHash.insert(Student("李四", 99.5));
	studentHash.insert(Student("王五", 89.5));

	cout << studentHash.query(Student("张三", 98.5)) << endl;

	return 0;
}
#endif

#if 0
// 默认的计算哈希的实现类
//实现线性探测哈希表
template<typename K>
class default_hash
{
public:
	int getHash(const K &key)
	{
		return key;
	}
};

template<>//特例化模板
class default_hash<string>
{
public:
	int getHash(const string &key)//提供了string对象怎么存到哈希表
	{
		int hash = 0;
		for (int i = 0; i < key.length(); ++i)//遍历的string的元素
		{
			hash += (key[i] << i);//   << i左移i位  避免hello和olleh的ASCII码相同
		}
		return hash;//返回int下标 返回存到了哈希表那个位置上
	}
};

template<typename K, typename Hash = default_hash<K>>
class CHashTable
{
public:
	CHashTable(double loadFactor = 0.75) :mloadFactor(loadFactor)
	{
		mall_bucket_num = mprimeTable[mprimeIndex];
		mpTable = new Node[mall_bucket_num];//桶都要用定的节点初始化一下
		muse_bucket_num = 0;
		for (int i = 0; i < mall_bucket_num; i++)
		{
			mpTable[i].mstate = UNUSE;//把每个桶的初始状态都定为未用过
		}
	}

	~CHashTable() 
	{
		delete[]mpTable;
		mpTable = nullptr;
	}

	void insert(const K &key) // 哈希表增加元素
	{
		if (((muse_bucket_num + 1) / mall_bucket_num) > mloadFactor)
		{//因为已使用的桶的数量初始化为0
			resize();
		}
		int index = mhash.getHash(key) % mall_bucket_num;
		if (mpTable[index].mstate == UNUSE|| mpTable[index].mstate == USED)
		{//只要不是正在用就都可以放数据
			mpTable[index].mdata = key;
			mpTable[index].mstate = USING;
		}
		else
		{
			int i = index;
			while (i++ % index)
			{
				if (mpTable[i].mstate == UNUSE || mpTable[i].mstate == USED)
				{
					mpTable[i].mdata = key;
					break;
				}
			}
		}
		muse_bucket_num + = 1;
	}
	void erase(const K &key)  // 哈希表删除元素
	{
		int index = mhash.getHash(key) % mall_bucket_num;
		if(mpTable[index].mdata==key)
		{
			mpTable[index].mdata == 0;
			mpTable[index].mstate = USED;
		}
		else
		{
			int i = index;
			while (i++ % index)
			{
				if (mpTable[i].mstate == UNUSE || mpTable[i].mstate == USED)
				{
					throw "no this item";
				}
				else
				{
					if (mpTable[i].mdata == key)
					{
						mpTable[index].mdata = 0;
						mpTable[index].mstate = USED;
					}
				}
			}
		}
		throw "no this item";
	}

	bool query(const K &key) // 哈希表查找元素
	{
		int index = mhash.getHash(key) % mall_bucket_num;
		if (mpTable[index].mdata == key)
		{
			return true;
		}
		else
		{
			int i = index;
			while (i++ % index)
			{
				if (mpTable[i].mstate == UNUSE || mpTable[i].mstate == USED)
				{
					return false;
				}
				else
				{
					if (mpTable[i].mdata == key)
					{
						return true;
					}
				}
			}
		}
		return false;
	}

private:
	enum STATE { USING, USED, UNUSE }; // 枚举桶的状态
	struct Node // 桶元素的类型 包括了数据和状态
	{
		STATE mstate;
		K mdata;
	};
	Node *mpTable; // 桶的数组
	int mall_bucket_num; // 桶的总数量
	int muse_bucket_num; // 已使用的桶数量
	double mloadFactor; // 加载因子
	Hash mhash; // 计算散列码的对象
	static int mprimeTable[4]; // 素数表
	static int mprimeIndex; // 素数表的下标

	void resize(); // 哈希表扩容函数
};
// {3, 7, 23, 53}
// {3, 7, 23, 53}
template<typename K, typename Hash>
int CHashTable<K, Hash>::mprimeTable[4] = { 3, 7, 23, 53 };
template<typename K, typename Hash>
int CHashTable<K, Hash>::mprimeIndex = 0;

int main()
{


	return 0;
}
#endif


#if 0
class BigInt
{
public:
	BigInt(string str) :strDigit(str) {}
private:
	string strDigit;   // 使用字符串存储大整数
};
// 打印函数ostream& operator<<(ostream &out, const BigInt &src);
// 大数加法
BigInt operator+(const BigInt &lhs, const BigInt &rhs)
{
	int pix = 0;//存进位
	vector<int> lvec;//保存左值
	vector<int> rvec;//保存右值
	int sumtmp; //保存返回值
	string tmp;
	int lsize = lhs.strDigit.length();
	for (int i = 0, j = lsize - 1; i < lsize; ++i, --j)
	{
		lvec.push_back(lhs.strDigit[j] - '0');
	}
	int rsize = rhs.strDigit.length();
	for (int i = 0, j = rsize - 1; i < rsize; ++i, --j)
	{
		rvec.push_back(rhs.strDigit[j] - '0');
	}
	int min = (lsize > rsize ? rsize : lsize);
	for (int i = 0; i < min; i++)
	{
		int j = lvec[i] + rvec[i];
		sumtmp = j % 10;
		pix = j / 10;
		tmp.push_back(sumtmp + '0');
	}
	while (rsize > min)
	{
		int j = rvec[min] + pix;
		sumtmp = j % 10;
		pix = j / 10;
		tmp.push_back(sumtmp + '0');
		min++;
	}
	while (lsize > min)
	{
		int j = lvec[min] + pix;
		sumtmp = j % 10;
		pix = j / 10;
		tmp.push_back(sumtmp + '0');
		min++;
	}
	return BigInt(tmp);
}
// 大数减法
BigInt operator-(const BigInt &lhs, const BigInt &rhs)
{

}
int main()
{
	BigInt int1("28937697857832167849697653231243");
	BigInt int2("9785645649886874535428765");
	cout << int1 + int2 << endl;
	cout << int1 - int2 << endl;
	return 0;
}


// 类模板 vector 默认构造 size:0-1-2-4-8-16-32-64....
template<typename T = int>
class Vector // 类的模板名字
{
public:
	Vector();
	~Vector();
	Vector(const Vector<T> &vec);
	Vector(Vector<T> &&vec);
	void operator=(const Vector<T> &vec);
	void operator=(Vector<T> &&vec);

	void reserve(int size); // 预留函数

	void push_back(const T &val); // 末尾添加元素
	void pop_back(); // 末尾删除元素
	bool empty()const; // 判空
	bool full()const; // 判满
	int size()const;//返回vector容器元素的个数

	void show()const; // 打印vector容器的所有元素
private:
	T *mpvec;
	int mcur;
	int msize;

	void resize(); // vector容器底层默认2倍扩容
};

template<typename T>
Vector<T>::Vector()
	:mcur(0)
	, msize(0)
	, mpvec(nullptr) {}

template<typename T>
Vector<T>::~Vector()
{
	delete[]mpvec;
	mpvec = nullptr;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& vec)//左值拷贝构造
{
	mpvec = new T[vec.size()];
	for (int i = 0; i < mcur; i++)
	{
		mpvec[i] = vec.mpvec[i];
	}
	msize = vec.msize;//空间大小
	mcur = vec.mcur;//现在存的元素个数
}

template<typename T>
Vector<T>::Vector(Vector<T>&& vec)
{
	mpvec = vec.mpvec;
	vec.mpvec = nullptr;
}

template<typename T>
void Vector<T>::operator=(const Vector<T>& vec)
{
	if (this == vec)
	{
		return;
	}
	delete[]mpvec;
	mpvec = new T[vec.msize];
	for (int i = 0; i < mcur; i++)
	{
		mpvec[i] = vec.mpvec[i];
	}
	msize = vec.msize;//空间大小
	mcur = vec.mcur;//现在存的元素个数

}

template<typename T>
void Vector<T>::operator=(Vector<T>&& vec)
{
	if (this == &vec)
	{
		return;
	}
	delete[]mpvec;
	msize = vec.msize;
	mcur = vec.mcur;
	mpvec = vec.mpvec;
	vec.mpvec = nullptr;
}

template<typename T>
void Vector<T>::reserve(int size)
{
	mpvec = new T[size];//T就是传入的类型 也就是我新创建的空间 类似于new int[size]
}

template<typename T>
void Vector<T>::push_back(const T & val)//尾部添加
{
	if (full())
	{
		resize();
	}
	mpvec[mcur++] = val;

}

template<typename T>
void Vector<T>::pop_back()//尾部删除
{
	if (empty())
	{
		return;
	}
	mcur--;
}

template<typename T>
bool Vector<T>::empty() const
{
	return mcur == 0;
}

template<typename T>
bool Vector<T>::full() const
{
	return mcur == msize;
}

template<typename T>
int Vector<T>::size() const
{
	return mcur;
}

template<typename T>
void Vector<T>::show() const
{
	for (int i = 0; i < mcur; i++)
	{
		cout << mpvec[i];
	}
	cout << endl;
}

template<typename T>
void Vector<T>::resize()//扩容
{
	T *tmp = new T[(msize+1) * 2];
	for (int i = 0; i < msize; i++)
	{
		tmp[i] = mpvec[i];
	}
	delete[]mpvec;//释放原先的
	mpvec = tmp;//将原来的指针指向新的
	msize = msize * 2;
}



int main()
{
	Vector<> intVec;
	intVec.push_back(20);
	intVec.push_back(30);
	intVec.push_back(21);
	intVec.show();

	return 0;
}
#endif
/*#if 0
template<typename T>
int findValueIndex(T arr[], int size, const T val)
{
	cout << typeid(T).name() << endl;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == val)
			return i;
	}
	return -1;
}
template<>
int findValueIndex<const char*>(const char* arr[], int size, const char * val)
{
	cout << "findValueIndex<const char*> " << endl;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i], val) == 0)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 12,3,4,5,6 };
	cout << findValueIndex<int>(arr, 5, 12) << endl;

	const char *strArr[] = { "aaa", "bbb", "ccc" };
	cout << findValueIndex<const char*>(strArr, 3, "bbb") << endl;

	return 0;
}
#endif*/