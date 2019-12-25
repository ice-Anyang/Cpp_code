#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<deque>
#include<list>
//using namespace std;
//为什么选择deque作为stack和queue的底层默认容器
//stack是一种后进先出的特殊线性数据结构，因此只要具有push_back()和pop_back()操作的线性结构，
//都可 以作为stack的底层容器，比如vector和list都可以；queue是先进先出的特殊线性数据结构，只要具有 push_back和pop_front操作的线性结构，
//都可以作为queue的底层容器，比如list。但是STL中对stack和 queue默认选择deque作为其底层容器，主要是因为：
//1. stack和queue不需要遍历(因此stack和queue没有迭代器)，只需要在固定的一端或者两端进行操作。 
//2. 在stack中元素增长时，deque比vector的效率高；queue中的元素增长时，deque不仅效率高，而且内 存使用率高

//由于队列是双向操作，而vector编译器把没有提供头删的接口
//尝试用list作为底层结构实现queue的功能。
namespace B
{
	template<typename T,class Con = list<T>>
	class Queue
	{
	public:
		Queue()
		{}
		void push(const T& x)//进队
		{
			_ls.push_back(x);
		}
		void pop()//出队
		{
			_ls.pop_front();
		}
		T& back()//队尾
		{
			return _ls.back();
		}
		const T& back()const
		{
			return _ls.back();
		}
		T& front()//队头
		{
			return _ls.front();
		}
		const T& front()const
		{
			return _ls.front();
		}
		size_t size()//队长
		{
			return _ls.size();
		}
		bool empty()//判空
		{
			return _ls.empty();
		}
	private:
		Con _ls;
	};
}
int main()
{
	B::Queue<int> qe;

	return 0;
}

/*

//队列也是以双向队列为底层实现。
namespace A
{
	template<typename T,class Con = deque<T>>
	class Queue
	{
	public:
		Queue()
		{}
		void push(const T& x)//进队
		{
			_de.push_back(x);
		}
		void pop()//出队
		{
			_de.pop_front();
		}
		T& back()//队尾
		{
			return _de.back();
		}
		const T& back()const
		{
			return _de.back();
		}
		T& front()//队头
		{
			return _de.front();
		}
		const T& front()const
		{
			return _de.front();
		}
		size_t size()//队长
		{
			return _de.size();
		}
		bool empty()//判空
		{
			return _de.empty();
		}

	private:
		Con _de;
	};
}

int main()
{
	A::Queue<int> q;
	q.push(1);
	q.push(3);
	q.push(5);
	q.push(7);
	q.push(9);
	cout << q.size() << endl;
	cout << q.front() << endl;
	q.pop();
	q.pop();
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.empty() << endl;
	cout << q.back() << endl;
	return 0;
}*/