
#include <string>
#include <vector>
#include<iostream>
using namespace std;

//有空间配置器的vector
//把所有用到释放构造析构等的地方都改为空间配置器的函数
template<typename T>
struct myallocator
{
	//内存开辟
	T*allocate(size_t size)
	{
		return (T*)malloc(size * sizeof(T));
	}
	//内存释放
	void deallocate(T *ptr)
	{
		free(ptr);//free释放
	}
	//对象构造
	void construct(T *ptr, const T &obj)
	{
		new (ptr) T(obj);
	}
	//对象析构
	void destroy(T *ptr)
	{
		ptr->~T();
	}
};

template<typename T=int,typename _Alloc=myallocator<T>>
class Vector
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
	int size()const; // 返回vector容器元素的个数
	void show()const; // 打印vector容器的所有元素

	class iterator
	{
	public:
		iterator(char *p = nullptr) :_ptr(p) {}
		bool operator!=(const iterator &it)
		{
			return _ptr != it._ptr;
		}
		bool operator == (const iterator &it)
		{
			return _ptr != it._ptr;
		}
		void operator++()
		{
			_ptr++;
		}
		T& operator*()
		{
			return *_ptr;
		}

	private:
	//	char *_ptr;
		T *_ptr;
	};
	iterator begin()
	{
		return iterator(mpvec);
	}
	iterator end() {
		return iterator(mpvec + mcur);
	}
	//插入函数
	iterator insert(iterator &where, const T &val)
	{//1.判断是否满 没满的话再插入值
		//2.
		if (where._ptr<mpvec || where._ptr>mpvec + mcur)
		{//mpvec是数组空间 是连续的空间,不能跳着插 
			throw"xxx";//抛异常
		}
		if(full())
		{
			int offset = where._ptr - mpvec;//保存要插入的位置下标
			resize();//因为resize后原先的空间没有了 所以前面要保存下标 
			where._ptr = mpvec + offset;//不用offset继续代表插入位置下标的原因是因为resize之后where指向的内存已经释放掉了
			//所以要重置where内存指针  offset是下标 where_ptr是指针
		}
		T *p = mpvec + mcur;//建一个指向数组存了值的最后一位的指针
		while (p > where._ptr)//把要插入位置的元素后面往后挪
		{//指针先指到数组存值的最后一位
			malloctor.construct(p, *(p - 1));
	//从当前数组存的元素最后一个开始往后挪动,先往后挪动一个
			malloctor.destroy(p - 1);
    //然后销毁前一个被挪动到后面的
			p--;//将指针向前挪动一位
		}
		malloctor.construct(p, val);//一直到p挪动到要插入的位置 放入插入值
		mcur++;//数组存的总元素+1
		return iterator(p);//返回一个迭代器表示 当前指向p指向的值
	}
	// 3.删除指定位置的元素
	iterator erase(iterator where)
	{
		if (where._ptr < mpvec || where._ptr > mpvec + mcur - 1)
		{//不符合的话报错 要删除的元素越界的话
			throw "xxx";
		}
		T *p = where._ptr;
		while (p < mpvec + mcur - 1)
		{//从要被删除的元素位置开始向后移动
			malloctor.destroy(p);//先删除要删除的元素
			malloctor.construct(p, *(p + 1));//然后把后面的元素补上来
			p++;
		}
		malloctor.destroy(p);//最后析构最后一个对象 因为mcur指向的地方不存值
		mcur--;
		return iterator(where._ptr); // T* iterator(T*)
	}

	// 4.提供operator[]    vec[2];
	T& operator[](int index) { return mpvec[index]; }
private:
	T *mpvec;//数组 单一的mpvec是数组的首地址或者数组退化成指针
	int mcur;//当前大小 不是指针!!! 
	int msize;//数组空间大小
	myallocator<T> malloctor;//定义空间配置器对象
	void resize(); // vector容器底层默认2倍扩容

};

template<typename T,typename _Alloc>
Vector<T, _Alloc>::Vector()
	:mcur(0)
	, msize(0)
	, mpvec(nullptr) {}

template<typename T, typename _Alloc>
Vector<T, _Alloc>::~Vector()
{
	for (int i = 0; i < mcur; ++i)
	{//析构容器中的有效对象 析构一个指针走一个
		malloctor.destroy(mpvec + i);
	}
	//当有效对象都析构完了,就把容器的内存释放掉
	malloctor.deallocate(mpvec);
	mpvec = nullptr;
}

