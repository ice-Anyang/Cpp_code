#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include<queue>
//#include<stack>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<functional>
#include<math.h>
#include<thread>
#include<assert.h>
#include<string.h>
using namespace std;


/*

class Base
{
public:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}

private:
	int _b = 1;
};

class A : public Base
{
public:
	void fun(int a)
	{
		cout << "A:fun()" << endl;
	}
private:
	int _a = 2;
};

int main()
{
	A a;
	a.fun(1);
	a.Base::fun();
	return 0;
}



/*
class Base
{
public:
	int fun(int a, int b)
	{
		return a + b;
	}
	double fun(int a, double b)
	{
		return a + b;
	}
};

int main()
{
	Base ba;
	int a = ba.fun(3, 4);
	cout << a << endl;
	double b = ba.fun(3, 4.0);
	cout << b << endl;

	return 0;
}



/*
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ-ȫ��" << endl;
	}
	virtual void fun()
	{
		cout << "Person::fun()" << endl;
	}
};
class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ-���" << endl;
	}
	
	void print()
	{
		cout << "Student::print()" << endl;
	}
private:
	int _b;
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person Mike;
	Func(Mike);
	Student Johnson;
	Func(Johnson);
	Mike.fun();
	Johnson.print();
	return 0;
}

/*
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;//4
};
int main()
{
	cout << sizeof(Base) << endl;
	return 0;
}

/*

class Person 
{
public:
	virtual void BuyTicket() 
	{ cout << "��Ʊ-ȫ��" << endl; }
};
class Student : public Person 
{
public:
	virtual void BuyTicket()
	{ cout << "��Ʊ-���" << endl; }
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person Mike;
	Func(Mike);
	Student Johnson;
	Func(Johnson);
	return 0;
}
/*

class Person
{
public:
	virtual Person* f()=0
	{
		cout << "this is Person:f()\n";
		return nullptr;
	}
};
class Student : public Person
{
public:
	virtual Student* f()
	{
		cout << "this is Student:f()\n";
		return nullptr;
	}
};

void Func(Person& p)
{
	p.f();
}
int main()
{
	//Person pe;//���󣬻����޷���ʵ��������
	Student stu;
	Func(stu);
	return 0;
}


/*
class Person 
{
public:
	virtual Person* f()
	{ 
		cout << "this is Person:f()\n";
		return nullptr;
	}
};
class Student : public Person 
{
public:
	virtual Student* f() 
	{ 
		cout << "this is Student:f()\n";
		return nullptr;
	}
};
void Func(Person& p)
{
	p.f();
}
int main()
{
	Student stu;
	Func(stu);
	return 0;
}

/*
class people
{
public:
	virtual void fun()
	{
		printf("this is people::fun()\n");
	}

	virtual void print()
	{
		cout << "this is people::print()" << endl;
	}

private:
	int _val;
};

class student : public people
{
	void fun()
	{
		cout << "this is student::fun()" << endl;
	}
	void print()
	{
		cout << "this is student::print()" << endl;
	}
private:
	int _sval;
};

void Func(people& pe)
{
	pe.fun();
	pe.print();
}

int main()
{
	people pu;
	Func(pu);

	student stu;
	Func(stu);

	return 0;
}




/*

int main()
{
	int a = 0, b = 1;
	int c = a + b;
	cout << c << endl;
	return 0;
}

/*

class people
{
public:
	virtual void fun()
	{
		printf("this is people::fun()\n");
	}

	virtual void print()
	{
		cout << "this is people::print()" << endl;
	}

private:
	int _val;
};

class student
{
	void fun()
	{
		cout << "this is student::fun()" << endl;
	}
	void print()
	{
		cout << "this is student::print()" << endl;
	}
private:
	int _sval;
};

void Func(people& pe)
{
	pe.fun();
	pe.print();
}

int main()
{
	people stu;
	Func(stu);

	return 0;
}


/*
//C++ �̳�
int main()
{
	int a = 337, b = 1, c = 2;
	int m = a + b*c;
	cout << m << endl;
	return 0;
}


/*
class A
{
public:
	int _a = 10;
};
class B : virtual public A
{
protected:
	int _b = 20;
};
class C : virtual public A
{
protected:
	int _c = 30;
};
class D : public B, public C
{
protected:
	int _d = 40;
};

int main()
{
	D d;
	d._a = 50;
	cout << d._a << endl;
	A a;
	cout << a._a << endl;

	return 0;
}


/*
class A
{
public:
	int _a = 10;
};
class B : public A
{
protected:
	int _b = 20;
};
class C : public A
{
protected:
	int _c = 30;
};
class D : public B, public C
{
protected:
	int _d = 40;
};
int main()
{
	D d;
	//d._a = 50;
	//���ڶ����ԣ�_a�޷�ȷ����class B �е� ����class C �еġ�
	return 0;
}

/*
class A
{
};
class B
{
};
class C : public A, public B
{
};

/*
class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};

class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;
}

int main()
{
	TestPerson();
	return 0;
}


/*
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // ����
};
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	//cout << s._stuNum << endl;
}
void main()
{
	Person p;
	Student s;
	Display(p, s);
}

/*
class Base
{
public:
	Base()
	{
		cout << "this is Base::Base()" << endl;
	}
	Base(const Base& b) :_m(b._m)
	{
		cout << "this is Base::Base(const Base& b)" << endl;
	}
	Base& operator=(const Base& b)
	{
		cout << "this is Base::Base& operator=(const Base& b)" << endl;
		if (this != &b)
			_m = b._m;
		return *this;
	}
	~Base()
	{
		cout << "this is Base::~Base()" << endl;
	}
private:
	int _m = 10;
};

class C : public Base
{
public:
	C()
	{
		cout << "this is C::C()" << endl;
	}
	C(const C& c) :_c(c._c)
	{
		cout << "this is C::C(const C& c)" << endl;
	}
	C& operator=(const C& c)
	{
		cout << "this is C::C& operator=(const C& c)" << endl;
		if (this != &c)
			_c = c._c;
		return *this;
	}
	~C()
	{
		cout << "this is C::~C()" << endl;
	}
private:
	int _c = 5;
};


int main()
{
	C c;
	C b = c;
	C d(b);
	return 0;
}


/*
class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // ����
};
class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //ѧ��
};
void Test()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}
int main()
{
	Test();
	return 0;
}



/*

class Base
{
public:
	Base()
	{
		cout << "this is Base::Base()" << endl;
	}
	Base(const Base& b) :_m(b._m)
	{
		cout << "this is Base::Base(const Base& b)" << endl;
	}
	Base& operator=(const Base& b)
	{
		cout << "this is Base::Base& operator=(const Base& b)" << endl;
		if (this != &b)
			_m = b._m;
		return *this;
	}
	~Base()
	{
		cout << "this is Base::~Base()" << endl;
	}
private:
	int _m = 10;
};

class C : public Base
{
public:
	C()
	{
		cout << "this is C::C()" << endl;
	}
	C(const C& c) :_c(c._c)
	{
		cout << "this is C::C(const C& c)" << endl;
	}
	C& operator=(const C& c)
	{
		cout << "this is C::C& operator=(const C& c)" << endl;
		if (this != &c)
			_c = c._c;
		return *this;
	}
	~C()
	{
		cout << "this is C::~C()" << endl;
	}
private:
	int _c = 5;
};


int main()
{
	C c;
	C b(c);
	C d = b;
	return 0;
}

/*


class Base
{
public:
	void fun()
	{
		cout << "This is Base::fun()" << endl;
	}
	int prin(int a)
	{
		cout << "This is Base::prin()" << endl;
		return 0;
	}
private:
	int _m = 5;
};

class B : public Base
{
public:
	void fun()
	{
		cout << "This is B::fun()" << endl;
	}
	void prin()
	{
		cout << "This is B::prin()" << endl;
	}
private:
	int _b = 10;
};

int main()
{
	B *pb = new B;
	//���õ������fun()������
	pb->fun();
	//�������������ø����fun()������
	pb->Base::fun();

	//���õ������prin()������
	pb->prin();
	//�������������ø����prin()������
	pb->Base::prin(1);

	return 0;
}



/*
//��ֵ���ݹ���

class Base
{
public:
	void fun()
	{
		cout << "This is Base::fun()" << endl;
	}
private:
	int _m = 5;
};

class A : public Base
{
public:
	void fun()
	{
		cout << "This is A::fun()" << endl;
	}
	void prin()
	{
		cout << "This is A::prin()" << endl;
	}
private:
	int _a = 10;
};


int main()
{
	//1.����Ķ��������Ķ���ֵ
	A ma;
	Base mb = ma;
	//2.�����ָ�����ָ���������ĵ�ַ
	Base* mp = &ma;
	//3.����Ķ�����Ը���������ø�ֵ
	Base& mbb = ma;

	//�����õĸ���ĳ�Ա����
	mb.fun();
	mp->fun();
	mbb.fun();

	return 0;
}



/*
class person
{
public:
	void print()
	{
		cout << _age << endl;
	}
private:
	int _age = 18;
};

class student : public person
{

//protected:
public:

	void fun()
	{
		cout << "student::fun()" << endl;
	}

protected:
	char *name = "zhangsan";

};

int main()
{
	person pr;
	student stu;
	stu.print();
	stu.fun();
	return 0;

}

/*
class person
{
public:
	void print()
	{
		cout << _age << endl;
	}
private:
	int _age = 18;
};

class student : public person
{

protected:
	char *name= "zhangsan";

};

int main()
{
	person pr;
	student stu;
	stu.print();
	return 0;

}

/* 
namespace Ice
{
	template<class T, class Con = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue() :_c()
		{}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			: _c(first, last)
		{
			make_heap(_c.begin(), _c.end(), Com);
		}
		bool empty()  
		{
			return _c.empty();
		}
		size_t size()
		{
			return _c.size();
		}
		T& top()
		{
			return _c.front();
		}
		void push(const T& x)
		{
			_c.push_back(x);
			push_heap(_c.begin(), _c.end(), Com);
		}
		void pop()
		{
			pop_heap(_c.begin(), _c.end(), Com);
			c.pop_back();
		}

	private:
		Con _c;
		Compare Com;
	};
}


int main()
{
	vector<int> vt{ 3, 2, 5, 4, 6, 7 };
	Ice::priority_queue<int> q1;
	for (int i = 0; i < vt.size();++i)
		q1.push(vt[i]);

	cout << q1.top() << endl;  // 7

	return 0;
}


/*
// 
int main()
{
	vector<int> vt{ 1, 3, 2, 4, 2, 5, 3, 4 };
	sort(vt.begin(), vt.end());

	vt.erase(unique(vt.begin(), vt.end()),vt.end());

	for (auto&e : vt)
	{
		cout << e << " ";
	}

	cout << endl;

	return 0;
}


/* 
int main()
{
	vector<int> vt{ 1,4,6,3,0,2,5 };

	priority_queue<int> p1;

	for (auto& e : vt)
	{
		p1.push(e);
	}
	cout << p1.top() << endl;

	//����ΪС�ѽ�������������һ�� greater ����
	priority_queue<int, vector<int>, greater<int>> q2(vt.begin(), vt.end());
	cout << q2.top() << endl;

	return 0;
}





/*
namespace Ice
{
	template<typename T,class Con = deque<T>>
	class Queue
	{
	public:
		Queue()
		{}
		void Push(const T& x)
		{
			_qu.push_back(x);
		}
		void Pop()
		{
			_qu.pop_front();
		}

		T& Front()
		{
			return _qu.front();
		}
		T& Back()
		{
			return _qu.back();
		}

		size_t Size()
		{
			return _qu.size();
		}

		bool Empty()
		{
			return _qu.empty();
		}

	private:
		Con _qu;
	};
}
int main()
{
	Ice::Queue<int> qu;

	qu.Push(1);
	qu.Push(2);
	qu.Push(3);
	qu.Pop();

	cout << qu.Front() << endl;//2
	cout << qu.Back() << endl;//3
	cout << qu.Size() << endl;//2
	cout << qu.Empty() << endl;//0

	return 0;

}


/*

namespace Ice
{
	template<typename T, class Con = deque<T>>
	class Stack
	{
	public:
		Stack()
		{
		}
		void Push(const T& x)
		{
			_st.push_back(x);
		}
		void Pop()
		{
			_st.pop_back();
		}

		T& Top()
		{
			return _st.back();
		}

		size_t Size()
		{
			return _st.size();
		}

		bool Empty()
		{
			return _st.empty();
		}
	private:
		Con _st;
	};
}

int main()
{
	Ice::Stack<int> st;

	st.Push(1);
	st.Push(2);
	st.Push(3);

	st.Pop();

	cout << st.Top() << endl;

	cout << st.Size() << endl;
	cout << st.Empty() << endl;

	return 0;
}



/*
#include<iostream>
using namespace std;

class Scopedptr
{
public:
	Scopedptr(int n) :pt(n)
	{

	}
	int operator*(Scopedptr s)
	{
		return s.pt;
	}
	~Scopedptr()
	{
		delete[];
	}
private:
	int pt;
};
void* operator new (size_t n)
{
	int* ptr = (int*)malloc(sizeof(int)*n);
	if (ptr != nullptr)
		return ptr;
}
void test(int n)
{
	Scopedptr ptr(new int(n));
	*ptr *= 2;

	std::cout << *ptr << std::endl;
}

int main()
{
	int n = 0;
	std::cin >> n;

	test(n);
	return 0;
}

/*
#include<iostream>
#include<string>
//using namespace std;

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int num = 0;
	int count[256] = { 0 };
	vector<int> vt;
	while (cin >> num)
		vt.push_back(num);
	for (int i = 0; i<vt.size(); ++i)
	{
		if (count[vt[i]] == 0)
		{
			count[vt[i]]++;
		}
		continue;
	}
	for (int i = 0; i < 256; ++i)
	{
		if (count[i] == 1)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}

/*
#include<iostream>

class Scopedptr
{
public:
	Scopedptr()
	{

	}
	void operator new(size_t n)
	{

	}
	int operator*(Scopedptr s)
	{
		return s.pt;
	}
	~Scopedptr()
	{

	}
private:
	int pt;
};
void test(int n)
{
	Scopedptr ptr(new int(n));
	*ptr *= 2;

	std::cout << *ptr << std::endl;
}

int main()
{
	int n = 0;
	std::cin >> n;

	test(n);
	return 0;
}

/*
class A
{
public:
	A()
	{}
	A(std::string str):_s(&str)
	{}
	std::string s()const{
		return *_s;
	}
	A operator&(const A& s) = delete;
	A operator=(const A& s)
	{
		_s = s._s;
		return *this;
	}
	A move(const A& s)
	{
		_s = s._s;
		return *this;
	}
	~A()
	{
		_s = nullptr;
	}

private:
	std::string* _s;

};

int main()
{
	std::string input;
	std::cin >> input;
	A a(input);
	A b(std::move(a));
	std::cout << b.s() << std::endl;
	A c;
	c = std::move(b);
	std::cout << c.s() << std::endl;
	return 0;
}

/*
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int num = 0;
	int count[256] = { 0 };
	vector<int> vt;
	while (cin >> num)
		vt.push_back(num);
	for (int i = 0; i<vt.size(); ++i)
	{
		if (count[vt[i]] != 0)
			continue;
		count[vt[i]]++;
	}
	for (int i = 0; i < 256; ++i)
	{
		if (count[i] == 1)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}


/*
int main()
{
	deque<int> de{ 1, 2, 3 };
	deque<int> de2{ 4, 5, 6, 7 };

	de.push_back(4);
	de.push_back(5);
	de.push_front(0);
	de.push_front(0);
	
	de.pop_back();
	de.pop_front();

	for (auto& e : de)
		cout << e << " ";
	cout << endl;

	de.swap(de2);

	for (auto& e : de)
		cout << e << " ";
	cout << endl;

	de2.clear();


	return 0;
}


/*
int main()
{
	deque<int> de;
	de.push_back(1);
	de.push_back(2);
	de.push_back(3);
	de.push_back(4);
	de.push_back(5);

	for (auto& e : de)
		cout << e << " ";
	cout << endl;

	cout << de[2] << endl;

	cout << de.front() << endl;
	cout << de.back() << endl;

	return 0;
}


/*
int main()
{

	deque<int> de={ 1, 2, 3, 4, 5 }; // C++ 11 ��ʼ���б�

	cout << de.size() << endl; //5 
	cout << de.empty() << endl; //0  ����

	de.resize(20, 2);
	deque<int>::iterator it = de.begin();

	while (it != de.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	
}

/*

int main()
{
	deque<int> d1;
	deque<int> d2(10, 2);
	deque<int> d3(d2);
	deque<int> d4(d2.begin(), d2.end());

	for (auto& e : d2)
		cout << e << " ";
	cout << endl;

	for (auto& e : d3)
		cout << e << " ";
	cout << endl;

	for (auto& e : d4)
		cout << e << " ";
	cout << endl;

	return 0;
}



/*

int strcmp(const char* dest,const char* src)
{
	assert(dest);
	assert(src);

	while ((*dest != '\0') && (*src == *dest))
	{
		dest++;
		src++;
	}
	
	return  *dest - *src;

}


int main()
{
	char *str1 = "hello world";
	char *str2 = "hello xian";
	int res = strcmp(str1, str2);
	if (res > 0)
		printf("str1>str2");
	else if (res == 0)
		printf("str1=str2");
	else
		printf("str1<str2");
	return 0;
}


/*
char *my_strcat(char *dest, const char *src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char *ret = dest;
	while (*dest!='\0')                 //Ѱ�ҵ�Ŀ���ַ�����'\0'λ��
	{
		dest++;
	}
	while (*dest++ = *src++);       //����������strcpy��ͬ
	return ret;
}

int main()
{
	char* ptr = "hello world!";
	char arr[100] = "asd";

	my_strcat(arr, ptr);
	printf("arr: %s", arr);
	return 0;
}

/*
void my_strcat(char *dest, const char *src, int len)
{
	char *ret = dest + len;
	assert(src);
	//printf("%s\n",(dest+1));
	while (*ret++ = *src++)
		;
}
int main()
{
	char arr1[20] = "hello world";
	char arr2[] = "efgh";
	int len = strlen(arr1);
	my_strcat(arr1, arr2, len);
	printf("%s\n", arr1);
	system("pause");
	return 0;
}
/*
char* my_strcat(char *dest, const char* src)
{

	while (*dest != '\0')
		dest++;
	*(dest++) = *(src++);

}

int main()
{
	char* ptr = "hello world!";
	char arr[100] = "asd";

	my_strcat(arr, ptr);
	printf("arr: %s", arr);
	return 0;
}


/*
int main()
{
	char str[80];
	strcpy(str, "these ");
	strcat(str, "strings ");
	strcat(str, "are ");
	strcat(str, "concatenated.");
	printf("%s", str);
	return 0;
}



/*
char* my_strcpy(char *dest, const char*src)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while ((*dest++ = *src++))
		;
	return ret;
}


int main()
{
	char* ptr = "hello world!";
	char arr[100] = "";

	my_strcpy(arr,ptr);
	printf("arr: %s", arr);
	return 0;
}


/*
//size_t my_strlen(char* str)//�ݹ�ʵ��
//{
//	while (*(str) != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	return 0;
//}
//
//size_t my_strlen(char* str)//ָ��-ָ��
//{
//	char* pt = str;
//	while (*(pt) != '\0')
//		pt++;
//	return pt-str;
//}

size_t my_strlen(char* str)//��ʱ����
{
	size_t count = 0;
	while (*(str) != '\0')
		count++;
	return count;
}

int main()
{
	char* ptr = "hello world";
	size_t len = my_strlen(ptr);
	printf("len = %d", len);
	return 0;
}

/*

int main()
{
	char *ptr = "hello world";
	cout << sizeof(ptr) << endl;//4  //ָ���С��Ϊ4���ֽ�
	cout << strlen(ptr) << endl;//11 

	char arr[] = "hello world";
	cout << sizeof(arr) << endl;//12 ���ڡ�\0��;
	cout << strlen(arr) << endl;//11

	char arr1[] = {'a','s','d','f','g' };

	cout << sizeof(arr1)/sizeof(char) << endl;//5
	cout << strlen(arr1) << endl;//27 ���ִ���û�С�\0��;

	char arr2[] = { 'a', 's', 'd', 'f', 'g' ,'\0'};
	cout << strlen(arr2) << endl;

	return 0;
}


/*
namespace ice
{
	class string
	{
		friend ostream& operator<<(ostream &out, const string &s);
	public:
		typedef char* iterator;//������
		

	public:
		string(const char* str="")//���캯��
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s)//�������캯��;
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string tem(s);
			this->Swap(tem);
		}

		string operator=(string s)//��ֵ���
		{
			this->Swap(s);
			return *this;
		}
		
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
		
		///////////////////////////////////////////
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		char operator[](size_t i)
		{
			assert(i<_size);
			return _str[i];
		}

		const char operator[](size_t i)const
		{
			assert(i < _size);
			return _str[i];
		}

		void push_back(char c)
		{
			if (_size == _capacity)
				Reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}

		size_t size()
		{
			return _size;
		}

		size_t capacity()
		{
			return _capacity;
		}

		void Swap(string& s)//��������
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		void Resize(size_t newSize, char c = '\0')
		{
			if (newSize > _size)
			{
				// ���newSize���ڵײ�ռ��С������Ҫ���¿��ٿռ�
				if (newSize > _capacity)
				{
					Reserve(newSize);//����
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
		void Reserve(size_t newCapacity)//����
		{
			// ������������ھ��������򿪱ٿռ�
			if(newCapacity > _capacity)
			{
				char* str = new char[newCapacity + 1];
				strcpy(str, _str);//�Ѿɿռ�����ݿ�����str;
				// �ͷ�ԭ���ɿռ�,Ȼ��ʹ���¿ռ�
				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}

		string& operator+=(char c)
			{
			push_back(c);
			return *this;
		}
		
		const char* c_str()const//  c_str  ����;
		{
			return _str;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
ostream& ice::operator<<(ostream &out, const string &s)
{
	out << s._str;
	return out;
}

int main()
{
	ice::string s("hello world");

	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i];
	cout << endl;
	return 0;
}



/*
//��ת�ַ���
class Solution {
public:
	string reverseString(string& s) {
		if (s.empty())
			return s;
		size_t start = 0;
		size_t end = s.size() - 1;
		while (start < end)
		{
			swap(s[start], s[end]);
			++start;
			--end;
		}
		return s;
	}
private:

};

int main()
{
	string str1("hello world");
	Solution So;
	So.reverseString(str1);
	cout << str1 << endl;
}

/*

int main()
{
	string str1("hello world!");
	string str2("like ");

	//str1.append("aaa");// ��str1 ��׷���ַ���
	str1.append(str2); // ��str1 ��׷�� str2
	cout << str1 << endl;

	str1.push_back('c');//׷���ַ�
	cout << str1 << endl;

	str2 += str1;//׷���ַ���str1
	str2 += 'a';//׷���ַ�
	cout << str2 << endl;

	cout << str2.c_str() << endl;//c��ʽ��ӡ

	// ��ȡfile�ĺ�׺
	string file1("string.cpp");
	size_t pos = file1.rfind('.');//�ҵ�posλ��
	string suffix(file1.substr(pos, file1.size() - pos));//��ȡpos����ַ� .cpp
	cout << suffix << endl;

	// npos��string�����һ����̬��Ա����
	// static const size_t npos = -1;
	// ȡ��url�е�����

	string url("http://www.cplusplus.com/reference/string/");
	cout << url << endl;
	size_t start = url.find("://");//�ҵ�����//����λ��
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
	}

	start += 3;//����://
	size_t finish = url.find('/', start);//�ҵ���start��ʼ�ġ�:/��.
	string address = url.substr(start, finish - start);//��start��ʼ������

	cout << address << endl;
	return 0;
}




/*
int main()
{
	string str1("I love you!");

	//1.operator[]
	for (int i = 0; i < str1.size(); ++i)
		cout << str1[i];
	cout << endl;

	//2.��������
	//auto �ؼ���
	auto it = str1.begin();
	while (it != str1.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
	
	//3.c++11 for ����
	for (auto &e : str1)
		cout << e;
	cout << endl;
	return 0;
}

/*

int main()
{
	string str1{ "hello world" };//C++11 ��ʼ���б�

	cout << str1.size() << endl;// 11
	cout << str1.empty() << endl;// 0 

	cout << str1.capacity() << endl;// 15
	str1.reserve(24);
	cout << str1.capacity() << endl; // 31

	str1.resize(40);

	cout << str1.size() << endl; // 40 
	cout << str1.capacity() << endl; // 47
	cout << str1 << endl; // ...

	str1.clear();
	cout << str1 << endl;
	cout << str1.capacity() << endl; // 47
	cout << str1.size() << endl; // 0
	return 0;
}

/*

int main()
{
	string str1;
	string str2("hello world!");
	string str3(5, 'a');
	string str4(str2);
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	return 0;
}


/*

#define DataType int

void PrintArray(int *arr, int left, int right)
{
	int i = 0;
	for (i = left; i <= right; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void BinInsertSort(int *arr, int left, int right)
{
	int low, high, mid;
	int tem, j;
	for (int i = left + 1; i <= right; i++)
	{
		low = left;
		high = i - 1;
		tem = arr[i];
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (tem < arr[mid])
				high = mid - 1;
			if (tem >= arr[mid])
				low = mid + 1;
		}
		for (j = i; j > low; --j)//Ų��lowλ��
		{
			arr[j] = arr[j - 1];
		}
		arr[low] = tem;//tem�����λ����low
	}
}
void TwoWayInsertSort(int *arr, int left, int right)//��·��������
{
	int n = right - left + 1;
	int *tem = (int*)malloc(sizeof(int)*n);

	tem[0] = arr[left];
	int start, final;
	start = final = 0;
	int key = 0;
	for (int i = left + 1; i <= right; ++i)
	{
		key = arr[i];
		if (key < tem[start])//1.
		{
			start = (start - 1 + n) % n;
			tem[start] = key;
		}
		else if (key > tem[final])//2.
		{
			final++;
			tem[final] = key;
		}
		else//3.
		{
			int end = final;
			final++;
			while (key < tem[end])
			{
				tem[(end + 1) % n] = tem[end];
				end = (end - 1 + n) % n;
			}
			tem[(end + 1) % n] = key;
		}
	}
	for (int i = 0; i<n; ++i)//��tem ����arr ��
	{
		arr[i] = tem[start];
		start = (start + 1) % n;
	}
	free(tem);
}
void ShellSort(int *arr, int left, int right)//ϣ������ 
{
	int gap = right - left + 1;//�ܳ���
	while (gap > 1)//�����������1
	{
		gap = gap / 3 + 1;//gap������ȷ����
		for (int i = left; i <= right - gap; ++i)
		{
			int end = i;
			int tem = arr[end + gap];
			while (end >= left && tem<arr[end])
			{
				arr[end + gap] = arr[end];//
				end -= gap;
			}
			arr[end + gap] = tem;
		}
	}
}

void Swap(DataType* a, DataType* b)//��������
{
	DataType tem = *a;
	*a = *b;
	*b = tem;
}

//ֱ��ѡ������
static int GetMinIndex(int *arr, int left, int right)
{
	int index = left;
	int min = arr[left];
	for (int i = left + 1; i <= right; ++i)
	{
		if (min > arr[i])
		{
			min = arr[i];
			index = i;
		}
	}
	return index;
}

void SelectSort(int *arr, int left, int right)
{
	int i = 0;
	for (i = left; i < right; i++)
	{
		int index = GetMinIndex(arr, i, right);//��ȡ��Сֵ���±�
		if (index != i)
		{
			Swap(&arr[index], &arr[i]);//������λ���ϵ�ֵ
		}
	}
}

//������
static void AdjustDown(int *arr, int n, int start)//�γ�С��
{
	int i = start;//�м�
	int j = 2 * i + 1;//���ֵ
	while (j < n)
	{
		if (j + 1 < n && arr[j] <arr[j + 1])
			j++;
		if (arr[i] < arr[j])
		{
			Swap(&arr[i], &arr[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}

void HeapSort(int *arr, int left, int right)
{
	int n = right - left + 1;//�ܳ���
	int cur = (n - 1) / 2;//ȡ�м�ֵ
	while (cur > left)
	{
		AdjustDown(arr, n, cur);
		cur--;
	}
	int end = right;
	while (end >= left)
	{
		Swap(&arr[left], &arr[end]);
		AdjustDown(arr, end - left, 0);
		end--;
	}
}

void BubbleSort(int *arr, int left, int right)//ð������
{
	for (int i = left; i < right; ++i)
	{
		bool inser = false;
		for (int j = left; j < right - i; ++j)
		{
			if (arr[j]>arr[j + 1])
				Swap(&arr[j], &arr[j + 1]);
			inser = true;
		}
		if (!inser)//û���ڶ���for���˳�
			break;
	}
}



int main()
{
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	int sz = sizeof(arr) / sizeof(int);

	//InertSort_1(arr,0,sz-1);//ֱ�Ӳ�������
	//InsertSort_2(arr, 0, sz - 1);//ֱ�Ӳ���Swap��������
	//BinInsertSort(arr, 0, sz - 1);
	//TwoWayInsertSort(arr, 0, sz - 1);//��·�鲢����
	//SelectSort(arr, 0, sz - 1);//ѡ������
	//HeapSort(arr, 0, sz - 1);//������
	//BubbleSort(arr, 0, sz - 1);//ð������

	PrintArray(arr, 0, sz - 1);//��ӡ����

	return 0;
}

/*

void PrintArray(int *arr, int left, int right)
{
	int i = 0;
	for (i = left; i <= right; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(DataType* a, DataType* b)//��������
{
	DataType tem = *a;
	*a = *b;
	*b = tem;
}

void InertSort_1(int* arr, int left, int right)//ֱ�Ӳ�������
{
	int i = 0;
	for (i = left + 1; i <= right; ++i)
	{
		int key = arr[i];
		int end = i - 1;
		while (end >= left && key < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
}

// ֱ�Ӳ��룬����Swap����
void InsertSort_2(int *arr, int left, int right)
{
	int i = left + 1;
	for (i = left + 1; i <= right; ++i)
	{
		int end = i - 1;
		while (end >= left && arr[end + 1] < arr[end])
		{
			Swap(&arr[end + 1], &arr[end]);
			end--;
		}
	}
}

void InsertSort_3(int *arr, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		//�ڱ�λ
		arr[0] = arr[i];
		int end = i - 1;
		while (arr[0] < arr[end]) //
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = arr[0];
	}
}

int main()
{
	int arr[] = { 5,2,4,6,1,3 };
	int sz = sizeof(arr) / sizeof(int);

	//InertSort_1(arr,0,sz-1);//ֱ�Ӳ�������
	//InsertSort_2(arr, 0, sz - 1);//ֱ�Ӳ���Swap��������
	InsertSort_3(arr, 0, sz - 1);//

	PrintArray(arr, 0, sz - 1 );//��ӡ����

	return 0;
}


/*
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();
	while (it != v.end()) 
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	v.push_back(5);//β��
	v.push_back(6);//β��

	it = v.begin();
	while (it != v.end()) 
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	v.pop_back();//β��ɾ��

	it = v.begin();
	while (it != v.end()) 
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// ��posλ��֮ǰ����30
	v.insert(pos, 30);

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//��3λ�õ�iostream
	pos = find(v.begin(), v.end(), 30);
	// ɾ��posλ�õ�����
	v.erase(pos);

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int> vt{ 5, 6, 7, 8 };
	
	v.swap(vt);//����vt �� v ���ռ������

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	return 0;
}

/*

//size(),capacity();
int main()
{
	vector<int> vt;
	cout <<"size= "<< vt.size() << endl;
	vt.resize(5,2);
	vt.reserve(10);
	cout << "capacity = "<<vt.capacity() << endl;
	cout << "size= " << vt.size() << endl;
	for (int i = 0; i < 20; ++i)
	{
		vt.push_back(i);
		cout << "vt[" << i << "]=" << vt.capacity() << endl;
	}
	cout << "size = " << vt.size() << endl;
	cout << vt.empty() << endl;//1 - kong 0 - feikong
	return 0;
}


/*

int main()
{
	vector<int> vt{ 1, 2, 3, 4 };//c++11��ʼ���б�


	vector<int>::iterator it = vt.begin();//˳���ӡ
	while (it != vt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = vt.begin();//���������޸�
	while (it != vt.end())
	{
		*it *= 2;//�������
		++it;
	}

	vector<int>::reverse_iterator rit = vt.rbegin();//�����ӡ
	while (rit != vt.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	return 0;
}


/*
//vector �Ĺ���
int main()
{
	vector<int> vt1;
	vector<int> vt2(10, 2);//10���ռ䣬��ʼ��Ϊ2
	vector<int> vt3(vt2.begin(), vt2.end());//���乹�졣
	vector<int> vt4(vt2);//�������졣
	for (auto &e : vt2)
		cout << e <<" " ;
	cout << endl;

	for (vector<int>::iterator it = vt3.begin(); it != vt3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (auto it = vt4.begin(); it != vt4.end(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}


/*
server.Post("/dish", [&dish_table](const Request& req, Response& resp) {
	LOG(INFO) << "������Ʒ: " << req.body << std::endl;
	Json::Reader reader;
	Json::FastWriter writer;
	Json::Value req_json;
	Json::Value resp_json;
	// 1. ��������� Json ��ʽ
	bool ret = reader.parse(req.body, req_json);
	if (!ret) {
		// �����������, ����һ��400��Ӧ
		resp_json["ok"] = false;
		resp_json["reason"] = "parse Request failed!\n";
		resp.status = 400;
		resp.set_content(writer.write(resp_json), "application/json");
		return;
	}
	// 2. ���в���У��
	if (req_json["name"].empty() || req_json["price"].empty()) {
		resp_json["ok"] = false;
		resp_json["reason"] = "Request has no name or price field!\n";
		resp.status = 400;
		resp.set_content(writer.write(resp_json), "application/json");
		return;
	}
	���ؿƼ�// 3. �������ݿ�ӿڽ��в�������
		ret = dish_table.Insert(req_json);
	if (!ret) {
		resp_json["ok"] = false;
		resp_json["reason"] = "Insert failed!\n";
		resp.status = 500;
		resp.set_content(writer.write(resp_json), "application/json");
		return;
	}
	// 4. ��װ��ȷ�ķ��ؽ��
	resp_json["ok"] = true;
	resp.set_content(writer.write(resp_json), "application/json");
	return;
}
/*

MYSQL* mysql = NULL;
int main() {
	using namespace httplib;
	using namespace order_system;
	Server server;
	// 1. ���ݿ�ͻ��˳�ʼ�����ͷ�
	mysql = MySQLInit();
	signal(SIGINT, [](int) { MySQLRelease(mysql); exit(0); });
	DishTable dish_table(mysql);
	OrderTable order_table(mysql);
	// 2. ����·��
	// ������Ʒ
	server.Post("/dish", [&dish_table](const Request& req, Response& resp) {
	});
	// �鿴���в�Ʒ
	server.Get("/dish", [&dish_table](const Request& req, Response& resp) {
	});
	// ɾ����Ʒ
	// raw string(c++ 11), ת���ַ�����Ч. ������ʾ������ʽ���ú���
	// ����������ʽ, ֻ��������������. \d+ ��ʾƥ��һ������
	// http://help.locoy.com/Document/Learn_Regex_For_30_Minutes.htm
	server.Delete(R"(/dish/(\d+))", [&dish_table](const Request& req, Response& resp) {
	});
	// �޸Ĳ�Ʒ
	server.Put(R"(/dish/(\d+))", [&dish_table](const Request& req, Response& resp) {
	});
	���ؿƼ�// ��������
		server.Post("/order", [&order_table](const Request& req, Response& resp) {
	});
	// �޸Ķ���״̬
	server.Put(R"(/order/(\d+))", [&order_table](const Request& req, Response& resp) {
	});
	// ��ȡ����
	server.Get("/order", [&order_table, &dish_table](const Request& req, Response& resp) {
	});
	// ��ȡ�û��ͻ���, ƥ������ id
	server.Get(R"(/client/table/(\S+))", [](const Request& req, Response& resp) {
	});
	// ���þ�̬�ļ�Ŀ¼
	server.set_base_dir("./wwwroot");
	server.listen("0.0.0.0", 9092);
	return 0;
}



/*

class OrderTable {
public:
	OrderTable(MYSQL* mysql) : mysql_(mysql) { }
	bool SelectAll(Json::Value* orders) {
		char sql[1024 * 4] = { 0 };
		sprintf(sql, "select * from order_table");
		int ret = mysql_query(mysql_, sql);
		if (ret != 0) {
			printf("ִ�� sql ʧ��! %s\n", mysql_error(mysql_));
			return false;
		}
		MYSQL_RES* result = mysql_store_result(mysql_);
		if (result == NULL) {
			printf("��ȡ���ʧ��! %s\n", mysql_error(mysql_));
			���ؿƼ�return false;
		}
		int rows = mysql_num_rows(result);
		for (int i = 0; i < rows; ++i) {
			MYSQL_ROW row = mysql_fetch_row(result);
			Json::Value order;
			order["order_id"] = atoi(row[0]); // ע��, order_id ������, table_id ���ַ���
			order["table_id"] = row[1];
			order["time"] = row[2];
			// [��Ҫ] ��Ҫ���ϲ�� dish_ids �滻�� dishes(�����ǲ�Ʒ ID ���в�Ʒ��ϸ��Ϣ)
			order["dish_ids_str"] = row[3];
			order["state"] = row[4];
			// ����������μ��뵽 dishes ��
			orders->append(order);
		}
		return true;
	}
	bool Insert(const Json::Value& order) {
		char sql[1024 * 4] = { 0 };
		// �˴� dish_ids ��Ҫ��ת���ַ���(������һ������,
		// ���� [1, 2, 3]. �����ת, ���޷� asCString)
		sprintf(sql, "insert into order_table values(null, '%s', '%s', '%s', %d)",
			order["table_id"].asCString(), order["time"].asCString(),
			order["dish_ids_str"].asCString(), order["state"].asInt());
		int ret = mysql_query(mysql_, sql);
		if (ret != 0) {
			printf("ִ�� sql ʧ��! sql=%s, %s\n", sql, mysql_error(mysql_));
			return false;
		}
		return true;
	}
	bool ChangeState(const Json::Value& order) {
		char sql[1024 * 4] = { 0 };
		sprintf(sql, "update order_table set state = %d where order_id = %d",
			order["state"].asInt(), order["order_id"].asInt());
		int ret = mysql_query(mysql_, sql);
		if (ret != 0) {
			printf("ִ�� sql ʧ��! sql=%s, %s\n", sql, mysql_error(mysql_));
			return false;
		}
		return true;
	}
private:
	MYSQL* mysql_;
}

/*
void PrintList(list<int> L)
{
	for (auto& e : L)
		cout << e << " ";
	cout << endl;
}

int main()
{
	// ������������list
	int array1[] = { 1, 2, 3 };
	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	list<int> l2{ 4, 5, 6 };
	PrintList(l1);
	// ����l1��l2�е�Ԫ��
	l1.swap(l2);
	PrintList(l2);
	// ��l2�е�Ԫ�����
	l2.clear();
	cout << l2.size() << endl;
	return 0;
}

/*
void PrintfList(list<int> L)
{
	for (auto& e : L)
		cout << e << " ";
	cout << endl;
}

void main()
{
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
	// ��list��β������4��ͷ������0
	L.push_back(4);
	L.push_front(0);
	// ɾ��listβ���ڵ��ͷ���ڵ�
	PrintfList(L);
	L.pop_back();
	L.pop_front();
	PrintfList(L);
}

/*
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> ls(arr,arr+sizeof(arr)/sizeof(arr[0]));

	list<int>::iterator it = ls.begin();
	//���������
	while (it != ls.end())
	{
		cout << *it<<" ";
		++it;
	}
	cout << endl;
	//���������
	for (list<int>::reverse_iterator it = ls.rbegin(); it != ls.rend(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}


/*
class A{

	void test(float a){ cout << "1"; }
};
class B :public A{
	void test(int b){ cout << "2"; }
};
int main()
{
	B *b = new B;
	A *a = new A;
	a = b;
	return 0;
}



/*
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n)
	{
		// write code here
		int Max = 0;
		int pos = 0;
		for (int i = 0; i<n; ++i)
		{
			if (Max < A[i])
			{
				Max = A[i];
				pos = i;
			}
		}
		if (pos == 0)
			return A[0] - A[n - 1];
		if (pos == n - 1)
			return A[n - 1] - A[0];
		int leftMax = A[pos] - A[0];
		int rightMax = A[pos] - A[n - 1];
		return leftMax > rightMax ? leftMax : rightMax;
	}
};

/*
int main(){
	int n;
	while (cin >> n)
	{
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int k, d;
		cin >> k >> d;
		vector<vector<long long>> dp_max(n, vector<long long>(k + 1, 0));
		vector<vector<long long>> dp_min(n, vector<long long>(k + 1, 0));
		for (int i = 0; i < n; i++)
		{
			dp_max[i][1] = a[i];
			dp_min[i][1] = a[i];
		}
		for (int i = 0; i < n; i++){
			for (int j = 2; j <= k; j++){
				for (int m = max(0, i - d); m <= i - 1; m++){
					dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i]));
					dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
				}
			}
		}
		long long max_value = dp_max[k - 1][k];
		for (int i = k; i < n; i++)
		{
			max_value = max(max_value, dp_max[i][k]);
		}
		cout << max_value << endl;
	}
	return 0;
}



/*
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

}

/*
int main()
{
	std::list<int> l1; // ����յ�l1
	std::list<int> l2(4, 100); // l2�з�4��ֵΪ100��Ԫ��
	std::list<int> l3(l2.begin(), l2.end()); // ��l2��[begin(), end()������ҿ������乹��l3
	std::list<int> l4(l3); // ��l3��������l4
	// ������Ϊ���������乹��l5
	int array[] = { 16, 2, 77, 29 };
	std::list<int> l5(array, array + sizeof(array) / sizeof(int));//���乹��
	// �õ�������ʽ��ӡl5�е�Ԫ��
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;

	for (auto& e : l5)
		std::cout << e << " ";
	std::cout << endl;
	return 0;
}
/*
int main()
{
	string str;
	while (cin >> str)
	{
		int flag = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] == '_')
			{
				str.erase(str.begin() + i);
				flag = 1;
				i--;
			}
			else if (flag == 1)
			{
				str[i] = toupper(str[i]);//ת����д
				cout << str[i];
				flag = 0;
			}
			else
			{
				cout << str[i];
			}
		}
		cout << endl;
	}

}

/*
//���Թ�
//���ַ����������
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int a[10][10] = { 0 };//��¼����״̬��0����û���߹�
char str[10][10];//��¼�Թ�
int bfs(int x0, int y0)
{
	queue<pair<int, int> > q;//�洢��������Ķ���
	pair<int, int> p;
	int x, y;
	q.push(make_pair(x0, y0));
	while (1)
	{
		p = q.front();
		x = p.first;
		y = p.second;
		if (x == 9 && y == 8)//�ߵ��յ���˳�ѭ��
			return a[9][8];
		
		//������4��if��䣬�ֱ��Ӧ���ӵ��ϡ��¡������ĸ����ڵĸ���
		//���������ӷ�������(���겻Խ�磬ͬʱ����'#'������֮ǰû���߹�)
		//�Ͱ���������С�������Ҫע����ǣ������Ƚ��ȳ��ͱ�֤������ڽ���
		//�������Ǳ������Զ�ĸ����ȴ���Ҳ����˵ֻ�е����(����ھ������2)
		//�����и��Ӷ�pop()�����У����Ϊ3�ĸ��Ӳű�Ϊ����Ԫ�ء�������һ���
		//���ӹ�ȣ�ֱ���ߵ����ڡ�
		//��Ȼ��Ҳ������һ��forѭ����������4��if������д����ϸ��
		if ((x - 1) >= 0 && (x - 1) <= 9 && y >= 0 && y <= 9 && a[x - 1][y] == 0 && str[x - 1][y] != '#')
		{
			a[x - 1][y] = a[x][y] + 1;
			q.push(make_pair(x - 1, y));
		}
		if ((x + 1) >= 0 && (x + 1) <= 9 && y >= 0 && y <= 9 && a[x + 1][y] == 0 && str[x + 1][y] != '#')
		{
			a[x + 1][y] = a[x][y] + 1;
			q.push(make_pair(x + 1, y));
		}
		if (x >= 0 && x <= 9 && (y - 1) >= 0 && (y - 1) <= 9 && a[x][y - 1] == 0 && str[x][y - 1] != '#')
		{
			a[x][y - 1] = a[x][y] + 1;
			q.push(make_pair(x, y - 1));
		}
		if (x >= 0 && x <= 9 && (y + 1) >= 0 && (y + 1) <= 9 && a[x][y + 1] == 0 && str[x][y + 1] != '#')
		{
			a[x][y + 1] = a[x][y] + 1;
			q.push(make_pair(x, y + 1));
		}
		q.pop();//�ж�����������4�����Ӻ�ø���Ӧ�ó���
	}
}


int main()
{
	char c;
	while (scanf("%c", &c))
	{
		str[0][0] = c;
		for (int i = 1; i<10; i++)
		{
			scanf("%c", &c);
			str[0][i] = c;
		}
		getchar();//�Ե�ĩβ�Ļ��з�
		for (int i = 1; i<10; i++)
		{
			for (int j = 0; j<10; j++)
			{
				scanf("%c", &c);
				str[i][j] = c;
			}
			getchar();//�Ե�ĩβ�Ļ��з�
		}
		printf("%d\n", bfs(0, 1));
		memset(a, 0, sizeof(a));//��ʼ��ȫ�ֱ���a����
	}
	return 0;
}
//������DFS�ⷨ��������Ϊû��BFSЧ�ʸ�
//DFS���������������һ�����ߵ��ڣ�Ȼ���ٻ�������ԭֵС�͸���ԭֵ
//���Ա����������ܸ���һ�㣬����DFSʹ���˵ݹ�
//#include<iostream>
//#include<string.h>
//using namespace std;
//int a[10][10] = { 0 };
//char str[10][10];
//int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
//void dfs(int x, int y)
//{
//	for (int i = 0; i<4; i++)
//	{
//		int m = x + dir[i][0];
//		int n = y + dir[i][1];
//		if (m >= 0 && m <= 9 && n >= 0 && n <= 9 && str[m][n] != '#')
//		{
//			if ((a[m][n] == 0) || (a[x][y] + 1)<a[m][n])
//			{
//				a[m][n] = a[x][y] + 1;
//				dfs(m, n);
//			}
//		}
//	}
//
//}
//int main()
//{
//	//  freopen("input.txt","r",stdin);
//	char c;
//	while (~scanf("%c", &c))
//	{
//		str[0][0] = c;
//		for (int i = 1; i<10; i++)
//		{
//			scanf("%c", &c);
//			str[0][i] = c;
//		}
//		getchar();
//		for (int i = 1; i<10; i++)
//		{
//			for (int j = 0; j<10; j++)
//			{
//				scanf("%c", &c);
//				str[i][j] = c;
//			}
//			getchar();
//		}
//		dfs(0, 1);
//		printf("%d\n", a[9][8]);
//		memset(a, 0, sizeof(a));
//	}
//	return 0;



/*
//���ַ����������
int main()
{
	string str;
	while (getline(cin, str))
	{
		int n = str.size();
		for (int i = 0; i < n; ++i)
		{
			if (str[i] >= '0'&&str[i] <= '9')
				cout << str[i];
		}
		cout << endl;
	}
	return 0;
}
/*
//f(n)=f(n-1)+f(n-2)
int main()
{

	for (int i = 0; i < 100; ++i)
	{
		printf("xuliangshigegou!\n");
	}
	return 0;
}

/*
int main()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%d * %d = %d  ", i,j,i*j);
		}
		printf("\n");
	}

	return 0;
}

/*
#define PRICE 30
int main()
{
	int num = 0;
	cout << "������ƻ��" << endl;
	cin >> num;
	cout << "����Ҫ��"<<num*PRICE<<"��Ǯ" << endl;
	//printf("����Ҫ��%dmoney\n", num*PRICE);
	return 0;
}
/*

// write your code here cpp

int main()
{
	stack<int> str;
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			if (s[0] >= '0'&&s[0] <= '9')
			{
				int num = 0;
				for (size_t i = 0; i < s.size(); ++i)
				{
					num = num * 10 + s[i] - '0';
					str.push(num);
				}
			}
			else
			{
				int x = str.top();
				str.pop();
				int y = str.top();
				str.pop();
				if (s == "+")
					str.push(x + y);
				else if (s == "*")
					str.push(x*y);
				else if (s == "-")
					str.push(x - y);
				else if (s == "/")
					str.push(y / x);
			}
			cout << str.top() << endl;
		}
	return 0;
}


/*
int main()
{
	int a = 0;
	int sum = 0;
	while (cin >> a)
	{
		vector<int> vt;
		vt.resize(3 * a);
		for (int i = 0; i<(3 * a); ++i)
			cin >> vt[i];
	} 
	sort(vt.begin(), vt.end());
	for (int i = a; i <= 3 * a - 2; i += 2)
	{
		sum += vt[i];
	}
	cout << sum << endl;
	return 0;
}

/*
class A
{
public:
	A() = default;
	A(int a) :_a(a)
	{}
	~A()
	{}
private:
	int _a;

};
int main()
{
	A a1;
	A a2(2);
	return 0;
}


/*
template<typename T>
void Swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

void Swap(double &a, double &b)
{
	double c = a;
	a = b;
	b = c;
}


/*
class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};


void Test2()
{
	// ���뵥��Test���͵Ķ���
	Test* p1 = new Test;
	delete p1;
	// ����10��Test���͵Ķ���
	Test* p2 = new Test[10];
	delete[] p2;
}

/*
int main()
{
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	// ����10��Test���͵Ŀռ�
	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
	free(p2);
	return 0;
}


//int main()
//{
//	//��̬����һ��int ���͵Ŀռ�
//	int* ptr = new int;
//	//��ʼ��Ϊ100
//	int* ptr1 = new int(100);
//	//��̬����һ������,��СΪ10
//	int* ptr2 = new int[10];
//
//	//�ֶ�����͵��ֶ��ͷš�
//	delete ptr;
//	delete ptr1;
//	delete[]ptr2;
//	return 0;
//}

/*

int main()
{
	int from = 0;
	int to = 0;
	long long arr[81] = { 1, 1 };
	for (int i = 2; i < 80; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	while (cin >> from >> to)
	{
		long sum = 0;
		for (int i = from; i <= to; ++i)
		{
			sum += arr[i - 1];
		}
		cout << sum << endl;
	}
	return 0;
}


/*

//#include<iostream>
//using namespace std;

int main()
{
	int fb[100001];
	fb[0] = 1; fb[1] = 1;
	for (int i = 2; i<100001; ++i)
	{
		fb[i] = fb[i - 1] + fb[i - 2];
		fb[i] = fb[i] % 1000000;//ȡ����λ����
	}
	int n = 0;
	while (cin >> n)
	{
		if (n<30)
			printf("%d\n", fb[n - 1]);
		else
			printf("%0.6d\n", fb[n - 1]);
	}
	return 0;
}


/*
// write your code here cpp

int main()
{
	int num = 0;
	while (cin >> num)
	{
		cout << num << "=";
		int* pnum = new int[1000];
		int j = 0;
		for (int i = 2; i<=sqrt(num); ++i)
		{
			while (num%i == 0)
			{
				if (num != 1)
				{
					pnum[j] = i;
					j++;
					num /= i;
				}
			}
		}
		if (num != 1)
		{
			pnum[j] = num;
			j++;
		}
		for (int i = 0; i<j; ++i)
		{
			cout << pnum[i];
			if (i + 1 < j)
				cout << "*";
		}
		cout << endl;
		delete pnum;
	}
	return 0;
}



/*

/*
// write your code here cpp
#include<iostream>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{

		if (n == 1)
			cout << 0 << endl;
		else if (n == 2 || n == 3)
			cout << 1 << endl;
		else
		{
			int count = 1;
			while (n>3)
			{
				if (n % 3 == 0)
					n /= 3;
				else
					n = n / 3 + 1;
				count++;
			}
			cout << count << endl;
		}
	}
	return 0;
}


/*
class Solution {
public:
	///**
	//*	���������е���С������ɺ�
	//*	���룺��������arr
	//*	���أ����������е���С������ɺ�
	//
	int getFirstUnFormedNum(vector<int> arr, int len)
	{
		if (len <= 0)
			return 0;
		int min = arr[0];
		int sum = 0;
		for (int i = 0; i<len; ++i)//�������
		{
			sum += arr[i];
			if (arr[i]<min)
				min = arr[i];
		}
		vector<int> vt(sum + 1, 0);
		for (int i = 0; i<len; ++i)
		{
			for (int j = sum; j >= arr[i]; --j)
			if (vt[j - arr[i]] + arr[i]>vt[j])
				vt[j] = vt[j - arr[i]] + arr[i];
		}
		for (int i = min; i <= sum; ++i)
		{
			if (i != vt[i])
				return i;
		}
		return sum + 1;
	}
};


//<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> fd1c2b72faefe19c54af14fc1c81eabf65c38d46


/*
// write your code here cpp
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		long a = 0;
		long b = 0;
		if (n == 0)
			break;
		else
		{
			a = pow(5, n) - 4;
			b = pow(4, n) + n - 4;
		}
		cout << a << " " << b << endl;
	}

	return 0;
}


/*

class Solution {
public:
	/*
	//  ����λ�϶�����������ż��λ�϶���ż��
	//  ���룺����arr�����ȴ���2
	//  len��arr�ĳ���
	// ��arr����������λ�϶�����������ż��λ�϶���ż��
	
	void oddInOddEvenInEven(vector<int>& arr, int len)
	{
		int i = 0;//+2Ϊż��λ
		int j = 1;//+2Ϊ����λ
		while (i<len && j<len)
		{
			if (arr[len - 1] % 2 == 0)//���һ��Ϊż��
			{
				swap(arr[len - 1], arr[i]);
				i += 2;
			}
			else//���һ��Ϊ����
			{
				swap(arr[len - 1], arr[j]);
				j += 2;
			}
		}
	}
};
*/



