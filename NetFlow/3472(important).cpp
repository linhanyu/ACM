//
// Created by Henry on 17/1/13.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <cstring>

using namespace std;

const int MAXE = 4000;
const int MAXV = 30;
const int INF = 0x3f3f3f3f;
const int src = 26;
const int dst = 27;
struct edge{
    int cap,next,v;
}G[MAXE];

int head[MAXV],dist[MAXV],layorC[MAXV],UFSet[MAXV],In[MAXV],Out[MAXV],ecur[MAXV];
int cur;

char str[100];

void addedge_(int u,int v,int cap){
    G[cur].v = v;
    G[cur].cap = cap;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addedge(int u,int v,int cap){
    addedge_(u,v,cap);
    addedge_(v,u,cap);
}

void BFS(int s){
    memset(dist,-1, sizeof(dist));

    queue<int > Q;
    dist[s] = 0;
    Q.push(s);
    layorC[0] = 1;

    while (!Q.empty()){
        s = Q.front();
        Q.pop();

        for (int i = head[s]; ~i ; i = G[i].next) {
            if (~dist[G[i].v]) continue;

            dist[G[i].v] = dist[s] + 1;
            layorC[dist[G[i].v]]++;
            Q.push(G[i].v);
        }
    }
}


int ISAP(int s,int t,int n){

    int u,flow,prev[MAXV];

    BFS(t);

    memcpy(ecur,head, sizeof(head));
    prev[s] = u = s;
    flow = 0;

    while (dist[u] < n){
        if (u == t){
            int f = INF,neck = u;
            for (int i = s; i != t ; i = G[ecur[i]].v) {
                if (G[ecur[i]].cap < f){
                    f = G[ecur[i]].cap;
                    neck = i;
                }

            }

            for (int i = s; i != t ; i = G[ecur[i]].v) {
                G[ecur[i]].cap -= f;
                G[ecur[i]^1].cap += f;
            }

            flow += f;
            u = neck;
        }

        int i;
        for (i = ecur[u]; ~i; i = G[i].next) {
            if (G[i].cap && dist[G[i].v] + 1 == dist[u]) break;
        }

        if (~i){
            ecur[u] = i;
            prev[G[i].v] = u;
            u = G[i].v;
        } else{
            if (--layorC[dist[u]] == 0) break;//gap
            int mind = n;

            for (int i = head[u]; ~i ; i = G[i].next) {
                if (G[i].cap && dist[G[i].v] < mind){
                    mind = dist[G[i].v];
                    ecur[u] = i;
                }
            }

            dist[u] = mind + 1;
            layorC[dist[u]]++;
            u = prev[u];
        }
    }

    return flow;
}

void init(){
    memset(head,-1, sizeof(head));
    memset(UFSet,-1, sizeof(UFSet));
    memset(In,0, sizeof(In));
    memset(Out,0, sizeof(Out));
    cur = 0;
}

int Find(int rt){
    return UFSet[rt] < 0 ? rt : (UFSet[rt] = Find(UFSet[rt]));
}

void Merge(int rt1,int rt2){
    rt1 = Find(rt1);
    rt2 = Find(rt2);

    if (rt1 == rt2) return;

    UFSet[rt1] = rt2;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        init();
        printf("Case %d: ",cases);

        int n,s = -1;
        scanf("%d",&n);
        while (n--){
            int type,len,rt1,rt2,u,v;
            scanf("%s %d",str,&type);
            len = strlen(str);
            u = str[0] - 'a';
            v = str[len - 1] - 'a';
            s = u;

            In[v]++;
            Out[u]++;

            addedge(u,v,1);

            if (type){
                addedge(v,u,1);
            }

            Merge(u,v);
        }

        bool flg = false;
        int cnt = 0,s1,s2;
        for (int i = 0; i < 26; ++i) {
            if(In[i] || Out[i]) {

                if (Find(s) != Find(i)){
                    flg = true;
                    break;
                }
                if ((In[i] + Out[i]) & 1){
                    In[i]++;
                    Out[i]++;
                    if (cnt++ == 0) s1 = i;
                    else s2 = i;
                }
            }
        }

        if ((cnt != 0 && cnt != 2) || flg){
            puts("Poor boy!");
            continue;
        }

        if (cnt == 2){
            In[s2]++;
            Out[s1]++;
            addedge(s1,s2,1);
        }

        for (int i = 0; i < 26; ++i) {
            if (Out[i] - In[i] > 0) addedge(src,i,(Out[i]-In[i])>>1);
            else if (In[i] - Out[i] > 0 ) addedge(i,dst,(In[i]-Out[i])>>1);
        }

        ISAP(src,dst,28);
        flg = false;
        for (int i = head[src]; ~i ; i = G[i].next) {
            if (G[i].cap && G[i^1].cap){
                flg = true;
                break;
            }
        }

        if (flg){
            puts("Poor boy!");
        } else{
            puts("Well done!");
        }
    }
}
