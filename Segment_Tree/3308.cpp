//
// Created by Henry on 16/10/12.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

#define LS rt<<1
#define RS rt<<1|1
#define MID(l,r) ((l+r)>>1)
#define lson l,mid,LS
#define rson mid+1,r,RS

const int MAXN = 100000 + 10;

int msum[MAXN << 2];
int lsum[MAXN << 2];
int rsum[MAXN << 2];
int num[MAXN];

void pushup(int l,int r,int rt){
    lsum[rt] = lsum[LS];
    rsum[rt] = rsum[RS];
    msum[rt] = max(msum[LS],msum[RS]);

    int mid = MID(l,r);
    int len = r - l + 1;

    if (num[mid] < num[mid + 1]){

        if (lsum[rt] == len - (len>>1)){
            lsum[rt] += lsum[RS];
        }

        if (rsum[rt] == len>>1){
            rsum[rt] += rsum[LS];
        }

        msum[rt] = max(msum[rt],lsum[RS] + rsum[LS]);
    }
}


void build(int l,int r,int rt){
    if (l == r){
        msum[rt] = lsum[rt] = rsum[rt] = 1;

    } else{
        int mid = MID(l,r);
        build(lson);
        build(rson);
        pushup(l,r,rt);
    }
}

void update(int pos,int key,int l,int r,int rt){
    if (l == r){
        num[l] = key;
//        pushup(l,r,rt);
        return;
    }

    int mid = MID(l,r);
    if (pos <= mid) update(pos,key,lson);
    else update(pos,key,rson);

    pushup(l,r,rt);
}

int query(int L,int R,int l,int r,int rt){
    if (L <= l && r <= R){
        return msum[rt];
    }

    int mid = MID(l,r);
    if (R <= mid) return query(L,R,lson);
    if (L > mid) return query(L,R,rson);

    int a,b,ans;
    a = query(L,R,lson);
    b = query(L,R,rson);
    ans = max(a,b);

    if (num[mid] < num[mid + 1]){
        ans = max(min(lsum[RS],R-mid) + min(rsum[LS] , mid - L + 1),ans);
    }

    return ans;
}

//void init(){
////    memset(Buffer,0, sizeof(Buffer));
////    memset(col,0, sizeof(col));
//}
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int n,m;
        scanf("%d %d",&n,&m);

        for (int i = 0; i < n; ++i) {
            scanf("%d",&num[i]);
        }


        build(0,n-1,1);

        char op[100];
        int a,b;
        for (int i = 0; i < m; ++i) {
            scanf("%s %d %d",op,&a,&b);
            if (op[0] == 'Q'){
                printf("%d\n",query(a,b,0,n-1,1));
            } else{
                update(a,b,0,n-1,1);
            }
        }
    }
}
//int main()
//{
//    int t;
//    scanf("%d",&t);
//    while(t--)
//    {
//        int n,m;
//        scanf("%d%d",&n,&m);
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%d",&num[i]);
//        }
//        build(1,n,1);
//        while(m--)
//        {
//            char op[121];
//            scanf("%s",op);
//            int a,b;
//            scanf("%d%d",&a,&b);
//            if(op[0]=='U')
//            {
//                a++;
//                update(a,b,1,n,1);
//            }
//            else
//            {
//                a++;
//                b++;
//                printf("%d\n",query(a,b,1,n,1));
//            }
//        }
//    }
//}

