//
// Created by Henry on 16/7/9.
//
#include <cstdio>
#include <memory>

#include <algorithm>

#define L_Child(a) (a<<1)
#define R_Child(a) ((a<<1) | 1)


#define NUM 11111
#define MID(a,b) ((a+b)>>1)
using namespace std;

int left[NUM],right[NUM],X[NUM*3];
int col[NUM<<4],cnt;
bool flag[NUM];


int Binary_Serch(int ar[],int left,int right,int key){

    while (left <= right){

        int mid = MID(left,right);

        if (key < ar[mid]){
            right = mid-1;
        } else if (key > ar[mid]){
            left = mid+1;
        } else{
            return mid;
        }
    }
    return -1;
}

int val,up_L,up_R;//
void PushDown(int rt){
    if (col[rt] != -1){
        col[L_Child(rt)] = col[R_Child(rt)] = col[rt];
        col[rt] = -1;
    }
}

void update(int left,int right,int rt){
    if ( up_L <= left && right <= up_R ){
        col[rt] = val;
        return;
    }

    PushDown(rt);
    int mid = MID(left,right);

    if (up_L <= mid){update(left,mid,L_Child(rt));}
    if (up_R > mid){update(mid + 1,right,R_Child(rt));}
}
void query(int left,int right,int rt){
    if (col[rt]!=-1){
        if (!flag[col[rt]]){
            cnt++;
            flag[col[rt]] = true;
        }
        return;
    }

    if (left == right){
        return;
    }

    int mid = MID(left,right);
    query(left,mid,L_Child(rt));
    query(mid+1,right,R_Child(rt));
}
int main(){
    int c,n,m,k;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        m=0,k=1,cnt=0;

        for (int i = 0; i < n; ++i) {
            scanf("%d %d",left + i,right + i);
            X[m++] = left[i];
            X[m++] = right[i];
        }

        sort(X,X+m);
        //离散化,去除重复数据
        for (int i = 1; i < m; ++i) {
            if (X[i] != X[i-1])
                X[k++] = X[i];
        }

        //在间隔大于1的点间插点
        for (int i = k-1; i > 0 ; --i) {
            if (X[i] != X[i-1]+1)
                X[k++] = X[i-1]+1;
        }
        sort(X,X+k);
        //0~k的线段树
        memset(col,-1,sizeof(col));
        //只有-1和0可以正常set
        memset(flag,0,sizeof(flag));


        for (int i = 0; i < n; ++i) {
            up_L=Binary_Serch(X,0,k,left[i]);
            up_R=Binary_Serch(X,0,k,right[i]);
            val = i;
            update(0,k,1);
        }
        query(0,k,1);
        //改变cnt的值
        printf("%d\n",cnt);
    }
}