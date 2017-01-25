//
// Created by Henry on 16/10/4.
//

#include <cstdio>
#include <algorithm>

using namespace std;

struct Node{
    int to;
    int next;
};

const int MAXV = 500 + 10;
const int MAXE = 10000 + 10;
const int OFFSET = 500;

bool used[MAXV + OFFSET];

int head[MAXV + OFFSET];
int match[MAXV + OFFSET];

Node Buffer[MAXE];

int cur;

void addEdge(int u,int v){
    Buffer[cur].to = v;
    Buffer[cur].next = head[u];
    head[u] = cur++;

    Buffer[cur].to = u;
    Buffer[cur].next = head[v];
    head[v] = cur++;
}

bool dfs(int u){
    used[u] = true;
    for (int i = head[u]; ~i ; i = Buffer[i].next) {
        int v = Buffer[i].to;
        int w = match[v];

        if ( w<0 || !used[w] && dfs(w)){
            match[u] = v;
            match[v] = u;
            return true;

        }
    }

    return false;
}

int bipartiteMatch(int begin,int end){
    int res = 0;
    memset(match,-1, sizeof(match));
    for (int i = begin; i <= end ; ++i) {
        if (match[i] < 0){
            memset(used,0, sizeof(used));
            if (dfs(i)) res++;

        }

    }

    return res;
}

void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
}
int main(){
    int n,k;
    while(~scanf("%d %d",&n,&k)){
        init();

        for (int i = 0; i < k; ++i) {
            int r,c;
            scanf("%d%d",&r,&c);
            addEdge(r+OFFSET,c);
        }


        printf("%d\n",bipartiteMatch(1,n));
    }
}