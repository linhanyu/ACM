//
// Created by Henry on 17/1/17.
//

#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

typedef pair<int,int> P;

const int MAXV = 255555;
const int MAXE = 1000000 + 10;
const int INF = 0x3f3f3f3f;

struct edge{
    int v,next,cost;
}G[MAXE];

int head[MAXV],dist[MAXV];
int cur,n,m;

vector<int > num[MAXV];
map<int,int > mp[MAXV];

void init(){
    for (int i = 1; i <= n ; ++i) {
        num[i].clear();
        mp[i].clear();
    }

    memset(head,-1, sizeof(head));
    cur = 0;
}

void addedge_(int u,int v,int cost){
    G[cur].v = v;
    G[cur].cost = cost;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addedge(int u,int v,int cost){
    addedge_(u,v,cost);
    addedge_(v,u,cost);
}

void dij(int s){
    bool vis[MAXV];

    memset(vis,0, sizeof(vis));
    memset(dist,0x3f, sizeof(dist));

    priority_queue<P,vector<P>,greater<P>> Q;
    for (int i = 0; i < num[1].size(); ++i) {
        dist[mp[1][num[1][i]]] = 0;
        Q.push(P(0,mp[1][num[1][i]]));
    }

    while (!Q.empty()){
        P s = Q.top();
        Q.pop();

        if(vis[s.second]) continue;
        vis[s.second] = true;

        for (int i = head[s.second]; ~i ; i = G[i].next) {
            if (s.first + G[i].cost < dist[G[i].v]){
                dist[G[i].v] = s.first + G[i].cost;
                Q.push(P(dist[G[i].v],G[i].v));
            }
        }
    }

}
int main(){

    while (~scanf("%d%d",&n,&m)){
        init();

        int cnt = 1;

        for (int i = 0; i < m; ++i) {
            int u,v,c,t;
            scanf("%d%d%d%d",&u,&v,&c,&t);
            if (!mp[u][c]){
                mp[u][c] = cnt++;
                num[u].push_back(c);
            }
            u = mp[u][c];
            if (!mp[v][c]){
                mp[v][c] = cnt++;
                num[v].push_back(c);
            }
            v = mp[v][c];

            addedge(u,v,t);
            //离散化站点
        }

        for(int i=1;i<=n;i++){
            sort(num[i].begin(),num[i].end());

            for (int j = 0; j < num[i].size() - 1; ++j) {
                int u = mp[i][num[i][j]];
                int v = mp[i][num[i][j+1]];

                addedge(u,v,num[i][j+1] - num[i][j]);
            }
        }

        dij(1);
        int ans = INF;
        for (int i = 0; i < num[n].size(); ++i) {
            ans = min(ans,dist[mp[n][num[n][i]]]);
        }
        printf("%d\n",ans);
    }
}