template<typename T, typename _Alloc>
Vector<T, _Alloc>::Vector(const Vector<T>& vec)//左值拷贝构造
{
	msize = vec.msize;//空间大小
	mcur = vec.mcur;//现在存的元素个数
	T *ptmp = malloctor.allocate(msize);
	//开辟内存 这里重新定义了数组空间 
	for (int i = 0; i < mcur; i++)
	{
		malloctor.construct(ptmp + i, vec.mpvec[i]);
	}
	mpvec = ptmp;//把旧的指向新的
}

template<typename T, typename _Alloc>
Vector<T, _Alloc>::Vector(Vector<T>&& vec)
{
	mpvec = vec.mpvec;
	vec.mpvec = nullptr;
	mcur = vec.mcur;
	msize = vec.msize;
}

template<typename T, typename _Alloc>
void Vector<T, _Alloc>::operator=(const Vector<T>& vec)
{
	if (this == &vec)
	{
		return;
	}
	
	malloctor.deallocate(mpvec);
	mpvec = nullpter;
//释放然后再重新申请内存再构造
	msize = vec.msize;//空间大小
	mcur = vec.mcur;//现在存的元素个数
	T *ptmp = malloctor.allocate(msize);
	
	for (int i = 0; i < mcur; i++)
	{
		malloctor.construct(ptmp+i, vec.mpvec[i]);
		//把vec里面的东西 拷贝构造给新申请出的内存ptmp
	}
	mpvec = ptmp;
}

template<typename T, typename _Alloc>
void Vector<T, _Alloc>::operator=(Vector<T>&& vec)
{
	if (this == &vec)
	{
		return;
	}
	malloctor.deallocate(mpvec);//释放内存
	msize = vec.msize;
	mcur = vec.mcur;
	mpvec = vec.mpvec;
	vec.mpvec = nullptr;
}

template<typename T, typename _Alloc>
void Vector<T, _Alloc>::reserve(int size)//预留
{
	if (size <= msize)
		return;
	T *ptmp = malloctor.allocate(size);
	for (int i = 0; i < mcur; i++)//把以前内存里的东西放到新的内存里 并且要再预留出一部分
	{
		malloctor.construct(ptmp + i, mpvec[i]);
	}
	malloctor.deallocate(mpvec);
	mpvec = ptmp;//把原先的指针指向新的
	msize = size;//更新大小
}

template<typename T, typename _Alloc>
void Vector<T, _Alloc>::push_back(const T & val)//尾部添加
{
	if (full())
	{
		resize();
	}
	T *ptmp = mpvec;//因为已经判断了是有内存的,所以直接进行对象的构造和放入值
	malloctor.construct(ptmp + mcur, val);
	mcur++;

}

template<typename T, typename _Alloc>
void Vector<T, _Alloc>::pop_back()//尾部删除
{
	if (empty())
	{
		return;
	}
	mcur--;//mcur这歌下标的值是不读的 所以--以后
	malloctor.destroy(mpvec + mcur);//进行指针+偏移量的来确定要析构的对象
}

template<typename T, typename _Alloc>
bool Vector<T, _Alloc>::empty() const
{
	return mcur == 0;
}

template<typename T, typename _Alloc>
bool Vector<T, _Alloc>::full() const
{
	return mcur == msize;
}

template<typename T, typename _Alloc>
int Vector<T, _Alloc>::size() const
{
	return mcur;
}

template<typename T, typename _Alloc>
void Vector<T, _Alloc>::show() const
{
	for (int i = 0; i < mcur; i++)
	{
		cout << mpvec[i] << " ";
	}
	cout << endl;
}

