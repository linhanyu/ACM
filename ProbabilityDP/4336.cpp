//
// Created by Henry on 16/11/12.
//

#include <cstdio>
#include <memory.h>
const int MAXN = 21;

double dp[1<<MAXN];
double p[MAXN];
double tt;

int n;

void solve(){


    tt = 1-tt;
    dp[(1<<n)-1] = 0;
    for (int i = (1<<n) - 2 ; i >=0 ; --i) {
        double x = 0,sum = 1;
        for (int j = 0; j < n; ++j) {
            int cur = 1<<j;
            if (cur & i){
                x += p[j];
            } else{
                sum += p[j] * dp[i|cur];
            }
        }

        dp[i] = sum/(1-x-tt);
    }

    printf("%.5lf\n",dp[0]);

}


int main(){
    while(~scanf("%d",&n)){
        tt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf",&p[i]);
            tt += p[i];
        }

        solve();
    }
}