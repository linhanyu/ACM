#include <cstdio>

enum PARTICULAR_VALUE{INFINITY_POSSITIVE = 1<<30};

template<class T>
class SkipNode {
public:
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

	void Insert(T val);
	
	bool is_in_list(T val);
private:
	SkipNode<T> * bottom;
	SkipNode<T> * tail;
	SkipNode<T> * list;

	SkipNode<T> * Find(T val, SkipNode<T> * ls);
	SkipNode<T> * Insert(T val, SkipNode<T> * ls);

	void Destory(SkipNode<T> * ls);

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
	Destory(list);
	delete bottom;
	delete tail;
}

template<class T>
void Skip_List<T>::Insert(T val)
{
	list = Insert(val, list);
}

template<class T>
bool Skip_List<T>::is_in_list(T val)
{
	return Find(val, list) != bottom;
}

template<class T>
SkipNode<T>* Skip_List<T>::Find(T val, SkipNode<T>* ls)
{
	SkipNode<T> * pos = ls;
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

	if (ls->right != tail)
	{
		new_node = new SkipNode<T>;
		new_node->down = ls;
		new_node->right = tail;
		new_node->val = INFINITY_POSSITIVE;
		ls = new_node;
	}

	return ls;
}

template<class T>
void Skip_List<T>::Destory(SkipNode<T>* ls)
{
	if (ls == bottom || ls==tail)
	{
		return;
	}

	Destory(ls->right);
	Destory(ls->down);
	delete ls;
}

// int main() {
// 	Skip_List<int> sl;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		sl.Insert(i);
// 	}
// 	bool flag;
// 	int temp;
// 	while (1)
// 	{
// 		scanf_s("%d", &temp);
// 		printf("%d", sl.is_in_list(temp));
// 	}
// }