//
// Created by Henry on 16/10/25.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>

const int MAXN = 21;

using namespace std;

int n;

//double dp[1<<MAXN];
double psb[MAXN];

void solve(){
    int end = (1<<n)-1;
    
//    fill(dp,dp + n,0);
    double res = 0;
    for (int i = 1; i <= end; ++i) {
        int counter = 0;
        double e = 0;
        for (int j = 0; j < n; j++) {
            int cur = 1<<j;

            if (cur & i){
                counter ++ ;
                //该状态卡数
                e += psb[j];
            }
        }

        if (counter & 1){
            res += 1/e;
        } else{
            res -= 1/e;
        }


    }

    printf("%lf\n",res);

}

int main(){

    while (~scanf("%d",&n)){
        for (int i = 0; i < n; ++i) {
            scanf("%lf",&psb[i]);
        }

        solve();

    }
}