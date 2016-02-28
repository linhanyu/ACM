template<class T>
class Splay_Tree_Node
{
public:
	T val;
	Splay_Tree_Node<T> * left;
	Splay_Tree_Node<	T> * right;
};

template <class T>
class Splay_Tree
{
public:
	Splay_Tree();

	void insert(T val);

	Splay_Tree_Node<T> * Splay(T val, Splay_Tree_Node<T> * pos);

	~Splay_Tree();


private:
	Splay_Tree_Node<T> * null_node;
	Splay_Tree_Node<T> * tree;

	Splay_Tree_Node<T> * Insert(T val, Splay_Tree_Node<T> * pos);

	void destory(Splay_Tree_Node<T> * tree);
};

template <class T>
void Splay_Tree<T>::insert(T val)
{
	tree = Insert(val, tree);
}

template <class T>
Splay_Tree_Node<T> * Splay_Tree<T>::Insert(T val, Splay_Tree_Node<T> * pos)
{
	static Splay_Tree_Node<T> * new_node=NULL;

	if (new_node==NULL)
	{
		new_node = new Splay_Tree_Node<T>;
	}
	new_node->val = val;

	if (pos == null_node)
	{
		new_node->left = new_node->right = null_node£»
		pos = new_node;
	}
	else
	{
		pos = Splay(val, pos);
		if (val < pos->val)
		{
			new_node->left = pos->left;
			new_node->right = pos;
			pos->left = null_node;
			pos = new_node;
		}
		else if (val > pos->val)
		{
			new_node->left = pos;
			new_node->right = pos->right;
			pos->right = null_node;
			pos = new_node;
		}
		else
		{
			return pos;
		}
	}

	new_node = NULL;
	return pos;
}

template <class T>
void Splay_Tree<T>::destory(Splay_Tree_Node<T> * tree)
{
	if (tree == null_node)
	{
		break;
	}
	destory(tree->left);
	destory(tree->right)£»
		delete tree;
}

template <class T>
Splay_Tree<T>::~Splay_Tree()
{
	destory(tree);
	delete null_node;
}

template <class T>
Splay_Tree_Node<T> * Splay_Tree<T>::Splay(T val, Splay_Tree_Node<T> * pos)
{
	static Splay_Tree_NodeM<T> Header;
	Splay_Tree_Node<T> * left_tree_max;
	Splay_Tree_Node<T> * right_tree_min;

	Header.left = Header.right = null_node;
	left_tree_max = right_tree_min = &Header;
	null_node->val = val;

	while (val != pos->val)
	{
		if (val < pos->val)
		{
			if (val < pos->left->val)
			{
				// 				pos = single_rotation_left(pos);
			}

			if (pos->left == null_node)
			{
				break;
			}

			right_tree_min->left = pos;
			right_tree_min = pos;
			pos = pos->left;
		}
		else {
			if (val > pos->right->val)
			{
				pos = single_rotation_right(pos);
			}

			if (pos->right == null_node)
			{
				break;
			}
			left_tree_min->right = pos;
			left = pos;
			pos = pos->right;
		}

		left_tree_max->left = pos->left;
		right_tree_min->right = pos->right;
		pos->left = Header.left;
		pos->right = Header.right;

		return pos;
	}
}

template <class T>
Splay_Tree<T>::Splay_Tree()
{
	null_node = new Splay_Tree_Node<T>;
	tree = null_node->left = null_node->right = null_node;
	
}