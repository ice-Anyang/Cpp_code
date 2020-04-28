#include<iostream>
#include<thread>
#include <atomic>
#include<mutex>
using namespace std;



/*
double Division(int a, int b)throw(int,double)
{
	// 当b == 0时抛出异常
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}
void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

int main()
{
	try 
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unkown exception" << endl;
	}
	return 0;
}


/*
int Div(int& a, int& b)throw(int,double,char,short)
{
	
	if (b == 0)
		throw b;//抛出异常

	cout << "aaaaaaaaaaa" << endl;
	return a / b;
}


int main()
{
	int a = 10;
	int b = 2;
	int c = 0;
	try//测试快
	{
		c = Div(a, b);
		cout << "bbbbbbbbbbbbb" << endl;
	}
	catch (int)//捕获错误
	{
		cout << "error::b==0" << endl;
		cout << "cccccccccccccc" << endl;
	}
	catch(char)
	{
		cout<<"error2::b==0"<<endl;
	}
	return 0;
}

/*
int sum = 0;


template<class _Mutex>
class lock_guard
{
public:
	// 在构造lock_gard时，_Mtx还没有被上锁
	explicit lock_guard(_Mutex& _Mtx)
		: _MyMutex(_Mtx)
	{
		_MyMutex.lock();
	}
	// 在构造lock_gard时，_Mtx已经被上锁，此处不需要再上锁
	lock_guard(_Mutex& _Mtx, adopt_lock_t)
		: _MyMutex(_Mtx)
	{}
	~lock_guard() _NOEXCEPT
	{
		_MyMutex.unlock();
	}
	lock_guard(const lock_guard&) = delete;//无赋值语句
	lock_guard& operator=(const lock_guard&) = delete;//无拷贝构造
private:
	_Mutex& _MyMutex;
};

mutex m;

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		//std::lock_guard<mutex> loc(m);
		std::unique_lock<mutex> uni(m);
		sum++;
	}
		
}
int main()
{
	cout << "Before joining, sum = " << sum << std::endl;
	thread t1(fun, 1000000);
	thread t2(fun, 1000000);
	t1.join();
	t2.join();
	cout << "After joining, sum = " << sum << std::endl;

	return 0;
}


/*

//atomic 不允许拷贝构造
#include <atomic>
int main()
{
	atomic<int> a1(0);
	//atomic<int> a2(a1); // 编译失败
	atomic<int> a2(0);
	//a2 = a1; // 编译失败
	return 0;
}


/*

atomic_long sum{ 0 };
void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
		sum++; // 原子操作
}
int main()
{
	cout << "Before joining, sum = " << sum << std::endl;
	thread t1(fun, 1000000);
	thread t2(fun, 1000000);
	t1.join();
	t2.join();
	cout << "After joining, sum = " << sum << std::endl;
	return 0;
}
 // 声明一个类型为T的原子类型变量t


/*
//atomic_long sum = { 1 };
mutex m;
int sum = 1;
void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		m.lock();
		sum++; // 原子操作
		m.unlock();
	}
		
}
int main()
{
	
	cout << "Before joining, sum = " << sum << std::endl;
	thread t1(fun, 1000000);
	thread t2(fun, 1000000);
	t1.join();
	t2.join();
	cout << "After joining, sum = " << sum << std::endl;
	return 0;
}*/