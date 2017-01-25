//
// Created by Henry on 16/10/13.
//

#include <cstdio>
#include <algorithm>

#define RS rt<<1|1
#define LS rt<<1
#define MID(a,b) ((a+b)>>1)
#define lson l,mid,LS
#define rson mid+1,r,RS

using namespace std;

const int MAXN = 100000 + 10;

int msum[MAXN<<2],lsum[MAXN<<2],rsum[MAXN<<2],num[MAXN<<2],col[MAXN<<2],A[MAXN];

void pushdown(int l,int r,int rt){
    if (col[rt] == 1){
        col[RS] = col[LS] = 1;
        col[rt] = 0;

        num[rt] = l - r + 1;

    } else if (col[rt] == -1){
        col[RS] = col[LS] = -1;
        col[rt] = 0;

        num[rt] = 0;
    }
}

void pushup(int l,int r,int rt){
    num[rt] = num[LS] + num[RS];

    lsum[rt] = lsum[LS];
    rsum[rt] = rsum[RS];


    int mid = MID(l,r);
    int len = r - l + 1;

    if (lsum[rt] == len - (len>>1)) lsum[rt] += lsum[RS];
    if (rsum[rt] == len>>1) rsum[rt] += rsum[LS];

    msum[rt] = max(lsum[rt],rsum[rt]);




}

void build(int l,int r,int rt){
    if(l == r){

    }
}
