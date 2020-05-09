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
		_Ty *release()//改变拥有权
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
//异常
double Division(int a, int b)
{
	// 当b == 0时抛出异常
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
//auto_ptr的使用
namespace bit
{
	//vs2013 缺点:不能管理数组对象
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
	int *p = new int(10);    //单个对象
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
	//缺点:不能管理数组对象  拥有权转义不彻底
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
	int *p = new int(10);    //单个对象
	bit::auto_ptr<int> aptr1(p);
	cout << "*aptr1 = " << *aptr1 << endl;
	//C++语法 
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
	//vs2013 缺点:不能管理数组对象
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
	int *p = new int(10);    //单个对象
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
	// auto_ptr的问题：当对象拷贝或者赋值后，前面的对象就悬空了
	// C++98中设计的auto_ptr问题是非常明显的，所以实际中很多公司明确规定了不能使用auto_ptr
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
	// 需要注意的是这里应该是sparray.operator->()->_year = 2018;
	// 本来应该是sparray->->_year这里语法上为了可读性，省略了一个->
	sparray->_year = 2018;
	sparray->_month = 1;
	sparray->_day = 1;
	return 0; 
}

/*
// 使用RAII思想设计的SmartPtr类
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
	// 讲tmp指针委托给了sp对象，用时老师的话说给tmp指针找了一个可怕的女朋友！天天管着你，直到你go
	SmartPtr<int> sp(tmp);
	// _MergeSort(a, 0, n - 1, tmp);
	// 这里假设处理了一些其他逻辑
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
//异常
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