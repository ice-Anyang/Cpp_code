#include <iostream>
using namespace std;


/*
class Base
{
public:
	Base()
	{
		cout << " This is Base::Base()" << endl;
	}
	virtual void fun()
	{
		cout << "This is Base::fun()" << endl;
	}
	virtual void list()
	{
		cout << "This is Base::list()" << endl;
	}
	virtual ~Base()
	{
		cout << "This is Base::~Base()" << endl;
	}
private:
	int B_date = 0;
};

class A : public Base
{
public:
	A()
	{
		cout << "This is A::A()" << endl;
	}
	void fun()
	{
		cout << "This is A::fun()" << endl;
	}
	void list()
	{
		cout << "This is A::list()" << endl;
	}
	virtual void print()
	{
		cout << "This is A::print()" << endl;
	}
	~A()
	{
		cout << "This is A::~A()" << endl;
	}
private:
	int a_date = 0;
};

int main()
{
	A a;
	Base* pa = &a;
	pa->fun();
	pa->list();
	return 0;
}


/*
//在多态下 ，基类的析构采用虚方法，防止内存泄漏
class Base
{
public:
	Base()
	{
		cout << " This is Base::Base()" << endl;
	}
	virtual void fun()
	{
		cout << "This is Base::fun()" << endl;
	}
	virtual ~Base()
	{
		cout << "This is Base::~Base()" << endl;
	}
private:
	int B_date=0;
};

class A : public Base
{
public:
	A()
	{
		cout << "This is A::A()" << endl;
	}
	void fun()
	{
		cout << "This is A::fun()" << endl;
	}
	~A()
	{
		cout << "This is A::~A()" << endl;
	}
private:
	int a_date=0;
};


int main()
{
	Base* ps = new A;
	ps->fun();
	delete ps;
	return 0;
}

/*
class Base
{
public:
	//void fun()
	//{
	//	cout << "Base::fun()" << endl;
	//}
	virtual void fun()
	{
		cout << "Base::fun()" << endl;
	}
};

class A : public Base
{
public:
	virtual void fun()
	{
		cout << "A::fun()" << endl;
	}
	void list()
	{
		cout << "A::list()" << endl;
	}
};

int main()
{
	//A _a;
	//_a.fun();//同名隐藏

	//多态
	Base *ps = new A;
	ps->fun();
	return 0;
}*/