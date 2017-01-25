//
// Created by Henry on 16/11/10.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAXN = 110;

char str[MAXN];
int dp[MAXN][MAXN];

bool judge(char a,char b){
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int main(){
    while (~scanf("%s",str) && str[0] != 'e'){
        int len = strlen(str);
        memset(dp,0, sizeof(dp));
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i + 1; j < len ; ++j) {
                dp[i][j] = dp[i+1][j];
                for (int k = i + 1; k <= j ; ++k) {
                    if (judge(str[i],str[k])){
                        dp[i][j] = max(dp[i][j],dp[i+1][k-1] + dp[k+1][j] + 2);
                    }
                }
            }
        }

        printf("%d\n",dp[0][len-1]);
    }

}