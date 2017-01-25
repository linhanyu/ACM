//
// Created by Henry on 16/10/11.
//

#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 10000 + 10;
const int MAXM = 50000 + 10;

int N,M,V;
int A[MAXM],B[MAXM];

vector<int > G[MAXN];
vector<int > rG[MAXN];
vector<int > vs;

bool used[MAXN];
int cmp[MAXN];

void add_edge(int u,int v){
    G[u].push_back(v);
    rG[v].push_back(u);
}

void dfs(int v){
    used[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
        if (!used[G[v][i]]) dfs(G[v][i]);
    }

    vs.push_back(v);
}

void rdfs(int v,int k){
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); ++i) {
        if (!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
}

int scc(){
    memset(used,0, sizeof(used));
    vs.clear();
    for (int i = 0; i < V; ++i) {
        if (!used[i]) dfs(i);
    }

    memset(used,0, sizeof(used));
    int k=0;
    for (int i = vs.size() - 1; i >= 0; --i) {
        if (!used[vs[i]]) rdfs(vs[i],k++);
    }

    return k;
}

void solve(){
    V = N;
    for (int i = 0; i < M; ++i) {
        add_edge(A[i]-1,B[i]-1);
    }

    int n = scc();

    int u = 0 ,num = 0;
    for (int i = 0; i < V; ++i) {
        if (cmp[i] == n-1){
            u = i;
            num++;
        }
    }

    memset(used,0, sizeof(used));
    rdfs(u,0);

    for (int i = 0; i < V; ++i) {
        if (used[i]) continue;
        num = 0;
        break;
    }
    printf("%d\n",num);
}

int main(){
    while (~scanf("%d %d",&N,&M)){
        for (int i = 0; i < M; ++i) {
            scanf("%d %d",&A[i],&B[i]);
        }

        solve();
    }
}