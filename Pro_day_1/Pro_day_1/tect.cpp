#include<iostream>
using namespace std;

//�����в���
//��������أ����������һ����Ϊ����ֻ������Ԫ�������һ������Ϊ���󣬿�������ԪҲ�����ó�Ա������
//��Ԫ������(1)���Է���˽�г�Ա�������˷�װ��
//         ��2����Ԫ����������const ���� 
//         ��3����Ԫ��������������κεط��������������޶������Ρ�
//			(4)һ�����������Ƕ�������Ԫ����
//			(5)��Ԫ�����ĵ��úͲ�ͬ�����ĵ��ú�ԭ����ͬ��
//��Ԫ������

class Int
{
public:
	Int operator++();// ++a
	Int operator++();// a++

private:
	long m_i;
};
int main()
{

	return 0;
}
/*
class	Complex
{
public:
	Complex() : m_real(0), m_imag(0)//���캯��
	{}
	~Complex()//��������
	{}

protected:

private:
	int m_real;
	int m_imag;

};
int main(int argc , char* argv[])
{

	return 0;
}

//namespace N1
//{
//	int c = 0;
//	int Add(int a, int b)
//	{
//		return a + b;
//	}	
//}
//
//namespace N2
//{
//	int c = 2;
//	int Add(int a, int b)
//	{
//		return a*b;
//	}
//}
//
//int main()
//{
//	using namespace N1;
//	int ret = Add(3, 5);
//	printf("ret = %d\n", ret);
//	printf("c = %d\n", c);
//	system("pause");
//	return 0;
//}

//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data()" << endl;
//	}
//	~Data()
//	{
//		cout << "~Data()" << endl;
//	}
//
//private:
//	int year;
//	int month;
//	int day;
//};
//
//int main()
//{
//	Data t;
//}
*/