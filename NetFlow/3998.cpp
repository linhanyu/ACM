//
// Created by Henry on 17/1/14.
//
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;


const int MAXV = 100;
const int MAXE = MAXV*MAXV*10;
const int INF = 0x3f3f3f3f;
const int src = MAXV-1;
const int dst = MAXV-2;
const int offset = MAXV/2;

struct edge{
    int next,v,cost,cap;
}G[MAXE];

int head[MAXV],dist[MAXV],A[MAXV];
int cur,Len;

void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
}

void addedge_(int u,int v,int cap,int cost){
    G[cur].v = v;
    G[cur].cap = cap;
    G[cur].cost = cost;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addedge(int u,int v,int cap,int cost){
    addedge_(u,v,cap,cost);
    addedge_(v,u,0,-cost);
}

void revspfa(int s){
    bool outQ[MAXV];

    memset(dist,0x3f, sizeof(dist));
    memset(outQ, true, sizeof(outQ));

    queue<int > Q;
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()){
        s = Q.front();
        Q.pop();
        outQ[s] = true;

        for (int i = head[s]; ~i ; i = G[i].next) {
            if (!G[i].cap && dist[s] - G[i].cost < dist[G[i].v]){
                dist[G[i].v] = dist[s] - G[i].cost;

                if (outQ[G[i].v]){
                    Q.push(G[i].v);
                    outQ[G[i].v] = false;
                }
            }
        }
    }
}

int MCISAP(int s,int t,int n){
    revspfa(t);

    int prev[MAXV],ecur[MAXV];
    int cnt,u,flow,cost;

    prev[s] = u = s;
    cnt = Len = flow =  0;
    memcpy(ecur,head, sizeof(head));

    while (dist[s] < 0){
        if (u == t){
            //aug
            cost = 0;
            int f = INF,neck = s;
            for (int i = s; i != t ; i = G[ecur[i]].v) {
                if (f > G[ecur[i]].cap){
                    f = G[ecur[i]].cap;
                    neck = i;
                }
            }

            flow += f;
            for (int i = s; i != t ; i = G[ecur[i]].v) {

                G[ecur[i]].cap -= f;
                G[ecur[i] ^ 1].cap += f;
                cost += G[ecur[i]].cost*f;
            }

            u = neck;

            if (!Len) Len = cost;

            if (cost == Len) cnt++;
            else break;
        }

        int i;
        for (i = ecur[u]; ~i ; i = G[i].next) {
            if (G[i].cap &&  dist[G[i].v] + G[i].cost <= dist[u]) break;
        }

        if (~i){
            //reset cur flag
            ecur[u] = i;
            edge & fuck = G[i];
            prev[G[i].v] = u;
            u = G[i].v;
        } else{

            int mind = INF;
            for (int j = head[u]; ~j ; j = G[j].next) {
                if (G[j].cap && dist[G[j].v] + G[j].cost < mind){
                    edge & fuck = G[j];

                    mind = dist[G[j].v] + G[j].cost;
                }
            }
            dist[u] = mind;

            u = prev[u];
        }
    }

    return cnt;
}

int main(){
    int n;
    while (~scanf("%d",&n)){
        if (!n){
            printf("%d\n%d\n",0,1);
            continue;
        }
        init();

        for (int i = 0; i < n; ++i) {
            scanf("%d",&A[i]);
            addedge(i,i+offset,1,0);
            addedge(src,i,1,0);
            addedge(i+offset,dst,1,0);
        }

        for (int i = 0;  i < n ; i++) {
            for (int j = i+1; j < n; ++j) {
                if (A[i] < A[j]){
                    addedge(i+offset,j,1,-1);
                }
            }
        }

        int cnt = MCISAP(src,dst,(n<<4) + 4);

        printf("%d\n%d\n",1-Len,cnt);
    }
}


//
//void revspfa(int s){
//    bool outQ[MAXV];
//
//    memset(dist,0x3f, sizeof(dist));
//    memset(outQ, true, sizeof(outQ));
//
//    queue<int > Q;
//    Q.push(s);
//    dist[s] = 0;
//
//    while (!Q.empty()){
//        s = Q.front();
//        Q.pop();
//        outQ[s] = true;
//
//        for (int i = head[s]; ~i ; i = G[i].next) {
//            if (G[i].cap && dist[s] + G[i].cost < dist[G[i].v]){
//                dist[G[i].v] = dist[s] + G[i].cost;
//                pree[G[i].v] = i;
//
//                if (outQ[G[i].v]){
//                    Q.push(G[i].v);
//                    outQ[G[i].v] = false;
//                }
//            }
//        }
//    }
//
//}
//
//int MCMF(int s,int t){
//    int cost,flow,cnt;
//
//    Len = flow = cnt = 0;
//
//    for (;;) {
//        revspfa(s);
//        if (dist[t]>=INF ) break;
//
//        int f = INF;
//        for (int i = t; i != s; i = G[pree[i]^1].v) {
//            f = min(f,G[pree[i]].cap);
//        }
//
//        flow += f;
//        cost = 0;
//        for (int i = t; i !=s ; i = G[pree[i]^1].v) {
//            G[pree[i]].cap -= f;
//            G[pree[i] ^ 1].cap += f;
//            cost += G[pree[i]].cost * f;
//        }
//
//        if (!Len) Len = cost;
//
//        if (cost == Len) cnt++;
//        else break;
//    }
//
//    return cnt;
//}