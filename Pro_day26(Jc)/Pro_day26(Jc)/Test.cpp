#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


/*
class Student
{
public:
	void print()
	{
		cout << "Student::print()" << endl;
	}
public:
	void SetA(int  n)
	{
		_name = n;
	}
private:
	int _name;
};

class A : public Student //单继承
{
public:
	void fun()
	{
		cout << "A::fun()" << endl;
	}
protected:
	int _name = 10;
private:
	int _a;
};

class B : public Student, public A//多继承
{
public:
	void list()
	{
		cout << "B::list()" << endl;
	}
private:
	int _b;
};



/*
class A
{
public:
	void fun()
	{
		cout << "A::fun()" << endl;
	}
protected:
	int _name = 10;
private:
	int _a;
};
class B : protected A
{
public:
	void list()
	{
		cout << "B::list()" << endl;
		fun();
		_name = 100;
		cout << "_name = " << _name << endl;
	}
private:
	int _b;
};

int main()
{
	B st;
	st.list();//对象只能调用公有成员
	return 0;
}

/*
//1 从对象的角度去观察
//2 从派生类的角度去观察父类
class Date
{
public:
	Date(int i = 0) :_year(i)
	{
		cout << "Date::Date()" << endl;
	}
	~Date()
	{
		cout << "Date::~Date()" << endl;
	}
public:
	void print()
	{
		cout << "Date::print()" << endl;
	}
protected:
	void list()
	{
		cout << "Date::list()" << endl;
	}
private:
	int _year;
};
class Test : public Date
{
public:
	Test()
	{
		cout << "Test::Test()" << endl;
	}
	~Test()
	{
		cout << "Test::~Test()" << endl;
	}
public:
	void fun()
	{
		cout << "Test::fun()" << endl;
		list();
	}
private:
	int _name;
};

int main()
{
	Test ls;
	ls.fun();
	//无法用对象直接调用基类的保护函数ls.list();
	ls.print();
	return 0;
}
/*
class Date
{
public:
	Date(int i = 0) :_year(i)
	{
		cout << "Date::Date()" << endl;
	}
	~Date()
	{
		cout << "Date::~Date()" << endl;
	}
public:
	void print()
	{
		cout << "Date::print()" << endl;
	}
protected:
	void list()
	{
		cout << "Date::list()" << endl;
	}
private:
	int _year;
};
class Test : public Date
{
public:
	Test()
	{
		cout << "Test::Test()" << endl;
	}
	~Test()
	{
		cout << "Test::~Test()" << endl;
	}
private:
	int _name;
};
int main()
{
	Test A;
	return 0;
}

/*
class A
{
public:
	int _c;
private:
	int _a=10;
};
class B : public A//继承
{
public:
	void fun()
	{
		_c = 100;
	}
private:
	int _b;
};
int main()
{
	B b;
	cout << sizeof(A) << endl;//4
	cout << sizeof(B) << endl;//8
	return 0;
}*/