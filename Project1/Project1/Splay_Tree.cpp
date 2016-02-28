template<class T>
class Splay_Tree_Node
{
public:
	T val;
	splay_tree_node * left;
	splay_tree_node * right;
};

template <template T>
class Splay_Tree
{
public:
	Splay_Tree();
	~Splay_Tree();

private:
	Splay_Tree_Node * null_node;
	Splay_Tree_Node * header;
	Splay_Tree_Node * tree;
};


template<template T>
Splay_Tree<T>::Splay_Tree()
{
	int b;
	null_node = new Splay_Tree_Node;
	null_node->left = null_node->right = null_node;
}


