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

class A : public Student //���̳�
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

class B : public Student, public A//��̳�
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
	st.list();//����ֻ�ܵ��ù��г�Ա
	return 0;
}

/*
//1 �Ӷ���ĽǶ�ȥ�۲�
//2 ��������ĽǶ�ȥ�۲츸��
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
	//�޷��ö���ֱ�ӵ��û���ı�������ls.list();
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
class B : public A//�̳�
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