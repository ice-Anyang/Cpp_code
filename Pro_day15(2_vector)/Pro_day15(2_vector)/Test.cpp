#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

namespace Acc
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		vector() :start(nullptr), finish(nullptr), end_of_storage(nullptr)
		{}
		~vector()
		{
			delete[]start;
			start = finish = end_of_storage = nullptr;
		}

	public:
		size_t size()const
		{
			return finish - start;
		}
		size_t capacity()const
		{
			return end_of_storage-start;
		}
	public:
		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}
	public:
		T& operator[](size_t i)
		{
			assert(i < size());
			return start[i];
		}
		void push_back(const T& value)
		{
			insert(end(), value);
		}
	public:
		iterator insert(iterator pos, const T &x)
		{
			if (size() == capacity())
			{
				int new_capacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(new_capacity);
			}

			iterator p = finish;
			if (pos == nullptr)
				*finish = x;
			else
			{
				while (p != pos)
				{
					*p = *(p - 1);
					p--;
				}
				*pos = x;
			}
			finish++;
			return pos;
		}
	public:
		void resize(size_t n,const T& value = T())
		{
			if (n > size)
			{
				finish = start + n;
				return;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			iterator p = finish;
			finish = finish + n - size();
			while (p != finish)
			{
				*p = value;
				p++;
			}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tem = new T[n];
				int old_size = size();
				for (int i = 0; i < old_size; ++i)
				{
					tem[i] = start[i];
				}
				delete[]start;
				start = tem;
				finish = start + old_size;
				end_of_storage = start + n;
			}
		}

	public:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
}

int main()
{
	Acc::vector<int> v1;
	cout << "size = " << v1.size() << endl;
	cout << "capacity = " << v1.capacity() << endl;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	return 0;
}