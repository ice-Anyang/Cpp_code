#include<iostream>
using namespace std;

//命令行参数
//运算符重载：如果参数第一个不为对象，只能用友元，如果第一个参数为对象，可以用友元也可以用成员方法。
//友元方法：(1)可以访问私有成员，打破了封装性
//         （2）友元函数不能用const 修饰 
//         （3）友元函数可以在类的任何地方声明，不能用限定符修饰。
//			(4)一个函数可以是多个类的友元函数
//			(5)友元函数的调用和不同函数的调用和原理相同。
//成元方法：

class Int
{
public:
	Int operator++();// ++a
	Int operator++();// a++

private:
	long m_i;
};
int main()
{

	return 0;
}
/*
class	Complex
{
public:
	Complex() : m_real(0), m_imag(0)//构造函数
	{}
	~Complex()//析构函数
	{}

protected:

private:
	int m_real;
	int m_imag;

};
int main(int argc , char* argv[])
{

	return 0;
}

//namespace N1
//{
//	int c = 0;
//	int Add(int a, int b)
//	{
//		return a + b;
//	}	
//}
//
//namespace N2
//{
//	int c = 2;
//	int Add(int a, int b)
//	{
//		return a*b;
//	}
//}
//
//int main()
//{
//	using namespace N1;
//	int ret = Add(3, 5);
//	printf("ret = %d\n", ret);
//	printf("c = %d\n", c);
//	system("pause");
//	return 0;
//}

//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data()" << endl;
//	}
//	~Data()
//	{
//		cout << "~Data()" << endl;
//	}
//
//private:
//	int year;
//	int month;
//	int day;
//};
//
//int main()
//{
//	Data t;
//}
*/