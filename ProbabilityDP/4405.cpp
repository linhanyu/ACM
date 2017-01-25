//
// Created by Henry on 16/11/5.
//

#include <cstdio>
#include <memory.h>

const int step = 6;
const int MAXN = 100000 + 10;
const int MAXM = 1000 + 10;

double dp[MAXN];
int rls[MAXN];

int n,m;

void init(){
    memset(rls,0, sizeof(rls));
}

void solve(){



    for (int i = 0; i < step; ++i) {
        dp[n+i] = 1/step;
    }

    for (int i = n -1 ; i >= 0 ; --i) {

        if (rls[i]){
            dp[i] = dp[rls[i]];
            continue;
        }

        dp[i] = 1;
        for (int j = 1; j <= step ; ++j) {

            dp[i] += dp[i+j]/6;
        }
    }

    printf("%.4lf\n",dp[0]);
}

int main(){

    while (~scanf("%d%d",&n,&m) && (n || m)){
        init();

        for (int i = 0; i < m; ++i) {
            int a,b;
            scanf("%d%d",&a,&b);
            rls[a] = b;
        }

        solve();
    }
}