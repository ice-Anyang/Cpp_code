#include<iostream>
#include<thread>
#include <atomic>
#include<mutex>
using namespace std;



/*
double Division(int a, int b)throw(int,double)
{
	// ��b == 0ʱ�׳��쳣
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
		throw b;//�׳��쳣

	cout << "aaaaaaaaaaa" << endl;
	return a / b;
}


int main()
{
	int a = 10;
	int b = 2;
	int c = 0;
	try//���Կ�
	{
		c = Div(a, b);
		cout << "bbbbbbbbbbbbb" << endl;
	}
	catch (int)//�������
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
	// �ڹ���lock_gardʱ��_Mtx��û�б�����
	explicit lock_guard(_Mutex& _Mtx)
		: _MyMutex(_Mtx)
	{
		_MyMutex.lock();
	}
	// �ڹ���lock_gardʱ��_Mtx�Ѿ����������˴�����Ҫ������
	lock_guard(_Mutex& _Mtx, adopt_lock_t)
		: _MyMutex(_Mtx)
	{}
	~lock_guard() _NOEXCEPT
	{
		_MyMutex.unlock();
	}
	lock_guard(const lock_guard&) = delete;//�޸�ֵ���
	lock_guard& operator=(const lock_guard&) = delete;//�޿�������
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

//atomic ������������
#include <atomic>
int main()
{
	atomic<int> a1(0);
	//atomic<int> a2(a1); // ����ʧ��
	atomic<int> a2(0);
	//a2 = a1; // ����ʧ��
	return 0;
}


/*

atomic_long sum{ 0 };
void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
		sum++; // ԭ�Ӳ���
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
 // ����һ������ΪT��ԭ�����ͱ���t


/*
//atomic_long sum = { 1 };
mutex m;
int sum = 1;
void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		m.lock();
		sum++; // ԭ�Ӳ���
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