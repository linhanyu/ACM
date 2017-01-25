//
// Created by Henry on 16/12/18.
//

#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 105;

set<int > tmp;

int dp[MAXN][MAXN][MAXN];
int A[3];
void init(){
    memset(dp,-1,sizeof(dp));
}

void dfs(int pos){
    if (pos == 4) return;


}
int main(){
    int t;
    scanf("%d",&t);
    init();

    while (t--){
        int a,b;
        scanf("%d%d",&a,&b);

        int Max = 0;
        for (int i = 1; i <= (a>>1) ; ++i) {
            A[0] = i;
            A[1] = a - i;
            A[2] = b;
            sort(A,A+3, sizeof(A));
            if (~dp[A[0]][A[1]][A[2]]) {
                tmp.clear();
                dfs(0);
            }


        }

        for (int i = 1; i <= (a>>1) ; ++i) {

        }
    }

}