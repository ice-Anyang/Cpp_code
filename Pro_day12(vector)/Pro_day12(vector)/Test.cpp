#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<vector>
//#include<string>
using namespace std;



namespace ice
{
	template<class T>
	class vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* iterator;//迭代器
		typedef const T* const_iterator;//常迭代器
		iterator begin() 
		{ 
			return _start; 
		}
		iterator end() 
		{ 
			return _finish;
		}
		const_iterator cbegin()const 
		{ 
			return _start; 
		}
		const_iterator cend() const 
		{ 
			return _finish; 
		}
		// construct and destroy
		vector()//构造空vector
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		vector(int n, const T& value = T())//构造n个空间
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		// 如果使用iterator做迭代器，会导致初始化的迭代器区间[first,last)只能是vector的迭代器
		// 重新声明迭代器，迭代器区间[first,last]可以是任意容器的迭代器
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)//区间构造
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(const vector<T>& v)//拷贝构造
			: _start(nullptr)
			  , _finish(nullptr)
			  , _endOfStorage(nullptr)
		{
			reserve(v.capacity());
			iterator it = begin();
			const_iterator vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.size();
			_endOfStorage = _start + v.capacity();
		}

		vector<T>& operator= (vector<T> v)//赋值语句
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		size_t size() const 
		{ 
			return _finish - _start; 
		}

		size_t capacity() const 
		{ 
			return _endOfStorage - _start; 
		}

		void reserve(size_t n)//设置容量
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				//if (_start)
				// memcpy(tmp, _start, sizeof(T)*size);
				if (_start)
				{
					for (size_t i = 0; i < oldSize; ++i)
						tmp[i] = _start[i];
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}

		void resize(size_t n, const T& value = T())//设置大小
		{
			// 1.如果n小于当前的size，则数据个数缩小到n
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			// 2.空间不够则增容
			if (n > capacity())
				reserve(n);
			// 3.将size扩大到n
			iterator it = _finish;
			iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}

		T& operator[](size_t pos)//重载[]
		{ 
			return _start[pos];
		}

		const T& operator[](size_t pos)const 
		{ 
			return _start[pos];
		}

		void push_back(const T& x)
		{ 
			insert(end(), x); 
		}
		void pop_back()
		{ 
			erase(--end()); 
		}

		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}
		iterator insert(iterator pos, const T& x)//在pos处插入x值
		{
			assert(pos <= _finish);
			// 空间不够先进行增容
			if (_finish == _endOfStorage)
			{
				size_t size = size();
				size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
				reserve(newCapacity);
				// 如果发生了增容，需要重置pos
				pos = _start + size;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(Iterator pos)//删除pos处的值
		{
			// 挪动数据进行删除
			iterator begin = pos + 1;
			while (begin != _finish) 
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}


		

	private:
		iterator _start; // 指向数据块的开始
		iterator _finish; // 指向有效数据的尾
		iterator _endOfStorage; // 指向存储容量的尾
	};
}

int main()
{
	vector<int> vt(2, 2);
	return 0;
}



/*
class string
{
public:
	string(const char* str = "")
	{
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str,str);
	}

	string(const string& s):
		_str(new char[strlen(s._str)+1])
	{
		strcpy(_str,s._str);
	}

	string& operator=(const string& s)
	{
		if (this != &s)
		{
			char* ptr = new char[strlen(s._str) + 1];
			strcpy(ptr, s._str);
			delete[]_str;
			_str = ptr;
		}
		return *this;
	}

	~string()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

int main()
{
	std::string s("asdfgh");
	return 0;
}

/*
int main()
{
	int m = 123;
	int n = 0123;
	printf("%o %o\n", m, n);
	return 0;
}
/*
int main()
{
	struct A
	{
		int a;
		short b;
		float c;
		int* p;
	};
	printf("%d\n", sizeof(struct A));
	return 0;
}


/*
int main()
{
	//浅拷贝和深拷贝

	return 0;
}

/*
int main()
{
	string str;
	while (getline(cin, str))
	{
		int flag = 1;
		int tem = 0;
		for (size_t i = str.size() - 1; i >= 0; --i)
		{
			if ( flag  && str[i] == ' ')
				continue;
			else if (str[i] != ' ')
			{
				flag = 0;
				++tem;
			}
			else
				break;
		}
		cout << tem << endl;
	}
	return 0;
}
/*

//迭代器失效常见问题
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 0 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	vector<int>::iterator it = v1.begin();

	while (it != v1.end())
	{
		if (*it % 2 == 0)
			it = v1.erase(it);
		//it++; 错误，跌加器失效
		else
			it++;
	}
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
/*
int main()
{

	int arr[] = { 1, 2, 3, 4, 5, 0 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	vector<int>::iterator pos = find(v1.begin(), v1.end(), 4);
	cout << *pos << endl;
	v1.erase(pos);

	pos = find(v1.begin(), v1.end(), 4);
	//v1.insert(pos, 4);//错误
	
	cout << *pos << endl;


	return 0;
}

/*
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	v1[0] = 10;
	cout << v1[0] << endl;

	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int> v2(4,2);

	v2.swap(v1);
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto& e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
/*
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 0 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	vector<int>::iterator pos = find(v1.begin(), v1.end(), 0);
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	
	v1.erase(pos);

	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}


/*
//尾部增加
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 0 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it <<" ";
		it++;
	}
	cout << endl;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.push_back(6);
	v1.push_back(7);

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;


	return 0;
}


/*
int main()
{
	vector<int> s1(6,2);
	cout << "s1.empty = " << s1.empty() << endl;// 0

	vector<int> s2 = s1;
	s2.resize(0);
	cout << "s2.empty = " << s2.empty() << endl;// 0
	return 0;
}

/*
int main()
{
	vector<int> v1;
	cout << "v1 size = " << v1.size() << endl;
	cout << "v1 capacity = " << v1.capacity() << endl;

	vector<int> v2(6, 22);
	cout << "v2 size = " << v2.size() << endl;
	cout << "v2 capacity = " << v2.capacity() << endl;

	v1.resize(100);
	cout << "v1 size = " << v1.size() << endl;
	cout << "v1 capacity = " << v1.capacity() << endl;

	v2.reserve(100);
	cout << "v2 size = " << v2.size() << endl;
	cout << "v2 capacity = " << v2.capacity() << endl;

	v1.resize(10);
	cout << "v1 size = " << v1.size() << endl;
	cout << "v1 capacity = " << v1.capacity() << endl;

	v2.reserve(10);
	cout << "v2 size = " << v2.size() << endl;
	cout << "v2 capacity = " << v2.capacity() << endl;
	return 0;
}*/