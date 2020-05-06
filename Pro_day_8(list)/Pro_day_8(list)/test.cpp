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

		Ref operator*() //��������
		{
			return _node->_data;
		}

		Ptr operator->() //�Զ�������
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
			clear();//��Ҫ��������֮ǰ��
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

		void push_back(const T& x)//β��
		{
			node* newnode = new node(x);
			node* tail = _head->_prev;//���ҳ�βԪ��

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			//insert(end(),x);
		}

		void pop_back()//βɾ
		{
			node* tail = _head->_prev->_prev;
			tail->_next = _head;
			_head->_prev = tail;
			//erase(--end());
		}

		void push_front(const T& x)//ͷ��
		{
			insert(begin(), x);
		}

		void pop_front()//ͷɾ
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
			return iterator(_head);//list�� end ���� _head
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
	// List�Ľڵ���
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
	//List �ĵ�����
	//������������ʵ�ַ�ʽ������Ӧ���������ײ����ݽṹʵ�֣�

	//1. ԭ��ָ̬�룬���磺vector
	//2. ��ԭ��ָ̬����з�װ���������ʹ����ʽ��ָ����ȫ��ͬ��������Զ�������б���ʵ�����·�����

	//1. ָ����Խ����ã������������б�������operator*()
	//2. ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
	//3. ָ�����++����ƶ������������б�������operator++()��operator++(int)
	//����operator--()/operator--(int)�ͷ���Ҫ���أ����ݾ���Ľṹ������˫�����������ǰ
	//�ƶ���������Ҫ���أ������forward_list�Ͳ���Ҫ����--
	//4. ��������Ҫ�����Ƿ���ȵıȽϣ���˻���Ҫ����operator==()��operator!=()
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
		typedef ListNode<T> Node;//list�ڵ�
		typedef Node* PNode;//�ڵ�ָ��
	public:
		typedef ListIterator<T, T&, T*> iterator;//������
		typedef ListIterator<T, const T&, const T&> const_iterator;//��������
	public:
		///////////////////////////////////////////////////////////////
		// List�Ĺ���
		list()//�޲ι���
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(int n, const T& value = T())//�вι���
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
		list<T>& operator=(const list<T> l)//��ֵ���
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
		// ��posλ��ǰ����ֵΪval�Ľڵ�
		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			// �Ƚ��½ڵ����
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}
		// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
		iterator erase(iterator pos)
		{
			// �ҵ���ɾ���Ľڵ�
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;
			// ���ýڵ�������в�������ɾ��
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
