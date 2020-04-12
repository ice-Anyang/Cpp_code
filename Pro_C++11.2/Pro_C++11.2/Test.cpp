#include<iostream>
#include<string.h>
using namespace std;


/*
//C++98中引用作用：因为引用是一个别名，需要用指针操作的地方，可以使用指针来代替，可以提高代码的
//可读性以及安全性。
//C++11中右值引用主要有以下作用：
//1. 实现移动语义(移动构造与移动赋值)
//2. 给中间临时变量取别名：
//3. 实现完美转发
//10 lambda表达式
//10.1 C++98中的一个例子
//在C++98中，如果想要对一个数据集合中的元素进行排序，可以使用std::sort方法。
void Fun(int &x){ cout << "lvalue ref" << endl; }
void Fun(int &&x){ cout << "rvalue ref" << endl; }
void Fun(const int &x){ cout << "const lvalue ref" << endl; }
void Fun(const int &&x){ cout << "const rvalue ref" << endl; }
template<typename T>
void PerfectForward(T &&t){ Fun(std::forward<T>(t)); }

int main()
{
	PerfectForward(10); // rvalue ref
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
	return 0;

}
/*
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s) : _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	//右值引用
	String(String &&s) : _str(s._str)
	{
		s._str = nullptr;
	}

	//s3 = s2 = s1;  //s2.operator=(s1);
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	//String s = s1 + s2;
	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		return strRet;
	}
	~String()
	{
		if (_str)
			delete[] _str;   //delete nullptr
	}
private:
	char* _str;
};

int main()
{
	String s1 = "Hello";
	//String s2 = s1;
	String s2 = move(s1);    //初始化
	return 0;
}

/*
void main()
{
	int a = 10;
	int *pa = &a;
	const int x = 1;
	//x = 100;
	const int *px = &x;
	int &b = a;
}

/*
int main()
{
	int a = 10;
	int &b = a;
	cout << b << endl;
	const int &c = a;
	cout << c << endl;
	int &&d = 10;
	cout << d << endl;
	return 0;
}
/*
int main()
{
	const int a = 9;
	const int &b = a;
	cout << b << endl;
	int c = 9;
	int &&d = 10;
	cout << d << endl;
	return 0;
}



/*
//lambda表达式复习
class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};
int main()
{

	Rate rt(2.5);
	cout << rt(1000, 2) << endl;
	// 函数对象
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);
	// lamber
	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };//相当于上面的Rate类
	auto a = r2(10000, 2);
	cout << a << endl;
	return 0;
}

/*
void(*PF)();
int main()
{
	auto f1 = []{cout << "hello world" << endl; };
	auto f2 = []{cout << "hello world" << endl; };
	// 此处先不解释原因，等lambda表达式底层实现原理看完后，大家就清楚了
	//f1 = f2; // 编译失败--->提示找不到operator=()
	// 允许使用一个lambda表达式拷贝构造一个新的副本
	auto f3(f2);
	f3();
	// 可以将lambda表达式赋值给相同类型的函数指针
	PF = f2;
	PF();
	return 0;
}

/*
int main()
{
	auto fun1 = []{cout << "hellowbit"<<endl; };
	auto fun2 = []{cout << "hellowLomato" << endl; };

	auto fun3 = fun1;//拷贝构造；
	fun3();

	auto pfun = fun1;
	pfun();
	return 0;
}



/*
int z = 15;
int main()
{
	int a = 10;
	cout << "a = " << a << endl;
	//[]  [=]   [&]  [a]  [&a]  [a, &b]  [this]
	auto fun = [&a](int x)->int
	{
		a = 100;
		return x + a + z;
	};

	cout << "a = " << a << endl;
	int res = fun(5);
	cout << "res = " << res << endl;
	return 0;
}


/*
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	//auto fun = [=](int x)->int
	//auto fun = [a](int x)->int
	auto fun = [a, b, c, d](int x)->int
	{
		return x + a + b + c + d;
	};

	int res = fun(5);
	cout << "res = " << res << endl;
}

/*
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	auto fun = [=](int x)->int
	//auto fun = [a](int x)->int
	//auto fun = [a, b, c, d](int x)->int
	{
		return x + a + b + c + d;
	};

	int res = fun(5);
	cout << "res = " << res << endl;
}


/*
auto fun = []{cout << "hello" << endl; };
int main()
{
	fun();
	return 0;
}

/*
class Test
{
public:
	Test(int a = 0) : m_a(a)
	{}
public:
	void fun(int a)const
	{
		m_a = a;
	}
private:
	mutable int m_a;
};
int main()
{
	Test t(100);
	t.fun(1);
	return 0;
}*/