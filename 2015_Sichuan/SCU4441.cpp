//
// Created by Henry on 16/11/22.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

#define lowbit(x) (x&(-x))
using namespace std;

const int MAXN = 100000 + 10000;
const int MAXT = 10000 + 10;
const int INF = 0x3f3f3f3f;

int n,cur,ans;
int A[MAXN],C[MAXN];
int f1[MAXN],f2[MAXN];
int tree[MAXT];
int ss[20];

void init(){
    cur = 0;
    ans = 0;
}

int getmax(int id){
    int re = 0;
    while (id){
        re = max(re,tree[id]);
        id -= lowbit(id);
    }

    return re;
}

void add(int id,int val){
    if (id == 0) return;

    for (int i = id; i <= 10000 ; i += lowbit(i)) {
        tree[i] = max(tree[i],val);
    }
}



int solve(int head){

    memset(tree,0, sizeof(tree));

    int tmp;
    f1[0] = 0;
    for (int i = head+1; i < head+n; ++i) {
        if (C[i] == 10000){
            f1[i-head] = f1[i-head-1];
            continue;
        }

        tmp = getmax(10000 - C[i] + 1) + C[i];
        f1[i-head] = max(f1[i-head-1],tmp);
        add(10000 - C[i] + 1,tmp);
    }

    memset(tree,0, sizeof(tree));

    f2[n] = 0;
    for (int i = head+n-1; i >= head+1 ; --i) {
        if (C[i] == 10000){
            f2[i-head] = f2[i-head+1];
            continue;
        }

        tmp = getmax(10000 - C[i] + 1) + C[i];
        f2[i-head] = max(tmp,f2[i-head+1]);
        add(10000 - C[i] + 1,tmp);
    }

    int re = 0;
    for (int i = 0; i < n; ++i) {
        re = max(re,f1[i] + f2[i+1]);
    }

    return re;
}

int main(){
    while (~scanf("%d",&n)){
        init();

        for (int i = 0; i < n; ++i) {
            scanf("%d",&A[i]);
            C[i] = A[i];
            C[i+n] = A[i];

            if (A[i] == 10000) ss[cur++] = i;
        }

        for (int i = 0; i < cur; ++i) {
            ans = max(ans,solve(ss[i]));
        }

        printf("%d\n",ans + 10000);
    }
}