/*
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		// write code here
		int LeftRes = 0;
		int RightRes = 0;
		int Min1 = 27;
		int Min2 = 27;
		for (int i = 0; i<left.size(); ++i)
		{
			if (left[i] == 0 && right[i] != 0)
			{
				LeftRes += right[i];
				RightRes += right[i];
			}
			if (left[i] != 0 && right[i] == 0)
			{
				LeftRes += left[i];
				RightRes += left[i];
			}
			if (left[i] == 0 && right[i] == 0)
			{
				LeftRes = left[i];
				RightRes = right[i];
				if (LeftRes<Min1)
					Min1 = left[i];
				if (RightRes<Min2)
					Min2 = right[i];
			}
		}

		RightRes = RightRes - Min2 + 2;
		LeftRes = LeftRes - Min1 + 2;

		if (RightRes > LeftRes)
			return LeftRes;
		else
			return RightRes;
	}
};

int main()
{
	Gloves a;
	vector<int> arr1;
	for (int i = 0; i < 4; ++i)
		cin >> arr1[i];
	vector<int> arr2;
	for (int i = 0; i < 4; ++i)
		cin >> arr2[i];
	int res = a.findMinimum(4,arr1,arr2);
	std::cout << res << endl;
	return 0;
}


/*
#include<iostream>
using namespace std;

int main()
{
	int num = 0;
	while (cin >> num)
	{
		int count = 0;
		while (num>0)
		{
			if (num & 1)
				count++;
			num >>= 1;
		}
		cout << count << endl;
	}
	return 0;
}


//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	int *b = a;
//	*b += 2;
//	*(b + 2) = 2;
//	b++;
//	printf("%d, %d\n", *b, *(b + 2));
//	return 0;
//
//}

/*
int main()
{
	int a = 0;
	int sum = 0;
	vector<int> vt;
	while (cin >> a)
	{
		vt.resize(3 * a);
		for (int i = 0; i<(3 * a); ++i)
			cin >> vt[i];
	} 
	sort(vt.begin(), vt.end());
	for (int i = a; i <= 3 * a - 2; i += 2)
	{
		sum += vt[i];
	} 
	cout << sum << endl;
	return 0;
}


/*
#include<iostream>
using namespace std;

bool IsPrime(int n)
{
	for (int i = 2; i<n; ++i)
	if (n % i == 0)
		return false;
	return true;
}

void MinSu(int n)
{
	int num1 = n / 2;
	int num2 = n - num1;
	while (1)
	{
		if (IsPrime(num1) && IsPrime(num2))
			break;
		num1--;
		num2++;
	}
	cout << num1 << endl;
	cout << num2 << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
		MinSu(n);
	return 0;
}




//void func(const int& v1, const int& v2)
//{
//	cout << v1 << endl;
//	cout << v2 << endl;
//
//}
//int main()
//{
//	int i = 0;
//	func(++i, i++);
//	return 0;
//}




/*
int main()
{
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	printf("%d,%d,%d", p[0][0], *(p[0] + 1), (*p)[2]);

	return 0;
}*/

