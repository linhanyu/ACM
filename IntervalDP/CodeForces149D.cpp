//
// Created by Henry on 16/11/10.
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <memory.h>

typedef long long LL;

const int MAXN = 1000;
const int MOD = 1000000000 + 7;

char str[MAXN];

int match[MAXN];

LL dp[MAXN][MAXN][3][3];

void getmatch(char str[],int len){
    int stack[MAXN];
    int cur = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == '('){
            stack[cur++] = i;
        } else{
            match[stack[--cur]] = i;
            match[i] = stack[cur];
        }
    }
}

void dfs(int l,int r){
    if (l+1 == r){
        dp[l][r][0][1] = 1;
        dp[l][r][1][0] = 1;
        dp[l][r][0][2] = 1;
        dp[l][r][2][0] = 1;
        return;
    }

    if (match[l] == r){
        dfs(l+1,r-1);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (j != 1){
                    dp[l][r][0][1] = (dp[l][r][0][1] + dp[l+1][r-1][i][j]) % MOD;
                }

                if (j != 2){
                    dp[l][r][0][2] = (dp[l][r][0][2] + dp[l+1][r-1][i][j]) % MOD;
                }

                if (i != 1){
                    dp[l][r][1][0] = (dp[l][r][1][0] + dp[l+1][r-1][i][j]) % MOD;
                }

                if (i != 2){
                    dp[l][r][2][0] = (dp[l][r][2][0] + dp[l+1][r-1][i][j]) % MOD;
                }
            }
        }
        return;
    } else{
        dfs(l,match[l]);
        dfs(match[l] + 1,r);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    for (int m = 0; m < 3; ++m) {
                        if (!((k==1 && m==1 ) || (k == 2 && m == 2))){
                            dp[l][r][i][j] = (dp[l][r][i][j] + (dp[l][match[l]][i][k] * dp[match[l] + 1][r][m][j]) % MOD) % MOD;
                        }
                    }
                }
            }
        }
    }
}
int main(){
    while (~scanf("%s",str)){
        int len = strlen(str);
        getmatch(str,len);
        memset(dp,0, sizeof(dp));

        dfs(0,len-1);
        LL ans = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ans = (ans + dp[0][len-1][i][j]) % MOD;
            }
        }

        printf("%lld\n",ans);
    }
}