//
// Created by Henry on 16/7/28.
//

#include <cstdio>
#include <algorithm>
#include <queue>

#define NUM 51
#define INF 0x7F

using namespace std;

typedef __int64 Long;

int n;
int map[NUM][NUM];
int Dis[NUM][NUM];
int key[4][2] = {0,-1,0,1,1,0,-1,0};

bool inQueue[NUM][NUM];

//4个方向,key[k][0]是x轴,[k][1]是y轴

Long dp[NUM][NUM];

struct ord{
    int x;
    int y;

    ord(int a,int b):x(a),y(b){}
    ord(){}
};
void Min_Time(){
    //SPFA二维

    queue<ord> Q;
    memset(Dis,1, sizeof(Dis));
    memset(inQueue,0, sizeof(inQueue));

    Dis[n][n] = map[n][n];
    Q.push(ord(n,n));

    while (!Q.empty()){
        ord tmp  = Q.front();
        Q.pop();
        inQueue[tmp.x][tmp.y] = false;

        for (int i = 0; i < 4; ++i) {
            //4个坐标
            int dx,dy;
            dx = tmp.x + key[i][0];
            dy = tmp.y + key[i][1];

            if (0 < dx && dx <= n && 0 < dy && dy <= n){
                if (Dis[dx][dy] > Dis[tmp.x][tmp.y] + map[dx][dy]){
                    Dis[dx][dy] = map[dx][dy] + Dis[tmp.x][tmp.y];
                    if (!inQueue[dx][dy]){
                        inQueue[dx][dy] = true;
                        Q.push(ord(dx,dy));
                    }
                }
            }
        }
    }



}
//void find()
//{
//    int i;
//    ord s;
//
//    queue<ord> Q;
//
//    memset(Dis,1,sizeof(Dis));
//    Dis[n][n]=map[n][n];
//    Q.push(ord(n,n));
//
//    while (!Q.empty())
//    {
//        s=Q.front();
//        Q.pop();
//
//        for (i=0;i<4;++i)
//        {
//            int x,y;
//            x=s.x+key[i][0]; y=s.y+key[i][1];
//            if (x>0&&x<=n && y>0&&y<=n)
//            {
//                if (Dis[x][y]>Dis[s.x][s.y]+map[x][y])
//                {
//                    Dis[x][y]=Dis[s.x][s.y]+map[x][y];
//                    Q.push(ord(x,y));
//                }
//            }
//
//        }
//    }
//}




Long dfs(int row,int col){
    if (row == n && col == n){
        return 1;
    }

    if (dp[row][col]){
        return dp[row][col];
    }

    Long sum = 0;
    for (int i = 0; i < 4; ++i) {
        int dx = row + key[i][0];
        int dy = col + key[i][1];
        if (0 < dx && dx <= n && 0 < dy && dy <= n && Dis[row][col] > Dis[dx][dy]){
            sum += dfs(dx,dy);
        }
    }

    return dp[row][col] = sum;

}

int main(){
    while (scanf("%d",&n)!=EOF){
        memset(dp,0, sizeof(dp));

        for (int i = 1; i <= n ; ++i) {
            for (int j = 1; j <= n ; ++j) {
                scanf("%d",&map[i][j]);
            }
        }

        Min_Time();
//        find();
        printf("%I64d\n",dfs(1,1));
    }
}