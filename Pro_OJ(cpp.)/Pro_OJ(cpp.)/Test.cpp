#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<thread>
using namespace std;




/*
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n)
	{
		// write code here
		int Max = 0;
		int pos = 0;
		for (int i = 0; i<n; ++i)
		{
			if (Max < A[i])
			{
				Max = A[i];
				pos = i;
			}
		}
		if (pos == 0)
			return A[0] - A[n - 1];
		if (pos == n - 1)
			return A[n - 1] - A[0];
		int leftMax = A[pos] - A[0];
		int rightMax = A[pos] - A[n - 1];
		return leftMax > rightMax ? leftMax : rightMax;
	}
};

/*
int main(){
	int n;
	while (cin >> n)
	{
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int k, d;
		cin >> k >> d;
		vector<vector<long long>> dp_max(n, vector<long long>(k + 1, 0));
		vector<vector<long long>> dp_min(n, vector<long long>(k + 1, 0));
		for (int i = 0; i < n; i++)
		{
			dp_max[i][1] = a[i];
			dp_min[i][1] = a[i];
		}
		for (int i = 0; i < n; i++){
			for (int j = 2; j <= k; j++){
				for (int m = max(0, i - d); m <= i - 1; m++){
					dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i]));
					dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
				}
			}
		}
		long long max_value = dp_max[k - 1][k];
		for (int i = k; i < n; i++)
		{
			max_value = max(max_value, dp_max[i][k]);
		}
		cout << max_value << endl;
	}
	return 0;
}



/*
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

}

/*
int main()
{
	std::list<int> l1; // 构造空的l1
	std::list<int> l2(4, 100); // l2中放4个值为100的元素
	std::list<int> l3(l2.begin(), l2.end()); // 用l2的[begin(), end()）左闭右开的区间构造l3
	std::list<int> l4(l3); // 用l3拷贝构造l4
	// 以数组为迭代器区间构造l5
	int array[] = { 16, 2, 77, 29 };
	std::list<int> l5(array, array + sizeof(array) / sizeof(int));//区间构造
	// 用迭代器方式打印l5中的元素
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;

	for (auto& e : l5)
		std::cout << e << " ";
	std::cout << endl;
	return 0;
}
/*
int main()
{
	string str;
	while (cin >> str)
	{
		int flag = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] == '_')
			{
				str.erase(str.begin() + i);
				flag = 1;
				i--;
			}
			else if (flag == 1)
			{
				str[i] = toupper(str[i]);//转换大写
				cout << str[i];
				flag = 0;
			}
			else
			{
				cout << str[i];
			}
		}
		cout << endl;
	}

}

/*
//走迷宫
//求字符串里的数字
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int a[10][10] = { 0 };//记录格子状态，0代表没有走过
char str[10][10];//记录迷宫
int bfs(int x0, int y0)
{
	queue<pair<int, int> > q;//存储格子坐标的队列
	pair<int, int> p;
	int x, y;
	q.push(make_pair(x0, y0));
	while (1)
	{
		p = q.front();
		x = p.first;
		y = p.second;
		if (x == 9 && y == 8)//走到终点就退出循环
			return a[9][8];
		
		//下面是4个if语句，分别对应格子的上、下、左、右四个相邻的格子
		//如果这个格子符合条件(坐标不越界，同时不是'#'，并且之前没有走过)
		//就把它放入队列。这里需要注意的是，队列先进先出就保证了离出口近的
		//格子总是比离出口远的格子先处理，也就是说只有当广度(离出口距离比如2)
		//的所有格子都pop()出队列，广度为3的格子才变为队首元素。就这样一点点
		//增加广度，直到走到出口。
		//当然你也可以用一个for循环替代这里的4个if，我想写的详细点
		if ((x - 1) >= 0 && (x - 1) <= 9 && y >= 0 && y <= 9 && a[x - 1][y] == 0 && str[x - 1][y] != '#')
		{
			a[x - 1][y] = a[x][y] + 1;
			q.push(make_pair(x - 1, y));
		}
		if ((x + 1) >= 0 && (x + 1) <= 9 && y >= 0 && y <= 9 && a[x + 1][y] == 0 && str[x + 1][y] != '#')
		{
			a[x + 1][y] = a[x][y] + 1;
			q.push(make_pair(x + 1, y));
		}
		if (x >= 0 && x <= 9 && (y - 1) >= 0 && (y - 1) <= 9 && a[x][y - 1] == 0 && str[x][y - 1] != '#')
		{
			a[x][y - 1] = a[x][y] + 1;
			q.push(make_pair(x, y - 1));
		}
		if (x >= 0 && x <= 9 && (y + 1) >= 0 && (y + 1) <= 9 && a[x][y + 1] == 0 && str[x][y + 1] != '#')
		{
			a[x][y + 1] = a[x][y] + 1;
			q.push(make_pair(x, y + 1));
		}
		q.pop();//判断完上下左右4个格子后该格子应该出队
	}
}


int main()
{
	char c;
	while (scanf("%c", &c))
	{
		str[0][0] = c;
		for (int i = 1; i<10; i++)
		{
			scanf("%c", &c);
			str[0][i] = c;
		}
		getchar();//吃掉末尾的换行符
		for (int i = 1; i<10; i++)
		{
			for (int j = 0; j<10; j++)
			{
				scanf("%c", &c);
				str[i][j] = c;
			}
			getchar();//吃掉末尾的换行符
		}
		printf("%d\n", bfs(0, 1));
		memset(a, 0, sizeof(a));//初始化全局变量a数组
	}
	return 0;
}
//下面是DFS解法，个人认为没有BFS效率高
//DFS深度优先搜索就是一条道走到黑，然后再回来，比原值小就更新原值
//所以遍历次数可能更多一点，另外DFS使用了递归
//#include<iostream>
//#include<string.h>
//using namespace std;
//int a[10][10] = { 0 };
//char str[10][10];
//int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
//void dfs(int x, int y)
//{
//	for (int i = 0; i<4; i++)
//	{
//		int m = x + dir[i][0];
//		int n = y + dir[i][1];
//		if (m >= 0 && m <= 9 && n >= 0 && n <= 9 && str[m][n] != '#')
//		{
//			if ((a[m][n] == 0) || (a[x][y] + 1)<a[m][n])
//			{
//				a[m][n] = a[x][y] + 1;
//				dfs(m, n);
//			}
//		}
//	}
//
//}
//int main()
//{
//	//  freopen("input.txt","r",stdin);
//	char c;
//	while (~scanf("%c", &c))
//	{
//		str[0][0] = c;
//		for (int i = 1; i<10; i++)
//		{
//			scanf("%c", &c);
//			str[0][i] = c;
//		}
//		getchar();
//		for (int i = 1; i<10; i++)
//		{
//			for (int j = 0; j<10; j++)
//			{
//				scanf("%c", &c);
//				str[i][j] = c;
//			}
//			getchar();
//		}
//		dfs(0, 1);
//		printf("%d\n", a[9][8]);
//		memset(a, 0, sizeof(a));
//	}
//	return 0;



/*
//求字符串里的数字
int main()
{
	string str;
	while (getline(cin, str))
	{
		int n = str.size();
		for (int i = 0; i < n; ++i)
		{
			if (str[i] >= '0'&&str[i] <= '9')
				cout << str[i];
		}
		cout << endl;
	}
	return 0;
}
/*
//f(n)=f(n-1)+f(n-2)
int main()
{

	for (int i = 0; i < 100; ++i)
	{
		printf("xuliangshigegou!\n");
	}
	return 0;
}

/*
int main()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%d * %d = %d  ", i,j,i*j);
		}
		printf("\n");
	}

	return 0;
}

/*
#define PRICE 30
int main()
{
	int num = 0;
	cout << "张三买苹果" << endl;
	cin >> num;
	cout << "张三要付"<<num*PRICE<<"块钱" << endl;
	//printf("张三要付%dmoney\n", num*PRICE);
	return 0;
}
/*

// write your code here cpp

int main()
{
	stack<int> str;
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			if (s[0] >= '0'&&s[0] <= '9')
			{
				int num = 0;
				for (size_t i = 0; i < s.size(); ++i)
				{
					num = num * 10 + s[i] - '0';
					str.push(num);
				}
			}
			else
			{
				int x = str.top();
				str.pop();
				int y = str.top();
				str.pop();
				if (s == "+")
					str.push(x + y);
				else if (s == "*")
					str.push(x*y);
				else if (s == "-")
					str.push(x - y);
				else if (s == "/")
					str.push(y / x);
			}
			cout << str.top() << endl;
		}
	return 0;
}


/*
int main()
{
	int a = 0;
	int sum = 0;
	while (cin >> a)
	{
		vector<int> vt;
		vt.resize(3 * a);
		for (int i = 0; i<(3 * a); ++i)
			cin >> vt[i];
	} 
	sort(vt.begin(), vt.end());
	for (int i = a; i <= 3 * a - 2; i += 2)
	{
		sum += vt[i];
	}
	cout << sum << endl;
	return 0;
}

/*
class A
{
public:
	A() = default;
	A(int a) :_a(a)
	{}
	~A()
	{}
private:
	int _a;

};
int main()
{
	A a1;
	A a2(2);
	return 0;
}


/*
template<typename T>
void Swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

void Swap(double &a, double &b)
{
	double c = a;
	a = b;
	b = c;
}


/*
class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};


void Test2()
{
	// 申请单个Test类型的对象
	Test* p1 = new Test;
	delete p1;
	// 申请10个Test类型的对象
	Test* p2 = new Test[10];
	delete[] p2;
}

/*
int main()
{
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	// 申请10个Test类型的空间
	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
	free(p2);
	return 0;
}


//int main()
//{
//	//动态申请一个int 类型的空间
//	int* ptr = new int;
//	//初始化为100
//	int* ptr1 = new int(100);
//	//动态申请一个数组,大小为10
//	int* ptr2 = new int[10];
//
//	//手动申请就得手动释放。
//	delete ptr;
//	delete ptr1;
//	delete[]ptr2;
//	return 0;
//}

/*

int main()
{
	int from = 0;
	int to = 0;
	long long arr[81] = { 1, 1 };
	for (int i = 2; i < 80; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	while (cin >> from >> to)
	{
		long sum = 0;
		for (int i = from; i <= to; ++i)
		{
			sum += arr[i - 1];
		}
		cout << sum << endl;
	}
	return 0;
}


/*

//#include<iostream>
//using namespace std;

int main()
{
	int fb[100001];
	fb[0] = 1; fb[1] = 1;
	for (int i = 2; i<100001; ++i)
	{
		fb[i] = fb[i - 1] + fb[i - 2];
		fb[i] = fb[i] % 1000000;//取后六位数字
	}
	int n = 0;
	while (cin >> n)
	{
		if (n<30)
			printf("%d\n", fb[n - 1]);
		else
			printf("%0.6d\n", fb[n - 1]);
	}
	return 0;
}


/*
// write your code here cpp

int main()
{
	int num = 0;
	while (cin >> num)
	{
		cout << num << "=";
		int* pnum = new int[1000];
		int j = 0;
		for (int i = 2; i<=sqrt(num); ++i)
		{
			while (num%i == 0)
			{
				if (num != 1)
				{
					pnum[j] = i;
					j++;
					num /= i;
				}
			}
		}
		if (num != 1)
		{
			pnum[j] = num;
			j++;
		}
		for (int i = 0; i<j; ++i)
		{
			cout << pnum[i];
			if (i + 1 < j)
				cout << "*";
		}
		cout << endl;
		delete pnum;
	}
	return 0;
}



/*

/*
// write your code here cpp
#include<iostream>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{

		if (n == 1)
			cout << 0 << endl;
		else if (n == 2 || n == 3)
			cout << 1 << endl;
		else
		{
			int count = 1;
			while (n>3)
			{
				if (n % 3 == 0)
					n /= 3;
				else
					n = n / 3 + 1;
				count++;
			}
			cout << count << endl;
		}
	}
	return 0;
}


/*
class Solution {
public:
	///**
	//*	正数数组中的最小不可组成和
	//*	输入：正数数组arr
	//*	返回：正数数组中的最小不可组成和
	//
	int getFirstUnFormedNum(vector<int> arr, int len)
	{
		if (len <= 0)
			return 0;
		int min = arr[0];
		int sum = 0;
		for (int i = 0; i<len; ++i)//求出区间
		{
			sum += arr[i];
			if (arr[i]<min)
				min = arr[i];
		}
		vector<int> vt(sum + 1, 0);
		for (int i = 0; i<len; ++i)
		{
			for (int j = sum; j >= arr[i]; --j)
			if (vt[j - arr[i]] + arr[i]>vt[j])
				vt[j] = vt[j - arr[i]] + arr[i];
		}
		for (int i = min; i <= sum; ++i)
		{
			if (i != vt[i])
				return i;
		}
		return sum + 1;
	}
};


//<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> fd1c2b72faefe19c54af14fc1c81eabf65c38d46


/*
// write your code here cpp
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		long a = 0;
		long b = 0;
		if (n == 0)
			break;
		else
		{
			a = pow(5, n) - 4;
			b = pow(4, n) + n - 4;
		}
		cout << a << " " << b << endl;
	}

	return 0;
}


/*

class Solution {
public:
	/*
	//  奇数位上都是奇数或者偶数位上都是偶数
	//  输入：数组arr，长度大于2
	//  len：arr的长度
	// 将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	
	void oddInOddEvenInEven(vector<int>& arr, int len)
	{
		int i = 0;//+2为偶数位
		int j = 1;//+2为奇数位
		while (i<len && j<len)
		{
			if (arr[len - 1] % 2 == 0)//最后一个为偶数
			{
				swap(arr[len - 1], arr[i]);
				i += 2;
			}
			else//最后一个为基数
			{
				swap(arr[len - 1], arr[j]);
				j += 2;
			}
		}
	}
};
*/