//int main()
//{
//	int num = 0;
//	int count = 0;
//	int mcount = 0;
//	while (cin >> num)
//	{
//		count = 0;
//		mcount = 0;
//		while (num)
//		{
//			if (num % 2 != 0)
//				count++;
//			else
//				count = 0;
//			if (count>mcount)
//				mcount = count;
//			num = num / 2;
//		}
//		cout << mcount << endl;
//	}
//
//	return 0;
//}




/*
int PassScore(string str)
{
	int sum = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
	//1.���볤��

	int len = str.size();
	if (len < 5)
		s1 = 5;
	else if (len >= 8)
		s1 = 25;
	else
		s1 = 10;
	//��ĸ������
	vector<char> vt1, vt2, vt3, vt4;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] <= 'z'&&str[i] >= 'a')
			vt1.push_back(str[i]);//��Сд��ĸ
		else if (str[i] <= 'Z'&&str[i] >= 'A')
			vt2.push_back(str[i]);//�Ŵ�д��ĸ
		else if (str[i] <= '9'&&str[i] >= '0')
			vt3.push_back(str[i]);//������
		else
			vt4.push_back(str[i]);//�ŷ���
	}
		int len1 = vt1.size();
		int len2 = vt2.size();
		int len3 = vt3.size();
		int len4 = vt4.size();
		if (len1 == 0 && len2 == 0)
			s2 = 0;
		else if (len1 != 0 && len2 != 0)
			s2 = 20;
		else
			s2 = 10;
		if (len3 == 0)
			s3 = 0;
		else if (len3 == 1)
			s3 = 10;
		else
			s3 = 20;
		//����
		if (len4 == 0)
			s4 = 0;
		else if (len4 == 1)
			s4 = 10;
		else
			s4 = 20;
		//����
		if (len1 != 0 && len2 != 0 && len3 != 0 && len4 != 0)
			s5 = 5;
		else if ((len2 != 0 || len1 != 0) && len3 != 0 && len4 != 0)
			s5 = 3;
		else if ((len2 != 0 || len1 != 0) && len3 != 0)
			s5 = 2;
		else
			s5 = 0;
		sum = s1 + s2 + s3 + s4 + s5;
		return sum;
}
int main()
{
	string str;
	while (cin >> str)
	{
		int sum = PassScore(str);
		switch (sum / 10)
		{
		case 9:
			cout << "VERY_WEAK" << endl;
			break;
		case 8:
			cout << "WEAK" << endl;
			break;
		case 7:
			cout << "AVERAGE" << endl;
			break;
		case 6:
			cout << "STRONG" << endl;
			break;
		case 5:
			cout << "VERY_STRONG"<<endl;
			break;
		default:
		{
				   if (sum >= 25)
					   cout << "SECURE" << endl;
				   else
					   cout << "VERY_SECURE" << endl;
		}
		}
	}
	return 0;
}*/

