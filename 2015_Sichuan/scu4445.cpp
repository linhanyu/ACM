//
// Created by Henry on 16/11/20.
//
#include <cstdio>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1000 + 10;
const int INF = 0x3f3f3f3f;

struct node{
    int x,y;
};

struct cmpx{
    bool operator()(const node & n1,const node & n2) const {
        if (n1.x == n2.x) return n1.y < n2.y;
        return n1.x < n2.x;
    }
};

struct cmpy{
    bool operator()(const node & n1,const node & n2) const{
        if (n1.y == n2.y) return n1.x < n2.x;
        return n1.y < n2.y;
    }
};


int BinarySearchUpperx(int key,node A[],int left,int right){
    while (left <= right){
        int mid = (left+right)>>1;
        if (key < A[mid].x) right = mid-1;
        else left = mid + 1;
    }

    return left;
}

int BinarySearchUppery(int key,node A[],int left,int right){
    while (left <= right){
        int mid = (left+right)>>1;
        if (key < A[mid].y) right = mid-1;
        else left = mid + 1;
    }

    return left;
}

int BinarySearchLowerx(int key,node A[],int left,int right){
    while (left <= right){
        int mid = (left+right)>>1;
        if (key > A[mid].x) left = mid+1;
        else right = mid - 1;
    }

    return left;
}

int BinarySearchLowery(int key,node A[],int left,int right){
    while (left <= right){
        int mid = (left+right)>>1;
        if (key > A[mid].y) left = mid+1;
        else right = mid - 1;
    }

    return left;
}



node xlist[MAXV],ylist[MAXV];

int main(){
    int n;
    while (~scanf("%d",&n)){
        for (int i = 0; i < n; ++i) {
            scanf("%d%d",&xlist[i].x,&xlist[i].y);
        }

        memcpy(ylist,xlist, sizeof(node)*n);
        sort(xlist,xlist + n,cmpx());
        sort(ylist,ylist + n,cmpy());

        int dir = 0;
        int MaxStep = 4*n+1;
        int step = 0;
        int x=0,y=0;
        while (step < MaxStep){
            int st,ed;
            int pos;
            switch (dir){
                case 0:
                    //右
//                    st = lower_bound(xlist,xlist+n,x,cmpBinaryx()) - xlist;
//                    ed = upper_bound(xlist,xlist+n,x,cmpBinaryx()) - xlist;
                    ed = BinarySearchUppery(y,ylist,0,n-1);
                    st = BinarySearchLowery(y,ylist,0,n-1);
                    pos = INF;

                    for (int i = st; i < ed; ++i) {
                        if (ylist[i].x > x && ylist[i].x < pos ) pos = ylist[i].x;
                    }

                    x = pos - 1;

                    dir = 1;
                    break;
                case 1:
                    //下
                    ed = BinarySearchUpperx(x,xlist,0,n-1);
                    st = BinarySearchLowerx(x,xlist,0,n-1);
//                    st = lower_bound(ylist,ylist+n,y,cmpBinaryy()) - ylist;
//                    ed = upper_bound(ylist,ylist+n,y,cmpBinaryy()) - ylist;
                    pos = -INF;

                    for (int i = st; i < ed; ++i) {
                        if (xlist[i].y < y && xlist[i].y > pos ) pos = xlist[i].y;
                    }

                    y = pos + 1;

                    dir = 2;
                    break;
                case 2:
                    //左
                    ed = BinarySearchUppery(y,ylist,0,n-1);
                    st = BinarySearchLowery(y,ylist,0,n-1);
//                    st = lower_bound(xlist,xlist+n,x,cmpBinaryx()) - xlist;
//                    ed = upper_bound(xlist,xlist+n,x,cmpBinaryx()) - xlist;
                    pos = -INF;

                    for (int i = st; i < ed; ++i) {
                        if (ylist[i].x < x && ylist[i].x > pos ) pos = ylist[i].x;
                    }

                    x = pos + 1;

                    dir = 3;
                    break;
                case 3:
                    //上
                    ed = BinarySearchUpperx(x,xlist,0,n-1);
                    st = BinarySearchLowerx(x,xlist,0,n-1);
//                    st = lower_bound(ylist,ylist+n,y,cmpBinaryy()) - ylist;
//                    ed = upper_bound(ylist,ylist+n,y,cmpBinaryy()) - ylist;
                    pos = INF;

                    for (int i = st; i < ed; ++i) {
                        if (xlist[i].y > y && xlist[i].y < pos ) pos = xlist[i].y;
                    }

                    y = pos - 1;

                    dir = 0;
                    break;
            }




            if (pos == INF || pos == -INF) break;
            step++;
        }

        printf("%d\n",step >= MaxStep ? -1:step);

    }

}