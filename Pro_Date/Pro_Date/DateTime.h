#ifndef _DATETIME_H_
#define _DATETIME_H_

#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;

struct Time
{
	int hour;
	int minute;
	int second;
};
struct Date
{
	int year;
	int month;
	int day;
};

class DateTime
{
public:
	DateTime();
	~DateTime();
public:
	void GetCurDateTime();
	void DateTimeShow();
	void DateTimeDShow();
	void ShowMenology();
private:
	Date _date;
	Time _time;
};


#endif/*_DATETIME_H_*/