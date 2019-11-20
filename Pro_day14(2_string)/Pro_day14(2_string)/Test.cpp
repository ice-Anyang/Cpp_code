#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

namespace Acc
{
	class string
	{
		friend ostream& operator<<(ostream &out, const string &s);
	public:
		string(const char *str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s) :_str(nullptr), _size(0), _capacity(0)
		{
			string tem(s._str);
			Swap(tem);
		}

		string& operator= (const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				Swap(tmp);
			}
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
				_capacity = _size = 0;
			}
		}
	public:
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
	public:
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				int new_capacity = (_capacity == 0 ? 1 : _capacity * 2);
				reserve(new_capacity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		void pop_back()
		{
			_size--;
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

		const char* c_str()const
		{
			return _str;
		}

	public:
		typedef char* iterator;
		typedef const char* const_iterator;
	public:
		iterator begin()
		{
			return _str;
		}
		const_iterator begin()const
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
	public:
		char operator[](size_t i)
		{
			assert(i<_size);
			return _str[i];
		}
		const char operator[](size_t i)const 
		{
			assert(i<_size);
			return _str[i];
		}
		string& operator+= (char c)
		{
			push_back(c);
			return *this;
		}
	public:
		void rsize(size_t new_sz,char ch ='\0')
		{
			if (new_sz > _size)
			{
				if (new_sz > _capacity)
				{
					reserve(new_sz);
				}
				memset(_str + _size, ch, new_sz - _size);
			}
			_str[new_sz] = '\0';
			_size = new_sz;
		}
		void reserve(size_t new_capacity)
		{
			if (new_capacity > capacity())
			{
				char* new_str = new char[new_capacity + 1];
				_capacity = new_capacity;
				strcpy(new_str, _str);
				delete[]_str;
				_str = new_str;
			}
		}
		void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}
ostream& Acc::operator<<(ostream &out, const string &s)
{
	out << s._str;
	return out;
}

int main()
{
	Acc::string s("asdfg");
	s.push_back('a');
	s.push_back('s');
	s.push_back('s');
	s.push_back('s');
	s.pop_back();

	for (size_t i = 0; i<s.size(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	return 0;
}
/*
int main()
{
	Acc::string s("asdfg");
	Acc::string s1(s);
	Acc::string::iterator it = s1.begin();
	for (size_t i = 0; i<s1.size(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	return 0;
}

/*
int main()
{
	Acc::string s("Hello Bit.");
	cout << s << endl;
	cout<< "size =" << s.size() << endl;
	cout<< "capacity =" << s.capacity() << endl;

	s.rsize(30);
	s.reserve(20);
	cout << "size =" << s.size() << endl;
	cout << "capacity =" << s.capacity() << endl;
	return 0;
}*/