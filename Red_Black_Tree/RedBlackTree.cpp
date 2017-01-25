//
// Created by Henry on 16/8/18.
//
#include <iostream>
#include <vector>

using namespace std;

enum COLOR{RED,BLACK};
template <class K,class T> struct Node;
template <class K,class T> struct RTree;


template <class K,class T>
class Node{
public:
    K key;
    T stdata;
    COLOR color;
    Node * L;
    Node * R;
    Node * P;

    bool operator==(const Node & n2) const { return key == n2.key;}
    bool operator<(const Node & n2) const { return key < n2.key;}
};



template <class K,class T>
class Rtree {
public:

    Node<K,T> *root;
    Node<K,T> setinal;
    Rtree() {
        setinal.color = BLACK;
        setinal.L = setinal.R = &setinal;
        root = &setinal;
    }

    void Insert(K & key,T & stData);
    void Delete(Node<K,T> * rt);
    void InsertFix(Node<K,T> * rt);
    void DeleteFix(Node<K,T> * rt);
    void Destory(Node<K,T> * rt);

    Node<K,T> * Find(K & key);
    Node<K,T> * Find(K & key,Node<K,T> * rt);
    Node<K,T> * LeftRotation(Node<K,T> * rt);
    Node<K,T> * RightRotation(Node<K,T> * rt);
    Node<K,T> * Minimal(Node<K,T> * rt);
    Node<K,T> * Maximal(Node<K,T> * rt);
    Node<K,T> * Successor(Node<K,T> * rt);
    Node<K,T> * Precessor(Node<K,T> * rt);

    T operator[](K & key);

    ~Rtree(){
        if(root != &setinal)
        Destory(root);

    }
};


template <class K,class T>
void Rtree<K,T>::Insert(K &key, T & stData) {
    Node<K,T> * cur = root;
    Node<K,T> * parent = &setinal;

    while(cur != &setinal){
        parent = cur;
        if (cur->key < key){
            cur = cur->L;
        } else if (cur->key > key){
            cur = cur->R;
        } else{
            return;
        }
    }

    cur = new Node<K,T>();
    cur->L = cur->R = &setinal;
    cur->color = RED;
    cur->stdata = stData;
    cur->key = key;
    cur->P = parent;

    if(parent == &setinal){
        root = cur;
    } else if(parent->key < key){
        //右树
        parent->R = cur;
    } else{
        parent->L = cur;
    }

//    InsertFix(cur);


}
template <class K,class T>
void Rtree<K,T>::Destory(Node<K, T> * rt) {
    if (rt == &setinal) return;
    Destory(rt->L);
    Destory(rt->R);
    delete rt;
}

template <class K,class T>
Node<K, T> * Rtree<K,T>:: LeftRotation(Node<K, T> *rt) {
    Node<K,T> * P = rt->P;
    Node<K,T> * New = rt->R;
    //保存好P和新节点
    rt->R = New->L;
    New->L->P = rt->R;
    //左子树给原节点
    rt->P = New;
    New->L = rt;
    //把rt粘给新节点
    New->P = P;
    //粘回去
    return New;
}

template <class K,class T>
Node<K, T> * Rtree<K,T>:: RightRotation(Node<K, T> *rt) {
    Node<K,T> * P = rt->P;
    Node<K,T> * New = rt->L;
    //保存好P和新节点
    rt->L = New->R;
    New->R->P = rt->L;
    //左子树给原节点
    rt->P = New;
    New->R = rt;
    //把rt粘给新节点
    New->P = P;
    //粘回去
    return New;
}
template<class T,class K>
Node<K, T> * Rtree<K,T>::Find(K &key) {
    Find(key,root);
}

template<class T,class K>
Node<K, T> * Rtree<K,T>::Find(K &key,Node<K,T> * rt) {
    Node<K,T> * cur = root;
    while(cur != &setinal){
        if(key < cur->key){
            cur = cur->L;
        } else if(cur->key < key){
            cur = cur->R;
        } else{
            break;
        }
    }

    return cur;
}

template<class T,class K>
Node<K, T> *Rtree<K,T>::Minimal(Node<K, T> * rt) {
    Node<K,T> * cur = rt;
    return nullptr;
}




int main(){

}