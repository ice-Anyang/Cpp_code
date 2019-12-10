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
	//����������fun��������ʱ���ͻ��Զ����ظ����е�����fun��������������ͬ�����ء�
	//��������ã��򣺼�������޶���
	_sd.Base::fun();
	_sd.Base::fun(1);
	return 0;
}


/*
//��������� ���Ը�ֵ�� ����Ķ��� / �����ָ�� / ��������á������и������˵������Ƭ������ �
//Ԣ����������и����ǲ���������ֵ��ȥ�� 
//��������ܸ�ֵ����������� �����ָ�����ͨ��ǿ������ת����ֵ���������ָ
class Person
{
public:
	void Print()
	{
		cout << "_name "<< endl;
	}
protected:
	string _name; // ����
private:
	int _age; // ����
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
	A b;//�ȹ��츸��ģ����������
	Base B;
	//B = b;
	//Base *ps = &b;
	//Base &bs = b;
	return 0;
}*/