#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>

using namespace std;





///////////////////////////////////////////////////////////
//cpp���ԣ�-��
//////////////////////////////////////////////////////////
//1.�ַ���ȡ

//int main()
//{
//	string st;
//	char tem[256] = {0};
//	while (cin >> st)
//	{
//		for (size_t i = 0; i < st.size(); ++i)
//		{
//			if (tem[st[i]] == 0)
//			{
//				cout<<st[i];
//				tem[st[i]]++;
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}
//2.����λ��
//int find(ar[], int n, int x)
//{
//	int low = 0;
//	int high = n - 1;
//	int mid;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (x == ar[mid])
//			return mid;
//		else if (x > ar[mid])
//		{
//			if (ar[mid]<ar[left] && x > ar[right]) //???
//			{
//				high = mid - 1;
//			}
//			else
//				low = mid + 1;
//		}
//		else
//		{
//			if ( ar[mid]>ar[left] && x <ar[left])  //???
//			{
//				low = mid + 1;
//			}
//			else
//				high = mid - 1;
//		}
//	}
//}
