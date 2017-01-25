//
// Created by Henry on 16/10/14.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

#define LS rt<<1
#define RS rt<<1|1
#define lson l,mid,LS
#define rson mid+1,r,RS
#define MID(l,r) ((l+r) >> 1)
using namespace std;

const int MAXN = 50000 + 10;

int lsum[MAXN<<2],rsum[MAXN<<2];

void pushup(int l,int r,int rt){
    lsum[rt] = lsum[LS];
    rsum[rt] = rsum[RS];

    int len = r-l+1;
    int mid = MID(l,r);

    if (lsum[rt] == len - (len>>1)) lsum[rt] += lsum[RS];
    if (rsum[rt] == len>>1) rsum[rt] += rsum[LS];

}

void build(int l,int r,int rt){
    lsum[rt] = rsum[rt] = r-l+1;

    if (l == r){

        return;
    }

    int mid = MID(l,r);

    build(lson);
    build(rson);
//    pushup(l,r,rt);
}

int Lquery(int L,int R,int l,int r,int rt){
    if (L <= l && r <= R){
        return lsum[rt];
    }

    int mid = MID(l,r);
    int len = r-l+1;
    int lans=0,rans=0;

    if (L <= mid) lans += Lquery(L,R,lson);
    if (R > mid ) rans += Lquery(L,R,rson);

    if (L > mid) return rans;
    if (R <= mid) return lans;
    if (lans == mid - L + 1) return lans + rans;
    return lans;
}

int Rquery(int L,int R,int l,int r,int rt){
    if (L <= l && r <= R){
        return rsum[rt];
    }

    int mid = MID(l,r);
    int len = r-l+1;
    int lans=0,rans=0;

    if (L <= mid) lans += Rquery(L,R,lson);
    if (R > mid ) rans += Rquery(L,R,rson);

    if (L > mid) return rans;
    if (R <= mid) return lans;
    if (rans == R - mid) return lans + rans;
    return rans;
}

void update(int pos,int key,int l,int r,int rt){
    if (l == r){
        lsum[rt] = rsum[rt] = key;
        return;
    }

    int mid = MID(l,r);

    if (pos <= mid) update(pos,key,lson);
    else update(pos,key,rson);

    pushup(l,r,rt);

}

int main(){
    int n,m;
    char op[50];
//    bool mark[MAXN];
    int lcmd[MAXN];
    int cur ;
    while (~scanf("%d %d",&n,&m)){
//        memset(mark,0,(n+1) * sizeof(bool));
        build(1,n,1);
        cur = 0;

        for (int i = 0; i < m; ++i) {
            int p;
            scanf("%s",op);

            if (op[0] == 'D'){
                scanf("%d",&p);
                update(p,0,1,n,1);
                lcmd[cur++] = p;
            } else if (op[0] == 'R'){
                update(lcmd[--cur],1,1,n,1);
            } else{
                scanf("%d",&p);
                int tmp = Rquery(1,p,1,n,1) + Lquery(p,n,1,n,1);
                printf("%d\n",tmp > 0 ? tmp-1:0);
            }
        }
    }
}