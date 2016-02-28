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
	~Splay_Tree();

private:
	Splay_Tree_Node<T> * null_node;
	Splay_Tree_Node<T> * tree;

	Splay_Tree_Node<T> * Splay(T val, Splay_Tree_Node<T> * pos);
};

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
	}
}

template <class T>
Splay_Tree<T>::Splay_Tree()
{
	null_node = new Splay_Tree_Node<T>;
	null_node->left = null_node->right = null_node;
}