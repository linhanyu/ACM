//
// Created by Henry on 16/9/30.
//

#include <cstdio>
#include <algorithm>
#include <queue>
#include <memory>

using namespace std;

const int MAXM = 10;
const int OFFSET = (1<<MAXM) + 10;
const int MAXV = MAXM + OFFSET + 10;
const int MAXE = MAXM * 100000 * 4;
const int src = MAXV - 2;
const int dst = MAXV - 3;
const int INF = 0x7FFFFFFF;

struct edge{
    int to,cap,next;
}edgeBuffer[MAXE];
int bufferCur;

int bittmp[OFFSET + 10];
int head[MAXV];
int level[MAXV];
int appearLevel[MAXV];

int pre[MAXV];
int cur[MAXV];

int n,m;

void addEdge(int u,int v,int cap){
    edgeBuffer[bufferCur].to = v;
    edgeBuffer[bufferCur].cap = cap;
    edgeBuffer[bufferCur].next = head[u];
    head[u] = bufferCur++;


    edgeBuffer[bufferCur].to = u;
    edgeBuffer[bufferCur].cap = 0;
    edgeBuffer[bufferCur].next = head[v];
    head[v] = bufferCur++;
}

void revBfs(int end){

    memset(level,-1, sizeof(level));
    memset(appearLevel,0, sizeof(appearLevel));

    queue<int> Q;

    Q.push(end);
    level[end] = 0;
    appearLevel[0] = 1;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();


        for (int i = head[u]; ~i ; i = edgeBuffer[i].next) {
            int v = edgeBuffer[i].to;
            if (~level[v]) continue;

            level[v] = level[u] + 1;
            appearLevel[level[v]]++;
            Q.push(v);
        }

    }
}

int maxFlow(int s,int t){
    memcpy(cur,head, sizeof(cur));

    revBfs(t);

    int flow=0,u;
    pre[s] = u = s;
    while(level[u] < n){
        if (u == t){
            int neck = u,f=INF;
            for (int i = s; i != t ; i = edgeBuffer[cur[i]].to) {
                if (f > edgeBuffer[cur[i]].cap){
                    f = edgeBuffer[cur[i]].cap;
                    neck = i;
                }
            }

            for (int i = s; i != t ; i = edgeBuffer[cur[i]].to) {
                edgeBuffer[cur[i]].cap -= f;
                edgeBuffer[cur[i] ^ 1].cap += f;
            }
            flow += f;
            u = neck;
        }

        int i;
        for (i = cur[u]; ~i ; i = edgeBuffer[i].next) {
            if (edgeBuffer[i].cap  && level[edgeBuffer[i].to] + 1 == level[u])
                break;
        }

        if (~i){
            //寻找成功
            cur[u] = i;
            pre[edgeBuffer[i].to] = u;
            u = edgeBuffer[i].to;

        }else{
            if ((--appearLevel[level[u]]) == 0) break;

            int mind = n;
            for (int i = head[u]; ~i ; i = edgeBuffer[i].next) {
                if (edgeBuffer[i].cap && mind  > level[edgeBuffer[i].to]){
                    mind = level[edgeBuffer[i].to];
                    cur[u] = i;
                }
            }

            level[u] = mind + 1;
            appearLevel[level[u]]++;
            u = pre[u];

        }

    }


    return flow;
}


void init(){
    memset(head,-1, sizeof(head));
    bufferCur = 0;
    memset(bittmp,0, sizeof(bittmp));
    n = 8;
    //沿回边,最大距离应该是7(原点到汇点为4)
}

//int main(){
//    for (int i = 0; i <= 10000; ++i) {
//        for (int j = 0; j < 9; ++j) {
//            printf("0 ");
//        }
//        puts("1");
//    }
//}

int main(){
    int tmp,manNum;

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