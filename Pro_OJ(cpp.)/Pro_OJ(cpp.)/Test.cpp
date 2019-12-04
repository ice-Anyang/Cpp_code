#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;

/*429. N�����Ĳ������
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
			{//��ǰ��������ʱ
				ans.push_back(tmp);
				CurLayerSize = q.size();
				tmp.clear();
			}
		}
		return ans;
	}
};
*/

/**515. ��ÿ�������������ֵ
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

/*��ţ�͡�����������
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

/**637. �������Ĳ�ƽ��ֵ
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

//107.��������α���2
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
		queue<TreeNode*> q;//��Žڵ�Ķ���
		q.push(root);
		ivec.push_back(root->val);//��Žڵ��е�ֵ
		vv.push_back(ivec);
		ivec.clear();//���ivec

		while (!q.empty())
		{
			p = q.front();
*/

//(stack and queue)102.����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
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
//������
//1.�ַ�����
int main()
{
string str;
while (cin >> str)
{
int count[256] = {0};//���ַ�
size_t size = str.size();
for (int i = 0; i < size; ++i)
{
if (0 == count[str[i]])
cout << str[i];//��ͬ��ӡ���
count[str[i]]++;//�������һ
}
cout << endl;
}
return 0;
}

////2.��һ���Ź�������飬����n����������������������������һ�����ȵ���λ�����磬ԭ����Ϊ[1,2,3,4,5,6]��������λ5��λ�ü������[6,1,2,3,4,5],���ڶ�����λ������飬��Ҫ����ĳ��Ԫ�ص�λ�á������һ�����Ӷ�Ϊlog������㷨����������
//����һ��int����A��Ϊ��λ������飬ͬʱ���������Сn����Ҫ���ҵ�Ԫ�ص�ֵx���뷵��x��λ��(λ�ô��㿪ʼ)����֤������Ԫ�ػ��졣
//����������
//[6,1,2,3,4,5],6,6
//���أ�0

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


//ģ��
//template<typename T1,class T2>
//template<typename T1,typename T2>
//template<class t1,class t2>



//225.�ö���ʵ��ջ
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
224.��ջʵ�ֶ���
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


/**223.��������������
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


/*222.���������������

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


/*221.ѹջ�ͳ�ջ
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