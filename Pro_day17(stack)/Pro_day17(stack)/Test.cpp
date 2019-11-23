#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//
//函数声明 接口说明
//queue() 构造空的队列
//empty() 检测队列是否为空，是返回true，否则返回false
//size() 返回队列中有效元素的个数
//front() 返回队头元素的引用
//back() 返回队尾元素的引用
//push() 在队尾将元素val入队列
//pop() 将队头元素出队列
//stack<int> st;
/*
template<class _Ty, class _Container = deque<_Ty> >//
class stack
{
public:
	stack() : c()
	{}
	void push(value_type&& _Val)
	{
		c.push_back(val);
	}
	bool empty() const
	{	// test if stack is empty
		return (c.empty());
	}
	size_type size() const
	{	// test length of stack
		return (c.size());
	}
	reference top()
	{	// return last element of mutable stack
		return (c.back());
	}
	const_reference top() const
	{	// return last element of nonmutable stack
		return (c.back());
	}
	void pop()
	{	// erase last element
		c.pop_back();
	}
protected:
	_Container c;	// the underlying container
};
int main()
{
	stack<int, vector<int> > st;
	for (int i = 0; i < 10; ++i)
	{
		st.push(i);
	}
	cout << "size = " << st.size() << endl;

	int value = 0;
	while (!st.empty())
	{
		value = st.top();
		st.pop();
		cout << value << " ";
	}
	cout << endl;
	return 0;
}


/*
int main()
{
	stack<int> st;
	cout << st.empty()<<endl;
	for (int i = 0; i < 5; ++i)
	{
		st.push(i);
	}
	cout << "size = " << st.size() << endl;

	cout << st.empty() << endl;

	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.push(20);
	st.push(40);
	cout << "size = " << st.size() << endl;

	return 0;
}*/