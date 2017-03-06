//
// Created by Henry on 17/3/5.
//

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 200 + 10;
const int INF = 0x3f3f3f3f;
int f[MAXN];
int dist[MAXN];
int n,a,b;

int BFS(int s){
    memset(dist,-1, sizeof(dist));

    queue<int > Q;

    dist[s] = 0;
    Q.push(s);

    while (!Q.empty()){
        s = Q.front();
        Q.pop();

        for (int i = -1; i <= 1; i += 2) {
            int v = s + f[s]*i;
            if (v > n || v < 1 || ~dist[v]) continue;
            dist[v] = dist[s] + 1;
            Q.push(v);
            if (v == b) return dist[v];
        }

    }

    return -1;

}

int main(){
    while (~scanf("%d",&n) && n){
        scanf("%d%d",&a,&b);
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&f[i]);
        }

        printf("%d\n",a == b ? 0 : BFS(a));
    }
}