template<typename T, typename _Alloc>
void Vector<T, _Alloc>::resize()//扩容
{
	if (msize > 0)
	{
		T *ptmp = malloctor.allocate(msize*2)
		for (int i = 0; i < msize; i++)
		{
			malloctor.construct(ptmp + i, mpvec[i]);
			// 析构容器中有效的对象
			malloctor.destroy(mpvec + i);
		}
		// 把容器内存释放掉
		malloctor.deallocate(mpvec);//mpvec是数组首地址,所以释放的时候是释放了从mpvec以后的值
		mpvec = ptmp;
		msize *= 2;
	}
	else
	{
		mpvec = malloctor.allocate(1);//vector内存扩容是0,1,2,4,8..当原本的为0时,就要给它新开辟一个空间
		msize = 1;
		mcur = 0;//当前未存元素
	}
}
int main()
{
	Vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100);
	}
	vec.push_back(62);

	auto it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	vec.insert(vec.begin(), 100);
	for (it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		if (*it == 62)
		{
			vec.insert(it, 200);
			break;
		}
	}
	vec.insert(vec.end(), 300);

	for (it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	vec.erase(vec.begin());
	//vec.erase(vec.end());

	it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		if (*it == 200)
		{
			vec.erase(it);
			break;
		}
	}

	for (it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
#if 0
class Test 
{
public:
	Test() :mptr(new int[10000])
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		delete[]mptr;
		cout << "~Test()" << endl;
	}
	Test(const Test& src)
	{
		cout << "Test(const Test&)" << endl;
		mptr = new int[10000];
		memcpy(mptr, src.mptr, 10000 * 4);
	}
	void operator=(const Test& src)
	{
		cout << "operator=" << endl;
		if (this == &src)
			return;
		delete[]mptr;
		mptr = new int[10000];
		memcpy(mptr, src.mptr, 10000 * 4);
	}
private:
	int *mptr;
};
int main()
{
	// C++ STL 组件之一：容器
	Test t1, t2, t3;              //三次构造
	cout << "------------" << endl;
	Vector<Test> vec;
	vec.reserve(10); // 只想预留空间
	cout << "------------" << endl;
	vec.push_back(t1);            //拷贝构造
	vec.push_back(std::move(t2));  //拷贝构造
	vec.push_back(t3);            //拷贝构造
	cout << "------------" << endl;
	vec.pop_back();               //一次析构
	cout << "------------" << endl;
	//五次析构
	return 0;
}
#endif 
#if 0
//Vector
没有内存管理的vector
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
	msize = vec.msize;//空间大小
	mcur = vec.mcur;//现在存的元素个数

	mpvec = new T[msize];
	for (int i = 0; i < mcur; i++)
	{
		mpvec[i] = vec.mpvec[i];
	}
	
}

template<typename T>
Vector<T>::Vector(Vector<T>&& vec)
{
	mpvec = vec.mpvec;
	vec.mpvec = nullptr;
	mcur = vec.mcur;
	msize = vec.msize;
}

template<typename T>
void Vector<T>::operator=(const Vector<T>& vec)
{
	if (this == &vec)
	{
		return;
	}
	delete[]mpvec;
	msize = vec.msize;//空间大小
	mcur = vec.mcur;//现在存的元素个数

	mpvec = new T[vec.msize];
	for (int i = 0; i < mcur; i++)
	{
		mpvec[i] = vec.mpvec[i];
	}


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
void Vector<T>::reserve(int size)//预留
{
	if (size <= msize)
		return;
	T *ptmp = new T[size];
	for (int i = 0; i < mcur; i++)//把以前内存里的东西放到新的内存里 并且要再预留出一部分
	{
		ptmp[i] = mpvec[i];
	}
	delete[]mpvec;//把原来的空间删掉
	mpvec = ptmp;//把原先的指针指向新的
	msize = size;//更新大小
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
		cout << mpvec[i]<<" ";
	}
	cout << endl;
}

template<typename T>
void Vector<T>::resize()//扩容
{
	if (msize > 0)
	{
		T *ptmp = new T[msize * 2];
		for (int i = 0; i < msize; i++)
		{
			ptmp[i] = mpvec[i];
		}
		delete[]mpvec;
		mpvec = ptmp;
		msize *= 2;
	}
	else
	{
		mpvec = new T[1];//vector内存扩容是0,1,2,4,8..当原本的为0时,就要给它新开辟一个空间
		msize = 1;
		mcur = 0;//当前未存元素
	}
}



int main()
{
	Vector<> intVec;
	intVec.push_back(20);
	intVec.push_back(30);
	intVec.push_back(21);
	intVec.show();
	//std::move把参数转为右值类型
	Vector<int> intVec2(std::move(intVec));
	Vector<int> intVec2(Vector<int>());

	return 0;
}//
#endif 