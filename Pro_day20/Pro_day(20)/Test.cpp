#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

/*
void BubbleSort(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0; 
		for (size_t i = 1; i < end; ++i)    
		{ 
			if (a[i - 1] > a[i])        
			{ 
				swap(&a[i - 1], &a[i]);
				exchange = 1; 
			} 
		}

		if (exchange == 0)        break;
	}
}



/*
void Print()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%d * %d = %d  ", i, j, i*j);
		}
		printf("\n");
	}
}
int main()
{
	Print();
	return 0;
}*/