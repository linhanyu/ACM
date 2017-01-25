//
// Created by Henry on 16/7/27.
//

#include <cstdio>
#include <algorithm>

#define NUM 501

using namespace std;

typedef int Int;

Int pre[NUM][NUM];

void printLCS(int (*ar)[NUM],int seqLen1,int seqLen2){
    if (seqLen1 == 0 || seqLen2 == 0){
        return;
    }

    if (pre[seqLen1][seqLen2] == 0){
        printLCS(ar,seqLen1-1,seqLen2-1);
        printf("%d\n",ar[seqLen1][seqLen2]);

    }else if (pre[seqLen1][seqLen2] == 1) {
        //来源于2行
        printLCS(ar, seqLen1, seqLen2 - 1);
    } else{
        //-1,则来源于1行
        printLCS(ar, seqLen1 - 1, seqLen2);
    }
}

void printLCS_loop(int (*ar)[NUM],int seqLen1,int seqLen2){
    int stack[NUM],cur = 0;
    while(seqLen1 && seqLen2){
        if (pre[seqLen1][seqLen2] == 0) {
            stack[cur++] = ar[seqLen1--][seqLen2--];
        } else if (pre[seqLen1][seqLen2] == 1) {
            //来源于第2行
            seqLen2--;
        } else{
            seqLen1--;
        }
    }

    while(cur){
        printf("%d\n",stack[--cur]);
    }
    printf("%d",stack[0]);


}

template <class T>
Int LCIS(Int dp[],T seq1[],T seq2[],int seqLen1,int seqLen2){
    memset(dp,0, sizeof(int) * (max(seqLen1,seqLen2)+1));

    Int Max;
    for (int i = 1; i <= seqLen1; ++i) {
        Max = 0;
        for (int j = 1; j <= seqLen2; ++j) {
            if (seq1[i] > seq2[j] && Max < dp[j]) Max = dp[j];
            if (seq1[i] == seq2[j]) dp[j] = Max+1;
        }
    }

    Max = 0;
    for (int i = 1; i <= seqLen2; ++i) {
        Max = max(Max,dp[i]);
    }

    return Max;
}

int main(){
    Int seq1[NUM];
    Int seq2[NUM];

    Int dp[NUM];

    int seq1Len,seq2Len,t,count;
    scanf("%d",&t);
    bool flag = false;
    while(t--){

        if (flag){
            puts("");
        }
        scanf("%d",&seq1Len);
        for (int i = 1; i <= seq1Len; ++i) {
            scanf("%d",&seq1[i]);
        }

        scanf("%d",&seq2Len);
        for (int i = 1; i <= seq2Len; ++i) {
            scanf("%d",&seq2[i]);
        }
        printf("%d\n",LCIS(dp,seq1,seq2,seq1Len,seq2Len));
        flag = true;
    }
}