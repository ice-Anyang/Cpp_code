#include<iostream>
#include<vector>
#include<set>
#include<array>
#include<list>//˫��ѭ������ 
#include<forward_list>//����ѭ��������
#include<map>
using namespace std;



class Test
{
public:
	Test() = delete;
	Test(int data) : m_data(data)
	{}
	Test(const Test &) = delete;
private:
	int m_data;
};
void main()
{
	//Test t0;
	Test t(1);
	//Test t1 = t;
}


/*
int main()
{
	list<int> ls{ 1, 3, 2, 5, 4, 6 };
	ls.push_back(7);
	ls.push_back(8);
	for (auto&e : ls)
		cout << e ;
	cout <<endl;

	forward_list<int> fl;
	fl.push_front(1);
	fl.push_front(2);
	fl.push_front(3);
	fl.push_front(4);
	fl.push_front(5);
	fl.push_front(6);
	auto pos = find(fl.begin(), fl.end(), 1);
	fl.insert_after(pos, 8);
	forward_list<int>::iterator it1 = fl.begin();
	//--it1;
	while (it1 != fl.end())
	{
		cout << *it1 << "-->";
		++it1;
	}
	cout << "Over" << endl;
	return 0;
}


/*
int main()
{
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//ar[0];
	//*(ar+offset)
	int n = sizeof(ar) / sizeof(ar[0]);
	for (auto& e : ar)
	{
		cout << e << " ";
	}
	cout << endl;

	array<int, 10> br = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i<11; ++i)
		cout << br[i] << " ";
	cout << endl;
	return 0;
}



/*
void* GetMemory(size_t size)
{
	return malloc(size);
}
int main()
{
	// ���û�д��������Ƶ�����������
	cout << typeid(decltype(GetMemory)).name() << endl;
	// ����������б��Ƶ����Ǻ�������ֵ������,ע�⣺�˴�ֻ�����ݣ�����ִ�к���
	cout << typeid(decltype(GetMemory(0))).name() << endl;
	return 0;
}

/*
int main()
{
	int a = 10;
	int b = 20;
	// ��decltype����a+b��ʵ�����ͣ���Ϊ����c������
	decltype(a + b) c;
	//������a+b��typeid(a+b).name()��Ϊc������
	//typeid(a).name() c;
	cout << typeid(a + b).name() << endl;

	cout << typeid(c).name() << endl;
	return 0;
}

/*
int main()
{
	set<int> st{ 1, 2, 8, 4, 6, 7 };
	//set<int>::iterator it = st.begin();
	//set<int>::iterator its = st.end();
	auto it = st.begin();//ͨ��auto �Ƶ�it������
	while (it!=st.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

/*
int main()
{
	short a = 12324;
	short b = 23456;
	short c = a + b;//�ַ��ض�
	cout << c << endl;
	cout << typeid(c).name() << endl;

	auto d = a + b;
	cout << d << endl;
	cout << typeid(d).name() << endl;

	return 0;
}

/*
int main()
{
	short a = 12324;
	short b = 23456;
	short c = a + b;//�ַ��ض�
	cout << c << endl;

}


/*
#include <initializer_list>
template<class T>
class Vector {
public:
	// ...
	Vector(initializer_list<T> l) : _capacity(l.size()), _size(0)
	{
		_array = new T[_capacity];
		for (auto e : l)
			_array[_size++] = e;
	}
	Vector<T>& operator=(initializer_list<T> l) {
		delete[] _array;
		size_t i = 0;
		for (auto e : l)
			_array[i++] = e;
		return *this;
	}
	// ...
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};



/*

class Point
{
public:
	Point(int a, int b) :_a(a), _b(b)
	{
		cout << "Point::Point() "<< endl;
	}
private:
	int _a;
	int _b;
};

int main()
{
	Point p{ 1, 2 };
	return 0;
}


/*
int main()
{
	int a{ 9 };
	int b = 4;
	cout << a << endl;
	return 0;
}

/*
int main()
{
	//C++11�������ô�����������б�(��ʼ���б�)��ʹ�÷�Χ��ʹ����������е��������ͺ��û��Զ�
	//������ͣ�ʹ�ó�ʼ���б�ʱ������ӵȺ�(= )��Ҳ�ɲ����
	vector<int> vt{ 1, 2, 3, 4, 5, 6 };
	set<int> st = { 4, 5, 6, 7, 83, 3 };
	map<int, int> mp = { { 1, 2 }, { 2, 3 } };
//	int arr[3] = { 1, 2, 3 };
//	for (auto &e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;

	return 0;
}*/
