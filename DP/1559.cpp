//
// Created by Henry on 16/8/4.
//

#include <cstdio>
#include <algorithm>

#define NUM 1002

using namespace std;

int maxSeq(int A[],int right,int y){
    static int tmp[NUM];
    tmp[0] = 0;

    for (int i = 1; i <= right; ++i) {
        tmp[i] = A[i];
        tmp[i] += tmp[i-1];
    }

    int Max = tmp[y] - tmp[0];
    for (int i = y+1; i <= right; ++i) {
        Max = max(Max,tmp[i]-tmp[i-y]);
    }

    return Max;

}

int maxRec(int (*rec)[NUM],int m,int n,int x,int y){
    static int tmp[NUM];
    //矩阵需预处理,在列上进行快速区间查询
    int Max = 0;
    for (int i = x; i <= m ; ++i) {
        //对于m行,从x开始
        for (int j = 1; j <= n ; ++j) {
            tmp[j] = rec[i][j] - rec[i-x][j];
        }

        Max = max(Max,maxSeq(tmp,m,y));
    }

    return Max;
}

int main(){
    int m,n,x,y,t;
    int rec[NUM][NUM];
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&m,&n,&x,&y);

        for (int i = 0; i <= m; ++i) {
            rec[i][0] = 0;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d",&rec[i][j]);
                rec[i][j]+=rec[i-1][j];
            }
        }

        printf("%d\n",maxRec(rec,m,n,x,y));
    }
}