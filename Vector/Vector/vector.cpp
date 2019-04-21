
#include <string>
#include <vector>
#include<iostream>
using namespace std;

//�пռ���������vector
//�������õ��ͷŹ��������ȵĵط�����Ϊ�ռ��������ĺ���
template<typename T>
struct myallocator
{
	//�ڴ濪��
	T*allocate(size_t size)
	{
		return (T*)malloc(size * sizeof(T));
	}
	//�ڴ��ͷ�
	void deallocate(T *ptr)
	{
		free(ptr);//free�ͷ�
	}
	//������
	void construct(T *ptr, const T &obj)
	{
		new (ptr) T(obj);
	}
	//��������
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

	void reserve(int size); // Ԥ������

	void push_back(const T &val); // ĩβ���Ԫ��
	void pop_back(); // ĩβɾ��Ԫ��
	bool empty()const; // �п�
	bool full()const; // ����
	int size()const; // ����vector����Ԫ�صĸ���
	void show()const; // ��ӡvector����������Ԫ��

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
	//���뺯��
	iterator insert(iterator &where, const T &val)
	{//1.�ж��Ƿ��� û���Ļ��ٲ���ֵ
		//2.
		if (where._ptr<mpvec || where._ptr>mpvec + mcur)
		{//mpvec������ռ� �������Ŀռ�,�������Ų� 
			throw"xxx";//���쳣
		}
		if(full())
		{
			int offset = where._ptr - mpvec;//����Ҫ�����λ���±�
			resize();//��Ϊresize��ԭ�ȵĿռ�û���� ����ǰ��Ҫ�����±� 
			where._ptr = mpvec + offset;//����offset�����������λ���±��ԭ������Ϊresize֮��whereָ����ڴ��Ѿ��ͷŵ���
			//����Ҫ����where�ڴ�ָ��  offset���±� where_ptr��ָ��
		}
		T *p = mpvec + mcur;//��һ��ָ���������ֵ�����һλ��ָ��
		while (p > where._ptr)//��Ҫ����λ�õ�Ԫ�غ�������Ų
		{//ָ����ָ�������ֵ�����һλ
			malloctor.construct(p, *(p - 1));
	//�ӵ�ǰ������Ԫ�����һ����ʼ����Ų��,������Ų��һ��
			malloctor.destroy(p - 1);
    //Ȼ������ǰһ����Ų���������
			p--;//��ָ����ǰŲ��һλ
		}
		malloctor.construct(p, val);//һֱ��pŲ����Ҫ�����λ�� �������ֵ
		mcur++;//��������Ԫ��+1
		return iterator(p);//����һ����������ʾ ��ǰָ��pָ���ֵ
	}
	// 3.ɾ��ָ��λ�õ�Ԫ��
	iterator erase(iterator where)
	{
		if (where._ptr < mpvec || where._ptr > mpvec + mcur - 1)
		{//�����ϵĻ����� Ҫɾ����Ԫ��Խ��Ļ�
			throw "xxx";
		}
		T *p = where._ptr;
		while (p < mpvec + mcur - 1)
		{//��Ҫ��ɾ����Ԫ��λ�ÿ�ʼ����ƶ�
			malloctor.destroy(p);//��ɾ��Ҫɾ����Ԫ��
			malloctor.construct(p, *(p + 1));//Ȼ��Ѻ����Ԫ�ز�����
			p++;
		}
		malloctor.destroy(p);//����������һ������ ��Ϊmcurָ��ĵط�����ֵ
		mcur--;
		return iterator(where._ptr); // T* iterator(T*)
	}

	// 4.�ṩoperator[]    vec[2];
	T& operator[](int index) { return mpvec[index]; }
private:
	T *mpvec;//���� ��һ��mpvec��������׵�ַ���������˻���ָ��
	int mcur;//��ǰ��С ����ָ��!!! 
	int msize;//����ռ��С
	myallocator<T> malloctor;//����ռ�����������
	void resize(); // vector�����ײ�Ĭ��2������

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
	{//���������е���Ч���� ����һ��ָ����һ��
		malloctor.destroy(mpvec + i);
	}
	//����Ч������������,�Ͱ��������ڴ��ͷŵ�
	malloctor.deallocate(mpvec);
	mpvec = nullptr;
}

