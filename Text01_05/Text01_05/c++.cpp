#include <iostream>
using namespace std;
struct Person {
	char *_name;
	char *_sex;
	int age;

	Person(char*name, char*sex, int age)
	{
		_name = new char[strlen(name)];
		strcpy_s(_name, strlen(name), name);
		_sex = new char[strlen(sex)];
		strcpy_s(_sex, strlen(sex), sex);
		
	}
};

struct Stack
{
	int 
};




int main()
{
	int *p = (int*)malloc(sizeof(int) * 20);
	free(p);
	p = NULL;


}