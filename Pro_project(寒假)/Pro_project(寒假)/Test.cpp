#include<iostream>
#include<string>
using namespace std;
int main()
{
	short i = 65537;
	int j = int(i + 1);
	printf("i=%d,j=%d\n", i, j);
}
//int main()
//{
//	int a[] = { 2, 4, 6, 8, 0 };
//	int *p = a;
//	a[2] = *p++;
//	cout << a[2] << endl; 
//	return 0;
//}

//void main()
//{
//	int a = 1; int b = 2;
//	for (; a<8; a++)
//	{
//		b += a; a += 2;
//	}
//	//
//	printf("%d，%d\n", a, b);
//}
//
//int main()
//{
//	int a[] = { 2, 5, 6, 8 }, *p = a, i;
//	for (i = 0; i<4; i++)
//		a[i] = *(p++);
//	printf("%d\n", a[0]);
//	return 0;
//}
/*
int func(int i, int j)
{
	if (i <= 0 || j <= 0)
		return 1;
	return 2 * func(i - 3, j / 2);
}
int main()
{
	cout << func(15, 20) << endl;
	return 0;
}*/

//Day 10
//int main()
//{
//	char s[] = "abcdefgh", *p = s;
//	p += 3;
//	printf("%d\n", strlen
//		(strcpy(p, "ABCD")));
//}

//int main()
//{
//	int a, b;
//	scanf("%d,%d", &a, &b);
//	if (a > b)
//	{
//		a = b;
//		b = a;
//	}
//	else
//	{
//		a++;
//		b++;
//	}
//	printf("%d %d\n", a, b);
//	return 0;
//}


//Day 9
//int f(int n)
//{
//	if (4)
//		return f(n - 1) + n;
//	else
//		return n;
//}
//int main()
//{
//	cout << f(4) << endl;
//	return 0;
//}

//struct HAR{ 
//	int x, y; 
//	struct HAR *p;
//} h[2];
//void main()
//{
//	h[0].x = 1; h[0].y = 2;
//	h[1].x = 3; h[1].y = 4;
//	h[0].p = &h[1]; 
//	h[1].p = h;
//	printf("%d,%d \n", (h[0].p)->x, (h[1].p)->y);//3,2
//}

//int a, b;
//void fun()
//{
//	a = 100;
//	b = 200;
//} 
//int main()
//{
//	int a = 5, b = 7;
//	fun();
//	printf("% d % d / n", a, b);
//	return 0;
//}


//DAY 7

//int main()
//{
//	char str[] = "ABCD";
//	char *p = str;
//	printf("%d\n", *(p + 4));
//	return 0;
//}

//int main()
//{
//	char *p = "abcdefgh", *r;
//	long *q;
//	q = (long*)p;
//	q++;
//	r = (char*)q;
//	printf("%s\n", r);
//}

//DAY 6
//int main()
//{
//	int n = 2;
//	n += n -= n*n;
//	printf("%d", n);
//	return 0;
//}


//DAY 5
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; ++i)
//	{
//		for (j = 1; j <= i; ++j)
//		{
//			printf("%d * %d = %d  ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}




//DAY 4
//int main()
//{
//	int b = 0;
//	switch(1)
//	{
//	case 1: b = 30;
//	case 2: b = 20;
//	case 3: b = 16;
//	default: b = 0;
//	}
//	cout << b << endl;
//}

//int main()
//{
//	float x[8] = { 0 };
//	cout << sizeof(x) << endl;
//	return 0;
//}




//DAY 3

//int main()
//{
//	int a = 0;
//	int i = 0;
//	while (i < 20)
//	{
//		for (;;)
//		{
//			if ((i % 10) == 0)
//				break;
//			else
//				i--;
//		}
//		i+=11; a+=i;
//	}
//	printf("%d\n", a);
//	return 0;
//}

