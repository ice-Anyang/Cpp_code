#include<iostream>
using namespace std;



/*
class Base
{
public:
	int B_date;
};

class A : virtual public Base
{
public:
	int a_date;
};

class B : virtual public Base
{
public:
	int b_date;
};

class D : public A, public B
{
public:
	int d_date;
};

int main()
{
	D d;
	d.a_date = 1;
	d.b_date = 2;
	d.B_date = 3;
	return 0;
}

/*
class Base
{
public:
	int B_date;
};

class A : public Base
{
public:
	int a_date;
};

class B : public Base
{
public:
	int b_date;
};

class D : public A, public B
{
public:
	int d_date;
};
int main()
{
	D d;
	d.a_date = 1;
	d.b_date = 2;
	d.d_date = 3;
	d.A::B_date = 4;
	d.B::B_date = 5;
	cout << &(d.A::B_date) << endl;
	cout << &(d.B::B_date) << endl;
	return 0;
}


/*
class Base
{
public:
	Base()
	{
		object_count++;
	}
public:
	static int object_count;
};
int Base::object_count = 0;

class A : public Base
{};
class B : public Base
{};
void main()
{
	A a;
	cout << a.object_count << endl;
	B b;
	cout << a.object_count << endl;
	cout << b.object_count << endl;
}

/*
class Person
{
public:
	Person()
	{
		++_count;
	}
	~Person()
	{}
protected:
	string _name;
private:
	static int _count;
};
int Person::_count = 0; 

class Student : public Person 
{
protected:    
	int _stuNum; // 学号 
}; 

class Graduate : public Student 
{ 
protected :   
	string _seminarCourse ; 
	// 研究科目 
};
int main()
{
	Student a1;
	Student a2;
	Student a3;
	Graduate g1;
	cout << "人数 = " << Person::_count << endl;
	Student::_count = 0;    
	cout << " 人数 :" << Person::_count << endl;
	return 0;
}





/*

class Student;
class Person 
{
public:   
	friend void Display(const Student& p, const Student& s);
protected:   
	string _name; // 姓名 
}; 

class Student : public Person 
{ 
private:
	int _stuNum; // 学号
};

void Display(const Student& p, const Student& s) 
{ 
	
}

int main() 
{
	Person p;
	return 0;
}



/*
class A
{
	friend ostream& operator<<(ostream &out, const A &d);
public:
	A()
	{
		cout << "A::A()" << endl;
	}
	A(const A& a)
	{
		cout << "A::A(const A)" << endl;
	}
	A& operator=(const A &a)
	{
		cout << "A& A::operator=(const A&)" << endl;
		return *this;
	}
	~A()
	{
		cout << "A::~A()" << endl;
	}
private:
	int a_date=1;
};

class D : public A
{
	friend ostream& operator<<(ostream &out, const D &d);
public:
	D() : A()
	{
		cout << "D::D()" << endl;
	}
	~D()
	{
		cout << "D::~D()" << endl;
	}
private:
	int d_data = 2;
};

ostream& operator<<(ostream &out, const D &d)
{
	//cout << d.a_data;
	cout << d.d_data;
	return out;
}

int main()
{
	D d;
	cout << d << endl;
	return 0;
}

/*

class A
{
public:
	A(int a)
	{
		cout << "class A::A()" << endl;
	}
	~A()
	{
		cout << "class A::~A()" << endl;
	}
};
class B
{
public:
	B(int b)
	{
		cout << "class B::B()" << endl;
	}
	~B()
	{
		cout << "class B::~B()" << endl;
	}
};
class C: public A,public B
{
public:
	C() :A(1), B(2), _a(0), _b(0)
	{
		cout << "class C::C()" << endl;
	}
	~C()
	{
		cout << "class C::~C()" << endl;
	}
private:
	A _a;
	B _b;
};

int main()
{
	C c;
	return 0;
}
*/