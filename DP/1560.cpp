//
// Created by Henry on 16/8/5.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

#define NUM1 9
#define NUM2 7
#define NUM3 40

using namespace std;

void LCS(char seq1[],int Len1, char seq2[],int Len2){
    static int dp[NUM3][NUM2];
    static int flag[NUM3][NUM2];

    memset(dp,0, sizeof(dp));

    for (int i = 0; i < Len1 ; ++i) {
        for (int j = 0; j < Len2; ++j) {
            if (seq1[i] == seq2[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                flag[i][j] = 0;
            } else if(dp[i+1][j] < dp[i][j+1]){
                dp[i+1][j+1] = dp[i][j+1];
                flag[i][j] = -1;
            } else{
                dp[i+1][j+1] = dp[i+1][j];
                flag[i][j] = 1;
            }
        }
    }


}

int main(){
    char seq[NUM1][NUM2];
    char tmp[NUM3];
    int len[NUM1],tmpLen;
    int t,n;

    scanf("%d",&t);
    len[0] = 1;
    seq[0][0] = '\0';

    while (t--){
        scanf("%d",&n);
        for (int i = 1; i <= n ; ++i) {
            scanf("%s\n",seq[i]);
            len[i] = strlen(seq[i]);
        }

        memcpy(tmp,seq[1],len[1]* sizeof(char));
        tmpLen = len[1];

        for (int i = 2; i <= n ; ++i) {

        }
    }

}