#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;//��׼�⺯�������ռ�

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
	//int& b = a;//����
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
//��ͨ�����ռ�
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
	namespace N3//�����ռ����Ƕ��
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
void way();//ʵ�ִʷ�����������
int main()
{
	char a;
	while (1)
	{
		way();
		cout << "�Ƿ��������" << endl;
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
	cout << "�����ַ���" << endl;
	getline(cin, s);//getline��������ʹ���뵽stringʱ������ո��ʹ���������޷�¼�뵽s�У������ܻس���������
	for (int i = 1; i <= 6; i++)
	{
		auto found = s.find(key[i]);//find������Ѱs�ַ�������key[i]����ϵ��ַ��������ҵ��򷵻ظ��ַ�����s������ĸ���±�
		if (found != string::npos)//nposΪstring���еı�������-1����found������npos���ʾ�ҵ�s����key[i]����ϵĹؼ���
		{
			int lon = key[i].length();//�ó��ַ�������
			for (int j = 0; j < lon; j++, found++)
				cout << s[found];
			cout << "�ֱ���Ϊ" << i << endl;
		}
	}
}*/