//int PassScore(string str)
//{
//	int sum = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
//	//1.���볤��
//
//	int len = str.size();
//	if (len<5)
//		s1 = 5;
//	else if (len >= 8)
//		s1 = 25;
//	else
//		s1 = 10;
//	//��ĸ������
//	vector<char> vt1, vt2, vt3, vt4;
//	for (int i = 0; i<len; ++i)
//	{
//		if (str[i] <= 'z'&&str[i] >= 'a')
//			vt1.push_back(str[i]);//��Сд��ĸ
//		else if (str[i] <= 'Z'&&str[i] >= 'A')
//			vt2.push_back(str[i]);//�Ŵ�д��ĸ
//		else if (str[i] <= '9'&&str[i] >= '0')
//			vt3.push_back(str[i]);//������
//		else
//			vt4.push_back(str[i]);//�ŷ���
//		int len1 = vt1.size();
//		int len2 = vt2.size();
//		int len3 = vt3.size();
//		int len4 = vt4.size();
//		if (len1 == 0 && len2 == 0)
//			s2 = 0;
//		else if (len1 != 0 && len2 != 0)
//			s2 = 20;
//		else
//			s2 = 10;
//		if (len3 == 0)
//			s3 = 0;
//		else if(len3 == 1)
//			s3 = 10;
//		else
//			s3 = 20;
//			//����
//			if (len4 == 0)
//				s4 = 0;
//			else if(len4 == 1)
//				s4 = 10;
//		else
//			s4 = 20;
//			//����
//			if (len1 != 0 && len2 != 0 && len3 != 0 && len4 != 0)
//				s5 = 5;
//			else if ((len2 != 0 || len!=0)&& len3 != 0 && len4 != 0)
//				s5 = 3;
//			else if ((len2 != 0 || len!=0)&& len3 != 0)
//				s5 = 2;
//			else
//				s5 = 0;
//			sum = s1 + s2 + s3 + s4 + s5;
//			return sum;
//	}
//	int main()
//	{
//		string str;
//		while (cin >> str)
//		{
//			int sum = PassScore(str);
//			switch (sum / 10)
//			{
//			case 9:
//				cout << "VERY_WEAK" << endl;
//				break;
//			case 8:
//				cout << "WEAK" << endl;
//				break;
//			case 7:
//				cout << "AVERAGE" << endl;
//				break;
//			case 6:
//				cout << "STRONG" << endl;
//				break;
//			case 5:
//				cout << "VERY_STRONG" < endl;
//				break;
//			default:
//				break;
//			}
//		}
//	}
//
//int main()
//{
//	int I = 1;
//	if (I <= 0)
//		printf("****\n");
//	else
//		printf("%%%%\n");
//	return 0;
//}



