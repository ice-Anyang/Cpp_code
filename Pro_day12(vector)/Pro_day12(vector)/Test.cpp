#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<vector>
//#include<string>
using namespace std;

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