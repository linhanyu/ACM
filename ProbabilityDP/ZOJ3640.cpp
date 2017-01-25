


#include <cstdio>
#include <memory.h>
#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 110;
const int MAXF = 10000+0;
const double FAC = (sqrt(5)+1.0)*0.5;

double t[MAXN],dp[MAXF];
int c[MAXN];
int n,f;

double dfs(int f){

    if (dp[f]) return dp[f];

    for (int i = 0; i < n; ++i) {
        if (f > c[i]){
            dp[f] += t[i]/n;
        } else{
            dp[f] += (1+dfs(f+c[i]))/n;
        }
    }

    return dp[f];
}

void init(){
    memset(dp,0, sizeof(dp));
}

int main(){
    while (~scanf("%d%d",&n,&f)){
        init();
        for (int i = 0; i < n; ++i) {
            scanf("%d",&c[i]);
            t[i] = int(c[i]*c[i]*FAC);
        }

        printf("%.3lf\n",dfs(f));
    }
}

