//
// Created by Henry on 16/11/20.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

const int MAXN = 30;
const int MAXV = 500 + 10;
const int MAXE = MAXV*MAXV + 10;

struct edge{
    int v,next;
}G[MAXE];

int head[MAXV],status[MAXV],Cnt[MAXV];

int cur,n,m,ans;

void addedge_(int u,int v){
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addedge(int u,int v){
    addedge_(u,v);
    addedge_(v,u);
}

void init(){
    memset(head,-1, sizeof(head));
    memset(status,0, sizeof(status));
    cur = 0;
}

bool avaliable(int u,int statu){
    for (int i = u; i < MAXN ; ++i) {
        //从u+1点开始
        statu |= 1<<i;
    }

    for (int i = 0; i < MAXN ; ++i) {
        if (!(statu & (1<<i)) && ((statu & status[i]) != status[i])){
            //1~30某一点没放,而且这一点的连边状态中有未覆盖到的点
            return false;
        }
    }

    return true;
}

void build(int x){
    int tmp = 0;
    Cnt[x] = 0;

    for (int i = head[x]; ~i ; i = G[i].next) {
        if (G[i].v < MAXN) tmp|= 1<<G[i].v ;
        else Cnt[x]++;
    }

    status[x] = tmp;
}

int solve(int statu){
    int cnt = 0;
    for (int i = MAXN ; i < n; ++i) {
        if ((status[i]&statu) != status[i])
            cnt++;
    }
    return cnt;
}

void dfs(int u,int statu,int cnt){
    if(!avaliable(u,statu)) return ;

    int tmp = statu;
    for (int i = u; i < MAXN; ++i) {
        tmp |= 1<<i;
    }

    if (cnt + solve(tmp) >= ans) return;

    if (u>=30){
        ans = min(ans,solve(statu) + cnt);
        return;
    }

    if ((statu & status[u]) == status[u] && !Cnt[u]){
        dfs(u+1,statu,cnt);
        return;
    }

    dfs(u+1,statu,cnt);
    dfs(u+1,statu|(1<<u),cnt+1);

}

int main(){
    while (~scanf("%d%d",&n,&m)){
        init();

        for (int i = 0; i < m; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u-1,v-1);
        }

        for (int i = 0; i < n ; ++i) {
            build(i);
        }

        ans = MAXN;
        dfs(0,0,0);
        printf("%d\n",ans);
    }

}