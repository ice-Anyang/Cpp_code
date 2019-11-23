#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//
//�������� �ӿ�˵��
//queue() ����յĶ���
//empty() �������Ƿ�Ϊ�գ��Ƿ���true�����򷵻�false
//size() ���ض�������ЧԪ�صĸ���
//front() ���ض�ͷԪ�ص�����
//back() ���ض�βԪ�ص�����
//push() �ڶ�β��Ԫ��val�����
//pop() ����ͷԪ�س�����
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