//
// Created by Henry on 16/10/27.
//
#include <cstdio>

const int rBegin[4][2] = {{0,0},{1,0},{0,1},{1,1}};
const int rFactor[4][2] = {{0,1},{1,0},{0,-1}};
const int crFactor[4][2] = {{1,0},{0,1},{-1,0}};

int maxDepth,y;
int board[3][3];

int geth(){
    int h = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            h += board[i][j] == 3*i+j+1 ? 0:1;
        }
    }

    return (h+3)/4;
}

bool judge(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != i*3 + j + 1)return false;
        }
    }
    return true;
}



void rotate(int x,int y,const int factor[4][2]){
    int tmp = board[x][y];
    int dx,dy;
    for (int i = 0; i < 3; ++i) {
        dx = x + factor[i][0];
        dy = y + factor[i][1];

        board[x][y] = board[dx][dy];

        x = dx;
        y = dy;
    }

    board[x][y] = tmp;
}

void dfs(int d){
    if(d + geth() > maxDepth) return;

    if(judge()){
        maxDepth = d;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        rotate(rBegin[i][0],rBegin[i][1],rFactor);
        dfs(d+1);
        rotate(rBegin[i][0],rBegin[i][1],crFactor);

        rotate(rBegin[i][0],rBegin[i][1],crFactor);
        dfs(d+1);
        rotate(rBegin[i][0],rBegin[i][1],rFactor);
    }
}

void solve(){
    maxDepth = y+1;
    dfs(0);


    printf("%d\n",maxDepth <= y ? maxDepth:-1);
}

int main(){
    char tmp[20],count = 1;
    while (~scanf("%s",tmp) && !(tmp[0] == '0' && tmp[1] == '0')){
        y = tmp[0] - '0';
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = tmp[i*3+j+1] - '0';
            }
        }

        printf("%d. ",count++);
        solve();
    }
}