template<typename T, typename _Alloc>
Vector<T, _Alloc>::Vector(const Vector<T>& vec)//��ֵ��������
{
	msize = vec.msize;//�ռ��С
	mcur = vec.mcur;//���ڴ��Ԫ�ظ���
	T *ptmp = malloctor.allocate(msize);
	//�����ڴ� �������¶���������ռ� 
	for (int i = 0; i < mcur; i++)
	{
		malloctor.construct(ptmp + i, vec.mpvec[i]);
	}
	mpvec = ptmp;//�Ѿɵ�ָ���µ�
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
//�ͷ�Ȼ�������������ڴ��ٹ���
	msize = vec.msize;//�ռ��С
	mcur = vec.mcur;//���ڴ��Ԫ�ظ���
	T *ptmp = malloctor.allocate(msize);
	
	for (int i = 0; i < mcur; i++)
	{
		malloctor.construct(ptmp+i, vec.mpvec[i]);
		//��vec����Ķ��� �������������������ڴ�ptmp
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
	malloctor.deallocate(mpvec);//�ͷ��ڴ�
	msize = vec.msize;
	mcur = vec.mcur;
	mpvec = vec.mpvec;
	vec.mpvec = nullptr;
}

template<typename T, typename _Alloc>
void Vector<T, _Alloc>::reserve(int size)//Ԥ��
{
	if (size <= msize)
		return;
	T *ptmp = malloctor.allocate(size);
	for (int i = 0; i < mcur; i++)//����ǰ�ڴ���Ķ����ŵ��µ��ڴ��� ����Ҫ��Ԥ����һ����
	{
		malloctor.construct(ptmp + i, mpvec[i]);
	}
	malloctor.deallocate(mpvec);
	mpvec = ptmp;//��ԭ�ȵ�ָ��ָ���µ�
	msize = size;//���´�С
}

template<typename T, typename _Alloc>
void Vector<T, _Alloc>::push_back(const T & val)//β�����
{
	if (full())
	{
		resize();
	}
	T *ptmp = mpvec;//��Ϊ�Ѿ��ж��������ڴ��,����ֱ�ӽ��ж���Ĺ���ͷ���ֵ
	malloctor.construct(ptmp + mcur, val);
	mcur++;

}

template<typename T, typename _Alloc>
void Vector<T, _Alloc>::pop_back()//β��ɾ��
{
	if (empty())
	{
		return;
	}
	mcur--;//mcur����±��ֵ�ǲ����� ����--�Ժ�
	malloctor.destroy(mpvec + mcur);//����ָ��+ƫ��������ȷ��Ҫ�����Ķ���
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
void Vector<T, _Alloc>::resize()//����
{
	if (msize > 0)
	{
		T *ptmp = malloctor.allocate(msize*2)
		for (int i = 0; i < msize; i++)
		{
			malloctor.construct(ptmp + i, mpvec[i]);
			// ������������Ч�Ķ���
			malloctor.destroy(mpvec + i);
		}
		// �������ڴ��ͷŵ�
		malloctor.deallocate(mpvec);//mpvec�������׵�ַ,�����ͷŵ�ʱ�����ͷ��˴�mpvec�Ժ��ֵ
		mpvec = ptmp;
		msize *= 2;
	}
	else
	{
		mpvec = malloctor.allocate(1);//vector�ڴ�������0,1,2,4,8..��ԭ����Ϊ0ʱ,��Ҫ�����¿���һ���ռ�
		msize = 1;
		mcur = 0;//��ǰδ��Ԫ��
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
	// C++ STL ���֮һ������
	Test t1, t2, t3;              //���ι���
	cout << "------------" << endl;
	Vector<Test> vec;
	vec.reserve(10); // ֻ��Ԥ���ռ�
	cout << "------------" << endl;
	vec.push_back(t1);            //��������
	vec.push_back(std::move(t2));  //��������
	vec.push_back(t3);            //��������
	cout << "------------" << endl;
	vec.pop_back();               //һ������
	cout << "------------" << endl;
	//�������
	return 0;
}
#endif 
#if 0
//Vector
û���ڴ�����vector
// ��ģ�� vector Ĭ�Ϲ��� size:0-1-2-4-8-16-32-64....
template<typename T = int>
class Vector // ���ģ������
{
public:
	Vector();
	~Vector();
	Vector(const Vector<T> &vec);
	Vector(Vector<T> &&vec);
	void operator=(const Vector<T> &vec);
	void operator=(Vector<T> &&vec);

	void reserve(int size); // Ԥ������

	void push_back(const T &val); // ĩβ���Ԫ��
	void pop_back(); // ĩβɾ��Ԫ��
	bool empty()const; // �п�
	bool full()const; // ����
	int size()const;//����vector����Ԫ�صĸ���

	void show()const; // ��ӡvector����������Ԫ��
private:
	T *mpvec;
	int mcur;
	int msize;

	void resize(); // vector�����ײ�Ĭ��2������
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
Vector<T>::Vector(const Vector<T>& vec)//��ֵ��������
{
	msize = vec.msize;//�ռ��С
	mcur = vec.mcur;//���ڴ��Ԫ�ظ���

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
	msize = vec.msize;//�ռ��С
	mcur = vec.mcur;//���ڴ��Ԫ�ظ���

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
void Vector<T>::reserve(int size)//Ԥ��
{
	if (size <= msize)
		return;
	T *ptmp = new T[size];
	for (int i = 0; i < mcur; i++)//����ǰ�ڴ���Ķ����ŵ��µ��ڴ��� ����Ҫ��Ԥ����һ����
	{
		ptmp[i] = mpvec[i];
	}
	delete[]mpvec;//��ԭ���Ŀռ�ɾ��
	mpvec = ptmp;//��ԭ�ȵ�ָ��ָ���µ�
	msize = size;//���´�С
}

template<typename T>
void Vector<T>::push_back(const T & val)//β�����
{
	if (full())
	{
		resize();
	}
	mpvec[mcur++] = val;

}

template<typename T>
void Vector<T>::pop_back()//β��ɾ��
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
void Vector<T>::resize()//����
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
		mpvec = new T[1];//vector�ڴ�������0,1,2,4,8..��ԭ����Ϊ0ʱ,��Ҫ�����¿���һ���ռ�
		msize = 1;
		mcur = 0;//��ǰδ��Ԫ��
	}
}



int main()
{
	Vector<> intVec;
	intVec.push_back(20);
	intVec.push_back(30);
	intVec.push_back(21);
	intVec.show();
	//std::move�Ѳ���תΪ��ֵ����
	Vector<int> intVec2(std::move(intVec));
	Vector<int> intVec2(Vector<int>());

	return 0;
}//
#endif 