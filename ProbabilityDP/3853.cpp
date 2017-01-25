//
// Created by Henry on 16/11/12.
//

#include <cstdio>
#include <memory.h>
#include <cmath>
using namespace std;

const double eps=1e-5;
const int MAXN = 1000 + 10;

double dp[MAXN][MAXN];
double p1[MAXN][MAXN],p2[MAXN][MAXN],p3[MAXN][MAXN];


int r,c;

void solve(){


    for (int i = r; i >= 1 ; --i) {
        for (int j = c; j >= 1 ; --j) {
            if (i == r && j == c) continue;

            if (fabs(1-p1[i][j]) <= eps) continue;

            dp[i][j] = p2[i][j]/(1-p1[i][j]) * dp[i][j+1] + p3[i][j]/(1-p1[i][j]) * dp[i+1][j] + 2/(1-p1[i][j]);
        }
    }

    printf("%.3lf\n",dp[1][1]);
}

int main(){
    while (~scanf("%d%d",&r,&c)){
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                scanf("%lf %lf %lf",&p1[i][j],&p2[i][j],&p3[i][j]);

            }
        }

        solve();
    }

}