#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<class _Ty>
class list
{
public:
	typedef size_t    size_type;
	typedef size_type difference_type;
	typedef _Ty       value_type;
	typedef _Ty*      poniter;
	typedef _Ty&      refrence;
	typedef const _Ty*  const_pointer;
	typedef const _Ty&  const_refrence;
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
		typedef struct _Node*&  _Nodepref;
		typedef _Ty&            _Vref;
		static _Nodepref _Next(_Nodeptr _P)
		{
			return ((_Nodepref)((*_P)._Next));
		} // _P->_Next;
		static _Nodepref _Prev(_Nodeptr _P)
		{
			return ((_Nodepref)((*_P)._Prev));
		}// _P->_Prev;
		static _Vref _Value(_Nodeptr _P)
		{
			return ((_Vref)(*_P)._Value);
		} //_P->_Value

	};
public:
	explicit list() :_Head(_Buynode()), _Size(0)
	{}
public:
	void push_back(const _Ty& _X)
	{
		_Nodeptr _S = _Buynode(_Head, _Acc::_Prev(_Head));
		_Acc::_Value(_S) = _X;
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Prev(_Acc::_Next(_S)) = _S;
		_Size++;
	}
protected:
	_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
	{
		_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
		_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
		_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
		return _S;
	}
private:
	_Nodeptr _Head;
	size_type _Size;

};

int main()
{
	list<int> mylist;
	mylist.push_back(1);
	return 0;
}
/*

template<typename _Ty>

class list
{
public:
	typedef size_t    size_type;
	typedef size_type difference_type;
	typedef _Ty       value_type;
	typedef _Ty*      poniter;
	typedef _Ty&      refrence;
	typedef const _Ty*  const_pointer;
	typedef const _Ty&  const_refrence;
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
		typedef struct _Node*&  _Nodepref;
		typedef _Ty&            _Vref;
		static _Nodepref _Next(_Nodeptr _P)
		{
			return ((_Nodepref)((*_P)._Next));
		} // _P->_Next;
		static _Nodepref _Prev(_Nodeptr _P)
		{
			return ((_Nodepref)((*_P)._Prev));
		}// _P->_Prev;
		static _Vref _Value(_Nodeptr _P)
		{
			return ((_Vref)(*_P)._Value);
		} //_P->_Value
	};
*/
//public:
//	explicit list() : _Head(_Buynode()), _Size(0)
//	{}
//public:
//	/*void push_back(const _Ty& _X)
//	{
//		_Nodeptr _S = _Buynode(_Head, _Head->_Prev);
//		_Acc::_Value(_S) = _X;
//		_Acc::_Prev(_Acc::_Next(_S)) = _S;
//		_Acc::_Next(_Acc::_Prev(_S)) = _S;
//		_Size++;
//	}*/
//	/*void push_back(const _Ty& _X)
//	{
//		_Nodeptr _S = _Buynode(_Head, _Head->_Prev);
//		_S->_Value = _X;
//		_S->_Prev->_Next = _S;
//		_S->_Next->_Prev = _S;
//		_Size++;
//	}*/
//	void push_back(const _Ty & _X)
//	{
//		_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
//		_S->_Value = _X;
//		_S->_Next = _Head;
//		_S->_Prev = _Head->_Prev;
//		_S->_Prev->_Next = _S;
//		_Head->_Prev = _S;
//		_Size++;
//	}
//
//	//void push_front(const _Ty& _X)
//	//{
//	//	_Nodeptr _S = _Buynode(_Head->_next,_Head );
//	//	_S ->_value = _X;
//	//	_S->_prev->_next = _S;
//	//	_S->_next->_prev = _S;
//	//	_Size++;
//	//}
//
//protected:
//	_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
//	{
//		_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
//		_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
//		_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
//		return _S;
//	}
//private:
//	_Nodeptr _Head;
//	size_type _Size;
//};
//int main()
//{
//	list<int>  mylist;
//	mylist.push_back(1);
//	//mylist.push_back(2);
//	//mylist.push_back(3);
//	//mylist.push_front(4);
//	//mylist.push_front(5);
//	//mylist.push_front(6);
//
//	return 0;
//}
