//
// Created by Henry on 17/2/12.
//

#include<cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 32;

int dst[MAXN][MAXN];
int n;
void rd(int A[][MAXN]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&A[i][j]);
        }
    }
}

void rt(int pre,int cur,int src[4][MAXN][MAXN]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            src[cur][i][j] = src[pre][n - j - 1][i];
        }
    }
}

int cp(int src[][MAXN]){
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (src[i][j] == dst[i][j]) ans++;
        }
    }

    return ans;
}

int main(){
    int src[4][MAXN][MAXN];

    while (~scanf("%d",&n) && n){
        rd(src[0]);
        rd(dst);

        for (int i = 1; i < 4; ++i) {
            rt(i-1,i,src);
        }

        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            ans = max(ans,cp(src[i]));
        }
        printf("%d\n",ans);
    }
}