/*
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		// write code here
		int LeftRes = 0;
		int RightRes = 0;
		int Min1 = 27;
		int Min2 = 27;
		for (int i = 0; i<left.size(); ++i)
		{
			if (left[i] == 0 && right[i] != 0)
			{
				LeftRes += right[i];
				RightRes += right[i];
			}
			if (left[i] != 0 && right[i] == 0)
			{
				LeftRes += left[i];
				RightRes += left[i];
			}
			if (left[i] == 0 && right[i] == 0)
			{
				LeftRes = left[i];
				RightRes = right[i];
				if (LeftRes<Min1)
					Min1 = left[i];
				if (RightRes<Min2)
					Min2 = right[i];
			}
		}

		RightRes = RightRes - Min2 + 2;
		LeftRes = LeftRes - Min1 + 2;

		if (RightRes > LeftRes)
			return LeftRes;
		else
			return RightRes;
	}
};

int main()
{
	Gloves a;
	vector<int> arr1;
	for (int i = 0; i < 4; ++i)
		cin >> arr1[i];
	vector<int> arr2;
	for (int i = 0; i < 4; ++i)
		cin >> arr2[i];
	int res = a.findMinimum(4,arr1,arr2);
	std::cout << res << endl;
	return 0;
}


/*
#include<iostream>
using namespace std;

int main()
{
	int num = 0;
	while (cin >> num)
	{
		int count = 0;
		while (num>0)
		{
			if (num & 1)
				count++;
			num >>= 1;
		}
		cout << count << endl;
	}
	return 0;
}


//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	int *b = a;
//	*b += 2;
//	*(b + 2) = 2;
//	b++;
//	printf("%d, %d\n", *b, *(b + 2));
//	return 0;
//
//}

/*
int main()
{
	int a = 0;
	int sum = 0;
	vector<int> vt;
	while (cin >> a)
	{
		vt.resize(3 * a);
		for (int i = 0; i<(3 * a); ++i)
			cin >> vt[i];
	} 
	sort(vt.begin(), vt.end());
	for (int i = a; i <= 3 * a - 2; i += 2)
	{
		sum += vt[i];
	} 
	cout << sum << endl;
	return 0;
}


/*
#include<iostream>
using namespace std;

bool IsPrime(int n)
{
	for (int i = 2; i<n; ++i)
	if (n % i == 0)
		return false;
	return true;
}

void MinSu(int n)
{
	int num1 = n / 2;
	int num2 = n - num1;
	while (1)
	{
		if (IsPrime(num1) && IsPrime(num2))
			break;
		num1--;
		num2++;
	}
	cout << num1 << endl;
	cout << num2 << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
		MinSu(n);
	return 0;
}




//void func(const int& v1, const int& v2)
//{
//	cout << v1 << endl;
//	cout << v2 << endl;
//
//}
//int main()
//{
//	int i = 0;
//	func(++i, i++);
//	return 0;
//}




/*
int main()
{
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	printf("%d,%d,%d", p[0][0], *(p[0] + 1), (*p)[2]);

	return 0;
}*/

