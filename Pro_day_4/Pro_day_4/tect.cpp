#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



/*
//�ڲ�������ⲿ�����Ԫ�ࡣ
//ע����Ԫ��Ķ��壬�ڲ������ͨ���ⲿ��Ķ�������������ⲿ���� �����г�Ա��
//�����ⲿ�಻���ڲ������Ԫ��

//1. �ڲ�����Զ������ⲿ���public��protected��private���ǿ��Եġ�
//2. ע���ڲ������ֱ�ӷ����ⲿ���е�static��ö�ٳ�Ա������Ҫ�ⲿ��Ķ��� / ������
//3. sizeof(�ⲿ��) = �ⲿ�࣬���ڲ���û���κι�ϵ��
class A
{
public:
	A(int a = 0) :_m_a(a)
	{}
	class B//�ڲ���
	{
	public:
		void fun(const A &a)
		{
			cout << _m_b << endl;
			cout << a._m_a << endl;
		}
	};
private:
	int _m_a;
	static int _m_b;//��̬��Ա

};
int A::_m_b = 1;//��̬��Ա��Ҫ������ⲿ����

int main()
{
	A::B b;
	b.fun(A(3));
	return 0;
}



/*
class Date;
class Time;

class Time
{
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0) 
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1;
	return 0;
}


/*
class Int;
class Test;
//��Ԫ��
class Int
{
public:
	Int(int d = 0) :m_i(d)
	{}
private:
	int m_i;
};
class Test
{
public:

private:
	int m_date;
};

/*
��Ԫ�����ɷ������˽�г�Ա����������ĳ�Ա���� 
��Ԫ����������const���� 
��Ԫ�����������ඨ����κεط�����������������޶������� 
һ�����������Ƕ�������Ԫ���� ��Ԫ�����ĵ�������ͨ�����ĵ��ú�ԭ����ͬ

class Test;

ostream& operator<<(ostream &out, const Test &i);//��Ԫ����
istream& operator>>(istream &in, const Test &i);//��Ԫ����

class Test
{
	friend ostream& operator<<(ostream &out, const Test &i);
	friend istream& operator>>(istream &in, const Test &i);

public:
	Test(int d = 0) : _date(d)
	{}
	~Test()
	{}
	Test(const Test &t)
	{
		_date = t._date;
	}
	Test& operator= (const Test& t)
	{
		if (this != &t)
		{
			_date = t._date;
		}
		return *this;
	}
private:
	int _date;
};

ostream& operator<<(ostream &out, const Test &i)
{
	out << i._date;
	return out;
}

istream& operator>>(istream &in, const Test &i)
{
	in >> i._date;
	return in;
}

int main()
{
	Test t;
	Test t1(t);
	int i = 0;
	cout << i << endl;
	return 0;
}


/*
class Test
{
public:
	Test(int d = 0) :m_date(d)
	{
		cout << "Creart Test object: " << this << endl;
	}

	Test(const Test& t)
	{
		cout << "Copy Test object: " << this << endl;
		m_date = t.m_date;
	}
	~Test()
	{
		cout << "Free Test object: " << this << endl;
	}
	Test& operator=(const Test& t)
	{
		cout << "Assign: " << this << endl;
		if (this != &t)
		{
			m_date = t.m_date;
		}
		return *this;
	}
public:
	int GetData()const
	{
		return m_date;
	}
private:
	int m_date;
};
Test fun(Test& x)
{
	int val = x.GetData();
	Test tem(val);
	return tem;
}

int main()
{
	Test t;
	Test t2 = t;
	return 0;
}


/*
class Test
{
public:
	Test(int d = 0) :m_date(d)
	{
		cout << "Creart Test object: " << this << endl;
	}
	
	Test(const Test& t)
	{
		cout << "Copy Test object: " << this << endl;
		m_date = t.m_date;
	}
	~Test()
	{
		cout << "Free Test object: " << this << endl;
	}
	Test& operator=(const Test& t)
	{
		cout << "Assign: " << this << endl;
		if (this != &t)
		{
			m_date = t.m_date;
		}
		return *this;
	}
public:
	int GetData()const
	{
		return m_date;
	}
private:
	int m_date;
};
Test fun(Test& x)
{
	int val = x.GetData();
	Test tem(val);
	return tem;
}

int main()
{
	Test t;
	Test t1;
	t1 = t;
	return 0;
}


/*
class Test
{
public:
	Test(int d = 0) :m_date(d)
	{}
	~Test()
	{}
	Test(const Test& t)
	{
		m_date = t.m_date;
	}
	Test& operator+(const Test& t)
	{
		if (this != &t)
		{
			m_date = t.m_date;
		}
		return *this;
	}
private:
	int m_date;

};

int main()
{
	Test t(6);
	Test t1;
	t1 = t;
	Test t2(t);
	return 0;
}





/*
// void fun()const
//void fun (const Test* const this)
//void fun()
//void fun(Test* const this)
//1. ÿ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ��(��ʼ��ֻ�ܳ�ʼ��һ��) 
//2. ���а������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ���� 
//(1)���ó�Ա����
//(2)const��Ա����
//(3)�����ͳ�Ա(����û��Ĭ�Ϲ��캯��)
//(1)explicit  ��ʽ
//(2)static ��̬��Ա���������������г�ʼ��
class A
{
public:
	A(int a,int b ,int c)
	{
		x = a;
		y = b;
		z = c;
	}
private:
	int x;
	int y;
	int z;
};

class Test
{
public:
	//���ٿռ�
	//��ʼֵ
	//�������
	explicit Test(int d = 0) :m_data(d), m_a(2,3,4)
	{
	}
	~Test()
	{}
private:
	int m_data;
	A m_a;
};
int main()
{
	Test t(10);
	t = (Test)100;
	return 0;
}*/