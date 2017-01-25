//
// Created by Henry on 16/10/27.
//
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

int board[4][4],Maxdepth;

int geth(){
    int cnt[4],resr=0,resc=0,Max;

    for (int i = 0; i < 4; ++i) {
        Max = 0;
        memset(cnt,0, sizeof(cnt));

        for (int j = 0; j < 4; ++j) {
            Max = max(Max,++cnt[board[i][j]-1]);
        }
        resr+=4-Max;
    }

    for (int i = 0; i < 4; ++i) {
        Max = 0;
        memset(cnt,0, sizeof(cnt));

        for (int j = 0; j < 4; ++j) {
            Max = max(Max,++cnt[board[j][i]-1]);
        }
        resc+=4-Max;
    }

    return (min(resc,resr)+3)/4;
}

void upRow(int i){
    int tmp = board[i][0];
    for (int j = 0; j< 3; ++j) {
        board[i][j] = board[i][j+1];
    }
    board[i][3] = tmp;
}

void downRow(int i){
    int tmp = board[i][3];
    for (int j = 3; j > 0; --j) {
        board[i][j] = board[i][j-1];
    }
    board[i][0] = tmp;
}

void upCol(int i){
    int tmp = board[0][i];
    for (int j = 0; j< 3; ++j) {
        board[j][i] = board[j+1][i];
    }
    board[3][i] = tmp;
}

void downCol(int i){
    int tmp = board[3][i];
    for (int j = 3; j > 0; --j) {
        board[j][i] = board[j-1][i];
    }
    board[0][i] = tmp;
}

int incDepth;
bool dfs(int d,int pre,int prei){
    int h = geth();
    if (d + h > Maxdepth) {
        incDepth = min(incDepth,d + h);
        return false;
    }



    if (h == 0) {
//        Maxdepth = d;
        return true;
    }

    for (int i = 0; i < 4; ++i) {
        if (pre != 1 || prei!=i){
            upRow(i);
            if (dfs(d+1,0,i))return true;
            downRow(i);
        }

        if (pre != 0 || prei!=i){
            downRow(i);
            if (dfs(d+1,1,i))return true;
            upRow(i);
        }


        if (pre != 4 || prei!=i){
            upCol(i);
            if (dfs(d+1,2,i))return true;
            downCol(i);
        }

        if (pre != 3 || prei!=i){
            downCol(i);
            if (dfs(d+1,3,i))return true;
            upCol(i);
        }



    }

    return false;
}

int idaStar(int d){
    for ( Maxdepth = 0; Maxdepth <= d ; ) {
//        incDepth = d+1;
        incDepth = d+1;
        if (dfs(0,-1,-1))break;
        Maxdepth = incDepth;
//        Maxdepth = incDepth;
    }

    return Maxdepth > d ? -1:Maxdepth;
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                scanf("%d",&board[i][j]);
            }
        }

        printf("%d\n",idaStar(5));
    }
}