//int main()
//{
//	int num = 0;
//	int count = 0;
//	int mcount = 0;
//	while (cin >> num)
//	{
//		count = 0;
//		mcount = 0;
//		while (num)
//		{
//			if (num % 2 != 0)
//				count++;
//			else
//				count = 0;
//			if (count>mcount)
//				mcount = count;
//			num = num / 2;
//		}
//		cout << mcount << endl;
//	}
//
//	return 0;
//}




/*
int PassScore(string str)
{
	int sum = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
	//1.密码长度

	int len = str.size();
	if (len < 5)
		s1 = 5;
	else if (len >= 8)
		s1 = 25;
	else
		s1 = 10;
	//字母和数字
	vector<char> vt1, vt2, vt3, vt4;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] <= 'z'&&str[i] >= 'a')
			vt1.push_back(str[i]);//放小写字母
		else if (str[i] <= 'Z'&&str[i] >= 'A')
			vt2.push_back(str[i]);//放大写字母
		else if (str[i] <= '9'&&str[i] >= '0')
			vt3.push_back(str[i]);//放数字
		else
			vt4.push_back(str[i]);//放符号
	}
		int len1 = vt1.size();
		int len2 = vt2.size();
		int len3 = vt3.size();
		int len4 = vt4.size();
		if (len1 == 0 && len2 == 0)
			s2 = 0;
		else if (len1 != 0 && len2 != 0)
			s2 = 20;
		else
			s2 = 10;
		if (len3 == 0)
			s3 = 0;
		else if (len3 == 1)
			s3 = 10;
		else
			s3 = 20;
		//符号
		if (len4 == 0)
			s4 = 0;
		else if (len4 == 1)
			s4 = 10;
		else
			s4 = 20;
		//奖励
		if (len1 != 0 && len2 != 0 && len3 != 0 && len4 != 0)
			s5 = 5;
		else if ((len2 != 0 || len1 != 0) && len3 != 0 && len4 != 0)
			s5 = 3;
		else if ((len2 != 0 || len1 != 0) && len3 != 0)
			s5 = 2;
		else
			s5 = 0;
		sum = s1 + s2 + s3 + s4 + s5;
		return sum;
}
int main()
{
	string str;
	while (cin >> str)
	{
		int sum = PassScore(str);
		switch (sum / 10)
		{
		case 9:
			cout << "VERY_WEAK" << endl;
			break;
		case 8:
			cout << "WEAK" << endl;
			break;
		case 7:
			cout << "AVERAGE" << endl;
			break;
		case 6:
			cout << "STRONG" << endl;
			break;
		case 5:
			cout << "VERY_STRONG"<<endl;
			break;
		default:
		{
				   if (sum >= 25)
					   cout << "SECURE" << endl;
				   else
					   cout << "VERY_SECURE" << endl;
		}
		}
	}
	return 0;
}*/

