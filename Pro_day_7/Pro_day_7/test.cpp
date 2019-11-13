#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


/*
template<typename Type, int MaxSize = 100>
class Stack
{
public:
	Stack()
	{
		capacity = MaxSize;
		base = new Type[capacity];
		size = 0;
	}
private:
	Type *base;
	size_t capacity;
	size_t size;
};
void main()
{
	Stack<int, 200> st;
}

/*
template<typename Type1, typename Type2>
class Stack
{
public:
	Stack()
	{
		cout << "Stack::Stack<Type1, Type2>" << endl;
	}
};

template<typename Type>
class Stack<Type, Type>
{
public:
	Stack()
	{
		cout << "Stack::Stack<Type, Type>" << endl;
	}
};

int main()
{
	Stack<char, char> st1;
	Stack<int, int> st2;
	Stack<char, int> st3;
	return 0;
}



//
//#include<stdlib.h>
//#include<stdio.h>
//
//#define MAX 6
//
//int main()
//{
//	
//	system("pause");
//	return 0;
//}

//int main()
//{
//	printf("%d\n", MAX(2, 6));
//	system("pause");
//	return 0;
//}

//#define NAME_MAX 20
//#define AGE_MAX 10
//
//int main()
//{
//
//	printf("%d\n", NAME_MAX);
//	printf("%d\n", AGE_MAX);
//
//	system("pause");
//	return 0;
//}
*/