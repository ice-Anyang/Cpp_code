#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{

	return 0;
}


/*
int main()
{
	int i = 10;//吃了十天
	int j = 1;
	int sum = 1;
	while (i > 0)
	{
		sum = 2 * (sum+j);
		i--;
	}
	printf("猴子第一天摘的桃子：%d\n", sum);
	return 0;
}


/*
/*
int main()
{
	string s;
	s.reserve(100);
	for (int i = 0; i < 100; i++)
	{
		cout << i << ":" << s.capacity() << endl;
	}
	return 0;
}



/*
int main()
{
	string s("Hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	return 0;
}


/*
int main()
{
	string s1("hellow");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	
	s1.resize(100);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.reserve(200);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	return 0;
}
/*
class Solution {
public:
	int firstUniqChar(string s)
	{
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i<size; i++)
			count[s[i]] += 1;

		for (int i = 0; i<size; i++)
		if (1 == count[s[i]])
			return i;
		return -1;
	}
};
int main()
{
	string s;
	getline(cin, s);
	int st = s.firstUniqChar(s);
	cout << st << endl;
	return 0;
}
/*
int main()
{
	string s;
	//cin>>s;  //' '  \n
	getline(cin, s);  //  \n  jfla falfjla 
	cout << s << endl;
	return 0;
}

/*
int main()
{
	string s1;
	string s2("asdfgh");
	string s3(s2);

	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << s3 << endl;

	s2.resize(10);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << s3 << endl;

	s2.reserve(100);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << s3 << endl;
	return 0;
}*/