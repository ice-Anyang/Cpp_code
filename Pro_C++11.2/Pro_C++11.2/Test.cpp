#include<iostream>
#include<string.h>
using namespace std;


/*
//C++98���������ã���Ϊ������һ����������Ҫ��ָ������ĵط�������ʹ��ָ�������棬������ߴ����
//�ɶ����Լ���ȫ�ԡ�
//C++11����ֵ������Ҫ���������ã�
//1. ʵ���ƶ�����(�ƶ��������ƶ���ֵ)
//2. ���м���ʱ����ȡ������
//3. ʵ������ת��
//10 lambda���ʽ
//10.1 C++98�е�һ������
//��C++98�У������Ҫ��һ�����ݼ����е�Ԫ�ؽ������򣬿���ʹ��std::sort������
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

	//��ֵ����
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
	String s2 = move(s1);    //��ʼ��
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
//lambda���ʽ��ϰ
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
	// ��������
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);
	// lamber
	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };//�൱�������Rate��
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
	// �˴��Ȳ�����ԭ�򣬵�lambda���ʽ�ײ�ʵ��ԭ����󣬴�Ҿ������
	//f1 = f2; // ����ʧ��--->��ʾ�Ҳ���operator=()
	// ����ʹ��һ��lambda���ʽ��������һ���µĸ���
	auto f3(f2);
	f3();
	// ���Խ�lambda���ʽ��ֵ����ͬ���͵ĺ���ָ��
	PF = f2;
	PF();
	return 0;
}

/*
int main()
{
	auto fun1 = []{cout << "hellowbit"<<endl; };
	auto fun2 = []{cout << "hellowLomato" << endl; };

	auto fun3 = fun1;//�������죻
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