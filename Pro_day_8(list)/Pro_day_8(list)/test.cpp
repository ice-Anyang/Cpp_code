#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


#include<iostream>
#include<assert.h>
using namespace std;
namespace ice
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;

		_list_node(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};

	template<class T, class Ref, class Ptr>
	class _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> Self;
	public:
		_list_iterator(node* node)
			:_node(node)
		{}

		Ref operator*() //内置类型
		{
			return _node->_data;
		}

		Ptr operator->() //自定义类型
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			_list_iterator<T, Ref, Ptr> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		//it1 !=  it2
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
		//private:
		node* _node;
	};


	template<class T>
	class list
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
	public:
		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(const list<T>& l)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			auto it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}

		list<T>& operator=(const list<T>& l)
		{
			clear();//不要忘记清理之前的
			auto it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
			return *this;


		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void push_back(const T& x)//尾插
		{
			node* newnode = new node(x);
			node* tail = _head->_prev;//先找出尾元素

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			//insert(end(),x);
		}

		void pop_back()//尾删
		{
			node* tail = _head->_prev->_prev;
			tail->_next = _head;
			_head->_prev = tail;
			//erase(--end());
		}

		void push_front(const T& x)//头插
		{
			insert(begin(), x);
		}

		void pop_front()//头删
		{
			erase(begin());
		}

		iterator erase(iterator pos)
		{
			node* cur = pos._node;
			assert(cur != _head);

			node* prev = cur->_prev;
			node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;

			delete cur;
			return iterator(next);
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		void print_list()
		{
			auto it = begin();
			while (it != end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);//list的 end 就是 _head
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}
	private:
		node* _head;
	};
}



/*
namespace ice
{
	// List的节点类
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
		: _pPre(nullptr)
		, _pNext(nullptr)
		, _val(val)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};
	//
	//List 的迭代器
	//迭代器有两种实现方式，具体应根据容器底层数据结构实现：

	//1. 原生态指针，比如：vector
	//2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：

	//1. 指针可以解引用，迭代器的类中必须重载operator*()
	//2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
	//3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
	//至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前
	//移动，所以需要重载，如果是forward_list就不需要重载--
	//4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
	//
	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			: _pNode(pNode)
		{}
		ListIterator(const Self& l)
			: _pNode(l._pNode)
		{}
		T& operator*()
		{ 
			return _pNode->_val; 
		}
		T* operator->()
		{
			return &(operator*()); 
		}
		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}
		Self& operator--(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pPre;
			return temp;
		}
		bool operator!=(const Self& l)
		{ 
			return _pNode != l._pNode;
		}
		bool operator==(const Self& l)
		{ 
			return _pNode != l._pNode; 
		}
		PNode _pNode;
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;//list节点
		typedef Node* PNode;//节点指针
	public:
		typedef ListIterator<T, T&, T*> iterator;//迭代器
		typedef ListIterator<T, const T&, const T&> const_iterator;//常迭代器
	public:
		///////////////////////////////////////////////////////////////
		// List的构造
		list()//无参构造
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(int n, const T& value = T())//有参构造
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				push_back(value);
		}
		template <class Iterator>
		list(Iterator first, Iterator last)
		{
				CreateHead();
				while (first != last)
				{
					push_back(*first);
					++first;
				}
			}
		list(const list<T>& l)
		{
			CreateHead();
			list<T> temp(l.cbegin(), l.cend());
			this->swap(temp);
		}
		list<T>& operator=(const list<T> l)//赋值语句
		{
			this->swap(l);
			return *this;
		}
		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
		// List Iterator
		iterator begin()
		{ 
			return iterator(_pHead->_pNext); 
		}
		iterator end()
		{ 
			return iterator(_pHead); 
		}
		const_iterator begin()
		{
			return const_iterator(_pHead->_pNext); 
		}
		const_iterator end()
		{ 
			return const_iterator(_pHead); 
		}
		void push_back(const T& val)
		{ 
			insert(begin(), val); 
		}
		void pop_back()
		{ 
			erase(--end()); 
		}
		void push_front(const T& val)
		{ 
			insert(begin(), val); 
		}
		void pop_front()
		{ 
			erase(begin()); 
		}
		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			// 先将新节点插入
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}
		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			// 找到待删除的节点
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;
			// 将该节点从链表中拆下来并删除
			pDel->_pPre->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = pDel->_pPre;
			delete pDel;
			return iterator(pRet);
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}
	private:
		PNode _pHead;
	};
}

/*
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
