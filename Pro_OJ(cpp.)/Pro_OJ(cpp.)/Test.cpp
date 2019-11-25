#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��ջʵ�ֶ���
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


/**��������������
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