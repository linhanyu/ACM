//
// Created by Henry on 16/11/3.
//

#include <cstdio>
#include <memory.h>
using namespace std;

const int MAXT = 1000 + 10;
const int MAXM = 30 + 5;

double dp[MAXT][MAXM][MAXM];
double pb[MAXT][MAXM];
double s[MAXT][MAXM];
int m,t,n;

void solve(){
    memset(s,0, sizeof(s));
    memset(dp,0, sizeof(dp));

    for (int i = 0; i < t  ; ++i) {
        //第i队,前j题,作出共k道 
        dp[i][0][0] = 1.0;
        for (int j = 1; j <= m; ++j) {
            dp[i][j][0] = dp[i][j-1][0] * (1-pb[i][j]);
        }

        for (int j = 1; j <= m ; ++j) {
            for (int k = 1; k <= j; ++k) {
                dp[i][j][k] = dp[i][j-1][k-1]*pb[i][j] + dp[i][j-1][k] * (1-pb[i][j]);
            }
        }

        s[i][0] = dp[i][m][0];
        for (int j = 1; j <= m ; ++j) {
            s[i][j] = s[i][j-1] + dp[i][m][j];
        }
    }

    double p1,p2;

    p1 = p2 = 1;
    for (int i = 0; i < t; ++i) {
        p1 *= (s[i][m] - s[i][0]);
    }
    for (int i = 0; i < t; ++i) {
        p2 *= (s[i][n-1] - s[i][0]);
    }

    printf("%.3f\n",p1-p2);
    
}

int main(){

    while(~scanf("%d%d%d",&m,&t,&n) && (m||n||t)){
        for (int i = 0; i < t; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%lf",&pb[i][j]);
            }
        }

        solve();


    }

}