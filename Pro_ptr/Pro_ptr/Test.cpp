#include<iostream>
#include<vector>
using namespace std;

/*
// ʹ��RAII˼����Ƶ�SmartPtr��
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}
		~SmartPtr()
	{
			if (_ptr)
				delete _ptr;
		}
private:
	T* _ptr;
};
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	// ��tmpָ��ί�и���sp������ʱ��ʦ�Ļ�˵��tmpָ������һ�����µ�Ů���ѣ���������㣬ֱ����go
	SmartPtr<int> sp(tmp);
	// _MergeSort(a, 0, n - 1, tmp);
	// ������账����һЩ�����߼�
	// ...
	vector<int> v(1000000000, 10);
}
int main()
{
	try {
		int a[5] = { 4, 5, 2, 3, 1 };
		MergeSort(a, 5);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}


/*
//�쳣
int main()
{
	try
	{
		int *p = new int[500000000];
	}
	catch (bad_alloc &e)
	{
		cout << e.what() << endl;
		return 0;
	}
	cout << "new OK." << endl;
	return 0;
}*/