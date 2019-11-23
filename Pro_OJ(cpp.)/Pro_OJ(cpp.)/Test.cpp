#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/*���������������

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

/*������ǰ�����
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
//1.�����沨����ʾ��������ʽ��ֵ��
//��Ч����������� + , -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��
//˵����
//��������ֻ�����������֡�
//�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������
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

	
/*2.ѹջ�ͳ�ջ
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	//if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
	//	return false;
	//int sz = pushV.size();
	//stack<int> st;
	//int i = 0;
	//for (int j = 0; j<sz; ++j)
	//{
	//	st.push(pushV[j]);//��ջ
	//	while (!st.empty() && st.top() == popV[i])//�Ƚ�
	//	{
	//		st.pop();//��ջ
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