// Text01_05.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<assert.h>
#include "pch.h"
#include <iostream>
using namespace std;
#include<stdio.h>    
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#define STAT     0
#define IN_WROD  1
#define OUT_WROD 2
#define END      3

void FileWordCount(int &tag, int &num, char *buff)
{
	if (tag == IN_WROD)
	{
		num -= 1;
	}
	for (int i = 0; buff[i] != '\0'; ++i)
	{
		printf("%c", buff[i]);
		switch (tag)
		{
		case STAT:
			if (isalpha(buff[i]))
			{
				tag = IN_WROD;
			}
			else
			{
				tag = OUT_WROD;
			}
			break;
		case IN_WROD:
			if ('\'' != buff[i] && '-' != buff[i] && !isalpha(buff[i]))
			{
				tag = OUT_WROD;
				num += 1;
			}
			break;
		case OUT_WROD:
			if (isalpha(buff[i]))
			{
				tag = IN_WROD;
			}
			break;
		}
	}
	if (tag == IN_WROD)
	{
		num += 1;
	}
}

int main()
{
	FILE *fq;
	char buff[20];
	int num = 0;
	int tag = STAT;
	fopen_s(&fq, "english.txt", "rb");
	if (fq == NULL)
	{
		printf("Open File Error");
		exit(1);
	}
	while (!feof(fq))
	{
		fgets(buff, 20, fq);
		FileWordCount(tag, num, buff);
	}
	printf("\n string wrod num = %d \n", num);
	return 0;
}
//typedef enum { 
//	MALLOCFAULT  = 1, 
//	INITSUCCESS  = 2, 
//	POSERROR     = 3, 
//	INCFULT      = 4,
//	SUCCESS      = 0
//}Statue;
//#define SEQ_INIT_SIZE 50
//#define SEQ_INC_SIZE  2    //增容
//typedef int ElemType;
//struct SeqList
//{
//	ElemType *data;
//	int cursize;     //个数
//	int maxsize;     //空间
//};
//Statue InitList(SeqList &seq)
//{
//	seq.data = (ElemType *)malloc(SEQ_INIT_SIZE);
//	if (NULL == seq.data)
//	{
//		return MALLOCFAULT;
//	}
//	ElemType tem[] = { 100,12,12,12,5,5,12,1,10,12 };
//	memcpy(seq.data, tem, 10 * sizeof(ElemType));
//	seq.cursize = 10;
//	seq.maxsize = SEQ_INIT_SIZE;
//	return INITSUCCESS;
//}
//void DestroyList(SeqList &seq)
//{
//	free(seq.data);   //free 后指针变成悬空指针
//	seq.data = NULL;
//	seq.maxsize = 0;
//	seq.cursize = 0;
//}
//int GetSize(SeqList &seq)
//{
//	return seq.cursize;
//}
//int Cacpacity(SeqList &seq)
//{
//	return seq.maxsize;
//}
////List 个数为0, empty
//bool Is_Empty(SeqList &seq)
//{
//	return GetSize(seq) == 0;
//}
//bool Is_Full(SeqList &seq)
//{
//	return GetSize(seq) == Cacpacity(seq);
//}
//bool Inc_Size(SeqList &seq)
//{
//	//增容 //1 2 3 4 5
//	ElemType *data = (ElemType *)malloc(sizeof(ElemType)*seq.maxsize * SEQ_INC_SIZE);
//	if (NULL == data)
//	{
//		return MALLOCFAULT;
//	}
//	memmove(data, seq.data, sizeof(ElemType)*seq.maxsize);
//	free(seq.data);
//	seq.data = data;
//	seq.maxsize = seq.maxsize * SEQ_INC_SIZE;
//	return SUCCESS;
//}
//Statue InsertItem(SeqList &seq, const int pos, const ElemType x)
//{
//	if ((pos < 1) || (pos > seq.maxsize) || (pos > seq.cursize))
//	{
//		return POSERROR;
//	}
//	if (Is_Full(seq) || (!(Inc_Size(seq))))
//	{
//		return INCFULT;
//	}
//	//库函数
//	memmove(&seq.data[pos + 1], &seq.data[pos], sizeof(ElemType)*(seq.cursize - pos));
//	seq.cursize += 1;
//	return SUCCESS;
//}
//void Push_Back(SeqList &seq, const ElemType x)
//{
//	InsertItem(seq, GetSize(seq), x);
//}
//void Push_Front(SeqList &seq, const ElemType x)
//{
//	InsertItem(seq, 1, x);
//}
//Statue EraseList(SeqList &seq, int pos)//按位置删除
//{
//	if ((pos < 1) || (pos >= seq.cursize))
//	{
//		return POSERROR;
//	}
//	memmove(&seq.data[pos - 1], &seq.data[pos], sizeof(ElemType)*(seq.cursize - pos));
//	seq.cursize -= 1;
//	return SUCCESS;
//}
//void Pop_Back(SeqList &seq)
//{
//	EraseList(seq, seq.cursize - 1);
//}
//void Pop_Front(SeqList &seq)
//{
//	EraseList(seq, 1);
//}
//void RemoveItem(SeqList &seq,const ElemType x)
//{
//	int j = 0;
//	for (int i = 0; i <seq.cursize; i++,j++)
//	{
//		//if ((x == seq.data[i]))
//		//{
//		//	seq.data[j] = seq.data[i + 1];
//		//	j--;
//		//}
//		if ((x != seq.data[i]))
//		{
//			seq.data[j] = seq.data[i];
//		}
//	}
//	cout << "j " << j << endl;
//	seq.cursize = j;
//}
//void Print_List(SeqList &seq)
//{
//	cout << "cursize: " << seq.cursize << endl;
//	cout << "data: ";
//	for (int i = 0; i < seq.cursize; i++)
//	{
//		cout << seq.data[i] << " ";
//	}
//	cout << endl;
//}
//void InsertSort(SeqList &seq)
//{
//	int j = 0;
//	for (int i = 1; i < seq.cursize; i++)
//	{
//		if (seq.data[i - 1] > seq.data[i]) {
//			seq.data[i] = seq.data[i-1];
//			j++;
//		}
//	}
//}
//void SelectSort(SeqList &seq)
//{
//	for (int i = 0; i < seq.cursize; i++)
//	{
//		int min = i;
//		for(int j=i+1; j < seq.cursize; j++)
//		{ 
//			if (seq.data[j] < seq.data[min]) 
//			{
//				min = j;
//			}
//		}
//		ElemType tmp = seq.data[i];
//		seq.data[i] = seq.data[min];
//		seq.data[min] = tmp;
//	}
//}
////堆排序
//void HeapSort(SeqList &seq)
//{
//	int i = 0; // temp保存当前父节点
//	int j = 2 * i + 1; // 先获得左孩子
//	ElemType par = seq.data[i];
//	while (j < seq.cursize)
//	{
//		// 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
//		if (j + 1 < seq.cursize && seq.data[j] < seq.data[j + 1])
//		{
//			j++;
//		}
//		// 如果父结点的值已经大于孩子结点的值，则直接结束
//		if (par >= seq.data[j])
//		{
//			break;
//		}
//		// 把孩子结点的值赋给父结点
//		par = seq.data[j];
//
//		// 选取孩子结点的左孩子结点,继续向下筛选
//		i = j;
//		i = 2 * i + 1;
//	}
//
//}
//void Swap(int &a, int &b)
//{
//	int x = a;
//	a = b;
//	b = x;
//}
////非递归实现二分查找
//int SearchValue(SeqList &mylist, ElemType val)    //必须有序且是顺序空间(链表就不可以)
//{
//	int pos = -1;
//	int left = 0;
//	int right = mylist.cursize - 1;
//	while (left <= right)
//	{
//		int mid = (right-left+1) / 2 + left;
//		if (mylist.data[mid] == val)
//		{
//			return mid;
//		}
//		else if (mylist.data[mid] > val)
//		{
//			right = mid - 1;
//		}
//		else if (mylist.data[mid] < val)
//		{
//			left = mid - 1;
//		}
//		else
//		{
//			while (mid > left && mylist.data[mid - 1] == val) 
//				--mid;
//			pos = mid;
//			break;
//
//
//		}
//	}
//}
////递归法实现二分查找
//int SearchValue(SeqList &mylist, int left,int right,ElemType val)    //必须有序且是顺序空间(链表就不可以)
//{
//	int pos = -1;
//	while (left <= right)
//	{
//		int mid = (right - left + 1) / 2 + left;
//		if (mylist.data[mid] == val)
//		{
//			pos = mid;
//		}
//		else if (mylist.data[mid] > val)
//		{
//			pos = SearchValue(mylist, left, mid - 1, val);
//		}
//		else if (mylist.data[mid] < val)
//		{
//			pos = SearchValue(mylist, mid + 1, right, val);
//		}
//		else
//		{
//			while (mid > left && mylist.data[mid - 1] == val)
//				--mid;
//			pos = mid;
//			break;
//		}
//	}
//	return pos;
//}
////快速排序
//int Partition(SeqList&mylist, int left, int right)
//{
//	int i = left;
//	int j = right;
//	ElemType tmp = mylist.data[i];
//	while (i < j)
//	{
//		while (i < j && mylist.data[j] < tmp)
//			--j;
//		if (i < j)
//		{
//			mylist.data[i] = mylist.data[j];
//		}
//		while (i < j && mylist.data[i] <= tmp)
//			++i;
//		if (i < j)
//		{
//			mylist.data[j] = mylist.data[i];
//		}
//		mylist.data[i] = tmp;
//		return i;
//	}
//}
////递归实现快速排序
//void QuickPass(SeqList&mylist, int left, int right)
//{
//	if (left < right)
//	{
//		int pos = Partition(mylist, left, right);
//		QuickPass(mylist, left, right-1);
//		QuickPass(mylist, pos+1, right);
//	}
//}
//
////找第k小的元素
//
//ElemType SelectK(SeqList &seq, int left, int right, int k)
//{
//	if (left == right && k == 1) return seq.data[left];
//	int index = Partition(seq, left, right);
//	int pos = index - left + 1;
//	if (k <= pos) return SelectK(seq, left, index, k);
//	else return SelectK(seq, index + 1, right, k - pos);
//}
//ElemType SelectK_Min(SeqList &seq, int k)
//{
//	assert(k >= 1 && k <= seq.cursize);
//	return SelectK(seq, 0, seq.cursize - 1, k);
//}
//
//void Perm(int *ar, int k, int m)
//{
//	if (k == m)
//	{
//		for (int i = 0; i <= m; ++i)
//		{
//			cout << ar[i] << " ";
//		}
//		cout << endl;
//	}
//	else
//	{
//		for (int j = k; j <= m; ++j)
//		{
//			Swap(ar[j], ar[k]);
//			Perm(ar, k + 1, m);
//			Swap(ar[j], ar[k]);
//		}
//	}
//	//并轨函数实现
//	void Merge(int *dst, int *src, int left, int m, int right);
//	//n是元素个数
//	void MergePass2(int *dst, int *src, int s, int n)
//	{//
//		for (int i = 0; i + 2 * s - 1<= n-1;i+2*s)
//		{
//			Merge(dst, src,i ,i + s - 1 ,i+2*s-1 );
//		}
//		if (n-1>=i+2*s)//当元素个数不足
//		{
//			Merge(dst, src, i, i + s - 1, n-1);
//		}
//
//	}

	////单链表
	//typedef int ElemType;
	//typedef struct ListNode
	//{
	//	ListNode *next;
	//	ElemType data;
	//};
	//typedef struct List //类型(可以看做一个类)；结构体
	//{
	//	ListNode *head;//成员变量；ListNode是成员变量的类 
	//	int cursize;
	//};
	//void InitList(List &Lt)
	//{
	//	Lt.head = (ListNode *)malloc(sizeof(ListNode));//所以这里初始化是给ListNode的成员变量初始化的
	//	Lt.head->next = NULL;
	//	Lt.cursize = 0;
	//}
	//bool InsertItem(List &Lt, int pos, ElemType x)
	//{
	//	if (pos <= 0 || pos >= Lt.cursize+1 ) return ;
	//	ListNode *p = Lt.head;
	//	int i = 1;
	//	while (i < pos)
	//	{
	//		p = p->next;
	//	}
	//	p = (ListNode *)malloc(sizeof(ListNode));
	//	p->data = x;
	//	
	//}
	//bool EraseList(List &Lt, int pos)
	//{

	//}
	//int main()
	//{
	//	List mylist;
	//	InitList(mylist);
	//	return 0;
	//}
	//int main()
	//{
	//	std::cout << "Hello World!\n";
	//}
