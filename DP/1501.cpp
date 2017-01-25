//
// Created by Henry on 16/7/29.
//
#include <cstdio>
#include <cstring>
#include <memory>

#define NUM 202

//bool strCmp(char str1[],char str2[],int end){
//    //exclusive-end inclusive-begin
//    for (int i = 0; i < end; ++i) {
//        if (str1[i] != str2[i]) return false;
//    }
//    return true;
//
//}

int main(){
    int n;

    int seqLen1,seqLen2,seqLen3;
    char seq1[NUM],seq2[NUM],seq3[NUM<<1];
    bool dp[NUM][NUM];
    scanf("%d",&n);
    seq1[0] = seq2[0] = seq3[0] = '!';
    for (int t = 1; t <= n; ++t) {
        scanf("%s %s %s\n",seq1+1,seq2+1,seq3+1);

        seqLen1 = strlen(seq1)-1;
        seqLen2 = strlen(seq2)-1;
        seqLen3 = seqLen1 + seqLen2;
        memset(dp,0, sizeof(dp));

        for (int i = 1; i <= seqLen1; ++i) {
            if (seq1[i] == seq3[i])
            dp[i][0] = true;
        }

        for (int i = 1; i <= seqLen2 ; ++i) {
            if (seq2[i] == seq3[i])
            dp[0][i] = true;
        }

        for (int i = 1; i <= seqLen1 ; ++i) {
            for (int j = 1; j <= seqLen2; ++j) {
                if ((dp[i-1][j] && seq1[i]==seq3[i+j]) || (dp[i][j-1] && seq2[j]==seq3[i+j]))
                    dp[i][j] = true;
            }
        }
//        for (int i = 1; i <= seqLen3; ++i) {
//            //遍历字符串儿
//            for (int j = seqLen1 ; j > 0 ; --j) {
//                if (i-j<0) continue;
//
//                if (dp[i-j] && strCmp(seq1,seq3+i-j,j)){
//                    //len为i-j的字串儿
//                    dp[i] = true;
//                }
//            }
//
//            for (int j = seqLen2 ; j > 0 ; --j) {
//                if (i-j<0) continue;
//
//                if (dp[i-j] && strCmp(seq2,seq3+i-j,j)){
//                    //len为i-j的字串儿
//                    dp[i] = true;
//                }
//            }
//        }
        if (dp[seqLen1][seqLen2]){
            printf("Data set %d: yes\n",t);
        } else{
            printf("Data set %d: no\n",t);
        }



    }



}
