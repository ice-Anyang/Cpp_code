#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdbool.h>
using namespace std;


//运算符的重载 .* / :: /? : / sizeof / . / 不能重载
class Date
{
public:
	Date(int year = 2001, int month = 6, int day = 22)//构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& t)//拷贝构造函数
	{
		_year = t._year;
		_month = t._month;
		_day = t._day;
	}
	Date operator=(const Date& t)//赋值运算符重载
	{
		if (this != &t)
		{
			_year = t._year;
			_month = t._month;
			_day = t._day;
		}
		return *this;
	}
	~Date()//析构函数
	{
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(d1);
	Date d3(1997, 12, 14);
	d1 = d3;
	return 0;
}


// 析构函数：系统也有个默认析构函数，生命周期结束，系统将自行调用
/*
class Date
{
public:
	Date()
	{
		cout << "Date()" << endl;
	}
	~Date()
	{
		cout << "~Date()" << endl;
	}
};
int main()
{
	Date d1;
	return 0;
}


// 构造函数
/*class Date
{
public:
	Date()
	{
		year = 2001;
		month = 6;
		day = 22;
	}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
private:
	int year;
	int month;
	int day;
};
int main()
{
	Date d1;
	return 0;
}
/*
class Date
{
public:
	//Date()
	//{
	//}
	//Date(int y, int m, int d)
	//{
	//	year = y;
	//	month = m;
	//	day = d;
	//}
	/*void SetDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void Display()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
private:
	int year;
	int month;
	int day;
};

int main()
{
	Date d; // 当没有自定义构造函数的时候，系统调用默认的构造函数
	//Date d1;
	//Date d2(2001, 6, 22);
	//Date d3();//不执行此条语句。注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明  
	//		  //以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象 
	/*d1.SetDate(2000, 1, 1);
	d2.SetDate(2001, 1, 1);
	d1.Display();
	d2.Display();
	return 0;
}*/