//
//
//
//
//
//struct Student
//{
//	char s_id[20];
//	char s_name[20];
//	char s_sex;
//	int s_age;
//};
//int main()
//{
//	Student s1 = { "201901001","yhping",'m',23 };
//	Student s2;
//	SaveStudent(s1);
//	LoasStudent(s2);
//	return 0;
//}
//
//void SaveStudent(Student &stu)
//{
//	FILE *fp = fopen("Student.txt", "a");
//	if (NULL == fp)
//	{
//		printf("open file error \n");
//		exit(1);
//	}
//	fwrite(&stu, sizeof(Student), 1, fp);
//	fclose(fp);
//	fp = NULL;
//}
//void LoasStudent(Student stu)
//{
//	FILE *fp = fopen("Student.txt", "a");
//	if (NULL == fp)
//	{
//		printf("open file error \n");
//		exit(1);
//	}
//	fread(&stu, sizeof(Student), 1, fp);
//	fclose(fp);
//	fp = NULL;
//}

#define STAT     0
#define IN_WROD  1
#define OUT_WROD 2
#define END      3

int main()
{
	char buff[256] = { " patiently and methodically explores yhping" };// the issues of when and how to use inlines, references"};
	int num = 0;
	int tag = STAT;

	for (int i = 0; buff[i] != '\0'; ++i)
	{
		switch (tag)
		{
		case STAT:
			if (isalpha(buff[i]))
			{
				tag = IN_WROD;
			}
			else
			{
				tag = OUT_WROD;
			}
			break;
		case IN_WROD:
			if (!isalpha(buff[i]))
			{
				tag = OUT_WROD;
				num += 1;
			}
			break;
		case OUT_WROD:
			if (isalpha(buff[i]))
			{
				tag = IN_WROD;
			}
			break;
		}
	}
	if (tag == IN_WROD)
	{
		num += 1;
	}
	printf("string wrod num = %d \n", num);
	return 0;
}


//
//}
//int main()
//{
//	for (int i = 1; i <= 20000; ++i)
//	{
//		
//	}
//
//}
//int Maxs(SeqList&seq, int left, int right)
//{
//	return seq.data[right];
//}
//
//int Cpair_Ar(SeqList&seq, int left, int right)
//{
//	if (right - left <= 0)
//	{
//		return INT_MAX;
//	}
//	int k = (right - left + 1) / 2;
//	int index = left + k - 1;
//	SelectK(seq, left, right, k);
//	int d1 = Cpair_Ar(seq, left, index);
//	int d2 = Cpair_Ar(seq, index + 1, right);
//	int maxs1 = Maxs();
//	int mins2 = Maxs();
//	return Min3S(d1, d2, mins2 - maxs1);
//
//}


//int main()
//{
//	SeqList mylist;
//	InitList(mylist);
//	Print_List(mylist);
//
//	RemoveItem(mylist,12);
//	Print_List(mylist);
//	DestroyList(mylist);
//	return 0;
//}

