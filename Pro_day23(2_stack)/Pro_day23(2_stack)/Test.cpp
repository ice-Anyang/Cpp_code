#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<deque>
#include<vector>
#include<list>
using namespace std;
//也可实现，只要调用了正确方法都能行。
//不过编译器底部是用的双向队列完成栈的。
namespace C
{
	template<typename T, class Con = list<T>>
	class Stack
	{
	public:
		Stack()
		{}
		void Push(const T& x)
		{
			_ls.push_back(x);
		}
		void Pop()
		{
			_ls.pop_back();
		}
		T& Top()
		{
			return _ls.back();
		}
		size_t Size()
		{
			return _ls.size();
		}
		bool Empty()
		{
			return _ls.empty();
		}
	private:
		Con _ls;
	};
}
int main()
{
	C::Stack<int> ls;
	ls.Push(1);
	ls.Push(3);
	ls.Push(5);
	cout << ls.Size() << endl;
	cout << ls.Top() << endl;
	ls.Pop();
	cout << ls.Top() << endl;
	return 0;
}


/*
//我们试试用vector来作为底层实现栈
namespace B
{
	template<typename T,class Con = vector<T>>
	class Stack
	{
	public:
		Stack()
		{}
		void Push(const T& x)
		{
			_v.push_back(x);
		}
		void Pop()
		{
			_v.pop_back();
		}
		T& Top()
		{
			return _v[_v.size() - 1];
		}
		size_t Size()
		{
			return _v.size();
		}
		bool Empty()
		{
			return _v.empty();
		}
	private:
		Con _v;
	};
}
int main()
{
	B::Stack<int> s;
	s.Push(1);
	s.Push(3);
	s.Push(5);
	cout << s.Size() << endl;
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	return 0;
}


/*
//STL在底层实现是靠deque作为它的底层，通过调用deque的方法实现它的功能。
namespace A
{
	template<typename T,class Con = deque<T>>
	class Stack
	{
	public:
		void push(const T& x)//进栈
		{
			_s.push_back(x);
		}
		void pop()//出栈
		{
			_s.pop_back();
		}
		T& top()//取栈顶
		{
			return _s.back();
		}
		size_t size()
		{
			return _s.size();
		}
		bool empty()
		{
			return _s.empty();
		}
	private:
		Con _s;
	};
}

int main()
{
	A::Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.size() << endl;
	cout << s.empty() << endl;
	return 0;
}*/