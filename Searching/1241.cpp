//
// Created by Henry on 16/8/24.
//

#include <cstdio>
#include <memory>
#define NUM 110

const int offset[][2] = {{-1,0},{1,0},{-1,1},{0,1},{1,1},{-1,-1},{0,-1},{1,-1}};
char map[NUM][NUM];
bool detected[NUM][NUM];
int m,n;

void DFS(int row,int col){
    detected[row][col] = true;
    int dx,dy;

    for (int i = 0; i < 8; ++i) {
        dx = row + offset[i][0];
        dy = col + offset[i][1];

        if (detected[dx][dy] || dx < 0 || dy<0 || dx >= m || dy >= n || map[dx][dy] == '*') continue;
        DFS(dx,dy);
    }

}

int main(){

    while (scanf("%d %d",&m,&n)!=EOF && m && n){
        //m row,n col
        for (int i = 0; i < m; ++i) {
            scanf("%s",&map[i][0]);
            memset(&detected[i][0],0, sizeof(bool) * n);
        }


        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!detected[i][j] && map[i][j] == '@'){
                    DFS(i,j);
                    count++;
                }
            }
        }

        printf("%d\n",count);




    }


}