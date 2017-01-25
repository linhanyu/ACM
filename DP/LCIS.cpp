//
// Created by Henry on 16/7/28.
//

//http://www.cnblogs.com/gj-Acit/p/3236384.html

#include <cstdio>
#include <algorithm>
#include <memory>

#define NUM 100

using namespace std;

//2d algorithm
template <class T>
int LCIS_2D(int (*dp)[NUM], T seq1[],T seq2[], int seqLen1,int seqLen2){
    int Max;
    for (int i = 1; i <= seqLen1; ++i) {
        Max = 0;
        for (int j = 1; j <= seqLen2 ; ++j) {
            dp[i][j] = dp[i-1][j];
            if (seq1[i] > seq2[j] && Max < dp[i-1][j]) Max = dp[i-1][j];
            if (seq1[i] == seq2[j]) dp[i][j] = Max + 1;
        }
    }

    Max = 0;
    for (int i = 1 ; i <= seqLen2; ++i) {
        Max = max(Max,dp[seqLen1][i]);
    }

    return Max;
}

template <class T>
int LCIS_1D(int dp[],T seq1[],T seq2[],int seqLen1,int seqLen2){
    memset(dp,0, sizeof(int) * (max(seqLen1,seqLen2)+1));

    int Max;
    for (int i = 1; i <= seqLen1 ; ++i) {
        Max = 0;
        for (int j = 1; j <= seqLen2; ++j) {
            if(seq1[i] > seq2[j] && Max < dp[j]) Max = dp[j];
            if (seq1[i] == seq2[j]) dp[j] = Max+1;
        }
    }

    Max = 0;
    for (int j = 1; j <= seqLen2 ; ++j) {
        Max = max(Max,dp[j]);
    }

    return Max;
}
int main(){
    int n;
    int seq1[NUM],seq2[NUM],seqLen1,seqLen2;
    int dp1[NUM][NUM],dp2[NUM];
    while(scanf("%d",&seqLen1)!=EOF && seqLen1) {

        for (int i = 1; i <= seqLen1; ++i) {
            scanf("%d",&seq1[i]);
        }
        scanf("%d",&seqLen2);
        for (int i = 1; i <= seqLen2; ++i) {
            scanf("%d",&seq2[i]);
        }

        memset(dp1,0, sizeof(dp1));
        printf("%d\n",LCIS_2D(dp1,seq1,seq2,seqLen1,seqLen2));
        printf("%d\n",LCIS_1D(dp2,seq1,seq2,seqLen1,seqLen2));
    }
}
