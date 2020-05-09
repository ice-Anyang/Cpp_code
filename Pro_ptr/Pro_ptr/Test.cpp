#include<iostream>
#include<vector>
#include <memory>
using namespace std;

namespace ice
{
	template<class _Ty>
	class auto_ptr
	{
	public:
		explicit auto_ptr(_Ty *_P = 0) :_Owns(_P != 0), _Ptr(_P)
		{}
		_Ty& operator*()const
		{
			return *_Ptr;
		}
		_Ty* operator->()const
		{
			return _Ptr;
		}
		_Ty *release()//�ı�ӵ��Ȩ
		{
			this->_Owns = false;
			return (_Ptr);
		}
		~auto_ptr()
		{
			if (_Owns)
			{
				delete _Ptr; //delete[]_Ptr;
				_Ptr = NULL;
			}
		}
	private:
		bool Owns;
		_Ty* Ptr;
	};
}

int main()
{
	int* p = new int(10);
	ice::auto_ptr<int> ptr1(p);
	cout << *ptr1 << endl;
	return 0;
}

/*
//�쳣
double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}
void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

int main()
{
	try {
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unkown exception" << endl;
	}
	return 0;
}

/*
//auto_ptr��ʹ��
namespace bit
{
	//vs2013 ȱ��:���ܹ����������
	template<class _Ty>
	class auto_ptr   //smart_ptr
	{
		typedef auto_ptr<_Ty> _Myt;
	public:
		explicit auto_ptr(_Ty *_Ptr = 0) : _Myptr(_Ptr)
		{}
		auto_ptr(_Myt& _Right) : _Myptr(_Right.release())
		{}
		_Myt& operator=(_Myt& _Right)
		{
			reset(_Right.release());
			return (*this);
		}
		~auto_ptr()
		{
			delete[]_Myptr;   //_Myptr==nullptr  delete nullptr;
		}
	public:
		_Ty& operator*() const
		{
			return (*get());
		}
		_Ty *operator->() const
		{
			return (get());
		}
		_Ty *get() const
		{
			return (_Myptr);
		}
		_Ty *release()
		{
			_Ty *_Tmp = _Myptr;
			_Myptr = 0;
			return (_Tmp);
		}
		void reset(_Ty *_Ptr = 0)
		{
			if (_Ptr != _Myptr)
				delete _Myptr;
			_Myptr = _Ptr;
		}
	private:
		_Ty *_Myptr;
	};
};
void main()
{
	int *p = new int(10);    //��������
	bit::auto_ptr<int> aptr1(p);
	cout << "*aptr1 = " << *aptr1 << endl;
	//int *q = new int(20);
	int *&q = p;
	aptr1.reset(q);
	//cout << "*aptr1 = " << *aptr1 << endl;
}

/*
namespace bit
{
	//vc6.0  
	//ȱ��:���ܹ����������  ӵ��Ȩת�岻����
	template<class _Ty>
	class auto_ptr
	{
	public:
		explicit auto_ptr(_Ty *_P = 0) :_Owns(_P != 0), _Ptr(_P)
		{}
		auto_ptr(auto_ptr<_Ty> &_Y) : _Owns(_Y._Owns), _Ptr(_Y.release())
		{}
		auto_ptr<_Ty>& operator=(auto_ptr<_Ty> &_Y)
		{
			if (this != &_Y)
			{
				if (_Ptr != _Y._Ptr)
				{
					if (_Owns)
						delete _Ptr;
					_Owns = _Y._Owns;
				}
				else if (_Y._Owns)
					_Owns = true;
				_Ptr = _Y.release();
			}
			return *this;
		}
		~auto_ptr()
		{
			if (_Owns)
			{
				delete _Ptr; //delete[]_Ptr;
				_Ptr = NULL;
			}
		}
	public:
		_Ty& operator*()const
		{
			return *_Ptr;
		}
		_Ty* operator->()const
		{
			return _Ptr;
		}
		_Ty *release()
		{
			this->_Owns = false;
			return (_Ptr);
		}
	private:
		bool _Owns;
		_Ty *_Ptr;
	};
};
void main()
{
	int *p = new int(10);    //��������
	bit::auto_ptr<int> aptr1(p);
	cout << "*aptr1 = " << *aptr1 << endl;
	//C++�﷨ 
	bit::auto_ptr<int> aptr2(aptr1);
	cout << "*aptr2 = " << *aptr2 << endl;
	cout << "*aptr1 = " << *aptr1 << endl;
	//int *q = new int(20);
	//bit::auto_ptr<int> aptr3(q);  //
	//aptr3 = aptr2;
	//bit::auto_ptr<int> aptr4(p);
	//aptr4 = aptr2;
}


/*
namespace bit
{
	//vs2013 ȱ��:���ܹ����������
	template<class _Ty>
	class auto_ptr   //smart_ptr
	{
		typedef auto_ptr<_Ty> _Myt;
	public:
		explicit auto_ptr(_Ty *_Ptr = 0) : _Myptr(_Ptr)
		{}
		auto_ptr(_Myt& _Right) : _Myptr(_Right.release())
		{}
		_Myt& operator=(_Myt& _Right)
		{
			reset(_Right.release());
			return (*this);
		}
		~auto_ptr()
		{
			delete[]_Myptr;   //_Myptr==nullptr  delete nullptr;
		}
	public:
		_Ty& operator*() const
		{
			return (*get());
		}
		_Ty *operator->() const
		{
			return (get());
		}
		_Ty *get() const
		{
			return (_Myptr);
		}
		_Ty *release()
		{
			_Ty *_Tmp = _Myptr;
			_Myptr = 0;
			return (_Tmp);
		}
		void reset(_Ty *_Ptr = 0)
		{
			if (_Ptr != _Myptr)
				delete _Myptr;
			_Myptr = _Ptr;
		}
	private:
		_Ty *_Myptr;
	};
};
void main()
{
	int *p = new int(10);    //��������
	bit::auto_ptr<int> aptr1(p);
	cout << "*aptr1 = " << *aptr1 << endl;
	//int *q = new int(20);
	int *&q = p;
	aptr1.reset(q);
}

/*
class Date
{
public:
	Date() { cout << "Date()" << endl; }
	~Date(){ cout << "~Date()" << endl; }
	int _year;
	int _month;
	int _day;
};
int main()
{
	auto_ptr<Date> ap(new Date);
	auto_ptr<Date> copy(ap);
	// auto_ptr�����⣺�����󿽱����߸�ֵ��ǰ��Ķ����������
	// C++98����Ƶ�auto_ptr�����Ƿǳ����Եģ�����ʵ���кܶ๫˾��ȷ�涨�˲���ʹ��auto_ptr
	ap->_year = 2018;
	return 0;
}


/*
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}
	~SmartPtr()
	{
		if (_ptr)
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
private:
	T* _ptr;
};

struct Date
{
	int _year;
	int _month;
	int _day;
};

int main()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 10;
	cout << *sp1 << endl;
	SmartPtr<int> sparray(new Date);
	// ��Ҫע���������Ӧ����sparray.operator->()->_year = 2018;
	// ����Ӧ����sparray->->_year�����﷨��Ϊ�˿ɶ��ԣ�ʡ����һ��->
	sparray->_year = 2018;
	sparray->_month = 1;
	sparray->_day = 1;
	return 0; 
}

/*
// ʹ��RAII˼����Ƶ�SmartPtr��
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}
		~SmartPtr()
	{
			if (_ptr)
				delete _ptr;
		}
private:
	T* _ptr;
};
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	// ��tmpָ��ί�и���sp������ʱ��ʦ�Ļ�˵��tmpָ������һ�����µ�Ů���ѣ���������㣬ֱ����go
	SmartPtr<int> sp(tmp);
	// _MergeSort(a, 0, n - 1, tmp);
	// ������账����һЩ�����߼�
	// ...
	vector<int> v(1000000000, 10);
}
int main()
{
	try {
		int a[5] = { 4, 5, 2, 3, 1 };
		MergeSort(a, 5);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}


/*
//�쳣
int main()
{
	try
	{
		int *p = new int[500000000];
	}
	catch (bad_alloc &e)
	{
		cout << e.what() << endl;
		return 0;
	}
	cout << "new OK." << endl;
	return 0;
}*/