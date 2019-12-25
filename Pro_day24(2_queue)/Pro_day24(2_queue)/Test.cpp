#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<deque>
#include<list>
//using namespace std;
//Ϊʲôѡ��deque��Ϊstack��queue�ĵײ�Ĭ������
//stack��һ�ֺ���ȳ��������������ݽṹ�����ֻҪ����push_back()��pop_back()���������Խṹ��
//���� ����Ϊstack�ĵײ�����������vector��list�����ԣ�queue���Ƚ��ȳ��������������ݽṹ��ֻҪ���� push_back��pop_front���������Խṹ��
//��������Ϊqueue�ĵײ�����������list������STL�ж�stack�� queueĬ��ѡ��deque��Ϊ��ײ���������Ҫ����Ϊ��
//1. stack��queue����Ҫ����(���stack��queueû�е�����)��ֻ��Ҫ�ڹ̶���һ�˻������˽��в����� 
//2. ��stack��Ԫ������ʱ��deque��vector��Ч�ʸߣ�queue�е�Ԫ������ʱ��deque����Ч�ʸߣ������� ��ʹ���ʸ�

//���ڶ�����˫���������vector��������û���ṩͷɾ�Ľӿ�
//������list��Ϊ�ײ�ṹʵ��queue�Ĺ��ܡ�
namespace B
{
	template<typename T,class Con = list<T>>
	class Queue
	{
	public:
		Queue()
		{}
		void push(const T& x)//����
		{
			_ls.push_back(x);
		}
		void pop()//����
		{
			_ls.pop_front();
		}
		T& back()//��β
		{
			return _ls.back();
		}
		const T& back()const
		{
			return _ls.back();
		}
		T& front()//��ͷ
		{
			return _ls.front();
		}
		const T& front()const
		{
			return _ls.front();
		}
		size_t size()//�ӳ�
		{
			return _ls.size();
		}
		bool empty()//�п�
		{
			return _ls.empty();
		}
	private:
		Con _ls;
	};
}
int main()
{
	B::Queue<int> qe;

	return 0;
}

/*

//����Ҳ����˫�����Ϊ�ײ�ʵ�֡�
namespace A
{
	template<typename T,class Con = deque<T>>
	class Queue
	{
	public:
		Queue()
		{}
		void push(const T& x)//����
		{
			_de.push_back(x);
		}
		void pop()//����
		{
			_de.pop_front();
		}
		T& back()//��β
		{
			return _de.back();
		}
		const T& back()const
		{
			return _de.back();
		}
		T& front()//��ͷ
		{
			return _de.front();
		}
		const T& front()const
		{
			return _de.front();
		}
		size_t size()//�ӳ�
		{
			return _de.size();
		}
		bool empty()//�п�
		{
			return _de.empty();
		}

	private:
		Con _de;
	};
}

int main()
{
	A::Queue<int> q;
	q.push(1);
	q.push(3);
	q.push(5);
	q.push(7);
	q.push(9);
	cout << q.size() << endl;
	cout << q.front() << endl;
	q.pop();
	q.pop();
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.empty() << endl;
	cout << q.back() << endl;
	return 0;
}*/