//int func(int m, int n)
//{
//	int x = 1, y = 1;
//	for (int i = 0; i<n; ++i)
//	{
//		x = (m + n) - i;
//		y = i + 1;
//	}
//	return x * y;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a, b;
//	int tem = func(a, a+b);
//	cout << tem << endl;
//	return 0;
//}




/*
int addAB(int A, int B)
{
	// write code here
	int tem = 0;
	while (B)
	{
		tem = A&B;
		A = A^B;
		B = tem << 1;
	}
	return A;
}

int main()
{
	int c = addAB(1, 2);
	cout << c << endl;
	return 0;
}*/


//class Test
//{
//public:
//	int a;
//	int b;
//	virtual void fun()
//	{}
//	Test(int temp1 = 0, int temp2 = 0)
//	{
//		a = temp1;
//		b = temp2;
//	}
//	int getA()
//	{
//		return a;
//	}
//	int getB()
//	{
//		return b;
//	}
//};
//
//
//
//int main()
//{
//	Test obj(5, 10);
//	int* pInt = (int*)&obj;
//	*(pInt + 0) = 100;
//	*(pInt + 1) = 200;
//	cout << obj.getA() << endl;
//	cout << obj.getB() << endl;
//	return 0;
//}



/*
bool chkParenthesis(string A, int n)
{
	// write code here
	stack<char> st;
	if (A.empty() == 0)
		return true;
	int i = 0;
	for (i = 0; i<n; ++i)
	{
		if (A[i] == '(')
			st.push(A[i]);
		else if (A[i] == ')')
		{
			if (st.top() == '(')
				st.pop();
			else
				st.push(A[i]);
		}
		else
			return false;
	}
	if (st.size() == 0)
		return true;
	return false;
}
int main()
{
	cout << chkParenthesis("()a()((()", 9) << endl;
	return 0;
}*/
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int f1 = 0, f2 = 1;
//	int num = 0, n = 0;
//	cin >> n;
//	while (n>num)
//	{
//		num = f1 + f2;
//		f1 = f2;
//		f2 = num;
//	}
//	int N = 0;
//	if (num == n)
//		cout << 0 << endl;
//	else
//	{
//		N = ((num - n) > (n - f1)) ? (n - f1) : (num - n);
//		cout << N << endl;
//	}
//	return 0;
//}

