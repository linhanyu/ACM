//
// Created by Henry on 16/12/11.
//
#include <cstdio>
#include <memory.h>
using namespace std;

typedef long long LL;
const int MAXN = 13;

int n,m;
int G[MAXN][MAXN];
int dp[1<<MAXN][510];
int f[MAXN];

int gcd(int a,int b){
    return b ? gcd(b,a%b) : a ;
}

void init(){
    f[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        f[i] = f[i-1] * i;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    init();
    while (t--){

        scanf("%d%d",&n,&m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d",&G[i][j]);
            }
        }

        memset(dp,0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < (1 << n); ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if ((1<<j) & i){
                    cnt++;
                }
            }

            for (int j = 0; j < n; ++j) {
                if ((1<<j) & i) continue;

                for (int k = 0; k <= m; ++k) {
                    if (k + G[cnt][j]>= m){
                        dp[(1<<j)|i][m] += dp[i][k];
                    } else{
                        dp[(1<<j)|i][k + G[cnt][j]] += dp[i][k];
                    }

                }
            }

        }

        if (dp[(1<<n)-1][m] == 0){
            puts("No solution");
        } else{
            int div = gcd(dp[(1<<n)-1][m],f[n]);
            printf("%d/%d\n",f[n]/div,dp[(1<<n)-1][m]/div);
        }
    }
}
