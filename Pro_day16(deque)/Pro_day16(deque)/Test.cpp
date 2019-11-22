#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<deque>
using namespace std;

int main()
{
	//deque������ʽ�����бȽϼ��ߣ���Ϊ���ֻ�Ǽ򵥵Ĵ洢Ԫ�أ�ʹ��vector���ɣ������Ԫ������λ�ý� �в������ɾ�������Ƚ϶࣬ʹ��list���ɣ�����һ�����ȥʹ��deque��deque����Ӧ�ã�����������Ϊ ��׼����stack��queue�ĵײ�ṹ(���½�
	int arr[] = { 6, 1, 3, 1, 4, 2, 2, 7, 8, 9, 10 };
	deque<int> de1(arr, arr + sizeof(arr) / sizeof(int));
	deque<int> de2(6, 2);
	de1.swap(de2);

	return 0;
}
/*
int main()
{
	int arr[] = { 6, 1, 3, 1, 4, 2, 2, 7, 8, 9, 14 };
	int n = sizeof(arr) / sizeof(int);
	deque<int> de(arr, arr + n);

	de.erase(de.begin());
	for (auto& e : de)
	{
		cout << e << " ";
	}
	cout << endl;
	deque<int>::iterator it = de.begin();
	it = it + 9;
	de.erase(it);
	for (auto& e : de)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << de[0] << endl;
	return 0;
}

/*
int main()
{
	int arr[] = { 6, 1, 3, 1, 4, 2, 2, 7, 8, 9, 14 };
	int n = sizeof(arr) / sizeof(int);
	deque<int> de(arr, arr + n);
	de.insert(de.begin(),4);
	deque<int>::iterator it = de.begin();
	it=it+4;
	de.insert(it, 23);
	for (auto& e : de)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << de.front() << endl;
	cout << de[4] << endl;

	//deque<int>::reverse_iterator rit = de.rbegin();
	//rit = rit - 4;
	//de.insert(rit, 100);//����
	return 0;
}

/*
int main()
{
	int arr[] = { 6, 1, 3, 1, 4, 2, 2, 7, 8, 9, 14 };
	int n = sizeof(arr) / sizeof(int);
	deque<int> de(arr, arr + n);
	de.push_back(12);
	de.push_back(14);
	de.push_front(22);
	de.push_front(6);
	
	for (auto& e : de)
	{
		cout << e << " ";
	}
	cout << endl;

	de.pop_back();
	de.pop_front();

	for (auto& e : de)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

/*
int main()
{
	int arr[] = { 6, 1, 3, 1, 4, 2, 2, 7, 8, 9, 10 };
	int n = sizeof(arr) / sizeof(int);
	deque<int> de1(arr, arr + sizeof(arr) / sizeof(int));
	for (int i = 0; i < n; i++)
	{
		cout << de1[i] << " ";
	}
	cout << endl;
	cout << de1[2] << endl;//������
	cout << de1.front() << endl;//ȡͷ
	cout << de1.back() << endl;//ȡβ
	return 0;
}


/*
int main()
{
	int arr[] = { 6, 1, 3, 1, 4, 2, 2, 7, 8, 9, 10 };
	deque<int> de1(arr, arr + sizeof(arr) / sizeof(int));
	cout << "size = " << de1.size() << endl;

	cout << de1.empty() << endl;

	de1.resize(20);//�ı��С
	cout << "size = " << de1.size() << endl;

	de1.clear();//����deque
	cout << de1.empty() << endl;//�п�

	return 0;
}


//cbegin()��cend()  ���ܸı�deque�����ݡ�
//crbegin()��crend()   ���ܸı�deque�����ݡ�


/*
int main()
{
	int arr[] = { 6, 1, 3, 1, 4, 2, 2, 7, 8, 9, 10 };
	deque<int> de1(arr, arr + sizeof(arr) / sizeof(int));
	deque<int>::iterator it = de1.begin();
	while (it != de1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	deque<int>::reverse_iterator rit = de1.rbegin();
	while (rit != de1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout <<endl;
	return 0;
}

/*
int main()
{
	int arr[] = { 6, 1, 3, 1, 4, 2, 2, 7, 8, 9, 10 };
	deque<int> de1(arr, arr + sizeof(arr) / sizeof(int));
	deque<int> de2 = de1;//fuzhi
	deque<int> de3(de1);//kaobei
	cout << "size = " << de1.size() <<endl;
	for (auto& e : de3)//C11����
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

/*
int main()
{
	deque<int> de1;
	deque<int> de2(6, 2);
	cout << "size = " << de1.size() << endl;
	cout << "size = " << de2.size() << endl;

	deque<int>::iterator it = de2.begin();//����������
	while (it != de2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto& e : de2)//C11����
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}*/