//
// Created by Henry on 17/2/6.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef unsigned long long uLL;

const int MAXN = 100 + 10;

uLL A[MAXN];
int n;



uLL dfs(int pos,uLL num){
    if (num == 0) return 0;

    if (pos >= n) return num;

    uLL ans = dfs(pos + 1 , num ^ A[pos]);
    if (ans == 0) return 0;
    ans = min(ans,dfs(pos + 1 , num | A[pos]));
    if (ans == 0) return 0;
    ans = min(ans,dfs(pos + 1 , num & A[pos]));
    if (ans == 0) return 0;
    ans = min(ans,dfs(pos + 1 , num | ~A[pos]));
    if (ans == 0) return 0;
    ans = min(ans,dfs(pos + 1 , num ^ ~A[pos]));
    if (ans == 0) return 0;
    ans = min(ans,dfs(pos + 1 , num & ~A[pos]));
    if (ans == 0) return 0;


    return ans;
}



int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        printf("Case #%d: ",cases);


        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            scanf("%llu",&A[i]);
        }

        printf("%llu\n",min(dfs(1,A[0]),dfs(1,~A[0])));

    }
}