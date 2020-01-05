#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char a = 97;
	char c;
	c = 'a' + '8' - '3';
	printf("%d\n", c);
	printf("%c\n", c);
	return 0;
}
//struct student
//{
//	long sno;
//	char name[10];
//	float score[3];
//};
//
//struct student* fun(struct student* a)
//{
//	int i;
//	a->sno = 1002;
//	strcpy(a->name, "LiSi");
//	for (i = 0; i < 3; ++i)
//	{
//		a->score[i]+=1;
//	}
//	return a;
//}
//int main()
//{
//
//	return 0;
//}
//
//char fun(char ch)
//{
//	if (ch >= '0'&&ch <= '9')
//		return '9' - (ch - '0');
//	return 0;
//}
//
//int main()
//{
//	char c1, c2;
//	printf("........: \n");
//	c1 = '2';
//	c2 = fun(c1);
//	printf("%c\n", c2);
//	return 0;
//}

//int fun(int n)
//{
//	int x = 0;
//	int t = 0;
//	while (n)
//	{
//		t = n % 10;
//		if (t % 2 == 0)
//		{
//			x = 10 * x + t;
//		}
//		n = n / 10;
//	}
//	return x;
//}
//
//int main()
//{
//	int a = 4567;
//
//	int i = fun(4567);
//	printf("%d", i);
//	return 0;
//}

//void fun(int m, int *k, int xx[])
//{
//	int i, j, q = 0, t = 0;
//	for (i = 2; i<m; i++)
//	{
//		for (j = 2; j<i; j++)
//		{
//			if (i%j == 0)
//				xx[q++] = i;
//			t++;
//			break;
//		}
//	}
//	*k = t;
//}
//
//int main()
//{
//	int m, n, zz[100];
//	void NONO();
//	printf("\nPlease enter an integer number between 10 and 100: ");
//	scanf("%d", &n);
//	fun(n, &m, zz);
//	printf("\n\nThere are %d non-prime numbers less than %d:", m, n);
//	for (n = 0; n < m; n++)
//		printf("\n  %4d", zz[n]);
//	NONO();
//}

//int fun(int x)
//{
//	int m = x, k = 1;
//	if (x < 1 || x > 100) return 0; // 题目要求
//	while (m) {
//		k *= 10;
//		m /= 10;
//	}
//	return (x * x % k == x);
//}

//double fun(int n, int x)
//{
//	int k = 1;
//	int i, j;
//	double sum = 0;
//
//	for (i = n; i >= 1; --i)
//	{
//		for (j = 1; j <= i; ++j)
//		{
//			k = k * j;
//		}
//		sum += 1.0 * pow(x, i) / k;
//		k = 1;
//	}
//	return sum;
//}
//void main()
//{
//	int n = 0, x = 0;
//	printf("please input two numbers:");
//	scanf("%d, %d", &n, &x);
//	printf("sum=%.2lf \n", fun(n, x) + 1);
//}

//double fun(double x, int n)
//{
//	double sum = 1.0, a = 1.0;
//	int i, j = 1;
//	for (i = 1; i <= n; i++)
//	{
//		a *= x;
//		j *= i;
//		sum = sum + a / j;
//	}
//	return sum;
//}
//int main()
//{
//	double x;
//	int n;
//	scanf("%lf%d", &x, &n);
//	printf("%lf\n", fun(x, n));
//	return 0;
//}
//void fun(int a[], int b[], int c[], int n){
//
//	for (int k = 0; k < n; k++){
//
//		c[k] = a[k] - b[n - 1 - k] * b[n - 1 - k];
//
//	}
//}