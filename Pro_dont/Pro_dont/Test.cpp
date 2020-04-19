#include<iostream>
#include<assert.h>
using namespace std;

/*
template<typename T>
class pushOnFull
{
private:
	T _value;
public:
	pushOnFull(T i)
	{
		_value = i;
	}
	T value()const
	{
		return _value;
	}
	void print()
	{
		cerr << "ջ����" << value() << "δѹ��ջ" << endl;
	}
};

//ջ���쳣����
template<typename T>
class popOnEmpty
{
public:
	void print()
	{
		cerr << "ջ�ѿգ��޷���ջ" << endl;
	}
};

template<typename T>
class Stack
{
private:
	int top;                                    //ջ��ָ�루�±꣩
	T *elements;                               //��̬��������ֵ
	int maxSize;                               //ջ������ɵ�Ԫ�ظ���
public:
	Stack(int default_size = 20)
	{
		maxSize = default_size;
		elements = new T[maxSize];
		top = -1;
	}
	~Stack()
	{
		delete[] elements;
	}
	////////////////////////////////////////////////////////////////
	void Push(const T &data) throw(pushOnFull<T>)
	{
		if (IsFull())
			throw pushOnFull<T>(data);
		elements[++top] = data;
	}
	T Pop() throw(popOnEmpty<T>)
	{
		if (IsEmpty())
			throw popOnEmpty<T>();

		T data = elements[top];
		top--;
		return data;
	}
	/////////////////////////////////////////////////////////////////
	bool IsEmpty() const
	{
		return top == -1;
	}
	bool IsFull() const
	{
		return top == maxSize - 1;
	}
	void PrintStack()
	{
		for (int i = top; i >= 0; --i)
			cout << elements[i] << " ";
		cout << endl;
	}
};
int main()
{
	Stack<int> st(10);

	try
	{
		for (int i = 1; i <= 10; ++i)
		{
			st.Push(i);
		}
	}
	catch (pushOnFull<int> &e)
	{
		e.print();
	}
	st.PrintStack();

	try
	{
		for (int i = 0; i <= 10; ++i)
			st.Pop();
	}
	catch (popOnEmpty<int> &e)
	{
		e.print();
	}

	cout << "Main End." << endl;
	return 0;
}

/*
double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	int* array = new int[10];
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;  //�����׳�
	}
	// ...
	cout << "delete []" << array << endl;
	delete[] array;
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
	return 0;
}
/*
struct Test
{
};
//try throw catch  �쳣�淶
//��߷���ֵ         �ұ�Ҳ�з���ֵ �쳣     
//int Div(int a, int b)throw()  //������Բ������׳��쳣
//int Div(int a, int b)throw(int,char,double, Test)  //������Բ������׳��쳣
//int Div(int a, int b)throw(int, char, double, Test)  //������Բ������׳��쳣
int Div(int a, int b)
{
	float d = 0.0;
	if (b == 0)
		throw d; //�׳��������ͣ�����ֵ
	cout << "aaaaaaaaaaaaaaaaaaa" << endl;
	return a / b;
}
void main()
{
	int result = 0;
	try  //���Կ�
	{
		result = Div(10, 0);
		cout << "bbbbbbbbbbbbbbbb" << endl;
	}

	catch (int)  //��������������
	{
		cout << "Div Error 1: b == 0." << endl;
		return;
	}
	catch (double)
	{
		cout << "Div Error 2: b == 0." << endl;
		return;
	}
	printf("result = %d\n", result);
}
/*
int Div(int a, int b)
{
	//assert(b != 0);
	if (b == 0)
		exit(1); // �쳣����
	int result = a / b;
	//printf("aaaaaaaaaaaaaaaa\n");
	return result;
}
int main()
{
	//cout << Div(10, 0) << endl;
	cout << Div(10, 2) << endl;

	return 0;
}



/*
int Div(int a, int b)
{
	//assert(b != 0);
	if (b == 0)
		exit(1); // �쳣����
	int result = a / b;
	printf("aaaaaaaaaaaaaaaa\n");
	return result;
}
int main()
{
	cout << Div(10, 0) << endl;
	return 0;
}*/