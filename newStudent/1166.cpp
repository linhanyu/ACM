//
// Created by Henry on 17/3/5.
//

#include <memory.h>
#include <cstdio>
#include <algorithm>

#define lowbit(x) (x&-x)

const int MAXN = 50000 + 10;

using namespace std;

int treeA[MAXN];
int n;

void update(int pos,int val){
    while (pos <= n){
        treeA[pos] += val;
        pos += lowbit(pos);
    }
}

int query(int pos){
    int ans = 0;
    while (pos){
        ans += treeA[pos];
        pos -= lowbit(pos);
    }
    return ans;
}


void init(){
    memset(treeA,0, sizeof(treeA));
}

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        printf("Case %d:\n",cases);

        init();
        scanf("%d",&n);
        int tmp1,tmp2;
        char str[30];

        for (int i = 1; i <= n ; ++i) {
            scanf("%d",&tmp1);
            update(i,tmp1);
        }

        while (scanf("%s",str) && str[0] != 'E'){
            if (str[0] == 'S'){
                scanf("%d%d",&tmp1,&tmp2);
                update(tmp1,-tmp2);
            } else if (str[0] == 'A'){
                scanf("%d%d",&tmp1,&tmp2);
                update(tmp1,tmp2);
            } else{
                scanf("%d%d",&tmp1,&tmp2);
                printf("%d\n",query(tmp2) - query(tmp1-1));
            }
        }
    }
}