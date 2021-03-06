// runnian.cpp: 定义控制台应用程序的入口点。
//
//判断x年x月x日是当年的第几天
#include "stdafx.h"
#include "iostream"
bool IsLeap(int year) {
	return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int YearMonth_To_day(int year, int month)
{

	int days[] = { 28,31,30,31,30,31,30,31,31,30,31,30,31 };

	if (year < 1 || month < 1 || month> 12)
	{
		return -1;
	}
	if (month == 2 && IsLeap(year))
	{
		month = 0;
	}
	return days[month];
}
	
int Total_YearMonthDay(int year, int month, int day)
{
	if (year < 1 || month < 1 || month> 12 || day < 1 || day >31)
	{
		return -1;
	}
	int total = 0;
	int days = 0;
	days = YearMonth_To_day(year, month);
	if (day > days) {
		return -1;
	}
	for (int i = 0; i < month; i++) {

		days = YearMonth_To_day(year, month);
		total += days;
	}
	total += day;
	return total;
}


int main()
{
	int year, month, day;
	scanf_s("%d %d %d", &year, &month,&day);
	day = Total_YearMonthDay(year, month, day);

	printf("%d year %d month %d day\n", year, month, day);
    return 0;
}

