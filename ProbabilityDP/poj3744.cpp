//
// Created by Henry on 17/1/21.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 11;

int mine[MAXN];

int main(){
    int n,maxm;
    double p;
    while(~scanf("%d",&n)){
        scanf("%lf",&p);

        maxm = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&mine[i]);
        }

        sort(mine,mine + n);

        double dp[3];
        int cur;
        cur = 0;


        dp[2] = 1;
        dp[1] = 1;

        //dp[0] ->maxm

        for (int i = mine[n-1]; i > 0 ; --i) {
            if(m < n){
                //i在mine里
                dp[cur] = 0;
            } else{
                dp[cur] = dp[(cur+1)%3]*p + dp[(cur+2)%3]*(1-p);
            }

            cur = (cur+1)%3;
        }

        printf("%.7lf\n",dp[cur]);
    }
}