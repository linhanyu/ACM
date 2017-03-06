//
// Created by Henry on 17/1/24.
//

#include <cstdio>
#include <algorithm>

#define L rt<<1
#define R rt<<1|1
#define lson l,mid,L
#define rson mid+1,r,R
#define MID (l+r)>>1
using namespace std;

const int MAXG = 800000 + 10;
const int MAXN = 200000 + 10;
int T[MAXG];
int ans[MAXN],pos[MAXN],val[MAXN];

void pushUp(int rt){
    T[rt] = T[L] + T[R];
}

void build(int l,int r,int rt){
    if (l == r){
        T[rt] = 1;
        return;
    }
    int mid = MID;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int pos,int val,int l,int r,int rt){
    if (l == r){
        T[rt] = 0;
        ans[l] = val;
        return;
    }
    int mid = MID;

    if (pos <= T[L]) update(pos,val,lson);
    else update(pos - T[L],val,rson);
    pushUp(rt);
}


int main(){
    int n;
    while (~scanf("%d",&n)){
        build(1,n,1);
        for (int i = 0; i < n ; ++i) {
            scanf("%d%d",&pos[i],&val[i]);
        }

        for (int i = n-1; i >=0 ; --i) {
            update(pos[i]+1,val[i],1,n,1);
        }

        for (int i = 1; i <= n; ++i) {
            printf("%d%c",ans[i],i == n ? '\n' : ' ');
        }
    }
}


//
//struct node{
//    int id;
//    int key;
//    int l,r;
//}TG[MAXG];
//
//int SplayCur,SplayT,cnt;
//
//int RoRight(int rt){
//    int newRt = TG[rt].l;
//    TG[rt].l = TG[newRt].r;
//    TG[newRt].r = rt;
//    return newRt;
//}
//
//int RoLeft(int rt){
//    int newRt = TG[rt].r;
//    TG[rt].r = TG[newRt].l;
//    TG[newRt].l = rt;
//    return newRt;
//}
//
//int Insert(int rt,int key,int val){
//    if (~rt){
//        if (key < TG[rt].key){
//            TG[rt].l = Insert(TG[rt].l,key,val);
//            return RoRight(rt);
//        } else if(key > TG[rt].key){
//            TG[rt].r = Insert(TG[rt].r,key,val);
//            return RoLeft(rt);
//        } else{
//            swap(TG[rt].id,val);
//            TG[rt].r = Insert(TG[rt].r,key+1,val);
//            return RoLeft(rt);
//        }
//    } else{
//        TG[SplayCur].id = val;
//        TG[SplayCur].r = TG[SplayCur].l = -1;
//        TG[SplayCur].key = key;
//        return SplayCur++;
//    }
//}
//
//void init(){
//    SplayCur = 0;
//    SplayT = -1;
//    cnt = 0;
//}
//
//void prt(int rt){
//    if (~rt){
//        prt(TG[rt].l);
//        printf("%d%c",TG[rt].id,++cnt == SplayCur ? '\n' : ' ');
//        prt(TG[rt].r);
//    }
//}