//int PassScore(string str)
//{
//	int sum = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
//	//1.密码长度
//
//	int len = str.size();
//	if (len<5)
//		s1 = 5;
//	else if (len >= 8)
//		s1 = 25;
//	else
//		s1 = 10;
//	//字母和数字
//	vector<char> vt1, vt2, vt3, vt4;
//	for (int i = 0; i<len; ++i)
//	{
//		if (str[i] <= 'z'&&str[i] >= 'a')
//			vt1.push_back(str[i]);//放小写字母
//		else if (str[i] <= 'Z'&&str[i] >= 'A')
//			vt2.push_back(str[i]);//放大写字母
//		else if (str[i] <= '9'&&str[i] >= '0')
//			vt3.push_back(str[i]);//放数字
//		else
//			vt4.push_back(str[i]);//放符号
//		int len1 = vt1.size();
//		int len2 = vt2.size();
//		int len3 = vt3.size();
//		int len4 = vt4.size();
//		if (len1 == 0 && len2 == 0)
//			s2 = 0;
//		else if (len1 != 0 && len2 != 0)
//			s2 = 20;
//		else
//			s2 = 10;
//		if (len3 == 0)
//			s3 = 0;
//		else if(len3 == 1)
//			s3 = 10;
//		else
//			s3 = 20;
//			//符号
//			if (len4 == 0)
//				s4 = 0;
//			else if(len4 == 1)
//				s4 = 10;
//		else
//			s4 = 20;
//			//奖励
//			if (len1 != 0 && len2 != 0 && len3 != 0 && len4 != 0)
//				s5 = 5;
//			else if ((len2 != 0 || len!=0)&& len3 != 0 && len4 != 0)
//				s5 = 3;
//			else if ((len2 != 0 || len!=0)&& len3 != 0)
//				s5 = 2;
//			else
//				s5 = 0;
//			sum = s1 + s2 + s3 + s4 + s5;
//			return sum;
//	}
//	int main()
//	{
//		string str;
//		while (cin >> str)
//		{
//			int sum = PassScore(str);
//			switch (sum / 10)
//			{
//			case 9:
//				cout << "VERY_WEAK" << endl;
//				break;
//			case 8:
//				cout << "WEAK" << endl;
//				break;
//			case 7:
//				cout << "AVERAGE" << endl;
//				break;
//			case 6:
//				cout << "STRONG" << endl;
//				break;
//			case 5:
//				cout << "VERY_STRONG" < endl;
//				break;
//			default:
//				break;
//			}
//		}
//	}
//
//int main()
//{
//	int I = 1;
//	if (I <= 0)
//		printf("****\n");
//	else
//		printf("%%%%\n");
//	return 0;
//}



