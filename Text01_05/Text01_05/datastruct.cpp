
#include<assert.h>
#include<iostream>
#include<malloc.h>
#include<limits.h>
#include<vector>
using namespace std;

typedef int ElemType;
typedef struct ListNode
{
	ListNode *next;
	ElemType data;
}ListNode;

typedef struct
{
	ListNode *head;
	int cursize;
}List;

ListNode * Buynode()
{
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == s) exit(1);// _exit(1);
	memset(s, 0, sizeof(ListNode));
	return s;
}
void Freenode(ListNode *p)
{
	free(p);
}
void InitList(List &Lt)//
{
	Lt.head = Buynode();
	Lt.cursize = 0;
}
bool InsertItem(List &Lt, int pos, ElemType x)
{
	if (pos <= 0 || pos > Lt.cursize + 1) return false;
	ListNode *p = Lt.head;
	int i = 1;
	while (i < pos)
	{
		p = p->next;
		++i;
	}
	ListNode *s = Buynode();
	s->data = x;
	s->next = p->next;
	p->next = s;
	Lt.cursize += 1;
	return true;
}
void Push_Back(List &Lt, ElemType x)
{
	InsertItem(Lt, Lt.cursize + 1, x);
}
void Push_Front(List &Lt, ElemType x)
{
	InsertItem(Lt, 1, x);
}
//删除单链表中第几个位置的元素
bool EraseList(List &Lt, int pos)
{
	if (pos <= 0 || pos > Lt.cursize) return false;
	ListNode *p = Lt.head;
	int i = 1;
	while (i<pos)
	{
		++i;
		p = p->next;
	}
	ListNode *q = p->next;
	p->next = q->next;
	Freenode(q);
	Lt.cursize -= 1;
	return true;
}
void Pop_Back(List &Lt)
{
	EraseList(Lt, Lt.cursize);
}
void Pop_Front(List &Lt)
{
	EraseList(Lt, 1);
}
int GetSize(List &Lt)
{
	return Lt.cursize;
}
bool Is_Empty(List &Lt)
{
	return GetSize(Lt) == 0;
}
void PrintList(List &Lt)
{
	ListNode *p = Lt.head->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//删除单链表中特定值的节点
void RemoveItem(List &Lt, ElemType x)
{
	ListNode *p = Lt.head->next;//头节点的下一个
	ListNode *s = Lt.head;//指向头结点
	int num = 0;
	while (p != NULL)
	{
		if (p->data != x)
		{
			s->next->data = p->data;
			s = s->next;
			num += 1;
		}
		p = p->next;
	}
	ListNode *p = s->next;
	s->next = NULL;
	while (p != NULL)
	{
		ListNode *q = p;
		p = p->next;
		Freenode(q);
	}
	Lt.cursize = num;
}
//链表的倒置
void ResList(List &Lt)
{



}
//链表的合并 将两个链表的值合并到第三个链表中去,并且按照从小到大合并
void MergeList(List &la, List &lb, List &lc)
{
	ListNode *ap = lb.head->next;
	ListNode *bp = lc.head->next;
	ListNode *cp = la.head;
	while (ap != NULL && bp != NULL) 
	{
		ListNode *s = Bu
		if (p1->data > p2->data)
		{
			s->next->data = p2->data;
			s = s->next;
		}

	}

}
//链表的清除
void ClearList(List &Lt)
{
	ListNode *p = Lt.head->next;


}
//双循环链表
typedef struct DLNode
{
	ElemType data;
	DLNode *pr;
	DLNode *next;
};
typedef struct  DLlist
{
	DLNode head;

};
void InitList(Node &lt)
{

}
bool InsertItem(DuLinkList &Lt, DuLNode *ptr, ElemType x)
{
	DuLNode * Buynode(DuLNode *pr = NULL, DuLNode *nt = NULL)
	{
		DuLNode *s = (DuLNode*)malloc(sizeof(DulNode));
		if (NULL == s) exit(1);


	}
}
int main()
{
	int ar[] = { 1,3,5,7,8,11,15 };
	int n = sizeof(ar) / sizeof(ar[0]);
	int br[] = { 2,4,6,8,10,16,18 };
	int m = sizeof(ar) / sizeof(ar[0]);
	List mylist, youlist, helist;
	InitList(mylist);
	InitList(youlist);
	InitList(helist);
	for (int i = 0; i < n; i++)
	{
		Push_Back(mylist, ar[i]);
	}
	for (int i = 0; i < m; i++)
	{
		Push_Back(youlist, ar[i]);
	}
	PrintList(mylist);
	PrintList(youlist);
	PrintList(helist);
	MergeList(helist, mylist, youlist);
	PrintList(mylist);
	PrintList(youlist);
	PrintList(helist);

}
//int main()
//{
//	int ar[] = { 12,23,34,45,56,67,78,89,90,100 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	List mylist;
//	InitList(mylist);
//
//	for (int i = 0; i<n; ++i)
//	{
//		Push_Back(mylist, ar[i]);
//		PrintList(mylist);
//	}
//	while (!Is_Empty(mylist))
//	{
//		Pop_Front(mylist);
//		PrintList(mylist);
//	}
//	return 0;
//}




/*
void main()
{
vector<int> ivec;
for(int i = 0;i<10;++i)
{
ivec.push_back(rand()%100);
}
int n = ivec.size();
for(int i = 0;i<n;++i)
{
cout<<ivec[i]<<" ";
}
cout<<endl;
}


void Swap(int &a,int &b)
{
int x = a;
a = b;
b = x;
}
#define SEQ_INIT_SIZE 10
#define SEQ_INC_SIZE  2

typedef enum{
MALLOCFAULT = -1,
INITSUCCESS = -2,
POSERROR = -3,
INCFAULT = -4,
SUCCESS = 0,
} Status;
typedef int ElemType;
typedef struct
{
ElemType *data;// malloc
int cursize;
int maxsize;
}SeqList;

Status InitList(SeqList &seq)
{
seq.data = (ElemType*)malloc(sizeof(ElemType)*SEQ_INIT_SIZE);
if(NULL == seq.data)
{
return MALLOCFAULT;
}
seq.cursize = 0;
seq.maxsize = SEQ_INIT_SIZE;
return INITSUCCESS;
}
void DestroyList(SeqList &seq)
{
free(seq.data);
seq.data = NULL;
seq.maxsize = 0;
seq.cursize = 0;
}
int GetSize(SeqList &seq)
{
return seq.cursize;
}
int GetCapacity(SeqList &seq)
{
return seq.maxsize;
}
// list 元素是0个，Empty;
bool Is_Empty(SeqList &seq)
{
return GetSize(seq) == 0;
}
bool Is_Full(SeqList &seq)
{
return GetSize(seq) == GetCapacity(seq);
}
bool Inc_Size(SeqList &seq)
{
ElemType *newdata = (ElemType*)realloc(seq.data,sizeof(ElemType)*seq.maxsize * SEQ_INC_SIZE);
if(NULL == newdata)
{
return false;
}
seq.data = newdata;
seq.maxsize= seq.maxsize * SEQ_INC_SIZE;
return true;
}
Status InsertItem(SeqList &seq,const int pos,const ElemType x)
{
if(pos < 0 || pos > GetSize(seq))
{
return POSERROR;
}
if(Is_Full(seq) && !Inc_Size(seq))
{
return INCFAULT;
}
memmove(&seq.data[pos+1],&seq.data[pos],sizeof(ElemType)*(seq.cursize - pos));
//for(int i = seq.cursize;i>pos;--i)
//{
//	seq.data[i] = seq.data[i-1];
//}
seq.data[pos] = x;
seq.cursize+=1;
return SUCCESS;
}
void Push_Back(SeqList &seq,const ElemType x)
{
InsertItem(seq,seq.cursize,x);
}
void Push_Front(SeqList &seq,const ElemType x)
{
InsertItem(seq,0,x);
}
Status EraseList(SeqList &seq,int pos)
{
if(pos < 0 || pos >= seq.cursize)
{
return POSERROR;
}
memmove(&seq.data[pos],&seq.data[pos+1],sizeof(ElemType)*(seq.cursize - pos -1));
seq.cursize -=1;
return SUCCESS;
}
void Pop_Back(SeqList &seq)
{
EraseList(seq,seq.cursize-1);
}
void Pop_Front(SeqList &seq)
{
EraseList(seq,0);
}
void RemoveItem(SeqList &seq,ElemType x)
{
int j = 0;
for(int i = 0;i<seq.cursize;++i)
{
if(seq.data[i] !=x)
{
seq.data[j] = seq.data[i];
++j;
}
}
seq.cursize = j;
}
void PrintList(SeqList &seq)
{
for(int i = 0;i<seq.cursize;++i)
{
printf("%d ",seq.data[i]);
}
printf("\n");
}

int FindValue(SeqList &seq,ElemType val)
{
int pos = -1;
for(int i = 0;i<seq.cursize ;++i)
{
if(seq.data[i] == val)
{
pos = i;
break;
}
}
return pos;
}

// InsertSort;
// SelectSort;
void InsertSort(SeqList &seq)
{// O(n) => O(n^2)
for(int i = 1;i<seq.cursize;++i)
{
if(seq.data[i] < seq.data[i-1])
{
int j = i - 1;
ElemType tmp = seq.data[i];
do
{
seq.data[j+1] = seq.data[j];
--j;
}while(j >= 0 && tmp < seq.data[j]);
seq.data[j+1] = tmp;
}
}
}
void SelectSort(SeqList &seq)
{
// O(n^2)
for(int i = 0;i<seq.cursize;++i)
{
int minpos = i;
for(int j = i+1;j<seq.cursize;++j)
{
if(seq.data[minpos] > seq.data[j])
{
minpos = j;
}
}
//////////////////////
if(i != minpos)
{
Swap(seq.data[i],seq.data[minpos]);
}
}
}

///////////////////////////////////////
void FilterDown(ElemType *ar,int start,int end)
{
int i = start,j = i*2+1;
ElemType item = ar[i];
while(j <= end)
{
if(j < end && ar[j] < ar[j+1]) ++j;
if(item >= ar[j]) break;
ar[i] = ar[j];
i = j;
j = 2*i+1;
}
ar[i] = item;
}
void HeapSort(SeqList &seq)
{
if(seq.cursize < 2) return ;
// 建成大堆
int pos = (seq.cursize-2)/2;
while(pos >= 0)
{
FilterDown(seq.data,pos,seq.cursize-1);
--pos;
}
/// O(n*log2n)
for(int i = seq.cursize-1;i>0;--i)
{
Swap(seq.data[0],seq.data[i]);
FilterDown(seq.data,0,i-1);
}
}

int SearchValue2(SeqList &seq,ElemType val)
{
int pos = -1;
int left = 0,right = seq.cursize - 1;
while(left <= right)
{
int mid = (right - left + 1)/2 + left;
if(val < seq.data[mid])
{
right = mid-1;
}else if(val > seq.data[mid])
{
left = mid+1;
}else
{
while(mid > left && seq.data[mid-1] == val) --mid;
pos = mid;
break;
}
}
return pos;
}

int Search(SeqList &seq,int left,int right,ElemType val)
{
int pos = -1;
if(left <= right)
{
int mid = (right - left + 1)/2 + left;
if(val < seq.data[mid])
{
pos = Search(seq,left,mid-1,val);
}else if(val > seq.data[mid])
{
pos = Search(seq,mid+1,right,val);
}else
{
while(mid > left && seq.data[mid-1] == val) --mid;
pos = mid;
}
}
return pos;
}
int SearchValue(SeqList &seq,ElemType val)
{
return Search(seq,0,seq.cursize-1,val);
}

int Partition(SeqList &seq,int left,int right)
{
int i = left, j = right;
ElemType tmp = seq.data[i];
while(i<j)
{
while(i<j && seq.data[j] > tmp) --j;
if(i<j) {seq.data[i] = seq.data[j];}
while(i<j && seq.data[i] <= tmp) ++i;
if(i<j) { seq.data[j] = seq.data[i];}
}
seq.data[i] = tmp;
return i;
}
void QuickPass(SeqList &seq,int left,int right)
{
if(left < right)
{
int pos = Partition(seq,left,right);
QuickPass(seq,left,pos-1);
QuickPass(seq,pos+1,right);
}
}
void QuickSort(SeqList &seq)
{
QuickPass(seq,0,seq.cursize-1); //
}
ElemType SelectK(SeqList &seq,int left,int right,int k)
{
if(left == right && k == 1) return seq.data[left];
int index = Partition(seq,left,right);
int pos = index - left + 1;
if(k <= pos) return SelectK(seq,left,index,k);
else return SelectK(seq,index+1,right,k - pos);
}
ElemType SelectK_Min(SeqList &seq,int k)
{
assert(k >= 1 && k <= seq.cursize);
return SelectK(seq,0,seq.cursize -1,k);
}

int MaxS(SeqList &seq,int left,int right)
{
return seq.data[right];
}
int MinS(SeqList &seq,int left, int right)
{
int min = seq.data[left];
for(int i = left + 1; i<=right;++i)
{
if(min > seq.data[i])
{
min = seq.data[i];
}
}
return min;
}
int Min3S(int d1,int d2,int d3)
{
return min(d1,min(d2,d3));
}
int Cpair_Ar(SeqList &seq,int left,int right)
{
if(right - left <= 0)
{
return INT_MAX;
}
int k = (right - left + 1)/2; //
int index = left + k - 1;
SelectK(seq,left,right,k); // s1 s2;
int d1 = Cpair_Ar(seq,left,index);// s1;
int d2 = Cpair_Ar(seq,index+1,right);// s2;
int maxs1 = MaxS(seq,left,index);// s1;
int mins2 = MinS(seq,index+1,right);// s2;
return Min3S(d1,d2,mins2 - maxs1);
}
int Cpair(SeqList &seq)
{
return Cpair_Ar(seq,0,seq.cursize-1);
}
/////////////////////////////////////////////
void Copy_Ar(int *dst,int *src,int left,int right)
{
for(int i = left ; i <= right;++i)
{
dst[i] = src[i];
}
}
void Merge(int *dst,int *src,int left, int m,int right)
{
int i = left, j = m+1;
int k = left;
while(i<=m && j <= right)
{
dst[k++] = src[i] < src[j]? src[i++]:src[j++];
}

while(i<=m )
{
dst[k++] = src[i++];
}

while(j <= right)
{
dst[k++] = src[j++];
}
}

void MergePass(int *br,int *ar,int left,int right)
{//     2      2
if(left < right)
{
int mid = (right - left + 1)/2 + left -1;//
MergePass(br,ar,left,mid);
MergePass(br,ar,mid+1,right);
Merge(br,ar,left,mid,right);
cout<<left<<" "<<mid<<" "<<right<<endl;
Copy_Ar(ar,br,left,right);
}
}
void MergeSort(SeqList &seq)
{
int * br = (int*)malloc(sizeof(int)*seq.cursize);
MergePass(br,seq.data,0,seq.cursize-1);
free(br);
}

void Merge(int *dst,int *src,int left, int m,int right);

// 0  1  2  3  4  5  6  7 8 9 10 11
// n - 1
void MergePass2(int *dst,int *src,int s,int n)
{// s = 2
int i = 0;
for(; i+2*s -1 <= n -1; i = i+2*s)
{
Merge(dst,src,i,i+s-1,i+2*s-1);//
}
if(n-1 >= i+s)
{
Merge(dst,src,i,i+s-1,n-1);
}
else
{
for(int j = i;j<n;++j)
{
dst[j] = src[j];
}
}
}
void PrintAr(int *ar,int n)
{
for(int i = 0;i<n;++i)
{
cout<<ar[i]<<" ";
}
cout<<endl;
}
void MergeSort2(SeqList &seq)
{
int s = 1;
int n = seq.cursize;
int *br = (int*)malloc(sizeof(int)*n);
while(s < n)
{// 0 1 2 3 4 5 6
MergePass2(br,seq.data,s,n);
cout<<s<<endl;
PrintAr(br,n);
s+=s; // 2;
MergePass2(seq.data,br,s,n);
cout<<s<<endl;
PrintAr(seq.data,n);
s+=s; // 4
}
free(br);
}
int main()
{
SeqList mylist;
InitList(mylist);
for(int i = 0;i<6;++i)
{
Push_Back(mylist,rand()%100);
}
Push_Back(mylist,23);
PrintList(mylist);
MergeSort2(mylist);
PrintList(mylist);
return 0;
}
//////////////////////////////////

void fun(int *ar,int *br,int i,int n)
{
if(i == n)
{
for(int j = 0;j<n;++j)
{
if(br[j])
{
cout<<ar[j]<<" ";
}
}
cout<<endl;
}
else
{
br[i] = 1;
fun(ar,br,i+1,n);
br[i] = 0;
fun(ar,br,i+1,n);
}
}


void main()
{
int ar[]={1,2,3};
int br[]={0,0,0};
fun(ar,br,0,3);
}
void fun(int &i,int n)
{
if(i>=n) { return ;}
else
{
fun(i++,n);
fun(i++,n);
}
}
int main()
{
int i = 0;
fun(i,3);
cout<<i<<endl;
}
// 子集 // 2// 3 //  4//
void Perm(int *ar,int k,int m)
{
if(k == m)
{
for(int i = 0;i<=m;++i)
{
cout<<ar[i]<<" ";
}
cout<<endl;
}
else
{
for(int j = k; j<=m;++j)
{
Swap(ar[j],ar[k]);
Perm(ar,k+1,m);
Swap(ar[j],ar[k]);
}
}
}
int main()
{
int ar[]={1,2,3};
Perm(ar,0,2);

return 0;
}
int main()
{
// 12 12 12 12 23 34 45 56 56 56 56 67 78 89 90
SeqList mylist;
InitList(mylist);
for(int i = 0;i<10;++i)
{
Push_Back(mylist,rand()%100);
}
PrintList(mylist);
for(int k = 1;k<=mylist.cursize;++k)
{
cout<<k<<" => "<<SelectK_Min(mylist,k)<<endl;
}
cout<<endl;
return 0;
}
// 1 ) malloc
// 2 )
// 3 )
//
// 1 1 2 3 5 8 13 21 34 55
// 1 2 3 4 5 6 7  8  9  10
//
// O(2 ^n)
int fac(int n,int a,int b)
{
if(n <= 2) return a;
else return fac(n-1,a+b,a);
}

int fac(int n)
{
int a = 1, b = 1;
return fac(n,a,b);
}


int fac(int n)
{
if(n <= 2) return 1;
else return fac(n-1) + fac(n-2);
}
// O(n)
int fun(int n)
{
int a = 1, b = 1,c = 1;
for(int i = 3;i<=n;++i)
{
c = a+b;
b = a;
a = c;
}
return c;
}
int main()
{
for(int i = 1;i<=20000;++i)
{
cout<<i<<" ="<<fun(i)<<endl;
}
return 0;
}
// O(n) S(n)
// gcc -Ml, --stack = xxxxx;


int fac(int n)
{
if(n<=1)
return 1;
else
return fac(n-1) * n;
}
// O(n) // S(1)
int fun(int n)
{
int sum = 1;
for(int i = 1;i<=n ;++i)
{
sum = sum *i;
}
return sum;
}
int main()
{
int n,sum;
cin>>n;
sum = fac(n);
cout<<n<<"! => "<<sum<<endl;
return 0;
}

int main()
{
int *p = (int*)calloc(10,sizeof(int));

free(p);
}


int main()
{
int *p = (int*)malloc(sizeof(int)*5);
int *s = (int*)malloc(sizeof(int)*5);
for(int i=0;i<5;++i)
{
p[i] = i;
}
//p = (int*)realloc(p,sizeof(int)*10);

int *newdata = (int*)realloc(p,sizeof(int)*10);
if(newdata != NULL)
{
p = newdata;
}

p = (int*)realloc(p,sizeof(int)*2);
//                !NULL         >  <
//                !NULL       0
//                 NULL      >0
///                NULL      =0
free(p);
p = NULL;
return 0;
}



bool Inc_Size(SeqList &seq)
{
ElemType *newdata = (ElemType*)malloc(sizeof(ElemType)*seq.maxsize * SEQ_INC_SIZE);
if(NULL == newdata)
{
return false;
}
memmove(newdata,seq.data,sizeof(ElemType)*seq.maxsize);
free(seq.data);
seq.data = newdata;
seq.maxsize= seq.maxsize * SEQ_INC_SIZE;
return true;
}
int main()
{
int *p = (int*)malloc(sizeof(int));
*p = 100;
cout<<*p<<endl;
free(p);
cout<<*p<<endl;
*p = 20;
cout<<*p<<endl;
return 0;
}


int main()
{
int *p = (int*)malloc(sizeof(int)*5);
for(int i =0;i<5;++i)
{
p[i] = i;
}
for(int i = 0;i<5;++i)
{
*p = i;
p = p+1;
}

free(p);
p = NULL;
}

int main()
{
int ar[]={34,78,90,12,23,67,18,100};
int n = sizeof(ar)/sizeof(ar[0]);
SeqList mylist;// data cursize maxsize;
InitList(mylist);
for(int i = 0;i<n;++i)
{
Push_Back(mylist,ar[i]);
}
PrintList(mylist);

HeapSort(mylist);
PrintList(mylist);


DestroyList(mylist);
return 0;
}








// c > malloc  // free
// c++ > new   // delete
int * GetArray(int n)
{
int *s = (int*)malloc(sizeof(int)*n);
//int *s1 = (int*)calloc(sizeof(int),n);
// NULL;
if(NULL == s)
{
exit(1);
}
memset(s,0,sizeof(int)*n);
return s;
}
void Freenode(int *p)
{
free(p);
}
int main()
{
int *p = GetArray(10);

Freenode(p);
p = NULL;
}


int main()
{
int *p = NULL;
int n;
cin>>n; // 10            4*n
p = (int *)malloc(sizeof(int)*n);//
for(int i = 0;i<n;++i)
{
p[i] = i;
*(p+i) = i;
//*p = i;
//++p;
}
for(int i = 0;i<n;++i)
{
cout<<p[i]<<" ";
}
cout<<endl;

free(p);
p = NULL;

return 0;

}
struct Student
{
char s_name[20];
int num;
int grade[5];
}; // s_name = "yhping",5 ,90,89,78,87,100;
void InitStudent(Student *sp)
{
if(NULL == sp) return;
strcpy(sp->s_name,"201801001");
sp->num = 5;
sp->grade[0] = 12;


}
void Init_Student(Student &s)
{
int ar[]={78,89,78,89,90};
strcpy(s.s_name,"yhping");
s.num = 5;
memmove(s.grade,ar,sizeof(ar));
}
int main()
{
Student s1;
}
struct Student
{
char s_id[20];
char s_name[20];
char s_sex;
int s_age;
};
//s ={s_id:"201801001",s_name:"yhping",s_sex:'m',s_age:23};
void InitStudent(Student *sp) // s_id=>"201801001","yhping",'m',23;
{
if(NULL == sp) return ;
strcpy(sp->s_id,"201801001");
strcpy(sp->s_name,"yhping");
sp->s_sex = 'm';
sp->s_age = 23;
//*sp = {"201801001","yhping",'m',23};// 2015 c11 c14 //c99
}
void Init_Student(Student &s)
{
strcpy(s.s_id,"201801001");
strcpy(s.s_name,"yhping");
s.s_sex = 'm';
s.s_age = 23;
//s ={"201801001","yhping",'m',23};
}
int main()
{
Student s1;
InitStudent(s1);
return 0;
}

void Swap(int *ap,int *bp)
{
if(NULL == ap || NULL == bp)
return ;
int a = *ap;
*ap = *bp;
*bp = a;
}
void Swap2(int &a,int &b)
{
int tmp = a;
a = b;
b = tmp;
}
int main()
{
int x = 10,y = 20;
cout<<"x = "<<x<<" y = "<<y<<endl;
Swap2(x,y);
cout<<"x = "<<x<<" y = "<<y<<endl;
return 0;
}

int main()
{
int a = 10;
a += 100;

type(a) b=0;
}


typedef int Array[10];

int main()
{
Array a,b;
}

#define SINT int *
typedef int *PINT;

int main()
{
SINT const a,b;//  int * const  a,b;
PINT const x,y;// x = &a; *x = 100;
}


void * my_memmove(void *dst,const void *src,int size)
{
void *p = dst;
assert(NULL != dst);
assert(NULL != src);
assert(size > 0);
while(size--)
{
*(char*)p = *(char*)src;
p   = (char*)p + 1;
src = (char*)src + 1;
}
return dst;
}

int my_strlen(const char *str)
{
int count = 0;
if(NULL == str) return count;
while(*str != '\0')
{
++str;
++count;
}
return count;
}


int main()
{
char str[256] ={"yhping hello"};
memmove(str+1,str,strlen(str)+1);
my_memmove(str+1,str,strlen(str)+1);

return 0;
}
int main()
{
char str1[256]={"yhping hello"};
char str2[256];
char str3[256];
my_memmove(str2,str1,0);
return 0;
}
///
#define DEBUG

#undef DEBUG
void * my_memmove(void *dst,const void *src,int size)
{
void *p = dst;
#ifdef DEBUG
if(NULL == dst || NULL == src || size < 1)
{
return dst;
}
#endif
while(size--)
{
*(char*)p = *(char*)src;
p = (char*)p + 1;
src = (char*)src + 1;
}
return dst;
}

int my_strlen(const char *str)
{
int count = 0;
if(NULL == str) return count;
while(*str != '\0')
{
++str;
++count;
}
return count;
}


int main()
{
char str1[256]={"yhping hello"};
char str2[256];
char str3[256];
my_memmove(str3,my_memmove(str2,str1,my_strlen(str1)+1),my_strlen(str1)+1);
//my_memmove(&s2,&s1,sizeof(Student));
return 0;
}
#include"yhp.h"
#include"yhp.h"
int main()
{
int ar[]={
#include"Array.txt"
};

return 0;
}
// # ##
#include<stdio.h>
#include<iostream>
using namespace std;

#define CPP 1
int maint()
{
int a = 10;
#if 0  // #ifdef CPP  #ifndef CPP
printf("%d %x\n",a,&a);
#else
cout<<a<<" "<<&a<<endl;
#endif
return 0;
}


#ifdef YHP
#endif

#define MUL(x,y)  ((x)*(y))
int main()
{
int a = 3 ,b = 5;
printf("%d \n",MUL(a+4,b+6));
printf("%d \n",(a+4*b+6));

return 0;
}


int Max(int a,int b)
{
return a>b? a:b;
}

#define MAX(a,b) (a>b? a:b)

int main()
{
int x = 10,y = 5;
double dx = 12.23,dy=34.45;
int c = Max(++x,y);
c = MAX(++x,y);// c = (++x>y?++x:y);
double dc;
dc = Max(dx,dy);
dc = MAX(dx,dy);
}

#define PI 3.14;

int main()
{
double r = 10, s= 0;
s = r * r * PI;
s = PI * r * r;

return 0;
}

#define MAX 10
#define PI 3.14
enum Status { OK = -1, ERROR = 10,NULLPOINT =3};
const int maxint = 10;
const double pi = 3.14;

int main()
{
int x = MAX;
int y = maxint;
int z = ERROR;
}



struct Student
{
int id;
char name[10];
int age;
};
// void *p ; 泛型指针
int main()
{
void  *p = NULL;
char *cp = NULL;
int a = 10;
char ch = 'a';
double dx = 12.23;
Student s;
p = &a;
p = &ch;
p = &dx;
p = &s;
*p;
p = (char*)p+1;
p = (char*)p+4;
p = (int*)p+1;
}
*/