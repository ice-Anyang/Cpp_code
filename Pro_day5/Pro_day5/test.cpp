#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


/*һ����ֻ����һ������

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

	Test* p1 = Test::Instance();//ͨ����������ľ�̬����
	Test* p2 = Test::Instance();
	Test* p3 = Test::Instance();
	return 0;
}



/*
//��ջ�ϴ���һ������
ֻ����ջ�ϴ������󣬼������ڶ��ϴ��������ֻҪ��new�Ĺ������ε����ɣ�
�����ε�operator new�Ͷ�λnew���ʽ
ע�⣺������operator new��ʵ��Ҳ����λnew���ε�
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
�ڶ��ϴ���һ������
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
	new(ar, 0) int(1); //��λnew
	new(ar, 3) int(100);
	new(ar, 5) int(200);
	int *p = new int;
	return 0;
}

//������ new


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
	Test* p1 = new Test;//new����ù��캯��
	delete p1;//delete���ȵ�������������Ȼ���ͷſռ�

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
//c++��̬���ٿռ�
int main()
{
	int* p4 = new int;//����һ�����οռ�
	int* p5 = new int[20];//����20��int�Ϳռ�
	int* p6 = new int(3);//��ʼ�����ٵĿռ�Ϊ3

	delete p4;
	delete[]p5;
	delete p6;//�ͷſռ�
	return 0;
}
//C���� ��̬���ٿռ�
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
