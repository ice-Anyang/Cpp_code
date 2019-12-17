#include<iostream>
using namespace std;

/*
class A
{
public:
	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
	virtual void test(){ func(); }
};
class B : public A
{
public:
	void func(int val = 0){ std::cout << "B->" << val << std::endl; }
};
int main(int argc, char* argv[])
{
	B*p = new B;
	p->test();
	return 0;
}
*/
/*
class Base1 { public: int _b1; };
class Base2 { public: int _b2; };
class Derive : public Base1, public Base2 { public: int _d; };
int main(){
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	return 0;
}

*/
/*
#include<iostream>
using namespace std;
class A{
public:
	A(char *s) { cout << s << endl; }
	~A(){}
};
class B :virtual public A
{
public:
	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
};
class C :virtual public A
{
public:
	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
};
class D :public B, public C
{
public:
	D(char *s1, char *s2, char *s3, char *s4) :B(s1, s2), C(s1, s3), A(s1)
	{
		cout << s4 << endl;
	}
};
int main() {
	D *p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}
*/
/*
//多态原理
class Person 
{
public:
	virtual void BuyTicket() 
	{ 
		cout << "买票-全价" << endl; 
	}
};
class Student : public Person 
{
public:
	virtual void BuyTicket() 
	{ 
		cout << "买票-半价" << endl;
	}
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person Mike;
	Func(Mike);
	Student Johnson;
	Func(Johnson);
	return 0;
}

/*
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _c = 0;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};

int main()
{
	Base b;
	Derive d;
	return 0;
}
/*
class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-舒适" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-操控" << endl;
	}
};
int main()
{
	//BMW b;
	//Car *ps = &b;
	//ps->Drive();
	BMW b;
	return 0;
}

/*
class Car
{
public:
	virtual void Drive()
	{}
};
class Benz :public Car 
{
public:
	virtual void Drive() override
	{ 
		cout << "Benz-舒适" << endl;
	}
};

int main()
{
	Benz b;
	Car* ps = &b;
	ps->Drive();
	return 0;
}


/*
class car
{
public:
	virtual void Drive() final
	{
		cout << "car::Drive()" << endl;
	}
};

class Benz :public car
{
public:
	//virtual void Drive()
	//{
	//	cout << "Benz::Drive()" << endl;
	//}
};

/*
class Base
{
public:
	Base()
	{
		base_data = 0;
	}
public:
	virtual void fun()
	{
		cout << "This is Base::fun()" << endl;
	}
	virtual void show()
	{
		cout << "This is Base;;show()" << endl;
	}
private:
	int base_data;
};
class D : public Base
{
public:
	D()
	{
		d_data = 0;
	}
public:
	void fun()
	{
		cout << "This is D::fun()" << endl;
	}
	void show()
	{
		cout << "This is D::show()" << endl;
	}
	virtual void print()
	{
		cout << "This is D::print()" << endl;
	}
private:
	int d_data;
};
void Func(Base& p)
{
	p.fun();
	p.show();
}

int main()
{
	Base b1;
	D b2;
	Func(b1);//多态
	Func(b2);//多态
	return 0;
}


/*
class Base
{
public:
	Base()
	{
		base_data = 0;
	}
public:
	virtual void fun()
	{
		cout << "This is Base::fun()" << endl;
	}
	virtual void show()
	{
		cout << "This is Base;;show()" << endl;
	}
	void fun1()
	{
		cout << "This is Base::fun1()" << endl;
	}
private:
	int base_data;
};
class D : public Base
{
public:
	D()
	{
		d_data = 0;
	}
public:
	void fun()
	{
		cout << "This is D::fun()" << endl;
	}
	void show()
	{
		cout << "This is D::show()" << endl;
	}
	virtual void print()
	{
		cout << "This is D::print()" << endl;
	}
private:
	int d_data;
};
typedef void(*vfptr_type)();

void PrintVTable(vfptr_type vtable[])
{
	cout << ":>" << vtable << endl;
	for (int i = 0; vtable[i] != nullptr; ++i)
	{
		vtable[i](); //(vtable+1)();
	}
}

int main()
{
	D d;
	vfptr_type *vtable = (vfptr_type*)(*(int*)&d);
	PrintVTable(vtable);
	return 0;
}


/*
class Base
{
public:
	Base()
	{
		B_date = 0;
	}
	virtual void fun()
	{
		cout << "This is Base::fun()" << endl;
	}
	virtual void list()
	{
		cout << "This is Base::list()" << endl;
	}
	virtual void show()
	{
		cout << "This is Base::show()" << endl;
	}
private:
	int B_date;
};
class D :public Base
{
public:
	D()
	{
		d_data = 0;
	}
public:
	void fun()
	{
		cout << "This is D::fun()" << endl;
	}
	void show()
	{
		cout << "This is D::show()" << endl;
	}
	virtual void print()
	{
		cout << "This is D::print()" << endl;
	}
private:
	int d_data;
};


int main()
{
	D _d;
	Base* ps;
	ps = &_d;
	ps->fun();
	ps->list();
	ps->show();
	return 0;
}*/