//int StrToInt(string str)
//{
//	int i = 0;
//	int flag = 1, sum = 0;
//	if (str.size() == 0)
//		return 0;
//	//���ж������ţ�����i++���������Ž�flag��Ϊ-1.
//	if (str[i] == '+')
//		i++;
//	if (str[i] == '-')
//	{
//		i++;
//		flag = 1;
//	}
//	while (str[i] != '\0')
//	{
//		if (str[i] == ' ')
//			i++;
//		if (str[i] >= '0'&&str[i] <= '9')//�������
//		{
//			sum = sum * 10 + flag*(str[i] - '0');
//			i++;
//		}
//		else
//			return 0;
//	}
//	return sum;
//}
//
//int main()
//{
//	string str = "-a123 456";
//	cout<<StrToInt(str)<<endl;
//	return 0;
//}

//
//int main()
//{
//	int w = 0;
//	int h = 0;
//	cin >> w >> h;
//	vector<vector<int>> vt();
//	int count=0;
//	for (int i = 0; i<w; ++i)
//	{
//		for (int j = 0; j<h; ++j)
//		{
//			if (vt[i][j] == 0)
//			{
//				count++;
//				if (i + 2<w)
//					vt[i + 2][j] = 1;
//				if (j + 2<h)
//					vt[i][j + 2] = 1;
//			}
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

