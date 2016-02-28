#include <cstdio>

enum COLOR_TYPE
{
	RED,
	BLACK
};

enum PARTICULAR_VALUE
{
	INFINITY_POSSITIVE = (1<<30),
	INFINITY_NEGATIVE = ~0
};

template<class T>
class Red_Black_Tree_Node
{
public:
	T val;
	Red_Black_Tree_Node<T> * left;
	Red_Black_Tree_Node<T> * right;
	COLOR_TYPE Color;

};

template <class T>
class Red_Black_Tree
{
public:
	Red_Black_Tree();

	void Insert(T val);

	~Red_Black_Tree();

private:
	Red_Black_Tree_Node<T> * null_node;
	Red_Black_Tree_Node<T> * tree; 
	Red_Black_Tree_Node<T> * G_G_Parent;
	Red_Black_Tree_Node<T> * G_Parent;
	Red_Black_Tree_Node<T> * Parent;
	Red_Black_Tree_Node<T> * X;

	Red_Black_Tree_Node<T> * Rotate(T val,Red_Black_Tree_Node<T> * parent);
	Red_Black_Tree_Node<T> * single_rotation_left(Red_Black_Tree_Node<T> * pos);
	Red_Black_Tree_Node<T> * single_rotation_right(Red_Black_Tree_Node<T> * pos);
	Red_Black_Tree_Node<T> * Insert(T val,Red_Black_Tree_Node<T> * tree);

	void handle_reorient(T val, Red_Black_Tree_Node<T> * tree);
	void destory(Red_Black_Tree_Node<T> * tree);


};

template<class T>
Red_Black_Tree<T>::Red_Black_Tree()
{
	null_node = new Red_Black_Tree_Node<T>;
	null_node->left = null_node->right = null_node;
	null_node->Color = BLACK;
	null_node->val = INFINITY_POSSITIVE;

	tree = new Red_Black_Tree_Node<T>;
	tree->val = INFINITY_NEGATIVE;
	tree->left = tree->right = null_node;
	tree->Color = BLACK;

}

template<class T>
void Red_Black_Tree<T>::Insert(T val)
{
	tree = Insert(val, tree);
}

template<class T>
Red_Black_Tree<T>::~Red_Black_Tree()
{
	destory(tree);
	delete null_node;
}

template<class T>
Red_Black_Tree_Node<T> * Red_Black_Tree<T>::Rotate(T val, Red_Black_Tree_Node<T>* parent)
{
	if (val<parent->val)
	{
		return parent->left = val < parent->left->val ? single_rotation_left(parent->left) : single_rotation_right(parent->left);
	} 
	else
	{
		return parent->right = val > parent->right->val ? single_rotation_right(parent->right) : single_rotation_left(parent->right);
	}
}

template<class T>
Red_Black_Tree_Node<T> * Red_Black_Tree<T>::single_rotation_left(Red_Black_Tree_Node<T>* pos)
{
	Red_Black_Tree_Node<T> * tmp = pos->left;
	pos->left = tmp->right;
	tmp->right = pos;

	return tmp;
}

template<class T>
Red_Black_Tree_Node<T> * Red_Black_Tree<T>::single_rotation_right(Red_Black_Tree_Node<T>* pos)
{
	Red_Black_Tree_Node<T> * tmp = pos->right;
	pos->right = tmp->left;
	tmp->left = pos;

	return tmp;
}

template<class T>
Red_Black_Tree_Node<T>* Red_Black_Tree<T>::Insert(T val, Red_Black_Tree_Node<T>* tree)
{
	X = Parent = G_Parent = tree;
	null_node->val = val;
	while (X->val != val)
	{
		G_G_Parent = G_Parent;
		G_Parent = Parent;
		Parent = X;

		if (val<X->val)
		{
			X = X->left;
		}
		else
		{
			X = X->right;
		}

		if (X->left->Color == RED && X->right->Color == RED)
		{
			handle_reorient(val, tree);
		}
	}

	if (X!=null_node)
	{
		return null_node;
	}

	X = new Red_Black_Tree_Node<T>;
	X->val = val;
	X->left = X->right = null_node;

	if (val<Parent->val)
	{
		Parent->left = X;
	}
	else
	{
		Parent->right =X;
	}
	handle_reorient(val, tree);

	return tree;
}

template<class T>
void Red_Black_Tree<T>::handle_reorient(T val, Red_Black_Tree_Node<T>* tree)
{
	X->Color = RED;
	X->left->Color = BLACK;
	X->right->Color = BLACK;
	if (Parent->Color==RED)
	{
		G_Parent->Color = RED;
		if ((val < G_Parent->val) != (val < Parent->val))
		{
			Parent = Rotate(val, G_Parent);
		}
		X = Rotate(val, G_G_Parent);
		X->Color = BLACK;
	}
	tree->right->Color = BLACK;
}

template<class T>
void Red_Black_Tree<T>::destory(Red_Black_Tree_Node<T> * tree)
{
	if (tree == null_node)
	{
		return;
	}

	destory(tree->left);
	destory(tree->right);
	delete tree;
}

// int main() {
// 	Red_Black_Tree<int> RBT;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		RBT.Insert(i);
// 	}
// 
// 	getchar();
// }