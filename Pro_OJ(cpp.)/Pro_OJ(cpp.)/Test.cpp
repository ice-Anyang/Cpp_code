#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
用栈实现队列
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


/**二叉树后续遍历
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


/*二叉树的中序遍历

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

	
/*2.压栈和出栈
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