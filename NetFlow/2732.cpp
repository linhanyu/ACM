//
// Created by Henry on 16/9/25.
//
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<iostream>

#define ABS(a) ( (a) > 0 ? (a) : (-(a)) )

using namespace std;

const int MAXN = 1000 + 10;
const int INF = 0x7FFFFFFF;
const int OFFSET = 400;

struct Edge{
    int to,cap,rev;
    Edge(){}
    Edge(int t,int c,int rev):to(t),cap(c),rev(rev){}
};

int n,m,s,t,src,dst;
vector<Edge> edges[MAXN];
int level[MAXN];
int iter[MAXN];

void init(){
    for (int i = 0; i < MAXN; ++i) {
        edges[i].clear();
    }
}

void addEdge(int u,int v,int cap){
    edges[u].push_back(Edge(v,cap,(int)edges[v].size()));
    edges[v].push_back(Edge(u,0,(int)edges[u].size()-1));
}

void BFS(int begin){
    memset(level,-1, sizeof(level));

    queue<int> Q;
    Q.push(begin);
    level[begin] = 0;

    while(!Q.empty()){
        int source = Q.front();
        Q.pop();

        for (int i = 0; i < edges[source].size(); ++i) {
            Edge & v = edges[source][i];
            if (v.cap > 0 && level[v.to] < 0 ){
                level[v.to] = level[source] + 1;
                Q.push(v.to);
            }
        }

    }

}

int dfs(int u,int t,int f){
    if (u == t) return f;

    for (int & i = iter[u]; i < edges[u].size(); ++i) {
        Edge & e = edges[u][i];
        if (e.cap > 0 && level[u] < level[e.to]){
            int d = dfs(e.to,t,min(f,e.cap));

            if (d>0){
                e.cap -= d;
                edges[e.to][e.rev].cap += d;
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
        if (level[t] < 0 )return flow;

        memset(iter,0, sizeof(iter));
        int f;

        while((f = dfs(s,t,INF)) > 0){
            flow += f;
        }

    }

}


//const int INF;
//int maxFlow(){
//    return INF;
//}

int main(){
    int cases,n,d,m,sum;
    string s;
    cin>>cases;

    src = MAXN-2;
    dst = MAXN-1;

    for (int cas = 1; cas <= cases ; ++cas) {

        scanf("%d %d",&n,&d);
        init();
        sum = 0;

        for (int i = 0; i < n; ++i) {
            cin>>s;

            if (!i) m = s.size();

            for (int j = 0; j < m; ++j) {
                if (s[j] - '0' > 0){
                    int id = i*m + j;
                    addEdge(id,id+OFFSET,s[j] - '0');

                    if (i - d < 0 || j - d < 0 || i+d >= n || j+d >= m){
                        addEdge(id+OFFSET,dst,INF);
                    } else{
                        for (int k = i-d ; k <= i+d; ++k) {
                            for (int l = j-d ; l <= j+d ; ++l) {
                                int id2 = k*m + l;
                                if (id == id2) continue;
                                if (ABS(i-k) + ABS(j-l) <= d) addEdge(id+OFFSET,id2,INF);
                            }
                        }
                    }

                }
            }


        }

        for (int  i = 0;  i< n; ++i) {
            cin>>s;

            for (int j = 0; j < m; ++j) {
                int id = m*i + j;
                if (s[j] == 'L'){
                    ++sum;
                    addEdge(src,id,1);
                }
            }
        }

        int ans = sum - maxFlow(src,dst);

        if(ans==0) printf("Case #%d: no lizard was left behind.\n",cas);
        else if(ans == 1)printf("Case #%d: 1 lizard was left behind.\n",cas);
        else printf("Case #%d: %d lizards were left behind.\n",cas,ans);
    }

    return 0;

//    printf("%d\n",maxFlow());
}
