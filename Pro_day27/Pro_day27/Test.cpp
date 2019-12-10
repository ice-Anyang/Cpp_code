#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	A(int a = 0)
	{
		cout << "A::A()" << endl;
	}
	~A()
	{
		cout << "A::~A()" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "B::B()" << endl;
	}
	~B()
	{
		cout << "B::~B()" << endl;
	}
};

class C
{
public:
	C()
	{
		cout << "C::C()" << endl;
	}
	~C()
	{
		cout << "C::~C()" << endl;
	}
};

class D : public A, public B, public C
{
public:
	D() :a(1), b(), c()
	{
		cout << "D::D()" << endl;
	}
	~D()
	{
		cout << "D::~D()" << endl;
	}
private:
	A a;
	C c;
	B b;
};




int main()
{
	D d;
	return 0;
}

/*
class Base
{
public:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}
	void fun(int)
	{
		cout << "Base::fun(int)" << endl;
	}
private:
	int _name;
};

class A : public Base
{
public:
	void fun()
	{
		cout << "A::fun()" << endl;
	}
private:
	int _a;
};

int main()
{
	A _sd;
	//_sd.fun(1);
	//_sd.fun();
	_sd.fun();
	//_sd.fun(1);
	//当子类中有fun（）函数时，就会自动隐藏父类中的所有fun（）函数，即：同名隐藏。
	//若真想调用，则：加上类的限定符
	_sd.Base::fun();
	_sd.Base::fun(1);
	return 0;
}


/*
//派生类对象 可以赋值给 基类的对象 / 基类的指针 / 基类的引用。这里有个形象的说法叫切片或者切 割。
//寓意把派生类中父类那部分切来赋值过去。 
//基类对象不能赋值给派生类对象 基类的指针可以通过强制类型转换赋值给派生类的指
class Person
{
public:
	void Print()
	{
		cout << "_name "<< endl;
	}
protected:
	string _name; // 姓名
private:
	int _age; // 年龄
	string _sex;
};
//class Student : protected Person
//class Student : private Person
class Student : public Person
{
protected:
	int _stunum; 
};

int main()
{
	Person p;
	Student s;
	//p = s;
	Person *ps = &s;
	//Person &rp = s;
	//s = p;
	Student *pst = (Student*)ps;
	//Student &rs = p;
}

/*
class Base
{
public:
	Base()
	{
		cout << "Base::Base()" << endl;
	}
	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
private:
	int _name;
}; 
class A : public Base
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
	int _a;
};

int main()
{
	A b;//先构造父类的，再是子类的
	Base B;
	//B = b;
	//Base *ps = &b;
	//Base &bs = b;
	return 0;
}*/