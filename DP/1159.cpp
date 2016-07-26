//
// Created by Henry on 16/7/22.
//
#include <cstdio>
#include <cstring>
#include <memory>
#include <algorithm>

#define NUM 1000

using namespace std;

int main(){
    char seq_1[NUM],seq_2[NUM];
    int len_1,len_2;
    int dp[NUM][NUM];
    seq_1[0] = ' ';
    seq_2[0] = ' ';
    while (scanf("%s %s\n",&seq_1[1],&seq_2[1])!=EOF){
        len_1 = (int)strlen(seq_1) - 1;
        len_2 = (int)strlen(seq_2) - 1;

        for (int i = 0; i <= len_1; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= len_2; ++i) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= len_1  ; ++i) {
            for (int j = 1; j <= len_2  ; ++j) {
                if (seq_1[i] == seq_2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        printf("%d\n",dp[len_1][len_2]);

    }
}