//int func(int m, int n)
//{
//	int x = 1, y = 1;
//	for (int i = 0; i<n; ++i)
//	{
//		x = (m + n) - i;
//		y = i + 1;
//	}
//	return x * y;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a, b;
//	int tem = func(a, a+b);
//	cout << tem << endl;
//	return 0;
//}




/*
int addAB(int A, int B)
{
	// write code here
	int tem = 0;
	while (B)
	{
		tem = A&B;
		A = A^B;
		B = tem << 1;
	}
	return A;
}

int main()
{
	int c = addAB(1, 2);
	cout << c << endl;
	return 0;
}*/


//class Test
//{
//public:
//	int a;
//	int b;
//	virtual void fun()
//	{}
//	Test(int temp1 = 0, int temp2 = 0)
//	{
//		a = temp1;
//		b = temp2;
//	}
//	int getA()
//	{
//		return a;
//	}
//	int getB()
//	{
//		return b;
//	}
//};
//
//
//
//int main()
//{
//	Test obj(5, 10);
//	int* pInt = (int*)&obj;
//	*(pInt + 0) = 100;
//	*(pInt + 1) = 200;
//	cout << obj.getA() << endl;
//	cout << obj.getB() << endl;
//	return 0;
//}



/*
bool chkParenthesis(string A, int n)
{
	// write code here
	stack<char> st;
	if (A.empty() == 0)
		return true;
	int i = 0;
	for (i = 0; i<n; ++i)
	{
		if (A[i] == '(')
			st.push(A[i]);
		else if (A[i] == ')')
		{
			if (st.top() == '(')
				st.pop();
			else
				st.push(A[i]);
		}
		else
			return false;
	}
	if (st.size() == 0)
		return true;
	return false;
}
int main()
{
	cout << chkParenthesis("()a()((()", 9) << endl;
	return 0;
}*/
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int f1 = 0, f2 = 1;
//	int num = 0, n = 0;
//	cin >> n;
//	while (n>num)
//	{
//		num = f1 + f2;
//		f1 = f2;
//		f2 = num;
//	}
//	int N = 0;
//	if (num == n)
//		cout << 0 << endl;
//	else
//	{
//		N = ((num - n) > (n - f1)) ? (n - f1) : (num - n);
//		cout << N << endl;
//	}
//	return 0;
//}

//int StrToInt(string str)
//{
//	int i = 0;
//	int flag = 1, sum = 0;
//	if (str.size() == 0)
//		return 0;
//	//先判断正负号，正号i++跳过，负号将flag改为-1.
//	if (str[i] == '+')
//		i++;
//	if (str[i] == '-')
//	{
//		i++;
//		flag = 1;
//	}
//	while (str[i] != '\0')
//	{
//		if (str[i] == ' ')
//			i++;
//		if (str[i] >= '0'&&str[i] <= '9')//组合数字
//		{
//			sum = sum * 10 + flag*(str[i] - '0');
//			i++;
//		}
//		else
//			return 0;
//	}
//	return sum;
//}
//
//int main()
//{
//	string str = "-a123 456";
//	cout<<StrToInt(str)<<endl;
//	return 0;
//}

//
//int main()
//{
//	int w = 0;
//	int h = 0;
//	cin >> w >> h;
//	vector<vector<int>> vt();
//	int count=0;
//	for (int i = 0; i<w; ++i)
//	{
//		for (int j = 0; j<h; ++j)
//		{
//			if (vt[i][j] == 0)
//			{
//				count++;
//				if (i + 2<w)
//					vt[i + 2][j] = 1;
//				if (j + 2<h)
//					vt[i][j + 2] = 1;
//			}
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

