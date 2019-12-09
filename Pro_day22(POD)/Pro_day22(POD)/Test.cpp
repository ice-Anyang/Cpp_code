#define _CRT_SECURE_NO_WARNINGS 1
#include<istream>
using namespace std;
//类型萃取
/*
class String
{
public:
	String(const char* str = "")
	{
		_date = new char[strlen(str) + 1];
		strcpy(_date, str);
	}
	String(const String& s)
	{
		String tem(s._date);
		swap(_date,tem._date);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String tem(s);
			swap(_date, tem._date);
		}
		return *this;
	}
	~String()
	{
		if (_date)
			delete[] _date;
		_date = nullptr;
	}

private:
	char* _date;
};

bool IsPODType(const char *type)
{
	const char* type_ar[] = {
		"bool",
		"short",
		"int",
		"float",
		"long",
		"double"
	};
	int n = sizeof(type_ar) / sizeof(const char*);
	for (int i = 0; i<n; ++i)
	{
		if (strcmp(type, type_ar[i]) == 0)
			return true;
	}
	return false;
}

struct __true_type
{};
struct __false_type
{};

template<class T>//泛型
struct type_traits
{
	typedef __false_type IsPODType;  //类型的萃取
};

template<>
struct type_traits<int>//特化
{
	typedef __true_type IsPODType; //
};

template<typename T>

//函数重载
void _Copy(T *dst, const T *src, size_t sz, __true_type)
{
	memcpy(dst, src, sizeof(T)*sz);
}

template<typename T>
void _Copy(T *dst, const T *src, size_t sz, __false_type)
{
	for (int i = 0; i<sz; ++i)
	{
		dst[i] = src[i];
	}
}

template<typename T>
void Copy(T *dst, const T *src, size_t sz)
{
	//类型萃取
	typename typedef type_traits<T>::IsPODType IsPOD;  
	//typedef type_traits<int>::IsPODType IsPOD;
	//__true_type IsPOD;
	_Copy(dst, src, sz, IsPOD());  //__true_type()
}

int main()
{
	String sa1[3] = { "aa", "bb", "cc" };
	String sa2[3];
	Copy(sa2, sa1, 3);
	//String s("asdfghjkl");
	//String s1 = s;
	//String s2(s1);
	return 0;
}

/*
class String
{
public:
	String(const char* str = "") 
	{
		_date = new char[strlen(str) + 1];
		strcpy(_date, str);
	}
	String(const String& s) :_date(nullptr)
	{
		String tem(s._date);
		swap(_date, tem._date);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String tem(s);
			swap(_date, tem._date);
		}
		return *this;
	}
	~String()
	{
		if (_date)
			delete[]_date;
		_date = nullptr;
	}
private:
	char* _date;
};


template <typename Type>
void Copy(Type *dst, const Type *str, size_t sz, bool IsPod)
{
	if (IsPod)
		memcpy(dst, str, sz*sizeof(Type));
	else
	{
		for(int i = 0; i < sz; ++i)
		{
			dst[i] = str[i];
		}
	}
}
bool IsPOD(const char* type)
{
	const char* type_arr[] = { "int", "bool", "short", "double", "long", "long long" };
	int n = sizeof(type_arr) / sizeof(const char*);

	for (int i = 0; i < n; ++i)
	{
		if (strcmp(type, type_arr[i]) == 0)
			return true;
	}
	return false;
}

int main()
{
	int  arr1[6] = {1,2,3,4,5,6 };
	int  arr2[10] = {};
	Copy(arr2, arr1, 6, IsPOD("int"));

	String ar[3] = { "as", "df", "gh" };
	String arr[4] = {};
	Copy(arr, ar, 3, IsPOD("String"));
	return 0;
}*/