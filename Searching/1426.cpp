//
// Created by Henry on 16/8/26.
//

#include <cstdio>
#include <cstring>
#include <iostream>

#define NUM 9
#define ToInt(a) (a-'0')

int pos[100][2];
//记录问号坐标,第一个是x,第二个是y
int Qmarks;
bool cols[NUM+1][NUM+1];
bool rows[NUM+1][NUM+1];
int Matrx[NUM][NUM];
//第NUM+1行/列,是否出现数字i
using namespace std;

void readMatix(int * Matrx,char * tmp,int row){
    int cur = 0;
    for (int i = 0; i < NUM; ++i) {
        while (tmp[cur] == ' ') cur++;
        if (tmp[cur] == '?') {
            pos[Qmarks][0] = row;
            pos[Qmarks++][1] = i;

            Matrx[i] = 0;
            cur++;
        } else {
            Matrx[i] = ToInt(tmp[cur++]);
            cols[i][Matrx[i]] = true;
            rows[row][Matrx[i]] = true;

        }
    }
}

void prtMatrix(int M[][NUM]){
    for (int i = 0; i < NUM; ++i) {
        printf("%d",M[i][0]);
        for (int j = 1; j < NUM; ++j) {
            printf(" %d",M[i][j]);
        }
        puts("");
    }
}

bool judge(int root,int stuff){
    int n = pos[root][0]/3 * 3;
    int m = pos[root][1]/3 * 3;
    for (int i = n; i < n + 3; ++i) {
        for (int j = m; j < m + 3; ++j) {
            if (Matrx[i][j] == stuff) return false;
        }
    }

    return true;
}

bool dfs(int root){
    if (root == Qmarks) return true;

    for (int i = 1; i <= 9 ; ++i) {

        if (!cols[pos[root][1]][i] && !rows[pos[root][0]][i] && judge(root,i)) {
            rows[pos[root][0]][i] = true;
            cols[pos[root][1]][i] = true;

            if (dfs(root + 1)) {
                Matrx[pos[root][0]][pos[root][1]] = i;
                return true;
            }
            cols[pos[root][1]][i] = false;
            rows[pos[root][0]][i] = false;
        }


    }
    return false;
}

int main(){

    int ans[NUM][NUM];
    char tmp[NUM * 5],tool;
    while(scanf("%s",tmp)!=EOF){
        getchar();
        memset(pos,0, sizeof(pos));
        memset(cols,0, sizeof(cols));
        memset(rows,0, sizeof(rows));
        Qmarks = 0;
        readMatix(Matrx[0], tmp,0);

        for (int i = 1; i < NUM; ++i) {
            gets(tmp);
            readMatix(Matrx[i],tmp,i);
        }


        dfs(0);
        prtMatrix(Matrx);
        puts("");
    }



}