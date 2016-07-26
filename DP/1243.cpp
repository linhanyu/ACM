//
// Created by Henry on 16/7/25.
//

#include <cstdio>
#include <memory>
#include <cstring>
#include <algorithm>

#define NUM 28
#define NUM_2 10000
#define To_Int(a) (a-'a')

using namespace std;

char seq[NUM],seq1[NUM_2],seq2[NUM_2];
int map[NUM],dp[NUM_2][NUM_2];

int main(){
    int n,tmp,len_1,len_2;

    while(scanf("%d",&n)!=EOF){
        getchar();
        scanf("%s",seq);

        for (int i = 0; i < n; ++i) {
            scanf("%d",&tmp);
            map[To_Int(seq[i])] = tmp;
        }

        getchar();
        scanf("%s\n",seq1 + 1);
        scanf("%s\n",seq2 + 1);
        len_1 = strlen(seq1 + 1);
        len_2 = strlen(seq2 + 1);

        dp[0][0] = 0;
        for (int i = 1; i <= len_1; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= len_2; ++i) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= len_1; ++i) {
            for (int j = 1; j <= len_2; ++j) {
                if (seq1[i] == seq2[j]){
                    dp[i][j] = dp[i-1][j-1] + map[To_Int(seq1[i])];
                } else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        printf("%d\n",dp[len_1][len_2]);


    }
}