//char fun(char a,char b)
//{
//	if (a < b)
//		return a;
//	return b;
//}
//
//int main()
//{
//	int a = '1', b = '1', c = '2';
//	cout << fun(fun(a, b), fun(b, c));
//	return 0;
//}

//int main()
//{
//	int m = 0123;
//	int n = 123;
//	printf("%o %o\n", m, n);
//	return 0;
//}


//int main()
//{
//	int num;
//	cin >> num;
//	vector<int> vt(num);
//	for (int i = 0; i<num; ++i)
//	{
//		cin >> vt[i];
//	}
//	int sum = 0;
//	for (int i = 0; i<num; ++i)
//	{
//		sum = sum + vt[i];
//		if (vt[i] > sum)
//			sum = vt[i];
//	}
//	cout << sum << endl;
//	return 0;
//}

//int main()
//{
//	long M = 0;
//	int N = 0;
//	int a = 0, b = 0;
//	int sum[100] = { 0 };
//	cin >> M >> N;
//	while (M != 0)
//	{
//		a = M%N;
//		M = M / N;
//		sum[b] = a;
//		b++;
//	}
//	for (int i = b-1; i >= 0; i--)
//	{
//		cout << sum[i];
//	}
//	return 0;
//}

//int main()
//{
//	int num1=0, num2=0, num3=0, num4=0;
//	cin >> num1>> num2>> num3>> num4;
//	int A, B1, B2, C;
//	A = (num1 + num3) / 2;
//	C = (num4 - num2) / 2;
//	B1 = (num4 + num2) / 2;
//	B2 = (num3 - num1) / 2;
//	if (B1 != B2)
//		cout << "No";
//	else
//		cout << A << " " << B1 << " " << C << " " << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> vt(4);
//	int num = 0;
//	int A, B1, B2, C;
//
//	A = (vt[0] + vt[2]) / 2;
//	C = (vt[1] + vt[3]) / 2;
//	B1 = (vt[3] - vt[0]) / 2;
//	B2 = (vt[1] + vt[3]) / 2;
//	if (B1 != B2)
//		cout << "No" << endl;
//	cout << A << B1 << C << endl;
//	return 0;
//}
////
//int main()
//{
//	int arr[] = { 1, 3, 5, 7,9 };
//	int *p = (int*)(&arr + 1);
//	printf("%d %d", *(arr + 1), *(p - 1));
//	return 0;
//}


//
//int cou = 0;
//int fun(int a)
//{
//	cou++;
//	if (a == 0)
//		return 1;
//	else if(a == 1)
//		return 2;
//	else
//	{
//		return fun(a - 1) + fun(a - 2);
//	}
//
//}
//int main()
//{
//	fun(8);
//	cout << cou << endl;
//	return 0;
//}
//



////数组中出现一半的数字
//
//int MoreThanHalfNum_Solution(vector<int> numbers)
//{
//	sort(numbers.begin(), numbers.end());//先排序
//	int num = numbers[numbers.size() / 2];
//	int tem = numbers.size() / 2;
//	int count = 0;//计数器
//	for (int i = 0; i<numbers.size(); ++i)
//	{
//		if (num == numbers[i])
//			++count;
//	}
//	if (count>tem)
//		return num;
//	return 0;
//}
//
//int main()
//{
//	vector<int> number = { 1, 5, 2, 1, 5, 5, 5, 5, 5 };
//	int ret = MoreThanHalfNum_Solution(number);
//	cout << "ret = "<<ret<< endl;
//	return 0;
//}



////倒置字符串
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	reverse(str.begin(), str.end());
//	auto itstart = str.begin();
//	while (itstart != str.end())
//	{
//		auto itend = itstart;
//		while (itend != str.end() && *itend != ' ')
//		{
//			itend++;
//		}
//		reverse(itstart, itend);
//		if (itend != str.end())
//			itstart = itend + 1;
//		else
//			itstart = itend;
//	}
//	cout << str << endl;
//	return 0;
//}



/**《牛客》输入一个链表，按链表从尾到头的顺序返回一个ArrayList.
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head)
	{
		vector<int> rec;
		ListNode* buf = head;
		ListNode* pre = buf;
		if (head == nullptr)
			return rec;
		while (head->next != nullptr)
		{
			buf = head->next;
			head->next = buf->next;
			buf->next = pre;
			pre = buf;
		}
		while (buf)
		{
			rec.push_back(buf->val);
			buf = buf->next;
		}
		return rec;
	}
};*/


/*题目描述《牛客》替换空格
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
class Solution {
public:
	void replaceSpace(char *str, int length)
	{
		int count = 0;
		for (int i = 0; i<length; ++i)
		{
			if (*(str + i) == ' ')
				count++;
		}
		for (int i = length - 1; i >= 0; --i)
		{
			if (str[i] != ' ')
				str[i + 2 * count] = str[i];
			else
			{
				str[i + 2 * count] = '0';
				str[i + 2 * count - 1] = '2';
				str[i + 2 * count - 2] = '%';
				count--;
			}
	
		}
		//string s(str);
		//int i=0;        
		//while((i=s.find(' ',i))>-1)
		//{           
		//	s.erase(i,1);            
		//	s.insert(i,"%20");                     
		//}        
		//auto ret=s.c_str();        
		//strcpy(str,ret);
	}
};*/

