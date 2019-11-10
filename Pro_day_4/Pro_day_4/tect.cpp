#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



/*
//内部类就是外部类的友元类。
//注意友元类的定义，内部类可以通过外部类的对象参数来访问外部类中 的所有成员。
//但是外部类不是内部类的友元。

//1. 内部类可以定义在外部类的public、protected、private都是可以的。
//2. 注意内部类可以直接访问外部类中的static、枚举成员，不需要外部类的对象 / 类名。
//3. sizeof(外部类) = 外部类，和内部类没有任何关系。
class A
{
public:
	A(int a = 0) :_m_a(a)
	{}
	class B//内部类
	{
	public:
		void fun(const A &a)
		{
			cout << _m_b << endl;
			cout << a._m_a << endl;
		}
	};
private:
	int _m_a;
	static int _m_b;//静态成员

};
int A::_m_b = 1;//静态成员需要在类的外部定义

int main()
{
	A::B b;
	b.fun(A(3));
	return 0;
}



/*
class Date;
class Time;

class Time
{
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0) 
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1;
	return 0;
}


/*
class Int;
class Test;
//友元类
class Int
{
public:
	Int(int d = 0) :m_i(d)
	{}
private:
	int m_i;
};
class Test
{
public:

private:
	int m_date;
};

/*
友元函数可访问类的私有成员，但不是类的成员函数 
友元函数不能用const修饰 
友元函数可以在类定义的任何地方声明，不受类访问限定符限制 
一个函数可以是多个类的友元函数 友元函数的调用与普通函数的调用和原理相同

class Test;

ostream& operator<<(ostream &out, const Test &i);//友元函数
istream& operator>>(istream &in, const Test &i);//友元函数

class Test
{
	friend ostream& operator<<(ostream &out, const Test &i);
	friend istream& operator>>(istream &in, const Test &i);

public:
	Test(int d = 0) : _date(d)
	{}
	~Test()
	{}
	Test(const Test &t)
	{
		_date = t._date;
	}
	Test& operator= (const Test& t)
	{
		if (this != &t)
		{
			_date = t._date;
		}
		return *this;
	}
private:
	int _date;
};

ostream& operator<<(ostream &out, const Test &i)
{
	out << i._date;
	return out;
}

istream& operator>>(istream &in, const Test &i)
{
	in >> i._date;
	return in;
}

int main()
{
	Test t;
	Test t1(t);
	int i = 0;
	cout << i << endl;
	return 0;
}


/*
class Test
{
public:
	Test(int d = 0) :m_date(d)
	{
		cout << "Creart Test object: " << this << endl;
	}

	Test(const Test& t)
	{
		cout << "Copy Test object: " << this << endl;
		m_date = t.m_date;
	}
	~Test()
	{
		cout << "Free Test object: " << this << endl;
	}
	Test& operator=(const Test& t)
	{
		cout << "Assign: " << this << endl;
		if (this != &t)
		{
			m_date = t.m_date;
		}
		return *this;
	}
public:
	int GetData()const
	{
		return m_date;
	}
private:
	int m_date;
};
Test fun(Test& x)
{
	int val = x.GetData();
	Test tem(val);
	return tem;
}

int main()
{
	Test t;
	Test t2 = t;
	return 0;
}


/*
class Test
{
public:
	Test(int d = 0) :m_date(d)
	{
		cout << "Creart Test object: " << this << endl;
	}
	
	Test(const Test& t)
	{
		cout << "Copy Test object: " << this << endl;
		m_date = t.m_date;
	}
	~Test()
	{
		cout << "Free Test object: " << this << endl;
	}
	Test& operator=(const Test& t)
	{
		cout << "Assign: " << this << endl;
		if (this != &t)
		{
			m_date = t.m_date;
		}
		return *this;
	}
public:
	int GetData()const
	{
		return m_date;
	}
private:
	int m_date;
};
Test fun(Test& x)
{
	int val = x.GetData();
	Test tem(val);
	return tem;
}

int main()
{
	Test t;
	Test t1;
	t1 = t;
	return 0;
}


/*
class Test
{
public:
	Test(int d = 0) :m_date(d)
	{}
	~Test()
	{}
	Test(const Test& t)
	{
		m_date = t.m_date;
	}
	Test& operator+(const Test& t)
	{
		if (this != &t)
		{
			m_date = t.m_date;
		}
		return *this;
	}
private:
	int m_date;

};

int main()
{
	Test t(6);
	Test t1;
	t1 = t;
	Test t2(t);
	return 0;
}





/*
// void fun()const
//void fun (const Test* const this)
//void fun()
//void fun(Test* const this)
//1. 每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次) 
//2. 类中包含以下成员，必须放在初始化列表位置进行初始化： 
//(1)引用成员变量
//(2)const成员变量
//(3)类类型成员(该类没有默认构造函数)
//(1)explicit  显式
//(2)static 静态成员必须在类的外面进行初始化
class A
{
public:
	A(int a,int b ,int c)
	{
		x = a;
		y = b;
		z = c;
	}
private:
	int x;
	int y;
	int z;
};

class Test
{
public:
	//开辟空间
	//初始值
	//构造对象
	explicit Test(int d = 0) :m_data(d), m_a(2,3,4)
	{
	}
	~Test()
	{}
private:
	int m_data;
	A m_a;
};
int main()
{
	Test t(10);
	t = (Test)100;
	return 0;
}*/