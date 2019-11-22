#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<deque>
using namespace std;

int main()
{
	//deque在序列式容器中比较鸡肋，因为如果只是简单的存储元素，使用vector即可，如果对元素任意位置进 行插入或者删除操作比较多，使用list即可，所以一般很少去使用deque。deque最大的应用，就是用其作为 标准库中stack和queue的底层结构(见下节
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
	//de.insert(rit, 100);//错误
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
	cout << de1[2] << endl;//第三个
	cout << de1.front() << endl;//取头
	cout << de1.back() << endl;//取尾
	return 0;
}


/*
int main()
{
	int arr[] = { 6, 1, 3, 1, 4, 2, 2, 7, 8, 9, 10 };
	deque<int> de1(arr, arr + sizeof(arr) / sizeof(int));
	cout << "size = " << de1.size() << endl;

	cout << de1.empty() << endl;

	de1.resize(20);//改变大小
	cout << "size = " << de1.size() << endl;

	de1.clear();//清理deque
	cout << de1.empty() << endl;//判空

	return 0;
}


//cbegin()和cend()  不能改变deque的内容。
//crbegin()和crend()   不能改变deque的内容。


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
	for (auto& e : de3)//C11遍历
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

	deque<int>::iterator it = de2.begin();//迭代器遍历
	while (it != de2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto& e : de2)//C11遍历
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}*/