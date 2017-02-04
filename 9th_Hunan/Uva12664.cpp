//
// Created by Henry on 17/1/25.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

const int MAXN = 100000 + 10;

typedef pair<int,int> P;

int dist[MAXN],cnt[MAXN];
int cost[3][10];

int dij(int s,int t){
    bool vis[MAXN];

    memset(vis,0, sizeof(vis));
    memset(dist,0x3f, sizeof(dist));

    priority_queue<P,vector<P>,greater<P>> Q;
    dist[s] = 0;
    cnt[s] = 0;
    Q.push(P(0,s));

    while (!Q.empty()){
        P u = Q.top();
        Q.pop();


        if (vis[u.second]) continue;
        vis[u.second] = true;
        if (u.second == t)return u.first;

        for (int i = 0; i < 10; ++i) {
            //append;
            int ds = u.second*10 + i;
            if (ds > t) break;

            if (u.first + cost[0][i] < dist[ds]){
                dist[ds] = u.first + cost[0][i];
                Q.push(P(dist[ds],ds));
                cnt[ds] = cnt[u.second]+1;
            }
        }

        for (int i = 0; i < 10; ++i) {
            //add;
            int ds = u.second + i;
            if (ds > t) break;

            if (u.first + cost[1][i] < dist[ds]){
                dist[ds] = u.first + cost[1][i];
                Q.push(P(dist[ds],ds));
                cnt[ds] = cnt[u.second]+1;
            }
        }

        for (int i = 0; i < 10; ++i) {
            //mul;
            int ds = u.second * i;
            if (ds > t) break;

            if (u.first + cost[2][i] < dist[ds]){
                dist[ds] = u.first + cost[2][i];
                Q.push(P(dist[ds],ds));
                cnt[ds] = cnt[u.second] + 1;
            }
        }
    }
}


int main(){
    int s,t,cases=0;
    while (~scanf("%d%d",&s,&t)){
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 10; ++j) {
                scanf("%d",&cost[i][j]);
            }
        }

        int ans = dij(s,t);
        printf("Case %d: %d %d\n",++cases,ans,cnt[t]);
    }
}