/*429. N叉树的层序遍历
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val) {
val = _val;
}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root)
	{
		if (root == NULL)
			return{};
		vector<vector<int>> ans;
		vector<int> tmp;
		queue<Node*> q;
		q.push(root);
		int CurLayerSize = q.size();
		while (!q.empty()){
			Node* cur = q.front();
			tmp.push_back(cur->val);
			q.pop();
			for (auto node : cur->children)
				q.push(node);
			if (--CurLayerSize == 0)
			{//当前层遍历完毕时
				ans.push_back(tmp);
				CurLayerSize = q.size();
				tmp.clear();
			}
		}
		return ans;
	}
};
*/

/**515. 在每个树行中找最大值
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

class Solution
{
public:
	vector<int> largestValues(TreeNode* root)
	{
		queue<TreeNode*> q;
		if (root)
			q.push(root);
		vector<int> res;
		while (!q.empty())
		{
			int n = q.size(), now = INT_MIN;
			while (n--)
			{
				TreeNode* tmp = q.front();
				q.pop();
				if (tmp->val>now)
					now = tmp->val;
				if (tmp->left)
					q.push(tmp->left);
				if (tmp->right)
					q.push(tmp->right);
			}
			res.push_back(now);
		}
		return res;
	}
};

*/

/*《牛客》二叉树镜像
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
//class Solution {
//public:
//	void Mirror(TreeNode *pRoot)
//	{
//		if (!pRoot)
//			return;
//		if (pRoot->left == nullptr && pRoot->right == nullptr)
//			return;
//		TreeNode *tem = pRoot->left;
//		pRoot->left = pRoot->right;
//		pRoot->right = tem;
//		if (pRoot->left != nullptr)
//			Mirror(pRoot->left);
//		if (pRoot->right != nullptr)
//			Mirror(pRoot->right);
//	}
//};

/**637. 二叉树的层平均值
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//class Solution {
//public:
//	vector<double> averageOfLevels(TreeNode* root)
//	{
//		vector<double> dev;
//		if (!root)
//			return dev;
//		queue<TreeNode*> q;
//		q.push(root);
//		TreeNode* last = root;
//		TreeNode* temp = nullptr;
//		double sum = 0;
//		int count = 0;
//		while (!q.empty())
//		{
//			temp = q.front();
//			q.pop();
//			if (temp->left)
//				q.push(temp->left);
//			if (temp->right)
//				q.push(temp->right);
//			++count;
//			sum += temp->val;
//			if (temp == last)
//			{
//				dev.push_back(sum / count);
//				count = 0;
//				sum = 0;
//				last = q.back();
//			}
//
//		}
//		return dev;
//	}
//};

//107.二叉树层次遍历2
/*Definition for a binary tree node.
* struct TreeNode {
	*int val;
	*TreeNode *left;
	*TreeNode *right;
	*TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
/*
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> vv;

		if (!root)
			return vv;
		TreeNode* p = nullptr;
		TreeNode* last = root;

		vector<int> ivec;
		queue<TreeNode*> q;//存放节点的队列
		q.push(root);
		ivec.push_back(root->val);//存放节点中的值
		vv.push_back(ivec);
		ivec.clear();//清空ivec

		while (!q.empty())
		{
			p = q.front();
*/

//(stack and queue)102.给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
/*
Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
/*
class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*> queue;
		queue.push(root);

		vector<int> level_res;
		int curNums = 1, nextNums = 0;

		TreeNode* node;

		while (!queue.empty())
		{
			node = queue.front();

			level_res.push_back(node->val);
			queue.pop();
			curNums--;

			if (node->left)
			{
				queue.push(node->left);
				nextNums++;
			}

			if (node->right)
			{
				queue.push(node->right);
				nextNums++;
			}


			if (curNums == 0)
			{
				res.push_back(level_res);

				level_res.clear();

				curNums = nextNums;
				nextNums = 0;
			}
		}

		return res;
	}
};
*/

/*
//测试题
//1.字符集合
int main()
{
string str;
while (cin >> str)
{
int count[256] = {0};//存字符
size_t size = str.size();
for (int i = 0; i < size; ++i)
{
if (0 == count[str[i]])
cout << str[i];//不同打印输出
count[str[i]]++;//出现则加一
}
cout << endl;
}
return 0;
}

////2.有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，例如，原数组为[1,2,3,4,5,6]，向左移位5个位置即变成了[6,1,2,3,4,5],现在对于移位后的数组，需要查找某个元素的位置。请设计一个复杂度为log级别的算法完成这个任务。
//给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，请返回x的位置(位置从零开始)。保证数组中元素互异。
//测试样例：
//[6,1,2,3,4,5],6,6
//返回：0

class Finder {
public:
int findElement(vector<int> A, int n, int x)
{
int left = 0;
int right = n - 1;
while (left <= right)
{
int mid = left + ((right - left) >> 1);
if (A[mid] == x)
return mid;
if (x > A[mid])
{
if (A[mid] < A[left] && x > A[right])
right = mid - 1;
else
left = mid + 1;
}
else
{
if (A[mid]>A[left] && x < A[left])
left = mid + 1;
else
right = mid - 1;
}
}
return -1;
}
};*/


