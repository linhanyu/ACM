#include <cstdio> 
#include <ctime>
#include <iostream>

using namespace std;



enum PARTICULAT_NUM{INFINITY_POSSITIVE=1<<30};

template<class T>
class Treaps_Node
{
public:
	T val;
	Treaps_Node * left;
	Treaps_Node * right;
	int priority;

};

template<class T>
class Treap
{
public:
	Treap();


	void insert(T val);
	void Delete(T val);


	~Treap();

private:
	Treaps_Node<T> * null_node;
	Treaps_Node<T> * treap;
	
	Treaps_Node<T> * single_rotation_left(Treaps_Node<T> * tp);
	Treaps_Node<T> * single_rotation_right(Treaps_Node<T> * tp);
	Treaps_Node<T> * Insert(T val, Treaps_Node<T> * tp);
	Treaps_Node<T> * Remove(T val, Treaps_Node<T> * tp);

	void destory(Treaps_Node<T> * tp);

};

template<class T>
Treap<T>::Treap()
{
	null_node = new Treaps_Node<T>;
	null_node->left = null_node->right = null_node;
	null_node->priority = INFINITY_POSSITIVE;
	treap = null_node;
}

template<class T>
void Treap<T>::insert(T val)
{
	treap = Insert(val, treap);
}

template<class T>
void Treap<T>::Delete(T val)
{
	treap = Remove(val, treap);
}

template<class T>
Treap<T>::~Treap()
{
	destory(treap);
	delete null_node;
}

template<class T>
Treaps_Node<T>* Treap<T>::single_rotation_left(Treaps_Node<T>* tp)
{
	Treaps_Node<T> * tmp = tp->left;
	tp->left = tmp->right;
	tmp->right = tp;

	return tmp;
}

template<class T>
Treaps_Node<T>* Treap<T>::single_rotation_right(Treaps_Node<T>* tp)
{
	Treaps_Node<T> * tmp = tp->right;
	tp->right = tmp->left;
	tmp->left = tp;

	return tmp;
}

template<class T>
Treaps_Node<T>* Treap<T>::Insert(T val, Treaps_Node<T>* tp)
{
	if (tp == null_node)
	{
		tp = new Treaps_Node<T>;
		tp->val = val;
		tp->left = tp->right = null_node;
		srand((unsigned)time(NULL));
		tp->priority = rand()%INFINITY_POSSITIVE;
	} 
	else if(val < tp->val)
	{
		tp->left = Insert(val, tp->left);
		if (tp->left->priority > tp->priority)
		{
			tp = single_rotation_left(tp);
		}

	}
	else if(val > tp->val)
	{
		tp->right = Insert(val, tp->right);
		if (tp->right->priority < tp->priority)
		{
			tp = single_rotation_right(tp);
		}
	}

	return tp;
}

template<class T>
Treaps_Node<T>* Treap<T>::Remove(T val, Treaps_Node<T>* tp)
{
	if (tp !=null_node)
	{
		if (val<tp->val)
		{
			tp->left = Remove(val, tp->left);
		} 
		else if (val > tp->val)
		{
			tp->right = Remove(val, tp->right);
		}
		else{
			if (tp->left->priority < tp->right->priority)
			{
				tp = single_rotation_left(tp);
			} 
			else
			{
				tp = single_rotation_right(tp);
			}

			if (tp != null_node)
			{
				tp = Remove(val, tp);
			}
			else
			{
				delete tp->left;
				tp->left = null_node;
			}
		}
	} 
	return tp;
}

template<class T>
void Treap<T>::destory(Treaps_Node<T>* tp)
{
	if (tp == null_node)
	{
		return;
	}
	destory(tp->left);
	destory(tp->right);
	delete tp;
}

// int main() {
// 	Treap<int> tp;
// 	for (int i = 0; i < 9; i++)
// 	{
// 		tp.insert(i);
// 	}
// 	getchar();
// 	tp.Delete(5);
// 	getchar();
// 	return 0;
// }