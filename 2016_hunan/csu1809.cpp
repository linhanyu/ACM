//
// Created by Henry on 17/1/15.
//

#include <cstdio>
#include <algorithm>

#define L(a) (a<<1)
#define R(a) (a<<1|1)
#define lson l,mid,L(rt)
#define rson mid+1,r,R(rt)
#define MID(a,b) ((a+b)>>1)
using namespace std;

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;

int T[MAXN<<2];

char str[MAXN];
int pth[MAXN];

void PushUp(int rt){
    T[rt] = min(T[L(rt)],T[R(rt)]);
}

void build(int l,int r,int rt){
    if (l == r){
        T[rt] = pth[l];
        return;
    }

    int mid = MID(l,r);
    build(lson);
    build(rson);
    PushUp(rt);
}

int query(int Lb,int Rb,int l,int r,int rt){
    if (Lb <= l && r <= Rb){
        return T[rt];
    }

    int mid = MID(l,r);

    int ans = INF;
    if (Lb <= mid) ans = min(ans,query(Lb,Rb,lson));
    if (Rb > mid) ans = min(ans,query(Lb,Rb,rson));

    return ans;
}
int main(){
    int n,q;
    while (~scanf("%d%d",&n,&q)){
        scanf("%s",str+1);
        pth[0] = 0;

        for (int i = 1; i <= n ; ++i) {
            if (str[i] == '(')pth[i] = pth[i-1] + 1;
            else pth[i] = pth[i-1] - 1;
        }

        build(1,n,1);

        while (q--){
            int a,b,ans;
            scanf("%d%d",&a,&b);

            if (a>b) swap(a,b);
            if (str[a] == str[b] || (str[a] == ')' && str[b] == '(' )){
                puts("Yes");
                continue;
            }
            ans = query(a,b-1,1,n,1);
            //前缀和 >= 0
            puts(ans < 2 ? "No" : "Yes");

        }
    }
}