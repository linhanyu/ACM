//
// Created by Henry on 17/1/23.
//

#include <cstdio>
#include <memory.h>

const int MAXN = 22;
const int MAXV = 32;
const int MAXE = 50000;
const int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

struct edge{
    int v,next;
}G[MAXE];

bool rls[MAXV][MAXV];
bool vis[MAXN][MAXN];
char mp[MAXN][MAXN];
int num[MAXN][MAXN];
int color[MAXV];
int colorcnt[5];
int head[MAXV];
int sum,r,c,cur;

void init(){
    memset(rls,0, sizeof(rls));
    memset(vis,0, sizeof(vis));
    memset(color,0, sizeof(color));
    memset(head,-1, sizeof(head));
    memset(colorcnt,0, sizeof(colorcnt));
    cur = 0;
}


void addedge_(int u,int v){
    if(rls[u][v])return;

    rls[u][v] = true;
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

bool outbound(int x,int y){
    return x < 0 || y < 0 || x >= r || y>=c;
}

void dfs(int x,int y,int cnt){
    if (vis[x][y]) return;

    vis[x][y] = true;
    num[x][y] = cnt;

    for (int i = 0; i < 4; ++i) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];

        if (outbound(dx,dy) || mp[dx][dy] != mp[x][y]) continue;

        dfs(dx,dy,cnt);
    }

}

bool judge(int pos,int c){
    int j;
    for (j = head[pos]; ~j ; j = G[j].next) {
        if (color[G[j].v] == c) break;
    }
    return !(~j);
}

int solveDfs(int pos){

    if (pos == sum)
        return colorcnt[1]&&colorcnt[2]&&colorcnt[3]&&colorcnt[4];

    int ans = 0;
    if(judge(pos,1)) {
        color[pos] = 1;
        colorcnt[1]++;
        ans += solveDfs(pos + 1);
        color[pos] = 0;
        colorcnt[1]--;
    }
    if(colorcnt[1] && judge(pos, 2)) {
        color[pos] = 2;
        colorcnt[2]++;
        ans += solveDfs(pos + 1);
        color[pos] = 0;
        colorcnt[2]--;

    }
    if(colorcnt[3] + colorcnt[4] < 5 && judge(pos, 3)) {
        color[pos] = 3;
        colorcnt[3]++;
        ans += solveDfs(pos + 1);
        color[pos] = 0;
        colorcnt[3]--;
    }

    if(colorcnt[3] + colorcnt[4] < 5 && colorcnt[3] && judge(pos, 4)) {
        color[pos] = 4;
        colorcnt[4]++;
        ans += solveDfs(pos + 1);
        color[pos] = 0;
        colorcnt[4]--;
    }

    return ans;
}

int main(){
    int cases = 0;
    while (~scanf("%d%d",&r,&c)){
        init();
        for (int i = 0; i < r; ++i) {
            scanf("%s",&mp[i][0]);
        }

        sum = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (vis[i][j])continue;
                dfs(i,j,sum++);
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int dx = i + dir[k][0];
                    int dy = j + dir[k][1];

                    if (outbound(dx,dy) || num[dx][dy] == num[i][j]) continue;
                    addedge_(num[i][j],num[dx][dy]);
                }
            }
        }

        if (sum < 4){
            printf("Case %d: %d\n",++cases,0);
            continue;
        }

        printf("Case %d: %d\n",++cases,solveDfs(0)<<2);
    }
}

//
//int solveDfs(int pos,int girl){
//    if (girl < 0) return 0;
//
//    if (pos == sum){
//        for (int i = 1; i <= 4; ++i) {
//            if (colorAppear[i]) continue;
//            return 0;
//        }
//        return 1;
//    }
//
//
//    int ans = 0;
//    for (int i = 1; i <= 4; ++i) {
//        color[pos] = i;
//        bool flg = false;
//
//        for (int j = head[pos]; ~j ; j = G[j].next) {
//            if (color[G[j].v] == color[pos]) {
//                flg = true;
//                break;
//            }
//        }
//
//        if (flg){
//            color[pos] = 0;
//            continue;
//        }
//
//        //能上
//        bool statu = colorAppear[i];
//        colorAppear[i] = true;
//        if (i == 3 || i == 4){
//            ans += solveDfs(pos+1,girl-1);
//        } else{
//            ans += solveDfs(pos+1,girl);
//        }
//        colorAppear[i] = statu;
//        color[pos] = 0;
//    }
//
//    return ans;
//}

//void addedge_(int u,int v){
//    if (rls[u][v]) return;
//
//    G[cur].v = v;
//    G[cur].next = head[u];
//    rls[u][v] = true;
//    head[u] = cur++;
//}

//int solveDfs(int u,int yellow,int blue,int cnt){
//    if (yellow < 0 || blue < 0) return 0;
//
//    if (cnt == sum)
//        return 1;
//
//    if (color[u])
//        return 0;
//
//
//
//    bool colorCnt[5];
//    memset(colorCnt,0, sizeof(colorCnt));
//    for (int i = head[u]; ~i ; i = G[i].next) colorCnt[color[G[i].v]] = true;
//    //统计临近国家颜色 0:无 1~4:...
//
//    int ans = 0;
//    for (int i = 1; i < 5; ++i) {
//        if (colorCnt[i]) continue;
//        //出现过,不涂
//
//        color[u] = i;
//        for (int j = head[u]; ~j ; j = G[j].next)
//        {
//            if (i == 3){
//                ans += solveDfs(G[j].v,yellow-1,blue,cnt+1);
//            } else if (i == 4){
//                ans += solveDfs(G[j].v,yellow,blue-1,cnt+1);
//            } else{
//                ans += solveDfs(G[j].v,yellow,blue,cnt+1);
//            }
//        }
//        color[u] = 0;
//    }
//
//    return ans;
//}