#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

template<class _Ty>
class list
{
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
		} //_P->_Value;
	};
public:
	// ÝÍÈ¡
	typedef size_t size_type;
	typedef size_type difference_type;
	typedef _Ty       value_type;
	typedef _Ty*      pointer;
	typedef _Ty&      reference;
	typedef const _Ty* const_pointer;
	typedef const _Ty& const_reference;
public:
	class iterator  //????
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
		iterator& operator++()
		{
			_Ptr = _Acc::_Next(_Ptr);
			return *this;
		}
	public:
		bool operator==(const iterator &it)
		{
			return _Ptr == it._Ptr;
		}
		bool operator!=(const iterator &it)
		{
			return !(*this == it);
		}
	protected:
		_Nodeptr _Ptr;
	};
public:
	explicit list() : _Head(_Buynode()), _Size(0)
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
	}/*
	void push_front(const _Ty & _X)
	{}
	void push_back(const _Ty & _X)
	{
	_Nodeptr _S = _Buynode(_Head, _Head->_Prev);
	_S->_Value = _X;
	_S->_Prev->_Next = _S;
	_S->_Next->_Prev = _S;
	_Size++;
	}

	void push_back(const _Ty & _X)
	{
	_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
	_S->_Value = _X;
	_S->_Next = _Head;
	_S->_Prev = _Head->_Prev;
	_S->_Prev->_Next = _S;
	_Head->_Prev = _S;
	_Size++;
	}
	*/
	/*void push_back(const _Ty &_X)
	{
		insert(end(), _X);
	}
	void push_front(const _Ty &_X)
	{
		insert(begin(), _X);
	}*/