//模板
//template<typename T1,class T2>
//template<typename T1,typename T2>
//template<class t1,class t2>



//225.用队列实现栈
//class MyStack {
//	queue<int> Q1;
//public:
//	/** Initialize your data structure here. */
//	MyStack()
//	{
//
//	}
//
//	/** Push element x onto stack. */
//	void push(int x)
//	{
//		Q1.push(x);
//	}
//
//	/** Removes the element on top of the stack and returns that element. */
//	int pop()
//	{
//		int size = Q1.size();
//		for (int i = 0; i<size - 1; ++i)
//		{
//			Q1.push(Q1.front());
//			Q1.pop();
//		}
//		int tem = Q1.front();
//		Q1.pop();
//		return tem;
//	}
//
//	/** Get the top element. */
//	int top()
//	{
//		return Q1.back();
//	}
//
//	/** Returns whether the stack is empty. */
//	bool empty()
//	{
//		return Q1.empty();
//	}
//};
//

/*
224.用栈实现队列
class MyQueue {
public:
stack<int> s1;
stack<int> s2;
/** Initialize your data structure here.
MyQueue()
{
}

//** Push element x to the back of queue.
void push(int x)
{
s1.push(x);
}

//** Removes the element from in front of queue and returns that element.
int pop(
{
if (s2.empty())
{
while (!s1.empty())
{
s2.push(s1.top());
s1.pop();
}
}
int tem = s2.top();
s2.pop();
return tem;
}

//** Get the front element.
int peek()
{
if (s2.empty())
{
while (!s1.empty())
{
s2.push(s1.top());
s1.pop();
}
}
int tem = s2.top();
return tem;

}

//** Returns whether the queue is empty.
bool empty()
{
return s1.empty() && s2.empty();
}
};*/

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/


/**223.二叉树后续遍历
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

class Solution {
public:
vector<int> postorderTraversal(TreeNode* root)
{
vector<int> res;
stack<TreeNode*> st;
if (root == nullptr)
return res;
TreeNode* pre = nullptr;
while (root || !st.empty())
{
if (root)
{
st.push(root);
root = root->left;
}
else
{
root = st.top();
if (root->right == nullptr || root->right == pre)
{
res.push_back(root->val);
pre = root;
root = nullptr;
st.pop();
}
else
{
root = root->right;
}
}
}
return res;
}
};*/


/*222.二叉树的中序遍历

* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

class Solution {
public:
vector<int> inorderTraversal(TreeNode* root)
{
/*stack<TreeNode*> nodes;
vector<int> res;
while(root)
{
nodes.push(root);
root = root->left;
}
while(!nodes.empty())
{
auto node = nodes.top();
nodes.pop();
res.push_back(node->val);
node = node->right;
while(node)
{
nodes.push(node);
node=node->left;
}
}
return res;
//vector<int> vec;

//stack<TreeNode*> st;
//while (root || !st.empty())
//{
//	while (root)
//	{
//		st.push(root);
//		root = root->left;
//	}
//	root = st.top();
//	st.pop();
//	vec.push_back(root->val);
//	root = root->right;
//}
//return vec;
}
};

*/

/*二叉树前序遍历
typedef struct TreeNode
{
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}

}TreeNode;

vector<int> preorderTraversal(TreeNode* root)
{
stack<TreeNode*> nodes;
vector<int> res;
while (root || !nodes.empty())
{
while (root)
{
nodes.push(root->right);
res.push_back(root->val);
root = root->left;
}
root = nodes.top();
nodes.pop();
}
return res;
}

int main()
{
TreeNode* s;
return 0;
}

/*
//1.根据逆波兰表示法，求表达式的值。
//有效的运算符包括 + , -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//说明：
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
class Solution {
public:
int evalRPN(vector<string>& tokens)
{
stack<int> numbers;
for (int i = 0; i < tokens.size(); ++i)
{
if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
{
int res;
int n2 = numbers.top();
numbers.pop();
int n1 = numbers.top();
numbers.pop();

if (tokens[i] == "+")
res = n1 + n2;
else if (tokens[i] == "-")
res = n1 - n2;
else if (tokens[i] == "/")
res = n1 / n2;
else
res = n1 * n2;
numbers.push(res);
}
else{
numbers.push(stoi(tokens[i]));
}
}
return numbers.top();
}
};
*/


/*221.压栈和出栈
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
//if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
//	return false;
//int sz = pushV.size();
//stack<int> st;
//int i = 0;
//for (int j = 0; j<sz; ++j)
//{
//	st.push(pushV[j]);//入栈
//	while (!st.empty() && st.top() == popV[i])//比较
//	{
//		st.pop();//出栈
//		++i;
//	}
//}
//if (st.empty())
//	return true;
//return false;

if(pushV.empty() || popV.empty() || pushV.size()!=popV.size())
return false;
stack<int> s;
int j=0;
for(int i=0;i<pushV.size();++i)
{
s.push(pushV[i]);
while(!s.empty()&&s.top()==popV[j])
{
s.pop();
++j;
}
}
if(s.empty())
return true;
return false;
}

int main()
{
vector<int> s1 = {1,2,3,4,5};
vector<int> s2 = { 4, 5, 3, 2, 1 };
bool tem=IsPopOrder(s1, s2);
cout << tem << endl;
return 0;
}*/