#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


/*一个类只创建一个对象

class Test
{
public:
	static Test* Instance()
	{
		if (nullptr == m_instance)
		{
			m_instance = new Test;
		}
		return m_instance;
	}
protected:
	Test(int d = 4) :m_date(d)
	{}
	Test(Test const&) = delete;
	Test& operator=(Test const&) = delete;
private:
	int m_date;
	static Test* m_instance;
};
Test* Test::m_instance = nullptr;

int main()
{

	Test* p1 = Test::Instance();//通过类访问它的静态方法
	Test* p2 = Test::Instance();
	Test* p3 = Test::Instance();
	return 0;
}



/*
//在栈上创建一个对象
只能在栈上创建对象，即不能在堆上创建，因此只要将new的功能屏蔽掉即可，
即屏蔽掉operator new和定位new表达式
注意：屏蔽了operator new，实际也将定位new屏蔽掉
class StackOnly
{ 
public:        
	StackOnly()
	{} 
private: 
	void* operator new(size_t size);
	void operator delete(void* p);
};

/*
在堆上创建一个对象
class Test
{
public:
	static Test* CreatObject()
	{
		Test *p1 = new Test;
		return p1;
	}

protected:
	Test(int d = 0) :m_date(d)
	{}
	Test(const Test& t)
	{
		m_date = t.m_date;
	}
private:
	int m_date;
};
int main()
{
	Test::CreatObject();
	return 0;
}

/*
void* operator new(size_t sz, int *ptr, int pos)
{
	return (ptr + pos);
}
int main()
{
	int ar[10];
	new(ar, 0) int(1); //定位new
	new(ar, 3) int(100);
	new(ar, 5) int(200);
	int *p = new int;
	return 0;
}

//操作符 new


/*
class Test
{
public:
	Test() :m_date(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int m_date;
};
//void Test1()
//{
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//
//	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
//	free(p2);
//}

void Test2()
{
	Test* p1 = new Test;//new会调用构造函数
	delete p1;//delete会先调用析构函数，然后释放空间

	Test* p2 = new Test[10];
	delete []p2;
}
int main()
{
	Test t1;
	Test2();
	return 0;
}

/*
//c++动态开辟空间
int main()
{
	int* p4 = new int;//开辟一个整形空间
	int* p5 = new int[20];//申请20个int型空间
	int* p6 = new int(3);//初始化开辟的空间为3

	delete p4;
	delete[]p5;
	delete p6;//释放空间
	return 0;
}
//C语言 动态开辟空间
/*
int main()
{
	int *p = (int*)malloc(sizeof(int)* 10);
	free(p);

	int *p2 = (int*)calloc(10, sizeof(int));
	int *p3 = (int*)realloc(p2, sizeof(int)* 20);
	free(p3);
	return 0;
}
//int main()
//{
//	int *p = (int*)malloc(sizeof(int)* 10);
//	
//	free(p);
//	int *p2 = (int*)calloc(10, sizeof(int));
//	int *p3 = (int*)realloc(p2, sizeof(int)* 20);
//	free(p3);
//	return 0;
//}
*/
