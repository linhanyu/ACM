//
// Created by Henry on 16/9/29.
//
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXM = 10;
const int OFFSET = 1<<MAXM;
const int INF = 0x7FFFFFFF;
const int src = OFFSET + MAXM + 1;
const int dst = OFFSET + MAXM + 2;

int bittmp[OFFSET + 10];
struct Edge{
    int to,cap,rev;

    Edge(){}
    Edge(int t,int c,int r):to(t),cap(c),rev(r){}
};


vector<Edge> G[4*MAXM + OFFSET];
int level[MAXM + OFFSET + 10];
int iter[MAXM + OFFSET + 10];

void addEdge(int from,int to,int cap){
    G[from].push_back(Edge(to,cap,G[to].size()));
    G[to].push_back(Edge(from,0,G[from].size() - 1));
}

void BFS(int begin){
    memset(level,-1, sizeof(level));

    queue<int> Q;
    level[begin] = 0;
    Q.push(begin);

    while (!Q.empty()){
        int source = Q.front();
        Q.pop();

        for (int i = 0; i < G[source].size(); ++i) {
            Edge & e = G[source][i];
            if (e.cap > 0 && level[e.to] < 0 ){
                level[e.to] = level[source] + 1;
                Q.push(e.to);
            }
        }

    }
}



int DFS(int u,int t,int f){
    if (u == t) return f;

    for (int & i = iter[u]; i < G[u].size(); ++i) {
        Edge & e = G[u][i];
        if (e.cap > 0 && level[u] < level[e.to]){
            int d = DFS(e.to,t,min(f,e.cap));

            if (d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;

            }


        }
    }

    return 0;

}

int maxFlow(int s,int t){
    int flow = 0;
    for (;;){
        BFS(s);
        if (level[t] < 0) return flow;

        memset(iter,0, sizeof(iter));
        int f;
        while((f = DFS(s,t,INF)) > 0){
            flow += f;
        }

    }
}

void init(){
    for (int i = 0; i < (MAXM +OFFSET + 10); ++i) {
        G[i].clear();
    }
}

int main(){
    int m,tmp,manNum;

    while(scanf("%d %d",&manNum,&m)!=EOF){
        init();


        for (int i = 0; i < manNum; ++i) {
            int bitmap = 0;
            for (int j = 0; j < m; ++j) {
                scanf("%d",&tmp);

                if (tmp){
                    bitmap |= 1<<j;
                }

            }
            bittmp[bitmap]++;
        }



        for (int i = 1; i < (1<<m); ++i) {

            if (bittmp[i]){
                addEdge(src,i,bittmp[i]);
                for (int j = 0; j < m; ++j) {
                    if ((1<<j)&i){
                        addEdge(i,j + OFFSET,bittmp[i]);
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d",&tmp);
            addEdge(i+OFFSET,dst,tmp);
        }

        maxFlow(src,dst) >= manNum ? puts("YES"):puts("NO");



    }
}


//int main(){
//    int m,n;
//    vector<int > helper;
//    while (scanf("%d %d",&n,&m)!=EOF){
//        init();
//        int bitmap=0,tmp;
//        for (int i = 0; i < n; ++i) {
//            helper.clear();
//            bitmap = 0;
//            for (int j = 0; j < m; ++j) {
//                scanf("%d",&tmp);
//                if (tmp){
//                    //第j个星球有路
//                    helper.push_back(j);
//                }
//                bitmap <<= 1;
//                bitmap |= tmp;
//            }
//
//            for (int j = 0; j < helper.size(); ++j) {
//                addEdge(bitmap,helper[j] + OFFSET,1);
//            }
//            addEdge(src,bitmap,1);
//
//        }
//
//        for (int i = 0; i < m; ++i) {
//            scanf("%d",&tmp);
//            addEdge(OFFSET + i,dst,tmp);
//        }
//
//        if (maxFlow(src,dst) == n){
//            puts("YES");
//        } else{
//            puts("NO");
//        }
//
//
//
//    }
//}