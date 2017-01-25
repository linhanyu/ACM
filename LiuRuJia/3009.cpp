//
// Created by Henry on 16/9/7.
//
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 21;
const int INF = 0x7FFFFFF;
const int offser[][2] = {{-1,0},{1,0},{0,1},{0,-1}};

bool rls[MAXN][MAXN];
int row,col;
int endrow,endcol;
bool inside(int r,int c){
    return r<row && r>=0 && c<col && c>=0;
}


int ans;
void dfs(int r,int c,int step){

    if (step>=10) return;

    for (int i = 0; i < 4; ++i) {
        int dr = r + offser[i][0];
        int dc = c + offser[i][1];

        if(rls[dr][dc]) continue;

        while(inside(dr,dc) && !rls[dr][dc]){
            if (dr == endrow && dc == endcol){
                ans = min(ans,step+1);
                return ;
            }
            dr += offser[i][0];
            dc += offser[i][1];
        }

        if(inside(dr,dc)){
            rls[dr][dc] = false;
            dfs(dr - offser[i][0],dc  -offser[i][1],step+1);
            rls[dr][dc] = true;
        }
    }

}



int main(){
    int tmp,beginr,beginc;
    while(scanf("%d %d",&col,&row)!=EOF && row && col){

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin>>tmp;
                switch (tmp){
                    case 0:
                        rls[i][j] = false;
                        break;
                    case 1:
                        rls[i][j] = true;
                        break;
                    case 2:
                        beginr = i;
                        beginc = j;
                        rls[i][j] = false;
                        break;
                    case 3:
                        endrow = i;
                        endcol = j;
                        rls[i][j] = false;
                        break;
                    default:
                        break;
                }
            }
        }

        ans = INF;
        dfs(beginr,beginc,0);
        if (ans == INF){
            puts("-1");
        } else{
            cout<<ans<<endl;
        }
    }
}