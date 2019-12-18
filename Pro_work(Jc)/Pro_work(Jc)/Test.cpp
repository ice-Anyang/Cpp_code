#include<iostream>
using namespace std;


class A
{
public:
	A() :m_iVal(0)
	{ 
		test();
	}
	virtual void func() 
	{
		cout << m_iVal << endl;//0
	}
	void test()
	{ 
		func();
	}
public:
	int m_iVal;
};

class B : public A
{
public:
	B(){
		test(); 
	}
	virtual void func()
	{
		++m_iVal;
		cout << m_iVal << endl;
	}
};

int main(int argc, char* argv[])
{
	A*p = new B;
	p->test();
	return 0;
}

//class A
//{
//public:
//	virtual void f()
//	{
//		cout << "A::f()" << endl;
//	}
//};
//
//class B : public A
//{
//	virtual void f()
//	{
//		cout << "B::f()" << endl;
//	}
//};
//int main()
//{
//	A* ps = (A*)new B;
//	ps->f();
//	return 0;
//}

//class Base
//{
//public:
//	virtual void f1()
//	{
//		cout << "Base::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "Base::f2()" << endl;
//	}
//};
//class B : public Base
//{
//public:
//	virtual void f1()
//	{ 
//		cout << "B::f1()" << endl; 
//	}
//	virtual void f2()
//	{ 
//		cout << "B::f2()" << endl; 
//	}
//	void f3()
//	{ 
//		cout << "B::f3()" << endl;
//	}
//};
//int main()
//{
//	Base b;
//	Base b1;
//	return 0;
//}
/*
class Base
{
public:
	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}
	virtual void f2()
	{
		cout << "Base::f2()" << endl;
	}
};

class A
{
public:
	void f1(){ cout << "A::f1()" << endl; }
	virtual void f2(){ cout << "A::f2()" << endl; }
	virtual void f3(){ cout << "A::f3()" << endl; }
};

class B : public A, public Base
{
public:
	virtual void f1(){ cout << "B::f1()" << endl; }
	virtual void f2(){ cout << "B::f2()" << endl; }
	void f3(){ cout << "B::f3()" << endl; }
};

int main()
{
	B _b;
	return 0;
}
*/

//class A
//{
//public:
//	void f1(){ cout << "A::f1()" << endl; }
//	virtual void f2(){ cout << "A::f2()" << endl; }
//	virtual void f3(){ cout << "A::f3()" << endl; }
//};
//
//class B : public A
//{
//public:
//	virtual void f1(){ cout << "B::f1()" << endl; }
//	virtual void f2(){ cout << "B::f2()" << endl; }
//	void f3(){ cout << "B::f3()" << endl; }
//};
//int main()
//{
//	A* pa;
//	B _b;
//	pa = &_b;
//	pa->f1();
//	pa->f2();
//	pa->f3();
//	return 0;
//}

//class A
//{
//public:
//	void test(float a)
//	{
//		cout << "1" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	void test(int b)
//	{
//		cout << "2" << endl;
//	}
//};
//int main()
//{
//	A _a;
//	B _b;
//	_a = _b;
//	_a.test(1);
//	return 0;
//}

/*
class B
{
public:
	int b;
};

class C1 : public B
{
public:
	int c1;
};

class C2 : public B
{
public:
	int c2;
};

class D : public C1, public C2
{
public:
	int d;
};

int main()
{
	D _d;
	cout << sizeof(_d) << endl;
	return 0;
}
*/

/*
class A
{
public:
	A() 
	{ 
		cout << "A::A()" << endl; 
	}
	~A() 
	{ 
		cout << "A::~A()" << endl;
	}
private:
	static int a;
};

class B : public A
{
public:
	B()
	{ 
		cout << "B::B()" << endl; 
	}
	~B() 
	{ 
		cout << "B::~b()" << endl; 
	}
private:
	int b;
};
int main()
{
	A _a;
	B _b;
	return 0;
}
*/
/*
class A
{
public:
	A() { cout << "A::A()" << endl; }
	~A() { cout << "A::~A()" << endl; }
private:
	static int a;
};

class B : public A
{
public:
	B() { cout << "B::B()" << endl; }
	~B() { cout << "B::~b()" << endl; }
private:
	int b;
};


int main()
{
	B _b;
	return 0;
}
*/

/*
class A
{
public:
	void f()
	{ 
		cout << "A::f()" << endl; 
	}
	int a;
};

class B : public A
{
public:
	void f(int a)
	{ 
		cout << "B::f()" << endl; 
	}
	int a;
};

int main()
{
	B b;
	b.f(1);
	return 0;
}*/

/*
class Base
{
public:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}
private:
	int _a;
	double _a;
};

int main()
{
	Base a;
	return 0;
}
*/