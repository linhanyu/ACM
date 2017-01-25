//
// Created by Henry on 16/8/18.
//
#include <iostream>

using namespace std;

enum STATE{EMPTY,NORMAL};

const int BufferSize = 2048;
int HeapSize = 0;

int LChild(int rt){
    return rt<<1;
}

int RChild(int rt){
    return rt<<1|1;
}

int Parent(int rt){
    return rt>>1;
}

template <class T,class K>
struct Node{
    STATE state= EMPTY;
    T key;
    K stData;

    bool operator<(const Node<T,K> & n2) const {
        return key < n2.key;
    }
};

Node<int,int> Buffer[BufferSize];

template <class T,class K>
void SwapNode(Node<T,K> & n1,Node<T,K> & n2){
    Node<T,K> tmp;
    tmp = n1;
    n1 = n2;
    n2 = tmp;
};

void PerDown(int rt){
    //最小堆
    if(Buffer[LChild(rt)].state == EMPTY){
        return;
    }

    int NewRt = LChild(rt);
    if (Buffer[RChild(rt)].state!=EMPTY && Buffer[RChild(rt)] < Buffer[LChild(rt)]){
        NewRt = RChild(rt);
    }

    if(Buffer[NewRt] < Buffer[rt]){
        SwapNode(Buffer[NewRt],Buffer[rt]);
        PerDown(NewRt);
    }
}

void PerUp(int rt){
    if(rt == 1){
        return;
    }

    int ParentRt = Parent(rt);

    if(Buffer[rt] < Buffer[ParentRt]){
        SwapNode(Buffer[rt],Buffer[ParentRt]);
        PerUp(ParentRt);
    }
}

template <class T,class K>
void Push(T key,K stdata){
    Buffer[++HeapSize].key = key;
    Buffer[HeapSize].stData = stdata;
    Buffer[HeapSize].state =NORMAL;

    PerUp(HeapSize);
}

int Pop(){
    //return satellite data
    SwapNode(Buffer[1],Buffer[HeapSize]);
    Buffer[HeapSize--].state = EMPTY;
    PerDown(1);

    return Buffer[HeapSize+1].stData;
}


void BuildHeap(int size){
    for (int i = size>>1; i >0 ; --i) {
        PerDown(i);
    }
}
int main(){
    for (int i = 10; i >= 1 ; --i){
        Buffer[11-i].state = NORMAL;
        Buffer[11-i].stData = i;
        Buffer[11-i].key = i;
    }
    HeapSize = 10;
    BuildHeap(10);

    for (int i = 10; i >= 1 ; --i) {
        cout<<Pop()<<endl;
    }
}