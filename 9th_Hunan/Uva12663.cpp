//
// Created by Henry on 17/1/26.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;

#define L rt<<1
#define R rt<<1|1
#define lson l,mid,L
#define rson mid+1,r,R
#define MID (l+r)>>1

int T[MAXN* 10];
int col[MAXN* 10];

void pushDown(int l,int r,int rt){
    if (col[rt]){

        T[L]+=col[rt];
        T[R]+=col[rt];
        col[L] += col[rt];
        col[R] += col[rt];
        col[rt] = 0;
    }
}

void pushUp(int rt){
    T[rt] = min(T[L],T[R]);
}

void build(int l,int r,int rt){
    col[rt] = 0;
    if(l == r){
        T[rt] = 0;
        return;
    }
    int mid = MID;

    build(lson);
    build(rson);
    pushUp(rt);
//    memset(T,0, sizeof(T));
}

void update(int LB,int RB,int l,int r,int rt){
    if(LB <= l && r <= RB){
        col[rt]++;
        T[rt]++;
        return;
    }

    pushDown(l,r,rt);
    int mid = MID;
    if (LB <= mid) update(LB,RB,lson);
    if (RB > mid) update(LB,RB,rson);
    pushUp(rt);
}

int query(int k,int l,int r,int rt){

    if(T[rt] >= k){
        return r-l+1;
    }

    if(l == r)return 0;
    pushDown(l,r,rt);
    int mid = MID;
    return query(k,rson)+query(k,lson);
}

int bridge[MAXN];
//
//int BinarySearch(int key,int A[],int l,int r){
//    int mid = MID;
//    while (l <= r){
//        if (key < A[mid]) r = mid-1;
//        else if ( key > A[mid]) l = mid+1;
//        else break;
//    }
//
//    return mid;
//}

int main(){
    int n,m,k,cases = 0;
    while (~scanf("%d%d%d",&n,&m,&k)){
        build(0,n-1,1);
        for (int i = 0; i < n; ++i) {
            scanf("%d",&bridge[i]);
        }

        sort(bridge,bridge+n);

        int upper = 0;
        for (int i = 0; i < m; ++i) {
            int a,b;
            scanf("%d%d",&a,&b);
            a = upper_bound(bridge,bridge+n,a) - bridge - 1;
            update(upper,a,0,n-1,1);
            upper = upper_bound(bridge,bridge+n,b) - bridge;

        }

        printf("Case %d: %d\n",++cases,query(k,0,n-1,1));
    }
}