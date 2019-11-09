#define _CRT_SECURE_NO_WARNINGS 1
#include"DateTime.h"
DateTime::DateTime()
{
	_date.year = 1;
	_date.month = 1;
	_date.day = 1;
	_time.hour = 0;
	_time.minute = 0;
	_time.second = 0;
}
DateTime::~DateTime()
{
}
void DateTime::GetCurDateTime()
{
	time_t te;
	time(&te);

	struct tm *ptm = localtime(&te);
	_date.year = ptm->tm_year + 1900;
	_date.month = ptm->tm_mon + 1;
	_date.day = ptm->tm_mday;
	_time.hour = ptm->tm_hour;
	_time.minute = ptm->tm_min;
	_time.second = ptm->tm_sec;
}

void DateTime::DateTimeShow()
{

}