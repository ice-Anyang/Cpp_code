#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

template<typename Type>
class AVLTree;

template<typename Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode(Type d=Type() ,AVLNode<Type>* left = nullptr,AVLNode<Type>* right = nullptr)
		:leftChild(left), rightChild(right), date(_d), bf(0)
	{}
	~AVLNode()
	{}
private:
	Type date;
	AVLNode<Type>* leftChild;
	AVLNode<Type>* rightChild;
	int bf;
};

template<typename Type>
class AVLTree
{
public:
	AVLTree() :root(nullptr)
	{}
public:
	bool Insert(const Type &x);
protected:
	void RotateR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		ptr->bf = subR->bf = 0;
	}
	void RotateL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		ptr = subL->rightChild;
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		ptr->bf = subL->bf = 0;
	}
	void RotateRL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type>*subR = ptr->rightChild;
		AVLNode<Type>*subL = ptr;


	}
	void RotateLR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr->leftChild;
		AVLNode<Type> *subR = ptr;
		ptr = subL->rightChild;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//subL->bf;
		if (ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//subR->bf;
		if (ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;
	}

protected:
    bool Insert(AVLNode<Type>* &t, const Type &x);
private:
	AVLNode<Type>* root;
};

template<typename Type>
bool AVLTree<Type>::Insert(const Type &x)
{
	return Insert(root, x);
}

template<typename Type>
bool AVLTree<Type>::Insert(AVLNode<Type>* &t,const Type &x)
{
	stack<AVLNode<Type>* > st;
	//1.插入数据
	AVLNode<Type>* p = t;
	AVLNode<Type>* pr = nullptr;
	while (p != nullptr)
	{
		if (x == p->date)
			return false;
		pr = p;
		st.push(pr);

		if (x < p->date)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	p = new AVLNode<Type>(x);

	if (pr == nullptr)
	{
		t = p;
		return true;
	}

	//链接节点
	if (x < pr->date)
		pr->leftChild = p;
	else
		pr->rightChild = p;
	//2.平衡调整,运用stack来进行
	while (!st.empty())
	{
		pr = st.top();
		st.pop();

		if (pr->leftChild == p)
			pr->bf--;
		else
			pr->bf++;
		if (pr->bf == 0)
			break;
		if (pr->bf == -1 || pr->bf == 1)
			p = pr;
		else
		if (pr->bf > 0)
		{
			if (p->bf > 0)
			{
				//向左旋转
				RotateL(pr);
			}
			else
			{
				//右右左
				RotateRL(pr);
			}
		}
		else
		{
			if (pr->bf < 0)
			{
				//向右旋转
				RolateR(pr);
			}
			else
			{
				//左左右
				RolateLR(pr);
			}
		}
	}

}


int main()
{
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int n = sizeof(arr) / sizeof(int);
	AVLTree<int> avl;
/*	for (int i = 0; i < n; ++i)
	{
		avl.Insert(arr[i]);
	}*/
	return 0;
}