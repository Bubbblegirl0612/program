#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

using namespace std;
#define SEQ_INIT_SIZE 100;
#define SEQ_INC_SIZE 2;
typedef int ElemType;
typedef enum{MALLOCFAULT = 1,MALLOCSUCSESS = 2};

struct Student
{
	char s_name[20];
	int num;
	int  grade[5];
};
struct SeqList
{
	ElemType *data;
	int cursize;
	int maxsize;
};
void InitStudent(Student *sp)//ָ���ʼ��,��Ҫ�����ж��Ƿ�Ϊ��

{
	if (NULL == sp) return;
	strcpy(sp->s_name, "yhp");

}
void InitStudent(Student &s)//���ó�ʼ�� 
{
	int ar[] = { 73,89,78,79,89 };
	strcpy(s.s_name, "yhping");
	s.num = 5;
	memmove(s.grade, ar, sizeof(ar));
}
void InsertItem(SeqList &seq, int pos, ElemType x)//���뺯��--���Ա�
{
	if (pos < 0 || pos>5)
	{
		return ;
	}
	if (seq.cursize > seq.maxsize)
	{
		return;
	}
//δ��
}
void DestroyList(SeqList &seq) {//�ͷź���
	free (seq.data);
	seq.data = NULL;
}
bool Inc_Size(SeqList &seq) //����
{
	ElemType *data = (ElemType*)malloc(seq.maxsize* SEQ_INC_SIZE);

}
void Push_Back(SeqList &seq, const ElemType x)//�����Ա�������
{
	
}
void Push_Front(SeqList &seq, const ElemType x)
{

}
void EraseList(SeqList &seq, int pos)
{
	if (pos<0||pos>seq.cursize )
	{
		return ;
	}
}
void RemoveItem(SeqList &seq, ElemType x)
{

	}
}
int main()
{
	Student s1;
	InitStudent(&s1);

}


//��ָ������ý��г�ʼ��ѧ��
//struct Student
//{
//	char s_id[20];
//	char s_name[20];
//	char s_sex;
//	int  s_age;
//};
//void InitStudent(Student &stud)
//{
//	stud = { "201801001","yhping",'m',23 };//�������߰汾�Ϳ������������
//}
//void InitStudent2(Student *stud)
//{
//	strcpy_s(stud->s_id, "201801001");
//	strcpy_s(stud->s_name, "yhping");
//	stud->s_sex = 'm';
//	stud->s_age = 23;
//}
//int main()
//{
//	Student s1;
//	Student s2;
//	InitStudent(s1);
//	cout << s1.s_name << endl;
//	InitStudent2(&s2);
//	cout << s1.s_name << endl;
//	return 0;
//}

////��Դ��ַ�Ķ���������Ŀ�ĵ�ַ��
//void my_memmove(void *dst, const void *src, int size)
//{
//	if (dst == NULL || src == NULL || size < 1)
//	{
//		return;
//	}
//	void *p = dst;
//	char *d = (char *)p;
//	const char *s = (const char *)src;
//	for (int i = 0; i < size; i++)
//	{
//		d[i] = s[i];
//	}
//}
//void main()
//{
//	char str1[256] = { "yhping hello" };
//	//char str2[256];
//	//char str3[256];
//	my_memmove(str1 + 1, str1, 10);
//	//cout << str2 << endl;
//}
//struct Student  //��Ƴ�Ա
//{
//	char s_id[10];
//	char s_name[20];
//	char s_sex;
//	int s_age;
//};
//int main()
//{
//	int a = 0;
//	Student s;
//	s.s_id[0] = 1;
//	s.s_id[1] = 2;
//	s.s_sex = 'man';
//	s.s_age = 10;
//}



//#include <ctype.h>
//using namespace std;
//int str_hex(const char *str);
//int str_oce(const char *str);
//int str_dig(const char *str);
//int my_atoi(const char* str);
//void fun(int x)
//{
//	static int a = x;
//}
//int main()
//{
//	system("pause");
//	return 0;
//}
//int my_atoi(const char* str)
//{
//	bool is_ = false;
//	while (isspace(*str) || '+' == *str || '-' == *str)
//	{
//		if ('-' == *str)
//		{
//			is_ = true;
//		}
//		str++;
//	}
//	int num = 0;
//	if ('0' == *str)
//	{
//		str++;
//		if (isdigit(*str))
//		{
//			num = str_oce(str);
//		}
//		else
//		{
//			num = str_hex(str++);
//		}
//	}
//	else
//	{
//		num = str_dig(str);
//	}
//	if (is_)
//	{
//		return -num;
//	}
//	else
//	{
//		return num;
//	}
//}
//int str_dig(const char *str)
//{
//	int num = 0;
//	while (isdigit(*str))
//	{
//		num = num * 10 + *str - '0';
//		++str;
//	}
//	return num;
//}
//int str_oce(const char *str)
//{
//	int num = 0;
//	while (isdigit(*str) && *str != '8'&&*str != '9')
//	{
//		num = num * 8 + *str - '0';
//		++str;
//	}
//	return num;
//}
//int str_hex(const char *str)
//{
//	int num = 0;
//	while (isxdigit(*str))
//	{
//		if (isdigit(*str))
//		{
//			num = num * 16 + *str - '0';
//		}
//		else if (isupper(*str))
//		{
//			num = num * 16 + *str - 'A' + 10;
//		}
//		else
//		{
//			num = num * 16 + *str - 'a' + 10;
//		}
//		++str;
//	}20
//	return num;1}


