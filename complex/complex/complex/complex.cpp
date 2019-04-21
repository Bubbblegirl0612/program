#include<iostream>
using namespace std;

// ������
class CComplex
{
public:
	CComplex(int r = 0, int i = 0)
		:mreal(r), mimage(i)
	{
		cout << "CComplex(int r = 0, int i = 0)" << endl;
	}
	~CComplex() //û�����ⲿ��Դ,�������ɶҲ����(��ָ����п��ܻ�����ⲿ��Դ��Ҫ������)
	{
		cout << "~CComplex" << endl;
	}
	
	CComplex& operator++()//ǰ�üӼ� 
	{//�Լ���һ�� �ٰ��Լ��������� �����������ʱ���� ���Է���������Ϊһֱ���õ��Ǳ���
		//���صĲ�������ʱ�� �����Ӻ���������return�����ֵ����
		++mreal; 
		++mimage;
		return *this;
	}
	CComplex operator++(int)//���üӼ� 
	{
		return CComplex(mreal++, mimage++);//�ȹ�����ʱ����=������.Ȼ���ٸ�������++
		//����һ�����ǻ�����ѡ��ǰ��++��д
	}
	void operator=(const CComplex &src)//��ֵ
	{
		cout << "void operator=(const CComplex &src)" << endl;
		mreal = src.mreal;
		mimage = src.mimage;
	}//comp3 = ����  opertor=(this(comp3),����) �ѵȺź���ĸ���ǰ��� ���Բ��÷���ֵ
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
	int mreal;//ʵ��
	int mimage;//����
};
//˫Ŀ������ĺ�������ֻ��������,һ��this һ���Ǵ�������.(��Ա������)
//��������Ӻ�����ֻ��д��ȫ�� ��Ȼд�ɳ�Ա�����Ļ���Ĭ�ϴ�һ��thisָ��,������������

CComplex operator+(const CComplex &a, const CComplex &b)
{
	cout << "CComplex operator+(const CComplex &a, const CComplex &b)" << endl;
	return CComplex(a.mreal + b.mreal, a.mimage + b.mimage); //����һ����ʱ����
}
ostream& operator<<(ostream &out, const CComplex &src)
{
	out << "real:" << src.mreal << " image:" << src.mimage << endl;
	return out;
}
//cout << comp1 << endl;˫Ŀ�����������������һ��������� һ���Ƕ���
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
	//��ʱ���������ֱ�ӱ�ɶ���Ĺ��� ��ʱ����Ĺ��콫�������
	comp3.show();
	cout << "============" << endl;
	
	// comp1.operator+(const CComplex &src)
	//comp3 = ����  opertor=(this(comp3),����)
	comp3 = comp1 + 20; // int => CComplex(int) 
	comp3.show();

	comp3 = 20 + comp1;//һ���������͵������ϸ���
	//1.20 ���������
	//2.������ʱ����
	//3.��ֵ����
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
		cout<<"cmp1��"<<endl;
	}
	cout << "============" << endl;
	//  ostream& out, const CComplex &src
	cout << comp1 << endl;//ֱ�ӵ�����������غ��� ��������ڵ����
	cout << "============" << endl;
	//cin >> comp1;
	//comp1.show();
	return 0;
}