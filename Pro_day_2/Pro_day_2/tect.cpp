#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//c++ 类与对象上篇

/*
//this 指针 指向的是当前对象的地址
//无法改变this指针的指向
//可以改变this指针指向空间的内容
//1. this指针的类型：类类型* const 
//2. 只能在“成员函数”的内部使用 
//3. this指针本质上其实是一个成员函数的形参，是对象调用成员函数时，将对象地址作为实参传递给this 形参。所以对象中不存储this指针。 
//4. this指针是成员函数第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传递，不需要用户 传递

class Date
{
public:
	void Display()
	{
		cout << this->year << "-" <<this-> month << "-" << this->day << endl;
	}
	void SetDate(int yea ,int mont ,int da)
	{
		this->year = yea;
		this->month = mont;
		this->day = da;
	}	
private:
	int year;
	int month;
	int day;
};

int main()
{
	Date t1,t2;
	t1.SetDate(2001,6,22);
	t2.SetDate(1997, 12, 14);
	t1.Display();
	t2.Display();
	system("pause");
	return 0;

}
/*
class A1
{
public:
	void fun1(){
	}
private:
	int a;
};

class A2
{
public:
	void fun2(){
	}
};

class A3
{

};
int main()
{
	cout << sizeof(A1) << endl;//整型大小4
	cout << sizeof(A2) << endl;//空类的大小为1
	cout << sizeof(A3) << endl;//空类的大小为1
	system("pause");
	return 0;
}

//定义一个 类
//class Person
//{
//public:
//	void showInfo()
//	{
//		name = "zhangsan";
//		age = 14;
//		sex = "nan";
//		cout << name << "-" << age << "-" << sex << endl;
//	}
//private:
//	char* name;
//	int age;
//	char* sex;
//};
//int main()
//{
//	Person man;
//	man.showInfo();
//	return 0;
//}

/*class Test
{
public:
	Test(int d = 0) : m_data(d)
	{
		cout << "Create Test Object : " << this << endl;
	}
	//Test t1 = t;
	Test(const Test &t)
	{
		cout << "Copy Create Test Object : " << this << endl;
		m_data = t.m_data;
	}
	//=重载 运算符的重载
	Test& operator=(const Test &t)
	{
		cout << "Assign: " << this << " = " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		cout << "Free Test Object : " << this << endl;
	}
public:
	int GetData()const
	{
		return m_data;
	}
	int SetData(int data)
	{
		GetData();
		m_data = data;
	}
private:
	int m_data;
};
Test fun(Test t)
{
	int value = t.GetData();
	Test tmp(value);
	return tmp;
}
int main()
{
	Test  t;
	t.GetData();
	system("pause");
	return 0;
}

/*
class Tect
{
public:
	Tect(int d ) : m_data(d)
	{}
	~Tect()
	{}
private:
	int m_data;
};
int main()
{
	Tect t1(10);
	return 0;
}*/