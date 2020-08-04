#include<iostream>
#include<vector>
using namespace std;

typedef enum { RED = 0, BLACK } Color_Type;

template<typename Type>
class RBTree;
template<typename Type>
class rb_iterator;


//节点的定义：
template<typename Type>
class RBTreeNode
{
	friend class RBTree<Type>;
	friend class rb_iterator<Type>;
public:
	RBTree(const Type &val = Type())
		:data(val), left(nullptr), right(nullptr), parent(nullptr), color(RED)
	{}
	~RBTreeNode()
	{}
private:
	Type data;
	RBTreeNode *left;
	RBTreeNode *right;
	RBTreeNode *parent;
	Color_Type colour;
};

//迭代器的定义实现：

template<typename Type>
class rb_iterator
{
	typedef rb_iterator self;
public:
	rb_iterator(RBTreeNode<Type>* p, RBTreeNode<Type>* nil)
		:node(p), NIL(nil)
	{}
public:
	Type& operator*()
	{
		return node->date;
	}
	self& operator++()
	{
		increment();
		return *this;
	}
	self& operator--()
	{
		decrement();
		return *this;
	}
public:
	bool operator==(const rb_iterator &rbit)
	{
		return node == rbit.node;
	}
	bool operator!=(const rb_iterator &rbit)
	{
		return node != rbit.node();
	}
protected:
	void increment()
	{
		if (node->right != NIL)
		{
			node = node->right;
			while (node->left != NIL)
				node = node->left;
		}
		else
		{
			RBTreeNode<Type>* p = node->parent;
			while (node == p->right)
			{
				node = p;
				p = p->parent;
			}
			node = p;
		}
	}
	void decrement()
	{
		if (node->left != NIL)
		{
			node = node->left;
			while (node->right != NIL)
				node = node->right;
		}
		else
		{
			RBTreeNode<Type>*p = node->parent;
			while (node == p->left)
			{
				node = p;
				p = p->parent;
			}
			node = p;
		}

	}
private:
	RBTreeNode<Type>* node;
	RBTreeNode<Type>*NTL;
};

//BSTree树的实现：
template<typename Type>
class RBTree
{
public:
	typedef rb_iterator<Type> iterator;

public:
	RBTree() :NIL(_Buynode()), end_node(_Buynode())
	{
		NIL->left = NIL->right = NIL->parent = NIL;
		NIL->colour = BLACK;
		end_node->left = end_node->right = end_node->parent = NIL;

		root = NIL;
	}

public:
	iterator begin()
	{
		RBTreeNode<Type> *p = root;
		while (p != NIL && p->left != NIL)
			p = p->left;
		return iterator(p, NIL);
	}
	iterator end()
	{
		return iterator(end_node, NIL);
	}

public:
	void set_endnode()
	{
		RBtreeNode<Type> *p = root;
		while (p != NIL&&p->right != NIL)
			p = p->right;
		p->right = end_node;
	}
	void insert(const Type& x)
	{
		insert(root, x);
	}
protected:
	void insert(RBTreeNode<Type> *&t, const Type& x)
	{
		//1.找到插入的位置
		RBTreeNode<Type> *pr = NIL;
		RBTreeNode<Type> *p = t;
		while (p != NIL)
		{
			if (x == p->data)
				return;
			pr = p;
			if (x < p->data)
			{
				p = p->left;
			}
			else
			{
				p = p->right;
			}
		}

		RBTreeNode<Type>* s = _Buynode(x);
		if (pr == NIL)
		{
			//第一次差入根节点
			t = s;
			t->parent = NIL;
		}
		else if (x < pr->data)
		{
			pr->left = s;
		}
		else
			pr->right = s;
		s->parent = pr;
		//2.平衡调整
		insert_fixup(t, s);
	}
protected:
	void insert_fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
	{
		//x为新插节点，s为叔伯节点，p为父节点，g为祖父节点
		while (x->parent->colour)
		{
			RBTreeNode<Type> *s;
			if (x->parent == x->parent->parent->left) //左分支
			{
				s = x->parent->parent->right;

				if (s->color == RED) //状况3
				{
					x->parent->color = BLACK;
					s->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
					continue;
				}
				else if (x == x->parent->right) //状况2  // <
				{
					x = x->parent;
					LeftRotate(t, x);
				}
				//状况1
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				RightRotate(t, x->parent->parent);
			}
			else //右分支
			{
				s = x->parent->parent->left;
				if (s->color == RED) ////状况3
				{
					x->parent->color = BLACK;
					s->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
					continue;
				}
				else if (x == x->parent->left) //状况2  // >
				{
					x = x->parent;
					RightRotate(t, x);
				}

				//状况1
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				LeftRotate(t, x->parent->parent);
			}
		}
		t->colour = BLACK;
		// 旋转方法都以p节点为轴点进行旋转
		void LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
		{
			RBTreeNode<Type> *s = p->right;
			p->right = s->left;
			if (s->left != NIL)
				s->left->parent = p;
			s->parent = p->parent;
			if (p->parent == NIL)
				t = s;
			else if (p == p->parent->left)
				p->parent->left = s;
			else
				p->parent->right = s;

			s->left = p;
			p->parent = s;
		}
		void RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
		{
			RBTreeNode<Type> *s = p->left;
			p->left = s->right;
			if (s->right != NIL)
				s->right->parent = p;
			s->parent = p->parent;
			if (p->parent == NIL)
				t = s;
			else if (p == p->parent->left)
				p->parent->left = s;
			else
				p->parent->right = s;

			s->right = p;
			p->parent = s;
		}
	}

protected:
	RBTreeNode<Type>* _Buynode(const Type &val = Type())
	{
		RBTreeNode* _S = new RBTreeNode<Type>(val);
		_S->left = _S->right = _S->parsent = NIL;
		return _S;
	}

private:
	RBTreeNode<Type> *root;//根节点
	RBTreeNode<Type> *NIL;//叶子节点
	RBTreeNode<Type> *end_node;

};

int main()
{
	vector<int> v = { 10, 7, 4, 2, 80, 15, 5, 6, 11, 13, 12 };

	RBTree<int> rb;
	for (const auto &e : v)
		rb.insert(e);
	rb.set_endnode();

	RBTree<int>::iterator it = rb.begin();
	while (it != rb.end())
	{
		cout << *it << " ";
		++it;
	}

	return 0;
}

