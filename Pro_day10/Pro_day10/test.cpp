#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<list>
using namespace std;

void Printf(list<int>& ls)
{
	for (auto& e : ls)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> list1(arr, arr + sizeof(arr) / sizeof(int));
	list<int>::iterator it = list1.begin();
	//auto it = list1.begin();

	Printf(list1);
	while (it != list1.end())
	{
		//list1.erase(it++);
		it = list1.erase(it);// �ĵ�������ʧЧ
	}
	cout << endl;
	Printf(list1);
	return 0;
}

/*
int main()
{
	int str[] = { 1, 2, 3 };
	int arr[] = { 1, 3, 5, 6, 8, 9, 12 };
	list<int> list1(arr, arr + sizeof(arr) / sizeof(int));
	list<int> list2(str, str + sizeof(str) / sizeof(int));
	list<int>::iterator it = list1.begin();
	for (int i = 0; i < 3; i++)
		it++;
	cout << *it << endl;//6  ��ȡ������ĸ�λ��
	auto pos = it;

	list1.insert(pos, 4);//�ڵ��ĸ�λ��ǰ���� 4  �� 1 3 5 4 6 8 9 12��
	Printf(list1);

	list1.insert(pos, 6, 2);//��posǰ������6��2
	Printf(list1);

	list1.insert(pos, list2.begin(), list2.end());//��posǰ����list2;
	Printf(list1);

	list1.erase(pos);
	Printf(list1);

	list1.erase(list1.begin(), list1.end());
	Printf(list1);//ɾ������list1��

	return 0;
}

/*
int main()
{
	
	int arr[] = { 1, 2, 3 };
	list<int> list1(arr,arr+sizeof(arr)/sizeof(int));
	list1.push_back(4);//β��
	list1.push_back(5);//ͷ��
	list1.push_front(0);//
	Printf(list1);
	list1.pop_back();//βɾ
	list1.pop_front();//ͷɾ
	Printf(list1);
	return 0;
}


/*
int main()
{
	list<int> list1(6, 2);
	list1.front();
	list1.back();
	cout << list1.front() << endl;//ȡlist��ͷ  ����
	cout << list1.back() << endl;//ȡlist��β   ����
	return 0;
}


/*
int main()
{
	list<int> list1(6, 6);

	cout << list1.size()<< endl;//6
	cout << list1.empty()<< endl;//0

	list1.clear();

	cout << list1.size() << endl;//0
	cout << list1.empty() << endl;//1
	return 0;
}


/*
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> list1(arr, arr + sizeof(arr) / sizeof(int));

	list<int>::iterator it = list1.begin();//���������

	while (it != list1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int>::reverse_iterator rit = list1.rbegin();//���������
	while (rit != list1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	return 0;
}

/*
int main()
{
	list<int> list1;//list�Ĵ�����
	list<int> list2(2);
	list<int> list3(10, 6);
	list<int> list4(list3);
	int arr[] = { 46, 3, 4, 5, 4, 7, 9, 5 };
	list<int> list5(arr,arr+sizeof(arr)/sizeof(int));
	for (auto& e : list1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto& e : list2)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::iterator it1 = list3.begin();
	while (it1 != list3.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	list<int>::iterator it2 = list4.begin();
	while(it2 != list4.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	for (auto& e : list5)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

/*
int main()
{
	int arr []= { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> list1(arr, arr + sizeof(arr) / sizeof(int));//

	//list<int>::iterator it=list1.begin();
	//while (it != list1.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	for (auto e : list1)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
/*
int main()
{
	list<int> list1;
	for (int i = 0; i < 5; i++)
	{
		list1.push_back(i);
	}
	list<int> list2;
	for (int i = 5; i < 10; ++i)
	{
		list2.push_back(i);
	}

	list1.swap(list2);//��������list�����ֵ

	for (auto e : list1)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : list2)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

/*
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> list1(arr, arr + 10);

	list1.clear();
	cout << list1.empty() << endl;
	cout << list1.size() << endl;
	list<int>::const_iterator it = list1.begin();//������

	while (it != list1.end())//��׼���
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}

/*
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> list1(arr, arr + 10);
	list<int>::iterator it = list1.begin();

	for (auto e : list1)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
/*
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> list1(arr, arr + 10);
	list<int> list2(list1);
	list<int>::iterator it = list1.begin();
	while (it != list1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	list<int>::reverse_iterator rit = list2.rbegin();
	while (rit != list2.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	return 0;
}

/*
int main()
{
	list<int> list1(10, 6);
	for (auto e : list1)//c++11��forѭ�����
		cout << e << " ";
	cout << endl;
	return 0;
}

/*
int main()
{
	list<int> mylist1;
	list<int> mylist2(10);
	list<int> mylist3(10, 2);
	list<int> mylist4(mylist3.begin(), mylist3.end());
	list<int> mylist5(mylist3);

	list<int>::iterator it = mylist3.begin();
	while (it != mylist3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}*/