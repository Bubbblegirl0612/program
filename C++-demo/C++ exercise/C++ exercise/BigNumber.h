#pragma once

class BigNumber
{
public:
	char Num[25];
	int count;
public:
	BigNumber();
	BigNumber(const BigNumber& src);
	BigNumber(const char* src, int len);
	BigNumber operator+(const BigNumber& src);
	BigNumber operator-(const BigNumber& src);
	BigNumber operator=(const BigNumber& src);
	bool operator<(const BigNumber& src);
	bool operator>(const BigNumber& src);
	bool operator==(const BigNumber& src);
};

