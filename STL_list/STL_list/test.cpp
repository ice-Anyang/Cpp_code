#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std; 

template<class _Ty> inline

_Ty* _MyAllocate(size_t _N, _Ty *)
{
	cout << "_Ty = " << typeid(_Ty).name() << endl;
	if (_N < 0)
		_N = 0;
	return ((_Ty *)operator new(_N * sizeof (_Ty)));
}

template<class _T1, class _T2> inline
void _MyConstruct(_T1  *_P, const _T2& _V)
{
	new ((void*)_P) _T1(_V); //¶¨Î» new //????????//
}

template<class _Ty> inline
void _MyDestroy(_Ty  *_P)
{
	_P->~_Ty();
}

template<class _Ty>
class myallocator
{
public:
	typedef size_t       size_type;
	typedef size_t       difference_type;
	typedef _Ty  *       pointer;
	typedef const _Ty *  const_pointer;
	typedef _Ty    &     reference;
	typedef const _Ty &  const_reference;
	typedef _Ty          value_type;
public:
	pointer allocate(size_type _N, const void *)
	{
		return (_MyAllocate(_N, (pointer)0));
	}
	void deallocate(void  *_P, size_type)
	{
		operator delete(_P);
	}
	void construct(pointer _P, const _Ty& _V)
	{
		_MyConstruct(_P, _V);
	}
	void destroy(pointer _P)
	{
		_MyDestroy(_P);
	}
	char* _Charalloc(size_type _N)
	{
		return (_MyAllocate(_N, (char *)0));
	}
};


template<class _Ty>
class list
{
public:
	typedef size_t size_type;
	typedef size_type difference_type;
	typedef _Ty       value_type;
	typedef _Ty*      pointer;
	typedef _Ty&      reference;
	typedef const _Ty* const_pointer;
	typedef const _Ty& const_reference;
protected:
	struct _Node;
	typedef struct _Node* _Nodeptr;
	struct _Node
	{
		_Nodeptr _Next, _Prev;
		_Ty _Value;
	};
	struct _Acc;
	struct _Acc
	{
		typedef struct _Node*& _Nodepref;
		typedef _Ty&           _Vref;
		static _Nodepref _Next(_Nodeptr _P)
		{return ((_Nodepref)((*_P)._Next));} // _P->_Next;
		static _Nodepref _Prev(_Nodeptr _P)
		{return ((_Nodepref)((*_P)._Prev));}// _P->_Prev;
		static _Vref _Value(_Nodeptr _P)
		{return ((_Vref)(*_P)._Value);} //_P->_Value;
	};
public:
	class iterator //µü´úÆ÷
	{
	public:
		iterator()
		{}
		iterator(_Nodeptr _P) : _Ptr(_P)
		{}
		_Nodeptr _Mynode()const
		{
			return  _Ptr;
		}
	public:
		_Ty operator*()
		{
			return _Acc::_Value(_Ptr);
		}
		iterator operator++()
		{
			_Ptr = _Acc::_Next(_Ptr);
			return *this;
		}
		iterator operator++(int)
		{
			iterator tem = *this;
			++(*this);
			return tem;
		}
		bool operator==(const iterator& s)
		{
			return _Ptr == s._Ptr;
		}
		bool operator!=(const iterator& s)
		{
			return !(*this == s);
		}
	private:
		_Nodeptr _Ptr;
	};
public:
	explicit list() :_Head(_Buynode()), _Size(0)
	{}
public:
	iterator begin()
	{
		return iterator(_Acc::_Next(_Head));
	}
	iterator end()
	{
		return iterator(_Head);
	}
public:
	void push_back(const _Ty & _X)
	{
		_Nodeptr _S = _Buynode(_Head, _Acc::_Prev(_Head));
		_Acc::_Value(_S) = _X;
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Prev(_Acc::_Next(_S)) = _S;
		_Size++;
	}
	void push_front(const _Ty& _X)
	{
		_Nodeptr _S = _Buynode(_Acc::_Next(_Head), _Head);
		_Acc::_Value(_S) = _X;
		_Acc::_Prev(_Acc::_Next(_S)) = _S;
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Size++;
	}
public:
	iterator insert(iterator _P, const _Ty& X = Ty())
	{
		_Nodeptr _S = _P._Mynode();
		_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
		_S = _Acc::_Prev(_S);
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Value(_S) = _X;
		_Size++;
		return iterator(_S);
	}
	iterator erase(iterator _P)
	{
		_Nodeptr _S = (_P++)._Mynode();
		_Acc::_Next(_Acc::_Prev(_S)) = _Acc::_Next(_S);
		_Acc::_Prev(_Acc::_Next(_S)) = _Acc::_Prev(_S);

		myallocator.destroy(&_Acc::Value(_S));
		_Freenode(_S);
		--_Size;
		return (_P);
	}
protected:
	_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
	{
		_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
		_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
		_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
		return _S;
	}
	void _Freenode(_Nodeptr _S)
	{
		free(_S);
	}
private:
	_Nodeptr _Head;
	size_type _Size;
};
int main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_front(3);
	mylist.push_front(4);
	list<int>::iterator it = mylist.begin();
	auto pos = ++it;
	mylist.erase(pos);
	while (it != mylist.end())
	{
		cout << *it << "-->";
		++it;
	}
	return 0;
}