#include<iostream>
#include<thread>
#include<mutex>
#include <atomic>

using namespace std;




int number = 0;
mutex g_lock;
int ThreadProc1()
{
	for (int i = 0; i < 100; i++)
	{
		//g_lock.lock();
		lock_guard<mutex> a(g_lock);
		++number;
		cout << "thread 1 :" << number << endl;
		//g_lock.unlock();
	}
	return 0;
}
int ThreadProc2()
{
	for (int i = 0; i < 100; i++)
	{
		//g_lock.lock();
		lock_guard<mutex> a(g_lock);
		--number;
		cout << "thread 2 :" << number << endl;
		//g_lock.unlock();
	}
	return 0;
}
int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);
	t1.join();
	t2.join();
	cout << "number:" << number << endl;
	system("pause");
	return 0;
}

/*
int number = 0;
mutex g_lock;
int ThreadProc1()
{
	for (int i = 0; i < 100; i++)
	{
		g_lock.lock();
		++number;
		cout << "thread 1 :" << number << endl;
		g_lock.unlock();
	}
	return 0;
}
int ThreadProc2()
{
	for (int i = 0; i < 100; i++)
	{
		g_lock.lock();
		--number;
		cout << "thread 2 :" << number << endl;
			g_lock.unlock();
	}
	return 0;
}
int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);
	t1.join();
	t2.join();
	cout << "number:" << number << endl;
	system("pause");
	return 0;
}
/*

//atmoic<T> t; // ����һ������ΪT��ԭ�����ͱ���t
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


/*
mutex mt;
unsigned long sum = 0L;
void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		mt.lock();//����
		sum++;       //ԭ�Ӳ���
		mt.unlock();//����
	}
}
int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);   //1000 0000
	thread t2(fun, 10000000);   //2000 0000
	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;
	return 0;
}

/*
class mythread
{
public:
	mythread(thread &th) : m_th(th)
	{}
	~mythread()
	{
		if (m_th.joinable())
			m_th.join();
	}
private:
	thread &m_th;
};

void ThreadFunc()
{
	for (;;)
		cout << "ThreadFunc()" << endl;
}
bool DoSomething()
{
	return false;
}
int main()
{
	std::thread t(ThreadFunc);
	t.detach();

	//mythread myth(t);  //����˼��
	//this->join()
	if (!DoSomething())
		return -1;
	return 0;
}

/*
void thread_fun1(int& a)
{
	a = 100;
	printf("thread_fun1 a = %d\n", a);
}
int main()
{
	int a = 10;
	thread th(thread_fun1, ref(a));

	th.join();//���߳������ȴ�
	printf("a = %d\n", a);

	return 0;
}

/*
int main()
{
	int a = 10;
	auto fun = [=,&a]()mutable->void
	{
		a = 100;
		printf("lambda a = %d\n", a);
	};
	fun();
	printf("a = %d\n", a);
	return 0;
}


/*
int main()
{
	int a = 10;
	auto fun = [=]()mutable->void
	{
		a = 100;
		printf("lambda a = %d\n", a);
	};
	fun();
	printf("a = %d\n", a);
	return 0;
}*/