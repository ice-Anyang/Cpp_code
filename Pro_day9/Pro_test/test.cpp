#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;//标准库函数命名空间

int main()
{
	int a = 6;
	auto b = &a;
	auto* c = &a;
	auto& d = a;
	cout << typeid(b).name() << endl;//int*
	cout << typeid(c).name() << endl;//int*
	cout << typeid(d).name() << endl;//int
	return 0;
}


/*
int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = a;
	cout << typeid(b).name() << endl;//int 
	cout << typeid(c).name() << endl;//char
	cout << typeid(d).name() << endl;//int
	return 0;
}


/*
int main()
{
	//const int a = 6;
	//int& b = a;//错误
	int a = 6;
	const int& b = a;
	cout << a << endl;
	return 0;
}

int main()
{
	int a = 3;
	int& b = a;
	b = 6;
	cout << a << endl;//6
	return 0;
}

int main()
{
	int a = 0;
	cin >> a;
	cout << a << endl;
	return 0;
}


/*
//普通命名空间
namespace N1
{
	int c = 0;
	int fun(int a, int b)
	{
		return a + b;
	}
}
namespace N2
{
	namespace N3//命名空间可以嵌套
	{
		int c = 4;
		int fun(int a, int b)
		{
			return a - b;
		}
	}
	int c = 1;
	int fun(int a, int b)
	{
		return a*b;
	}
}
int main()
{
	printf("%d\n", N1::c);
	printf("%d\n", N1::fun(2, 3));
	printf("%d\n", N2::c);
	printf("%d\n", N2::fun(2, 3));
	printf("%d\n", N2::N3::c);
	printf("%d\n", N2::N3::fun(2,3));
	return 0;
}
/*
#include<iostream>
#include<string>
using namespace std;
string key[] = { "", "begin", "if", "then", "while", "do", "end" };
void way();//实现词法分析器功能
int main()
{
	char a;
	while (1)
	{
		way();
		cout << "是否继续输入" << endl;
		cin >> a;
		getchar();
		if (a == 'n' || a == 'N')
			break;
	}
	system("pause");
	return 0;
}
void way()
{
	string s;
	cout << "输入字符串" << endl;
	getline(cin, s);//getline函数可以使输入到string时不会因空格而使后面内容无法录入到s中，仅接受回车结束输入
	for (int i = 1; i <= 6; i++)
	{
		auto found = s.find(key[i]);//find函数找寻s字符串中与key[i]相符合的字符串，若找到则返回该字符串在s中首字母的下标
		if (found != string::npos)//npos为string类中的变量，即-1；若found不等于npos则表示找到s中与key[i]相符合的关键字
		{
			int lon = key[i].length();//得出字符串长度
			for (int j = 0; j < lon; j++, found++)
				cout << s[found];
			cout << "种别码为" << i << endl;
		}
	}
}*/