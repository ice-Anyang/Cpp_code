#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<deque>
#include<vector>
#include<list>
using namespace std;
//Ҳ��ʵ�֣�ֻҪ��������ȷ���������С�
//�����������ײ����õ�˫��������ջ�ġ�
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
//����������vector����Ϊ�ײ�ʵ��ջ
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
//STL�ڵײ�ʵ���ǿ�deque��Ϊ���ĵײ㣬ͨ������deque�ķ���ʵ�����Ĺ��ܡ�
namespace A
{
	template<typename T,class Con = deque<T>>
	class Stack
	{
	public:
		void push(const T& x)//��ջ
		{
			_s.push_back(x);
		}
		void pop()//��ջ
		{
			_s.pop_back();
		}
		T& top()//ȡջ��
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