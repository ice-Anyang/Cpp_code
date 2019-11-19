#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A1
{
public:
	void fun()
	{
		cout << "A1::fun()" << endl;
	}
private:
	int _mate;
	char str;
};
class A2
{
public:

private:
	int _mate;
	char str;
};
class A3
{
public:
	void fun()
	{
		cout << "A3::fun()" << endl;
	}
private:

};
class A4
{
	class s
	{
		int a;
		char b;
	};
	void fun()
	{
		cout << "A4::fun()" << endl;
	}
	int c;
	char d;
};

int main()
{
	cout << sizeof(A1) << endl;//8
	cout << sizeof(A2) << endl;//8
	cout << sizeof(A3) << endl;//1
	cout << sizeof(A4) << endl;//8

	return 0;
}

/*
class Test
{
public:
	//void Display()
	//{
	//	cout << _mate<<"-" << _date << endl;
	//}
	void Display()
	{
		cout << this->_mate << "-" << this->_date << endl;
	}
	//void SetTest(int mate, int date)
	//{
	//	_mate = mate;
	//	_date = date;
	//}
	void SetTest(int mate,int date)
	{
		this->_date = date;
		this->_mate = mate;
	}
private:
	int _mate;
	int _date;
};
int main()
{
	Test t1, t2;
	t1.SetTest(2, 2);
	t2.SetTest(6, 6);
	t1.Display();
	t2.Display();
	return 0;
}


/*
class Test
{
public:
	void fun(int a, int b);
public:
	int _mate;
	int _date;
};

void Test::fun(int a= 9, int b = 7)
{
	cout << "Test::fun()" << endl;
}

int main()
{
	Test te;
	te.fun(1, 2);
	te._date = 10;
	te._mate = 6;
	return 0;
}

/*
class student
{
public:
	void SetStudentInfo(const char* name, const char* gender, int age);
	void PrintStudentInfo();

private:
	char _name[20];
	char _gender[3];
	int _age;
};
void student::SetStudentInfo(const char* name, const char* gender, int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}

void student::PrintStudentInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}




/*
class student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};


class Test //类名
{
	//类体。
public:

protected:

private:
	int _mate;
};

/*
struct student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{ 
		strcpy(_name, name);
		strcpy(_gender, gender); 
		_age = age; 
	}        
	void PrintStudentInfo() 
	{ 
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	return 0;
}*/