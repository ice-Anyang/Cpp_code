#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
public:
	void Display()const
	{
		cout << _year <<" "<< _month <<" "<< _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class Date
{
public:
	void Display(const Date* this)
	{
		cout << this->_year << " " << this->_month << " " << this->_day << endl;

	}
private:
	int _year;
	int _month;
	int _day;
};


/*
class String
{
public:
	String(const char* str = "asd")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	String(const String& s) : _str((char*)malloc(strlen(s._str) + 1))
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)    
	{
		if (this != &s)        
		{
			char* pStr = new char[strlen(s._str) + 1];            
			strcpy(pStr, s._str);            
			delete[] _str;            
			_str = pStr; 
		}                
		return *this;
	}
	String* operator&()
	{

	}
	const String* operator&()const
	{

	}
	~String()
	{
		free(_str);
	}
private:
	char* _str;
};
int main()
{
	String s1("hello ");
	String s2 = s1;
	return 0;
}

/*
class Date 
{
public:    
	Date(int year = 1900, int month = 1, int day = 1)
	{ 
		_year = year;
		_month = month;
		_day = day;
	}
	~Date()
	{

	}
	Date operator+(const Date& d)
	{
		_year = _year + d._year;
		_month = _month + d._month;
		_day = _day + d._day;
		return *this;
	}
private:    
	int _year;
	int _month; 
	int _day;
};
int main()
{
	Date d1;
	Date d2;
	Date d3 = d2 + d1;// = 运算符重载编译器自动生成
	return 0;
}

/*
class String
{
public:
	String(const char* str = "asdf")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	String(const String& s) : _str((char*)malloc(strlen(s._str) + 1))
	{ 
		strcpy(_str, s._str); 
	}
	~String()
	{
		free(_str);
	}
private:
	char* _str;
};
int main()
{
	String s1;
	String s2(s1);
	return 0;
}
/*
class Date
{
public:
	Date(int year, int month, int day) 
		: _year(year),
		  _month(month),
		  _day(day)
	{} 

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2001,6,22);
	Date d2(d1);
	return 0;
}


/*
class string
{
public:
	string(const char* str = "asdf")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~string()
	{
		free(_str);
	}
private:
	char* _str;
};


/*
class List
{
public:
	List(int date)
	{
		*_date = date;
		_size = 0;
		_capacity = 0;
	}
	~List()
	{
		_date = nullptr;
		_size = _capacity = 0;
	}
private:
	DataType* _date;
	size_t _size;
	size_t _capacity;
};

int main()
{
	List l1(3);
	return 0;
}
/*
class Test
{
public:
	Test()
	{}
	Test(int date = 0)//参数可以有初始值。
	{
		_date = date;
	}
private:
	int _date;
};

int main()
{
	Test t1();//调用第一个构造函数
	Test t2(2);//调用有参数的构造函数
	return 0;
}

/*
class Test
{
public:
	Test(int date = 0)  //构造函数
	{
		_date = date;
	}

	//Test(int date = 0) :_date(date)  //初始化方法二
	//{}
private:
	int _date;
};
int main()
{
	Test t1(3);
	return 0;
}*/