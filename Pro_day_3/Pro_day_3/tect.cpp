#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdbool.h>
using namespace std;


//����������� .* / :: /? : / sizeof / . / ��������
class Date
{
public:
	Date(int year = 2001, int month = 6, int day = 22)//���캯��
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& t)//�������캯��
	{
		_year = t._year;
		_month = t._month;
		_day = t._day;
	}
	Date operator=(const Date& t)//��ֵ���������
	{
		if (this != &t)
		{
			_year = t._year;
			_month = t._month;
			_day = t._day;
		}
		return *this;
	}
	~Date()//��������
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


// ����������ϵͳҲ�и�Ĭ�������������������ڽ�����ϵͳ�����е���
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


// ���캯��
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
	Date d; // ��û���Զ��幹�캯����ʱ��ϵͳ����Ĭ�ϵĹ��캯��
	//Date d1;
	//Date d2(2001, 6, 22);
	//Date d3();//��ִ�д�����䡣ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������  
	//		  //���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ��� 
	/*d1.SetDate(2000, 1, 1);
	d2.SetDate(2001, 1, 1);
	d1.Display();
	d2.Display();
	return 0;
}*/