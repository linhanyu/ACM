#include <cstdio>

static enum PARTICULAR_VALUE{INFINITY_POSSITIVE = 1<<30};

template<class T>
class SkipNode {
	T val;
	SkipNode * right;
	SkipNode * down;

};

template<class T>
class Skip_List
{
public:
	Skip_List();
	~Skip_List();

private:
	SkipNode<T> * bottom;
	SkipNode<T> * tail;
	SkipNode<T> * list;

	SkipNode<T> * Find(T val, SkipNode<T> * ls);
	SkipNode<T> * Insert(T val, SkipNode<T> * ls);

};

template<class T>
Skip_List<T>::Skip_List()
{
	bottom = new SkipNode<T>;
	bottom->right = bottom->down = bottom;

	tail = new SkipNode<T>;
	tail->val = INFINITY_POSSITIVE;
	tail->right = tail;

	list = new SkipNode<T>;
	list->val = INFINITY_POSSITIVE;
	list->down = bottom;
	list->right = tail;

}

template<class T>
Skip_List<T>::~Skip_List()
{
}

template<class T>
SkipNode<T>* Skip_List<T>::Find(T val, SkipNode<T>* ls)
{
	SkipNode<T> pos = ls;
	bottom->val = val;
	while (val!=pos->val)
	{
		if (val<pos->val)
		{
			pos = pos->down;
		}
		else
		{
			pos = pos->right;
		}
	}

	return pos;
}

template<class T>
SkipNode<T>* Skip_List<T>::Insert(T val, SkipNode<T>* ls)
{
	SkipNode<T> * pos = ls;
	SkipNode<T> * new_node;
	bottom->val = val;

	while (pos != bottom)
	{
		while (val > pos->val)
		{
			pos = pos->right;
		}

		if (pos->val > pos->down->right->right->val)
		{
			new_node = new SkipNode<T>;
			new_node->right = pos->right;
			new_node->down = pos->down->right->right;
			pos->right = new_node;
			new_node->val = pos->val;
			pos->val = pos->down->right->val;

		}
		else
		{
			pos = pos->down;
		}

	}

	return ls;
}
