//
// Created by Henry on 16/11/20.
//

#include <cstdio>
#include <memory.h>
#include <queue>
#include <set>
#include <algorithm>
typedef long long LL;

using namespace std;

const int MAXV = 100000 + 10;
const int MAXE = 1000000 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
struct edge{
    int next,v;
}G[MAXE];



LL n,m,a,b,MaxDepth;
int head[MAXV];
LL dist[MAXV];
int cur;
set<int>st,ts;

bool flag;

LL BFS(int begin){
    MaxDepth = a == 0 ? INF : b/a + 1;

    memset(dist,-1, sizeof(dist));

    queue<int > Q;
    Q.push(begin);
    dist[begin] = 0;

    while(!Q.empty()){
        int s = Q.front();

        if(s == n || dist[s] > MaxDepth) break;

        Q.pop();

        for (int i = head[s]; ~i ; i = G[i].next) {
            if (!(~dist[G[i].v])){
                dist[G[i].v] = dist[s] + 1;
                Q.push(G[i].v);
            }
        }


    }

    return ~dist[n] ? min(dist[n]*a,b) : b;

}

LL BFS_C(int begin){

    MaxDepth = b == 0 ? INF : a/b + 1;

    st.clear();
    ts.clear();

    for (int i = 2; i <= n; ++i) st.insert(i);

    queue<int > Q;
    Q.push(begin);
    dist[begin] = 0;
    dist[n] = INF;

    while(!Q.empty()){
        int s = Q.front();

        if(s == n || dist[s] > MaxDepth) break;

        Q.pop();


        for (int i = head[s]; ~i ; i = G[i].next) {
            int v = G[i].v;
            if(st.count(v) == 0) continue;
            st.erase(v);
            ts.insert(v);
        }

        for (set<int>::iterator it = st.begin(); it !=st.end() ; ++it) {
            Q.push(*it);
            dist[*it] = dist[s] + 1;
        }

        st.swap(ts);
        ts.clear();
    }

    return min(dist[n]*b,a);

}


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
    cur = 0;
    flag = false;
}


int main() {
    while (~scanf("%lld%lld%lld%lld", &n, &m, &a, &b)) {
        //a:highway b
        init();

        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u > v) swap(u,v);

            addedge(u,v);
            //a边
            if (u == 1 && v == n) flag = true;
        }

        printf("%lld\n",flag ? BFS_C(1):BFS(1));
    }
}
