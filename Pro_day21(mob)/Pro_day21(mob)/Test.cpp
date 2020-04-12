#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
	return 0;
}

//模板的泛化和特化
/*
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Data<int, char>" << endl;
	}
private:
	int _d1;
	char _d2;
};
template<>
class Data<int, int>
{
public:
	Data()
	{
		cout << "Data<int, char>" << endl;
	}
private:
	int _d1;
	char _d2;
};
template<class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "Data<T1, T2>" << endl;
	}
private:
	T1 _d1;
	int _d2;
};
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
template<class T>
class Data<T*, T*>
{
public:
	Data()
	{
		cout << "Data<T1, T2>" << endl;
	}
private:
	T _d1;
	T _d2;
};
void main()
{
	Data<int*, double*> d1;
	Data<int*, int*> d2;
}
/*

template <typename T1,typename T2>

class Date
{
public:
	Date()
	{
		cout << "(_y, _m) " << endl;
	}
private:
	T1 _y;
	T2 _m;

};

template<class T1,class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "(_y ,_m)" << endl;
	}
private:
	T1 _y;
	T2 _m;
};
int main()
{
	Date <int, int> s;
	return 0;
}


/*
template <typename T>

class Date
{
public:
	Date()
	{
		cout << "(_y, _m) "<< endl;
	}
private:
	T _y;
	T _m;

};

int main()
{
	Date<int> s;
	return 0;
}
/*
class Student
{
public:
	Student(int i ,char* n,char* s)
	{
		id = i;
		strcpy(name, n);
		strcpy(sex, s);
	}
	bool operator==(const Student& s)
	{
		if (id == s.id && !strcpy(name, s.name) && !strcpy(sex, s.sex))
			return true;
		return false;
	}
private:
	int id;
	char name[10];
	char sex[3];
};

template <typename Type>//泛化

bool IsEqul(Type &left, Type &right)
{
	return left == right;
}

template<>
bool IsEqul<char*>(char* &left, char* &right)  //特化
{
	if (strcmp(left, right) == 0)
		return true;
	return false;
}
int main()
{
	char *s1 = "asdfg";
	char *s2 = "asdfg";

	char arr1[] = "asdfg";
	char arr2[] = "asdfg";

	Student stu1(100, "hello", "男");
	Student stu2(101, "pater", "女"); 

	bool flag2 = IsEqul(stu1, stu2);
	cout << flag2 << endl;//0

	bool flag = IsEqul(s1, s2);
	cout << flag << endl;//1

	bool flag1 = IsEqul(arr1, arr2);//存在问题
	cout << flag1 << endl;//0

	cout << strcmp(s1, s2) << endl;//0  相等
	cout << strcmp(arr1, arr2) << endl;//0   


	return 0;
}


/*
template <typename Type>//类型参数

Type Max(Type a, Type b)
{
	return a > b ? a : b;
}

template <typename Type,int n>//非类型参数

class Arry
{
public:
	Arry()
	{
		memset(arr, 0, sizeof(Type)*n);
	}
private:
	Type arr[n];
};

int main()
{
	Max<int>(1, 3);
	Arry<int, 10> a;
	return 0;
}


/*
template <typename Type>
Type Add(Type a, Type b)
{
	return a + b;
}
int main()
{
	int tem = Add(6, 12);
	cout << "Add = " << tem << endl;
	return 0;
}*/