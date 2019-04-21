#pragma once
struct Stack
{
	int *_arr;
	int _len;
	int _top;

	Stack();
	Stack(const Stack& src);
	Stack& operator=(const Stack& src);
	~Stack();































































	void pop();
	void push();
	void resize();
	bool IsFull();
	bool Isempty();

};