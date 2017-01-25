//
// Created by Henry on 16/10/13.
//

#include <memory.h>
#include <cstdio>
#include <algorithm>

#define LS rt<<1
#define RS rt<<1|1
#define MID(a,b) ((a+b)>>1)
#define lson l,mid,LS
#define rson mid+1,r,RS

using namespace std;

const int MAXN = 50000 + 10;

int lsum[MAXN << 2],rsum[MAXN << 2],msum[MAXN<<2],cnt[MAXN<<2],lf[MAXN<<2],rf[MAXN<<2],flag[MAXN<<2];
bool reset[MAXN << 2];

void build(int l,int r,int rt){
    flag[rt] = 0;
    lsum[rt] = rsum[rt] = msum[rt] = r - l + 1;
    lf[rt] = rf[rt] = -1;
    cnt[rt] = 0;
    reset[rt] = false;

    if (l == r) return;

    int mid = MID(l,r);
    build(lson);
    build(rson);
}


void Reset(int l,int r,int rt){
    reset[rt] = true;

    lsum[rt] = rsum[rt] = msum[rt] = r-l+1;
    lf[rt] = rf[rt] = -1;
    cnt[rt] = 0;
}

void pushup(int l,int r,int rt){
    cnt[rt] = cnt[LS] + cnt[RS];
    lsum[rt] = lsum[LS];
    rsum[rt] = rsum[RS];

    int len = r-l+1;

    if (lsum[rt] == len - (len>>1)) lsum[rt] += lsum[RS];
    if (rsum[rt] == len>>1) rsum[rt] += rsum[LS];

    msum[rt] = max(lsum[rt],rsum[rt]);
    msum[rt] = max(msum[rt],rsum[LS]+lsum[RS]);


}

void pushdown(int rt,int l,int r){
    int len = r-l+1;
    if (reset[rt]){
        flag[rt] = 0;
        reset[rt] = false;
        reset[LS] = reset[RS] = true;
        cnt[LS] = cnt[RS] = flag[LS] = flag[RS] = 0;
        lf[LS] = lf[RS] = rf[LS] = rf[RS] = -1;
        msum[LS] = lsum[LS] = rsum[LS] = len - (len>>1);
        msum[RS] = lsum[RS] = rsum[RS] = len>>1;
    }

    if (flag[rt] == 1){
        flag[rt] = 0;
        flag[LS] = flag[RS] = 1;
        lsum[LS] = rsum[LS] = msum[LS] = lsum[RS] = rsum[RS] = msum[RS] = 0;
        lf[LS] = lf[RS] = lf[rt];
        rf[LS] = rf[RS] = rf[rt];

    } else if (flag[rt] == 2){
        flag[rt] = 0;
        flag[LS] = flag[RS] = 2;
        lsum[LS] = rsum[LS] = msum[LS] = len - (len>>1);
        lsum[RS] = rsum[RS] = msum[RS] = len>>1;
        lf[LS] = lf[RS] = -1;
        rf[LS] = rf[RS] = -1;
    }
}

void set_cnt(int pos,int val, int l,int r,int rt ){
    pushup(l,r,rt);
    if (l == r){
        cnt[rt] += val;
        return;
    }

    int mid = MID(l,r);

    if (pos <= mid){
        set_cnt(pos,val,lson);
    } else{
        set_cnt(pos,val,rson);
    }

    pushup(l,r,rt);
}

int main(){

}