//char fun(char a,char b)
//{
//	if (a < b)
//		return a;
//	return b;
//}
//
//int main()
//{
//	int a = '1', b = '1', c = '2';
//	cout << fun(fun(a, b), fun(b, c));
//	return 0;
//}

//int main()
//{
//	int m = 0123;
//	int n = 123;
//	printf("%o %o\n", m, n);
//	return 0;
//}


//int main()
//{
//	int num;
//	cin >> num;
//	vector<int> vt(num);
//	for (int i = 0; i<num; ++i)
//	{
//		cin >> vt[i];
//	}
//	int sum = 0;
//	for (int i = 0; i<num; ++i)
//	{
//		sum = sum + vt[i];
//		if (vt[i] > sum)
//			sum = vt[i];
//	}
//	cout << sum << endl;
//	return 0;
//}

//int main()
//{
//	long M = 0;
//	int N = 0;
//	int a = 0, b = 0;
//	int sum[100] = { 0 };
//	cin >> M >> N;
//	while (M != 0)
//	{
//		a = M%N;
//		M = M / N;
//		sum[b] = a;
//		b++;
//	}
//	for (int i = b-1; i >= 0; i--)
//	{
//		cout << sum[i];
//	}
//	return 0;
//}

//int main()
//{
//	int num1=0, num2=0, num3=0, num4=0;
//	cin >> num1>> num2>> num3>> num4;
//	int A, B1, B2, C;
//	A = (num1 + num3) / 2;
//	C = (num4 - num2) / 2;
//	B1 = (num4 + num2) / 2;
//	B2 = (num3 - num1) / 2;
//	if (B1 != B2)
//		cout << "No";
//	else
//		cout << A << " " << B1 << " " << C << " " << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> vt(4);
//	int num = 0;
//	int A, B1, B2, C;
//
//	A = (vt[0] + vt[2]) / 2;
//	C = (vt[1] + vt[3]) / 2;
//	B1 = (vt[3] - vt[0]) / 2;
//	B2 = (vt[1] + vt[3]) / 2;
//	if (B1 != B2)
//		cout << "No" << endl;
//	cout << A << B1 << C << endl;
//	return 0;
//}
////
//int main()
//{
//	int arr[] = { 1, 3, 5, 7,9 };
//	int *p = (int*)(&arr + 1);
//	printf("%d %d", *(arr + 1), *(p - 1));
//	return 0;
//}


//
//int cou = 0;
//int fun(int a)
//{
//	cou++;
//	if (a == 0)
//		return 1;
//	else if(a == 1)
//		return 2;
//	else
//	{
//		return fun(a - 1) + fun(a - 2);
//	}
//
//}
//int main()
//{
//	fun(8);
//	cout << cou << endl;
//	return 0;
//}
//



////�����г���һ�������
//
//int MoreThanHalfNum_Solution(vector<int> numbers)
//{
//	sort(numbers.begin(), numbers.end());//������
//	int num = numbers[numbers.size() / 2];
//	int tem = numbers.size() / 2;
//	int count = 0;//������
//	for (int i = 0; i<numbers.size(); ++i)
//	{
//		if (num == numbers[i])
//			++count;
//	}
//	if (count>tem)
//		return num;
//	return 0;
//}
//
//int main()
//{
//	vector<int> number = { 1, 5, 2, 1, 5, 5, 5, 5, 5 };
//	int ret = MoreThanHalfNum_Solution(number);
//	cout << "ret = "<<ret<< endl;
//	return 0;
//}



////�����ַ���
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	reverse(str.begin(), str.end());
//	auto itstart = str.begin();
//	while (itstart != str.end())
//	{
//		auto itend = itstart;
//		while (itend != str.end() && *itend != ' ')
//		{
//			itend++;
//		}
//		reverse(itstart, itend);
//		if (itend != str.end())
//			itstart = itend + 1;
//		else
//			itstart = itend;
//	}
//	cout << str << endl;
//	return 0;
//}



/**��ţ�͡�����һ�������������β��ͷ��˳�򷵻�һ��ArrayList.
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head)
	{
		vector<int> rec;
		ListNode* buf = head;
		ListNode* pre = buf;
		if (head == nullptr)
			return rec;
		while (head->next != nullptr)
		{
			buf = head->next;
			head->next = buf->next;
			buf->next = pre;
			pre = buf;
		}
		while (buf)
		{
			rec.push_back(buf->val);
			buf = buf->next;
		}
		return rec;
	}
};*/


/*��Ŀ������ţ�͡��滻�ո�
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
class Solution {
public:
	void replaceSpace(char *str, int length)
	{
		int count = 0;
		for (int i = 0; i<length; ++i)
		{
			if (*(str + i) == ' ')
				count++;
		}
		for (int i = length - 1; i >= 0; --i)
		{
			if (str[i] != ' ')
				str[i + 2 * count] = str[i];
			else
			{
				str[i + 2 * count] = '0';
				str[i + 2 * count - 1] = '2';
				str[i + 2 * count - 2] = '%';
				count--;
			}
	
		}
		//string s(str);
		//int i=0;        
		//while((i=s.find(' ',i))>-1)
		//{           
		//	s.erase(i,1);            
		//	s.insert(i,"%20");                     
		//}        
		//auto ret=s.c_str();        
		//strcpy(str,ret);
	}
};*/

