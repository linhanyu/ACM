//
// Created by Henry on 16/8/18.
//
//enum STATE{NORMAL,EMPTY};
//enum COLOR{RED,BLACK};
//
//const int BufferSize = 1024;
//
//template <class K,class T>
//struct Node{
//    K key;
//    T stData;
//    COLOR color= BLACK;
//    STATE state = EMPTY;
//
//    bool operator==(const Node<K,T> & n2){
//        return key == n2.key;
//    }
//};
//
//Node Buffer[BufferSize];
//
//template <class T,class K>
//void SwapNode(Node<T,K> & n1,Node<T,K> & n2){
//    Node<T,K> tmp;
//    tmp = n1;
//    n1 = n2;
//    n2 = tmp;
//};
//
//int Lchild(int rt){
//    return rt<<1;
//}
//
//int Rchild(int rt){
//    return rt<<1|1;
//}
//
//int Parent(int rt){
//    return rt>>1;
//}
//template <class T,class K>
//int LeftRotate(int rt){
//    Node<T,K> tmp = Buffer[rt];
//}
//
//void FixUp(int rt){
//    int ParentRt = Parent(rt);
//    int GrandRt = Parent(ParentRt);
//
//    if (Buffer[ParentRt] == Buffer[Lchild(GrandRt)]){
//        //父亲是左节点
//
//    }
//}
//void DoInsert(int rt){
//
//    if(Buffer[rt].state == EMPTY){
//        Buffer[rt].state = NORMAL;
//        Buffer[rt].stData = Buffer[0].stData;
//        Buffer[rt].key = Buffer[0].key;
//        Buffer[rt].color = RED;
//        if(Buffer[Parent(rt)].color == RED){
//            FixUp(rt);
//        }
//        Buffer[1].color = BLACK;
//        return;
//    }
//}
//
//template <class K,class T>
//void Insert(K key,T stdata){
//    //use Buffer[0] as helper
//    Buffer[0].key = key;
//    Buffer[0].stData = stdata;
//    DoInsert(1);
//}