public:
	iterator insert(iterator _P, const _Ty &_X = _Ty())
	{
		_Nodeptr _S = _P._Mynode();
		_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
		_S = _Acc::_Prev(_S);
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Value(_S) = _X;
		_Size++;
		return iterator(_S);
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
void main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	//mylist.push_front(3);
	//mylist.push_front(4);

	list<int>::iterator it = mylist.begin();
	while (it != mylist.end())
	{
		cout << *it << "-->";
		++it;
	}
}
/*
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int MAX = 120;//规定字符串的最大长度不超过120个字符
char strToken[MAX];//存放当前宇符串
char *Key_Word[5] = { "dim", "if", "do", "stop", "end" };//存放保留字
FILE*fp;

int Isletter(char ch)//是否为字母 
{
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
		return 1;
	return 0;
}
int Isdigit(char ch)//是否为数字
{

	if (ch >= '0'&&ch <= '9')
		return 1;
	return 0;
}
int  Reserve()//是否为保留字
{
	int i;
	for (i = 0; i<5; i++)
	if (strcmp(strToken, Key_Word[i]) == 0)
		return (i + 1);
	return 0;
}
void Retract(int &i, char &ch)//将搜索指示器回溯同一个位置，并将ch设置为空
{
	i = i - 1;
	ch = ' ';
}
void GetChar(int &i, char Buffer[MAX], char &ch)//将下一个字符读到ch 中 
{
	i = i + 1;
	ch = Buffer[i];
}
void Concat(char &ch, char strToken[MAX], int &k)//将ch中字符连接的srToken之后 
{
	strToken[k] = ch;
	k = k + 1;
}
void InsertId(char value[MAX], int &k)//将stToken中字符添加到value中 
{
	for (int i = 0; i<MAX; i++)
		value[i] = strToken[i];
}
int i, k, code;
char Buffer[MAX], ch, value[MAX];
int i, k, code;
while (!feof(fp)) //检测是否结束
{
	stcpy(Buffer, " ");//清空缓冲区
	fgets(Buffer, MAX, fp);//读取字符串 

	while (i<MAX&&ch != '\0')
	{
		ch = Buffer[i];
		if (Islettert(ch))
		{
			k = 0:
			while (Isletter(ch) Iscligit(ch) && i< MAX)//是标识符
			{
				Concant(ch, strToken, k);
				GetChar(i, Buffer, ch);
			}
			strToken[k] = '\0';
			Retract(i.ch);
			cout << strToken;
			code = Reserve();//配保留字，并返同其编码值
			if (code == 0)
			{
				Insertld(value.strToken);
				cout << "<6," << value << ">" << "t标识符" << endl;//标识符
			}
			else
				cout << "<" << code << ",_>" << "t保留字" << endl;//保留字
			strcpy(strToken, "");
		}
		else if (Isdigiti(ch))
		{
			k = 0;
			while (Isdigit(ch) && i<MAX)// 常数
			{
				Concat(ch, strToken, k);
				GetChar(i, Buffer, ch);
			}
			strToken[k] = '\0';
			Retract(i, ch);
			cout << strToken;
			cout << "<7,";
			cout<stToken << ">" << "\t 常数" << endl;
			strcpy(strToken, "");
		}
		else if (ch == '≠')
		{
			cout << ch;
			GetChar(i, Buffer, ch);
			if (ch == '* ')
				cout << ch << "<12," endl;//**
			else
			{
				cout << "11,>" << endl;//*
				--i
			}//
		}
		else if (ch == '+')
			cout << ch << "<9,>" << endl;//+
		else if (ch == '-')
			cout << ch << "<10,>" << endl;//-
		else if (ch == ',')
			cout << ch << "<13,>" << endl;
		else if (ch == '(')
			cout << ch << "<14>" << endl;
		else if (ch == ')')
			cout << ch << "<15>" << endl;


		i++;
	}//
	while (i<MAX)
		ch = ' ';
}//
while (!feo(fp))
felose(fp);
}
int main(void)
{
	int s;
	cout << "INPUT THE S:" << endl;
	cin << s;
	return0;
}
cout << "*************词法分析****************" << endl;
analysis();
cout << "*************词法分析****************" << endl;
return 0;
}

/*
template<class _Ty>
class list
{
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
		} //_P->_Value;
	};
public:
	// ÝÍÈ¡
	typedef size_t size_type;
	typedef size_type difference_type;
	typedef _Ty       value_type;
	typedef _Ty*      pointer;
	typedef _Ty&      reference;
	typedef const _Ty* const_pointer;
	typedef const _Ty& const_reference;
public:
	class iterator  //????
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
		iterator& operator++()
		{
			_Ptr = _Acc::_Next(_Ptr);
			return *this;
		}
	public:
		bool operator==(const iterator &it)
		{
			return _Ptr == it._Ptr;
		}
		bool operator!=(const iterator &it)
		{
			return !(*this == it);
		}
	protected:
		_Nodeptr _Ptr;
	};
public:
	explicit list() : _Head(_Buynode()), _Size(0)
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
	/*
	void push_back(const _Ty & _X)
	{
	_Nodeptr _S = _Buynode(_Head, _Acc::_Prev(_Head));
	_Acc::_Value(_S) = _X;
	_Acc::_Next(_Acc::_Prev(_S)) = _S;
	_Acc::_Prev(_Acc::_Next(_S)) = _S;
	_Size++;
	}
	void push_front(const _Ty & _X)
	{}
	void push_back(const _Ty & _X)
	{
	_Nodeptr _S = _Buynode(_Head, _Head->_Prev);
	_S->_Value = _X;
	_S->_Prev->_Next = _S;
	_S->_Next->_Prev = _S;
	_Size++;
	}

	void push_back(const _Ty & _X)
	{
	_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
	_S->_Value = _X;
	_S->_Next = _Head;
	_S->_Prev = _Head->_Prev;
	_S->_Prev->_Next = _S;
	_Head->_Prev = _S;
	_Size++;
	}
	
	void push_back(const _Ty &_X)
	{
		insert(end(), _X);
	}
	void push_front(const _Ty &_X)
	{
		insert(begin(), _X);
	}
public:
	iterator insert(iterator _P, const _Ty &_X = _Ty())
	{
		_Nodeptr _S = _P._Mynode();
		_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
		_S = _Acc::_Prev(_S);
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Value(_S) = _X;
		_Size++;
		return iterator(_S);
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
void main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_front(3);
	mylist.push_front(4);

	list<int>::iterator it = mylist.begin();
	while (it != mylist.end())
	{
		cout << *it << "-->";
		++it;
	}
}
/*
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
class String;
ostream& operator<<(ostream& out, const String& t);
istream& operator>>(istream& in, String& t);

class String
{
	friend ostream& operator<<(ostream& out, const String& t);
	friend istream& operator>>(istream& in, String& t);

public:
	String(char *str = "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if (this != &s)
		{
			free(m_data);
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		delete[]m_data;
		m_data = nullptr;
	}
	int lenght()const
	{
		return strlen(m_data);
	}
public:
	char operator[](const int& i);
	String operator+(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	bool operator>(const String& s);
	bool operator<(const String& s);
	bool operator<=(const String& s);
	bool operator>=(const String& s);


private:
	char * m_data;
};

char String::operator[](const int& i)
{
	assert(i >= 0 && i < lenght());
	return m_data[i];
}

String String::operator+(const String& s)
{
	int total_size = lenght() + s.lenght() + 1;
	char* tem = new char[total_size];
	strcpy(tem, m_data);//拷贝字符串
	strcat(tem, s.m_data);//链接字符串

	String tems(tem);
	delete[]tem;
	return tems;
}

String& String::operator+=(const String& s)
{
	int new_size = lenght() + s.lenght() + 1;
	char* tem = new char(new_size);
	strcpy(tem, m_data);
	strcat(tem, s.m_data);

	delete[]m_data;
	m_data = tem;
	return *this;
}

bool String::operator==(const String& s)
{
	if (strcmp(m_data, s.m_data) == 0)
		return true;
	return false;
}

bool String::operator!=(const String& s)
{
	return !(*this == s);
}

bool String::operator>(const String& s)
{
	if (strcmp(m_data, s.m_data) == 1)
		return true;
	return false;
}

bool String::operator<(const String& s)
{
	if (strcmp(m_data, s.m_data) == -1)
		return true;
	return false;
}

bool String::operator<=(const String& s)
{
	return !(*this > s);
} 

bool String::operator>=(const String& s)
{
	return !(*this < s);
}

ostream& operator<<(ostream& out, const String& t)
{
	out << t.m_data;
	return out;
}
istream& operator>>(istream& in, String& t)
{
	in >> t.m_data;
	return in;
}


int main()
{
	String s1("Hello"); //s1[0] ==> H
	String s2("Bit.");

	//for (int i = 0; i<s1.lenght(); ++i)
	//	cout << s1[i];
	//cout << endl;
	//String s = s1 + s2; //s = HelloBit
	//s1 += s2;
	//cout << s1 << endl;
	if (s1 == s2)
		cout << "s1 == s2" << endl;
	//if (s1 != s2)
	//	cout << "s1 != s2" << endl;
	//if (s1 > s2)
	//	cout << "s1 > s2" << endl;
	//if (s1 < s2)
	//	cout << "s1 < s2" << endl;
	//if (s1 >= s2)
	//	cout << "s1 >= s2" << endl;
	//if (s1 <= s2)
	//	cout << "s1 <= s2" << endl;

	return 0;
}*/