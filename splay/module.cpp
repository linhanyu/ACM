//
// Created by Henry on 17/1/24.
//

#include <cstdio>

const int MAXG = 1000;

struct node{
    int key;
    int l;
    int r;
    bool d;
} TG[MAXG];

struct Splaytree{
    int t;
    int num;

    Splaytree():t(-1),num(0){}

    void Insert(int key){
        t = Insert(key,t);
    }

    int RightRotate(int t){
        int newt = TG[t].l;
        TG[t].l = TG[newt].r;
        TG[newt].r = t;

        return newt;
    }

    int LeftRotate(int t){
        int newt = TG[t].r;
        TG[t].r = TG[newt].l;
        TG[newt].l = t;

        return newt;
    }
    int Insert(int key, int t){
        if (~t){
            if (key < TG[t].key){
                TG[t].l = Insert(key,TG[t].l);
                return RightRotate(t);
            } else if (key > TG[t].key){
                TG[t].r = Insert(key,TG[t].r);
                return LeftRotate(t);
            } else{
                return t;
            }
        } else{
            TG[num].l = TG[num].r = -1;
            TG[num].key = key;
            TG[num].d = false;
            return num++;
        }
    }

    int DeleteMin(){
        int x = t;
        int pre = t;
        while (~x) {
            pre = x;
            x = TG[x].l;
        }
        return pre;
    }

    int DeleteMax(){
        int x = t;
        int pre = t;
        while (~x) {
            pre = x;
            x = TG[x].r;
        }
        return pre;
    }


    void clear(){
        num = 0;
    }

} tree;