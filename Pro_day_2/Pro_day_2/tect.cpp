#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//c++ ���������ƪ

/*
//this ָ�� ָ����ǵ�ǰ����ĵ�ַ
//�޷��ı�thisָ���ָ��
//���Ըı�thisָ��ָ��ռ������
//1. thisָ������ͣ�������* const 
//2. ֻ���ڡ���Ա���������ڲ�ʹ�� 
//3. thisָ�뱾������ʵ��һ����Ա�������βΣ��Ƕ�����ó�Ա����ʱ���������ַ��Ϊʵ�δ��ݸ�this �βΡ����Զ����в��洢thisָ�롣 
//4. thisָ���ǳ�Ա������һ��������ָ���βΣ�һ������ɱ�����ͨ��ecx�Ĵ����Զ����ݣ�����Ҫ�û� ����

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
	cout << sizeof(A1) << endl;//���ʹ�С4
	cout << sizeof(A2) << endl;//����Ĵ�СΪ1
	cout << sizeof(A3) << endl;//����Ĵ�СΪ1
	system("pause");
	return 0;
}

//����һ�� ��
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
	//=���� �����������
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