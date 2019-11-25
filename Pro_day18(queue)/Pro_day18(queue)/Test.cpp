#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
using namespace std;

int main()
{
	int arr[] = { 3, 5, 34, 1, 8, 0, 6, 8, 2, 1 };
	int m = sizeof(arr) / sizeof(int);

	priority_queue<int, vector<int>, greater<int>> q2(arr, arr + m);

	cout << "size = " << q2.size() << endl;

	while (!q2.empty())
	{
		cout << q2.top() << " ";
		q2.pop();
	}
	cout << endl;
	return 0;
}

/*
int main()
{
	int arr[] = { 1, 2, 8, 6, 4, 5, 6, 10, 8, 7, 9 };
	int n = sizeof(arr) / sizeof(int);
	priority_queue<int> q1(arr, arr + n);

	cout << "size = " << q1.size() << endl;
	cout << "top = " << q1.top() << endl;
	q1.pop();//É¾³ýdui¶¥ÔªËØ
	cout << "top = " << q1.top() << endl;
	while (!q1.empty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;

	return 0;
}

/*
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
void main()
{
	queue<int> q;
	for (int i = 1; i <= 10; ++i)
		q.push(i);
	cout << "size = " << q.size() << endl;
	cout << "front = " << q.front() << endl;
	cout << "back = " << q.back() << endl;
	int value;
	while (!q.empty())
	{
		value = q.front();
		q.pop();
		cout << value << " ";
	}
}
/*
int main()
{
	queue<int> qu1;

	for (int i = 0; i < 6; ++i)
	{
		qu1.push(i);
	}
	cout << "size = " << qu1.size() << endl;
	cout << "front = " << qu1.front() << endl;
	cout << "back = " << qu1.back() << endl;

	qu1.pop();
	cout << "size = " << qu1.size() << endl;
	cout << "front = " << qu1.front() << endl;
	cout << "back = " << qu1.back() << endl;

	qu1.push(3);
	cout << "size = " << qu1.size() << endl;
	cout << "front = " << qu1.front() << endl;
	cout << "back = " << qu1.back() << endl;


	return 0;
}

/*
// queue::front
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main()
{
	std::queue<int> myqueue;

	myqueue.push(77);
	myqueue.push(16);

	myqueue.front() -= myqueue.back();    // 77-16=61

	std::cout << "myqueue.front() is now " << myqueue.front() << '\n';

	return 0;
}
/*
int main()
{
	queue<int> qu1;
	if (!qu1.empty())
	{
		for (int i = 0; i < 6; ++i)
		{
			qu1.push(i);
		}
	}
	cout << "size = " << qu1.size() << endl;
	//cout << "front = " << qu1.front() << endl;
	//cout << "back = " << qu1.back() << endl;

	//qu1.pop();
	//cout << "size = " << qu1.size() << endl;
	//cout << "front = " << qu1.front() << endl;
	//cout << "back = " << qu1.back() << endl;

	//qu1.push(3);
	//cout << "size = " << qu1.size() << endl;
	//cout << "front = " << qu1.front() << endl;
	//cout << "back = " << qu1.back() << endl;
	return 0;
}*/