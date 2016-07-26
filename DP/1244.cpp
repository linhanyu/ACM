//
// Created by Henry on 16/7/25.
//

#include <cstdio>
#include <memory>
#include <algorithm>

#define NUM 1001
#define L_son(a) (a<<1)
#define R_son(a) ((a<<1)|1)
#define MID(a,b) ((a+b) >> 1)

using namespace std;

int sum[NUM<<2];
int num_seq[NUM];
int line[NUM];


void Push_up(int root){
    sum[root] = sum[L_son(root)] + sum[R_son(root)];
}

void initial(int left,int right,int rt){
    if(left == right){
        scanf("%d",&sum[rt]);
        return;
    }

    int mid = MID(left,right);
    initial(left,mid,L_son(rt));
    initial(mid +1,right,R_son(rt));

    Push_up(rt);
}

int query(int L_bound,int R_bound,int left,int right,int rt){
    if (L_bound <= left && right <= R_bound){
        return sum[rt];
    }

    int mid = MID(left,right);
    int sum = 0;

    if (L_bound <= mid) sum += query(L_bound,R_bound,left,mid,L_son(rt));
    if (R_bound >  mid) sum += query(L_bound,R_bound,mid+1,right,R_son(rt));

    return sum;
}
int main(){
    int n,m;
    int dp[NUM][NUM];
    while (scanf("%d",&n)!=EOF && n){
        scanf("%d",&m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d",&line[i]);
        }

        initial(1,n,1);
        memset(dp,0, sizeof(dp));
        for (int i = 1; i <= m; ++i) {
            for (int j = line[i]; j <= n; ++j) {
                dp[i][j] = max(dp[i][j-1],max(dp[i-1][j - line[i]] + query(j - line[i] + 1,j ,1,n,1),dp[i][j]));
            }
        }

        int Max = 0;
        for (int i = 1; i <= n; ++i) {
            Max = max(dp[m][i],Max);
        }
        printf("%d\n",Max);
    }
}
