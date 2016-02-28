#include <iostream>

enum COLOR_TYPE
{
	RED,
	BLACK
};

enum PARTICULAR_VALUE
{
	INFINITY_POSSITIVE = INT_FAST32_MAX,
	INFINITY_NEGATIVE = ~0
};

template<class T>
class Red_Black_Tree_Node
{
public:
	T val;
	Red_Black_Tree_Node * left;
	Red_Black_Tree_Node * right;
	COLOR_TYPE Color;

};

template <class T>
class Red_Black_Tree
{
public:
	Red_Black_Tree();
	~Red_Black_Tree();

private:
	Red_Black_Tree_Node<T> * null_node;
	Red_Black_Tree_Node<T> * tree;

	Red_Black_Tree_Node * Rotate(T val,Red_Black_Tree_Node<T> * parent);
	Red_Black_Tree_Node * single_rotation_left(Red_Black_Tree_Node<T> * pos);
	Red_Black_Tree_Node * single_rotation_right(Red_Black_Tree_Node<T> * pos);


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
Red_Black_Tree<T>::~Red_Black_Tree()
{
}

template<class T>
Red_Black_Tree_Node * Red_Black_Tree<T>::Rotate(T val, Red_Black_Tree_Node<T>* parent)
{
	if (val<pos->val)
	{
		return parent->left = val < parent->left->val ? single_rotation_left(parent->left) : single_rotation_right(parent->left);
	} 
	else
	{
		return parent->right = val > parent->right->val ? single_rotation_right(parent->right) : single_rotation_left(parent->right);
	}
}

template<class T>
Red_Black_Tree_Node * Red_Black_Tree<T>::single_rotation_left(Red_Black_Tree_Node<T>* pos)
{
	Red_Black_Tree_Node<T> * tmp = pos->left;
	pos->left = tmp->right;
	tmp->right = pos;

	return tmp;
}

template<class T>
Red_Black_Tree_Node * Red_Black_Tree<T>::single_rotation_right(Red_Black_Tree_Node<T>* pos)
{
	Red_Black_Tree_Node<T> * tmp = pos->right;
	pos->right = tmp->left;
	tmp->left = pos;

	return tmp;
}
