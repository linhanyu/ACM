//
// Created by Henry on 16/10/28.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int Begin[] = {2,4};

const int MoveOffset = 'A';
const int MAXN = 7;
const int SUM = 8;
const int MAXDEEP = 1000;
const int INF = 0x3f3f3f3f;

char ans[MAXDEEP];

int anssym;
int MaxDepth,incDepth;
int G[MAXN][MAXN];

void moveR_L(int i){
    int tmp = G[i][0];
    for (int j = 0; j < MAXN - 1; ++j) {
        G[i][j] = G[i][j+1];
    }
    G[i][MAXN-1] = tmp;
}

void moveR_R(int i){
    int tmp = G[i][MAXN-1];
    for (int j = MAXN - 1 ; j > 0; --j) {
        G[i][j] = G[i][j-1];
    }
    G[i][0] = tmp;
}

void moveC_U(int i){
    int tmp = G[0][i];
    for (int j = 0 ; j < MAXN - 1; ++j) {
        G[j][i] = G[j+1][i];
    }
    G[MAXN - 1][i] = tmp;
}

void moveC_D(int i){
    int tmp = G[MAXN-1][i];
    for (int j = MAXN - 1; j > 0 ; --j) {
        G[j][i] = G[j-1][i];
    }
    G[0][i] = tmp;
}

int geth(){
    int cnt[3];
    int Max;

    memset(cnt,0, sizeof(cnt));
    Max = 0;

    for (int i = Begin[0]; i <= Begin[1]; ++i) {
        for (int j = Begin[0]; j <=Begin[1]; ++j) {
            if (i==3 && j == 3)continue;
            Max = max(Max,++cnt[G[i][j]-1]);
        }
    }

    return ((SUM-Max)+2)/3;
}

bool dfs(int d,int pre){
    int h = geth();

    if (d + h > MaxDepth){
        incDepth = min(d+h,incDepth);
        return false;
    }

    if(h == 0){
        ans[d] = '\0';
        anssym = G[Begin[0]][Begin[0]];
        return true;
    }

    //0:2列上移
    //1:4列上移
    //2:2行右移
    //3:4行右移
    //4:4列下移
    //5:2列下移
    //6:4行左移
    //7:2行左移


    if (pre != 5){
        moveC_U(Begin[0]);
        if (dfs(d+1,0)){
            ans[d] = 0 + MoveOffset;
            return true;
        }
        moveC_D(Begin[0]);
    }

    if (pre != 4){
        moveC_U(Begin[1]);
        if (dfs(d+1,1)){
            ans[d] = 1 + MoveOffset;
            return true;
        }
        moveC_D(Begin[1]);
    }

    if (pre != 7){
        moveR_R(Begin[0]);
        if (dfs(d+1,2)){
            ans[d] = 2 + MoveOffset;
            return true;
        }
        moveR_L(Begin[0]);
    }

    if (pre != 6){
        moveR_R(Begin[1]);
        if (dfs(d+1,3)){
            ans[d] = 3 + MoveOffset;
            return true;
        }
        moveR_L(Begin[1]);
    }

    if (pre != 1){
        moveC_D(Begin[1]);

        if (dfs(d+1,4)){
            ans[d] = 4 + MoveOffset;
            return true;
        }
        moveC_U(Begin[1]);
    }

    if (pre != 0){
        moveC_D(Begin[0]);

        if (dfs(d+1,5)){
            ans[d] = 5 + MoveOffset;
            return true;
        }
        moveC_U(Begin[0]);
    }

    if (pre != 3){
        moveR_L(Begin[1]);
        if (dfs(d+1,6)){
            ans[d] = 6 + MoveOffset;
            return true;
        }
        moveR_R(Begin[1]);
    }

    if (pre != 2){
        moveR_L(Begin[0]);
        if (dfs(d+1,7)){
            ans[d] = 7 + MoveOffset;
            return true;
        }
        moveR_R(Begin[0]);
    }



    return false;

}

int Astar(){
    MaxDepth = 0;
    while (MaxDepth < INF){
        incDepth = INF;
        if (dfs(0,-1)) break;
        MaxDepth = incDepth;
    }


    return MaxDepth;
}
int main(){
//    int G[MAXN][MAXN];
//    while (~scanf("%d",& G[0][Begin[0]]) &&  G[0][Begin[0]]){
//
//        for (int j = 0; j < MAXN; ++j) {
//            for (int i = 0; i < 2; ++i) {
//
//                if (i==0 && j==0) continue;
//
//                if (j == Begin[0] || j == Begin[1]){
//                    for (int k = 0; k < MAXN; ++k) {
//                        scanf("%d",&G[j][k]);
//                    }
//                    break;
//
//                 } else{
//                    scanf("%d",&G[j][Begin[i]]);
//                }
//
//            }
//        }
//
//        if (Astar()){
//            puts(ans);
//        } else{
//            puts("No moves needed");
//        }
//        printf("%d\n",anssym);
//    }
}