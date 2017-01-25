//
// Created by Henry on 17/1/18.
//

#include <cstdio>
#include <memory.h>
#include <cmath>

using namespace std;

const int MAXN = 10;
const int MAXM = 10000;


int dp[MAXN][MAXN][MAXN][MAXN];

int fpow(int base,int mi){ return mi ? fpow(base,mi-1)*base : 1; }

void destruct(int num,int mod[]){
    for (int i = 3; i >= 0; --i) {
        int pw = fpow(10,i);
        mod[i] = num/pw;
        num %= pw;
    }
}

void init(){
    memset(dp,0, sizeof(dp));
    int mod[4];
    for (int p = 32; p*p < MAXM ; ++p) {
        destruct(p*p,mod);

        for (int i = 1; i < MAXN; ++i) {
            if(mod[3] == i) continue;
            dp[i][mod[2]][mod[1]][mod[0]] ++;
        }

        for (int i = 0; i < MAXN; ++i) {
            if(mod[2] == i) continue;
            dp[mod[3]][i][mod[1]][mod[0]] ++;
        }

        for (int i = 0; i < MAXN; ++i) {
            if(mod[1] == i) continue;
            dp[mod[3]][mod[2]][i][mod[0]] ++;
        }

        for (int i = 0; i < MAXN; ++i) {
            if(mod[0] == i) continue;
            dp[mod[3]][mod[2]][mod[1]][i] ++;
        }
    }

}



int main(){
    init();
    int t,mod[4];
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        int n;
        scanf("%d",&n);
        destruct(n,mod);
        printf("Case %d: %d\n",cases,dp[mod[3]][mod[2]][mod[1]][mod[0]]);
    }
}