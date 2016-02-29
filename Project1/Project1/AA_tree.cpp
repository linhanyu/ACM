#include <cstdio>

template<class T>
class AA_Node
{
public:
	T val;
	AA_Node<T> * left;
	AA_Node<T> * right;
	int level;

};

template<class T>
class AA_Tree
{
public:
	AA_Tree();

	void insert(T val);
	void Delete(T val);

	~AA_Tree();

private:
	AA_Node<T> * null_node;
	AA_Node<T> * tree;

	AA_Node<T> * Skew(AA_Node<T> * at);
	AA_Node<T> * Split(AA_Node<T> * at);
	AA_Node<T> * single_rotate_left(AA_Node<T> * at);
	AA_Node<T> * single_rotate_right(AA_Node<T> * at);
	AA_Node<T> * Insert(T val,AA_Node<T> * at);
	AA_Node<T> * Remove(T val, AA_Node<T> * at);

	void Destory(AA_Node<T> * tr);

	
};

template<class T>
AA_Node<T> * AA_Tree<T>::Remove(T val, AA_Node<T> * at)
{
	static AA_Node<T> * Delete_ptr;
	static AA_Node<T> * Last_ptr;

	if (at!=null_node)
	{
		Last_ptr = at;
		if (val < at->val)
		{
			at->left = Remove(val, at->left);
		}
		else
		{
			Delete_ptr = at;
			at->right = Remove(val, at->right);
		}

		if (at == Last_ptr)
		{
			if (Delete_ptr !=null_node && val == Delete_ptr->val)
			{
				Delete_ptr->val = at->val;
				Delete_ptr = null_node;
				at = at->right;
				delete Last_ptr;
			}
		}

		else if (at->left->level < at->level -1 || at->right->level < at->level -1)
		{
			if (at->right->level > --at->level)
			{
				at->right->level = at->level;
			}

			at = Skew(at);
			at->right = Skew(at->right);
			at->right->right = Skew(at->right->right);
			at = Split(at);
			at->right = Split(at->right);


		}

		return at;
	}
	


}

template<class T>
void AA_Tree<T>::Destory(AA_Node<T>* tr)
{
	if (tr == null_node)
	{
		return;
	}
	Destory(tr->left);
	Destory(tr->right);
	delete tr;
}

template<class T>
AA_Tree<T>::AA_Tree()
{
	null_node = new AA_Node<T>;
	null_node->left = null_node->right = null_node;
	null_node->level = 0;
	tree = null_node;
}

template<class T>
void AA_Tree<T>::insert(T val)
{
	tree = Insert(val, tree);
}

template<class T>
void AA_Tree<T>::Delete(T val)
{
	tree = Remove(val, tree);
}

template<class T>
AA_Tree<T>::~AA_Tree()
{
	Destory(tree);
	delete null_node;
}

template<class T>
AA_Node<T>* AA_Tree<T>::Skew(AA_Node<T> * at)
{
	if (at->left->level == at->level)
	{
		at = single_rotate_left(at);
	}
	return at;
}

template<class T>
AA_Node<T> * AA_Tree<T>::Split(AA_Node<T>* at)
{
	if (at->right->right->level == at->level)
	{
		at = single_rotate_right(at);
		at->level++;
	}
	return at;
}

template<class T>
AA_Node<T>* AA_Tree<T>::single_rotate_left(AA_Node<T>* at)
{
	AA_Node<T> * tmp = at->left;
	at->left = tmp->right;
	tmp->right = at;

	return tmp;
}

template<class T>
AA_Node<T>* AA_Tree<T>::single_rotate_right(AA_Node<T>* at)
{
	AA_Node<T> * tmp = at->right;
	at->right = tmp->left;
	tmp->left = at;

	return tmp;
}

template<class T>
AA_Node<T>* AA_Tree<T>::Insert(T val, AA_Node<T>* at)
{
	if (at == null_node)
	{
		at = new AA_Node<T>;
		at->val = val;
		at->level = 1;
		at->left = at->right = null_node;
		return at;
	}
	else if(val<at->val) {
		at->left = Insert(val, at->left);
	}
	else if(val>at->val)
	{
		at->right = Insert(val, at->right);
	}

	at = Skew(at);
	at = Split(at);
	return at;
}


// int main() {
// 	AA_Tree<int> at; 
// 
// 	for (int i = 0; i < 8; i++)
// 	{
// 		at.insert(i);
// 	}
// 	at.Delete(5);
// 	getchar();
// 	return 0;
// }