/*429. N�����Ĳ������
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val) {
val = _val;
}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root)
	{
		if (root == NULL)
			return{};
		vector<vector<int>> ans;
		vector<int> tmp;
		queue<Node*> q;
		q.push(root);
		int CurLayerSize = q.size();
		while (!q.empty()){
			Node* cur = q.front();
			tmp.push_back(cur->val);
			q.pop();
			for (auto node : cur->children)
				q.push(node);
			if (--CurLayerSize == 0)
			{//��ǰ��������ʱ
				ans.push_back(tmp);
				CurLayerSize = q.size();
				tmp.clear();
			}
		}
		return ans;
	}
};
*/

/**515. ��ÿ�������������ֵ
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

class Solution
{
public:
	vector<int> largestValues(TreeNode* root)
	{
		queue<TreeNode*> q;
		if (root)
			q.push(root);
		vector<int> res;
		while (!q.empty())
		{
			int n = q.size(), now = INT_MIN;
			while (n--)
			{
				TreeNode* tmp = q.front();
				q.pop();
				if (tmp->val>now)
					now = tmp->val;
				if (tmp->left)
					q.push(tmp->left);
				if (tmp->right)
					q.push(tmp->right);
			}
			res.push_back(now);
		}
		return res;
	}
};

*/

/*��ţ�͡�����������
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
//class Solution {
//public:
//	void Mirror(TreeNode *pRoot)
//	{
//		if (!pRoot)
//			return;
//		if (pRoot->left == nullptr && pRoot->right == nullptr)
//			return;
//		TreeNode *tem = pRoot->left;
//		pRoot->left = pRoot->right;
//		pRoot->right = tem;
//		if (pRoot->left != nullptr)
//			Mirror(pRoot->left);
//		if (pRoot->right != nullptr)
//			Mirror(pRoot->right);
//	}
//};

/**637. �������Ĳ�ƽ��ֵ
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//class Solution {
//public:
//	vector<double> averageOfLevels(TreeNode* root)
//	{
//		vector<double> dev;
//		if (!root)
//			return dev;
//		queue<TreeNode*> q;
//		q.push(root);
//		TreeNode* last = root;
//		TreeNode* temp = nullptr;
//		double sum = 0;
//		int count = 0;
//		while (!q.empty())
//		{
//			temp = q.front();
//			q.pop();
//			if (temp->left)
//				q.push(temp->left);
//			if (temp->right)
//				q.push(temp->right);
//			++count;
//			sum += temp->val;
//			if (temp == last)
//			{
//				dev.push_back(sum / count);
//				count = 0;
//				sum = 0;
//				last = q.back();
//			}
//
//		}
//		return dev;
//	}
//};

//107.��������α���2
/*Definition for a binary tree node.
* struct TreeNode {
	*int val;
	*TreeNode *left;
	*TreeNode *right;
	*TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
/*
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> vv;

		if (!root)
			return vv;
		TreeNode* p = nullptr;
		TreeNode* last = root;

		vector<int> ivec;
		queue<TreeNode*> q;//��Žڵ�Ķ���
		q.push(root);
		ivec.push_back(root->val);//��Žڵ��е�ֵ
		vv.push_back(ivec);
		ivec.clear();//���ivec

		while (!q.empty())
		{
			p = q.front();
*/

//(stack and queue)102.����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
/*
Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
/*
class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*> queue;
		queue.push(root);

		vector<int> level_res;
		int curNums = 1, nextNums = 0;

		TreeNode* node;

		while (!queue.empty())
		{
			node = queue.front();

			level_res.push_back(node->val);
			queue.pop();
			curNums--;

			if (node->left)
			{
				queue.push(node->left);
				nextNums++;
			}

			if (node->right)
			{
				queue.push(node->right);
				nextNums++;
			}


			if (curNums == 0)
			{
				res.push_back(level_res);

				level_res.clear();

				curNums = nextNums;
				nextNums = 0;
			}
		}

		return res;
	}
};
*/

/*
//������
//1.�ַ�����
int main()
{
string str;
while (cin >> str)
{
int count[256] = {0};//���ַ�
size_t size = str.size();
for (int i = 0; i < size; ++i)
{
if (0 == count[str[i]])
cout << str[i];//��ͬ��ӡ���
count[str[i]]++;//�������һ
}
cout << endl;
}
return 0;
}

////2.��һ���Ź�������飬����n����������������������������һ�����ȵ���λ�����磬ԭ����Ϊ[1,2,3,4,5,6]��������λ5��λ�ü������[6,1,2,3,4,5],���ڶ�����λ������飬��Ҫ����ĳ��Ԫ�ص�λ�á������һ�����Ӷ�Ϊlog������㷨����������
//����һ��int����A��Ϊ��λ������飬ͬʱ���������Сn����Ҫ���ҵ�Ԫ�ص�ֵx���뷵��x��λ��(λ�ô��㿪ʼ)����֤������Ԫ�ػ��졣
//����������
//[6,1,2,3,4,5],6,6
//���أ�0

class Finder {
public:
int findElement(vector<int> A, int n, int x)
{
int left = 0;
int right = n - 1;
while (left <= right)
{
int mid = left + ((right - left) >> 1);
if (A[mid] == x)
return mid;
if (x > A[mid])
{
if (A[mid] < A[left] && x > A[right])
right = mid - 1;
else
left = mid + 1;
}
else
{
if (A[mid]>A[left] && x < A[left])
left = mid + 1;
else
right = mid - 1;
}
}
return -1;
}
};*/


//ģ��
//template<typename T1,class T2>
//template<typename T1,typename T2>
//template<class t1,class t2>



//225.�ö���ʵ��ջ
//class MyStack {
//	queue<int> Q1;
//public:
//	/** Initialize your data structure here. */
//	MyStack()
//	{
//
//	}
//
//	/** Push element x onto stack. */
//	void push(int x)
//	{
//		Q1.push(x);
//	}
//
//	/** Removes the element on top of the stack and returns that element. */
//	int pop()
//	{
//		int size = Q1.size();
//		for (int i = 0; i<size - 1; ++i)
//		{
//			Q1.push(Q1.front());
//			Q1.pop();
//		}
//		int tem = Q1.front();
//		Q1.pop();
//		return tem;
//	}
//
//	/** Get the top element. */
//	int top()
//	{
//		return Q1.back();
//	}
//
//	/** Returns whether the stack is empty. */
//	bool empty()
//	{
//		return Q1.empty();
//	}
//};
//

/*
224.��ջʵ�ֶ���
class MyQueue {
public:
stack<int> s1;
stack<int> s2;
/** Initialize your data structure here.
MyQueue()
{
}

//** Push element x to the back of queue.
void push(int x)
{
s1.push(x);
}

//** Removes the element from in front of queue and returns that element.
int pop(
{
if (s2.empty())
{
while (!s1.empty())
{
s2.push(s1.top());
s1.pop();
}
}
int tem = s2.top();
s2.pop();
return tem;
}

//** Get the front element.
int peek()
{
if (s2.empty())
{
while (!s1.empty())
{
s2.push(s1.top());
s1.pop();
}
}
int tem = s2.top();
return tem;

}

//** Returns whether the queue is empty.
bool empty()
{
return s1.empty() && s2.empty();
}
};*/

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/


/**223.��������������
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

class Solution {
public:
vector<int> postorderTraversal(TreeNode* root)
{
vector<int> res;
stack<TreeNode*> st;
if (root == nullptr)
return res;
TreeNode* pre = nullptr;
while (root || !st.empty())
{
if (root)
{
st.push(root);
root = root->left;
}
else
{
root = st.top();
if (root->right == nullptr || root->right == pre)
{
res.push_back(root->val);
pre = root;
root = nullptr;
st.pop();
}
else
{
root = root->right;
}
}
}
return res;
}
};*/


/*222.���������������

* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

class Solution {
public:
vector<int> inorderTraversal(TreeNode* root)
{
/*stack<TreeNode*> nodes;
vector<int> res;
while(root)
{
nodes.push(root);
root = root->left;
}
while(!nodes.empty())
{
auto node = nodes.top();
nodes.pop();
res.push_back(node->val);
node = node->right;
while(node)
{
nodes.push(node);
node=node->left;
}
}
return res;
//vector<int> vec;

//stack<TreeNode*> st;
//while (root || !st.empty())
//{
//	while (root)
//	{
//		st.push(root);
//		root = root->left;
//	}
//	root = st.top();
//	st.pop();
//	vec.push_back(root->val);
//	root = root->right;
//}
//return vec;
}
};

*/

/*������ǰ�����
typedef struct TreeNode
{
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}

}TreeNode;

vector<int> preorderTraversal(TreeNode* root)
{
stack<TreeNode*> nodes;
vector<int> res;
while (root || !nodes.empty())
{
while (root)
{
nodes.push(root->right);
res.push_back(root->val);
root = root->left;
}
root = nodes.top();
nodes.pop();
}
return res;
}

int main()
{
TreeNode* s;
return 0;
}

/*
//1.�����沨����ʾ��������ʽ��ֵ��
//��Ч����������� + , -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��
//˵����
//��������ֻ�����������֡�
//�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������
class Solution {
public:
int evalRPN(vector<string>& tokens)
{
stack<int> numbers;
for (int i = 0; i < tokens.size(); ++i)
{
if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
{
int res;
int n2 = numbers.top();
numbers.pop();
int n1 = numbers.top();
numbers.pop();

if (tokens[i] == "+")
res = n1 + n2;
else if (tokens[i] == "-")
res = n1 - n2;
else if (tokens[i] == "/")
res = n1 / n2;
else
res = n1 * n2;
numbers.push(res);
}
else{
numbers.push(stoi(tokens[i]));
}
}
return numbers.top();
}
};
*/


/*221.ѹջ�ͳ�ջ
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
//if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
//	return false;
//int sz = pushV.size();
//stack<int> st;
//int i = 0;
//for (int j = 0; j<sz; ++j)
//{
//	st.push(pushV[j]);//��ջ
//	while (!st.empty() && st.top() == popV[i])//�Ƚ�
//	{
//		st.pop();//��ջ
//		++i;
//	}
//}
//if (st.empty())
//	return true;
//return false;

if(pushV.empty() || popV.empty() || pushV.size()!=popV.size())
return false;
stack<int> s;
int j=0;
for(int i=0;i<pushV.size();++i)
{
s.push(pushV[i]);
while(!s.empty()&&s.top()==popV[j])
{
s.pop();
++j;
}
}
if(s.empty())
return true;
return false;
}

int main()
{
vector<int> s1 = {1,2,3,4,5};
vector<int> s2 = { 4, 5, 3, 2, 1 };
bool tem=IsPopOrder(s1, s2);
cout << tem << endl;
return 0;
}*/