#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct complex{
	float e1;
	float e2;
}complex;
complex initcomplex(float x, float y)
{
	complex z1;
	z1.e1 = x;
	z1.e2 = y;
	return z1;
}
void addcomplex(complex *z, complex z1, complex z2)
{
	z->e1 = z1.e1 + z2.e1;
	z->e2 = z1.e2 + z2.e2;
}
void minuscomplex(complex* z, complex z1, complex z2)
{
	z->e1 = z1.e1 - z2.e1;
	z->e2 = z1.e2 - z2.e2;
}
void mulcomplex(complex* z, complex z1, complex z2)
{
	float a, b, c, d;
	a = z1.e1*z2.e1;
	b = z1.e2*z2.e2;
	c = z1.e1*z2.e2;
	d = z1.e2*z2.e1;
	z->e1 = a - b;
	z->e2 = c + d;
}
void ericomplex(complex* z, complex z1, complex z2)
{
	float a, b, c, d, e, f, g, h, t;
	a = z1.e1*z2.e1;
	b = z1.e2*z2.e2;
	c = z1.e1*z2.e2;
	d = z1.e2*z2.e1;
	e = a + b;
	f = d - c;
	g = z2.e1*z2.e1;
	h = z2.e2*z2.e2;
	t = g + h;
	z->e1 = e / t;
	z->e2 = f / t;
}
void outputcomplex(complex z)
{
	if ((z.e2>0) && (z.e1 != 0))
	{
		printf("%.3f+%.3fi\n", z.e1, z.e2);
	}
	if ((z.e2<0) && (z.e1 != 0))
	{
		printf("%.3f%.3fi\n", z.e1, z.e2);
	}
	if ((z.e2 == 0) && (z.e1 != 0))
	{
		printf("%.3f\n", z.e1);
	}
	if ((z.e1 == 0) && (z.e2 != 0))
	{
		printf("%.3fi\n", z.e2);
	}
	if ((z.e1 == 0) && (z.e2 == 0))
	{
		printf("0\n");
	}
}
int main()
{
	complex z1, z2, z;
	z = initcomplex(0, 0);
	float x, y;
	printf("请输入第一个复数:");
	scanf("%f%f", &x, &y);
	z1 = initcomplex(x, y);
	outputcomplex(z1);
	printf("请输入第二个复数:");
	scanf("%f%f", &x, &y);
	z2 = initcomplex(x, y);
	outputcomplex(z2);
	printf("两个复数相加结果");
	addcomplex(&z, z1, z2);
	outputcomplex(z);
	printf("两个复数相乘结果");
	mulcomplex(&z, z1, z2);
	outputcomplex(z);
	printf("两个复数相减结果");
	minuscomplex(&z, z1, z2);
	outputcomplex(z);
	printf("两个复数相除结果");
	ericomplex(&z, z1, z2);
	outputcomplex(z);
	return 0;
}
