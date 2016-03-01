#include <cstdio>


template <class T>
class two_d_tree_node
{
public:
	T * val;
	two_d_tree_node<T> * left;
	two_d_tree_node<T> * right;
	~two_d_tree_node() { delete[] val; };
};

template <class T>
class two_d_tree
{
public:
	two_d_tree();
	void Insert(T val1,T val2);
	void Do_Reange(T low_1, T high_1, T low_2, T high_2,void(*func)(T val_1, T val_2));
	~two_d_tree() { destory(tree); };

private:
	two_d_tree_node<T> * tree;
	two_d_tree_node<T> * insert(T val[], two_d_tree_node<T> * tree, int level)
		;
	void do_range(T * low, T * hight, two_d_tree_node<T> * tree, int level, void(*func)(T val1, T val2));
	void destory(two_d_tree_node<T> * tree);
};

template <class T>
void two_d_tree<T>::Do_Reange(T low_1, T high_1, T low_2, T high_2, void(*func)(T val_1, T val_2))
{
	T low[2];
	T high[2];
	low[0] = low_1;
	low[1] = low_2;
	high[0] = high_1;
	high[1] = high_2;
	do_range(low, high, tree, 0, func);
	
}

template <class T>
two_d_tree_node<T> * two_d_tree<T>:: insert(T val[], two_d_tree_node<T> * tree, int level)
{
	if (tree == nullptr)
	{
		tree = new two_d_tree_node<T>;
		tree->left = tree->right = nullptr;
		tree->val = val;
	}
	else if(val[level] < (tree->val)[level])
	{
		tree->left = insert(val, tree->left, !level);

	}
	else
	{
		tree->right = insert(val, tree->right, !level);

	}

	return tree;
}

template<class T>
void two_d_tree<T>::do_range(T * low, T * hight, two_d_tree_node<T>* tree, int level, void(*func)(T val1, T val2))
{
	if (tree !=nullptr)
	{
		if (low[0] <= tree->val[0] && tree->val[0] <= hight[0] && low[1] <= tree->val[1] && tree->val[1] <= hight[1]) {
			(*func)(tree->val[0], tree->val[1]);
		}

		if (low[level] <= tree->val[level])
		{
			do_range(low, hight, tree->left,!level, func);
		}

		if (hight[level] >= tree->val[level])
		{
			do_range(low, hight, tree->right, !level, func);

		}
	}
}

template<class T>
void two_d_tree<T>::destory(two_d_tree_node<T>* tree)
{
	if (tree == nullptr)
	{
		return;
	}

	destory(tree->left);
	destory(tree->right);
	delete tree;
}

template <class T>
two_d_tree<T>::two_d_tree():tree(nullptr)
{
}

template<class T>
void two_d_tree<T>::Insert(T val1, T val2)
{
	T * tmp = new T[2];
	tmp[0] = val1;
	tmp[1] = val2;
	tree = insert(tmp, tree, 0);
}


template <class T>
void rec_print(T val_1, T val_2) {
	printf("val_1:%d\tval_2:%d\n",val_1,val_2);
}

// int main() {
// 	two_d_tree<int> tdt;
// 	for (int i = 0, j = 1; i < 10;i++,j<<=1)
// 	{
// 		tdt.Insert(i, j);
// 	}
// 	tdt.Do_Reange(2, 8, 1, 64, rec_print);
// 	getchar();
// 	return 0;
// 
// }