//5、判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。OJ链接
//class Solution {
//public:
//	bool isPalindrome(int x)
//	{
//		if (x<0)
//			return false;
//		if (x / 10 == 0)
//			return false;
//		int num = x;
//		long long cur = 0;
//		while (num != 0)
//		{
//			cur = cur * 10 + num % 10;
//			num = num / 10;
//		}
//		return x == cur;
//	}
//};
//DAY2
//int main()
//{
//	int a = 10;
//	int b = 10;
//	a = b = ++b;
//	printf("%d ,%d", a, b);
//	return 0;
//}

//4.给定一个数组 nums 和一个值 val ，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成
//class Solution {
//public:
//	int removeElement(vector<int>& nums, int val)
//	{
//		if (nums.size() == 0)
//			return 0;
//		int j = 0;
//		/*for(int i = 0 ; i<nums.size();++i)
//		{
//		if(nums[i]!=val)
//		{
//		nums[j]=nums[i];
//		j++;
//		}
//		}*/
//		for (auto &num : nums)
//		{
//			if (num != val)
//			{
//				nums[j] = num;
//				j++;
//			}
//		}
//		return j;
//	}
//};

//5.给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它
//将会被按顺序插入的位置, 你可以假设数组中无重复元素
//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target)
//	{
//		/* int left = 0;
//		int right = nums.size()-1;
//		int mid = 0;
//		while(left < right)
//		{
//		mid = left + (right - left)/2;
//		if(nums[mid]<target)
//		left = mid++;
//		if(nums[mid]>target)
//		right = mid--;
//		if(nums[mid]==target)
//		return mid;
//		}
//		if(target <= nums[left])
//		return left;
//		else
//		return left+1;*/
//		if (target<nums[0])
//			return 0;
//		if (nums[nums.size() - 1]<target)
//			return nums.size();
//		int tem;
//		for (int i = 0; i<nums.size() - 1; i++)
//		{
//			if (nums[i] == target)
//				return i;
//			if (nums[i]<target&&target<nums[i + 1])
//				tem = i + 1;
//		}
//		if (nums[nums.size() - 1] == target)
//			return nums.size() - 1;
//		return tem;
//	}
//};




//DAY 1
//4.实现函数 ToLowerCase() ，该函数接收一个字符串参数 str ，并将该字符串中的大写字母转换成小写字母，
//之后返回新的字符串
//class Solution {
//public:
//	string toLowerCase(string str)
//	{
//		/*for(auto &e : str)
//		{
//		e |= 32;
//		}
//		return str;*/
//		int len = str.size();
//		for (int i = 0; i < len; ++i)
//		{
//			if (str[i] <= 'Z' && str[i] >= 'A')
//			{
//				str[i] = str[i] + 32;
//			}
//		}
//		return str;
//
//	}
//
//};

//5.给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
//class Solution {
//public:
//	void rotate(vector<int>& nums, int k)
//	{
//		/* k = k%nums.size();
//		reverse(nums.begin(),nums.begin()+nums.size()-k);
//		reverse(nums.begin()+nums.size()-k,nums.end());
//		reverse(nums.begin(),nums.end());*/
//		vector<int> newvec(nums.size(), 0);
//		for (int i = 0; i<nums.size(); i++)
//			newvec[(i + k) % nums.size()] = nums[i];
//		for (int i = 0; i<nums.size(); i++)
//			nums[i] = newvec[i];
//	}
//};

//2
//int main()
//{
//	int i = 10;
//	int j = 10;
//	int k = 3;
//	k *= i + j;
//	printf("%d", k);
//	return 0;
//}

//1.
//int main()
//{
//	int sum = 0;
//	int num = 0;
//	num = sum = 7;
//	sum = num++;
//	sum++;
//	num++;
//	printf("%d %d", sum, num);
//
//	return 0;
//}

/*
int main()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << i << "*" << j<< "=" << i*j;
		}
		cout << endl;
	}
	return 0;
}*/