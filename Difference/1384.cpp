//
// Created by Henry on 16/9/1.
//
//#include"iostream"
//#include "queue"
//#define inf 0x7FFFFFFF
//#define M 500010
//using namespace std;
//
//int head[M],minm,maxm,dis[M],edge_sum;
//bool inq[M];
//struct a{
//    int end,jie,next;
//}edge[M];
//
//
//void Init(){
//    edge_sum=0;
//    memset(head,-1,sizeof(head));
//    minm=inf;
//    maxm=-inf;
//    memset(inq,0,sizeof(inq));
//    memset(dis,-inf,sizeof(dis));
//}
//
//
//void add_edge(int u,int v, int jie){
//    edge[edge_sum].end=v;
//    edge[edge_sum].jie=jie;
//    edge[edge_sum].next=head[u];
//    head[u]=edge_sum++;
//}
//
//
//int max(int a,int b){ if(a>b)return a;return b;}
//int min(int a,int b){ if(a<b)return a;return b;}
//
//int spfa(){
//    memset(dis,inf,sizeof(dis));
//    queue<int> q;
//    while(!q.empty())q.pop();
//
//    q.push(minm), inq[minm]=1,  dis[minm]=0;
//
//    while( !q.empty()){
//        int u=q.front();	q.pop(),  inq[u]=0;
//
//        for(int i=head[u] ; i!=-1; i=edge[i].next )
//        {
//            int v=edge[i].end, jie=edge[i].jie;
//            if(dis[v]<dis[u]+jie)
//            {
//                dis[v]=dis[u]+jie;
//                if( !inq[v] )	inq[v]=!inq[v],  q.push(v);
//            }
//        }
//
//    }
//    return dis[maxm];
//}
//
//int main(){
//    int n;
//    while(~scanf("%d",&n)){
//        Init();
//        while(n--){
//            int u,v,jie;
//            scanf("%d %d %d",&u,&v,&jie);
//            add_edge(u,v+1,jie);
//
//            minm=min(u,minm);
//            maxm=max(v+1,maxm);
//        }
//        for( int i=minm;i<=maxm;i++)
//            add_edge(i,i+1,0),  add_edge(i+1,i,-1);
//        printf("%d\n",spfa());
//    }
//    return 0;
//}




#include <vector>
#include <deque>
#include <cstdio>
#include <algorithm>

#define NUM 500010
#define INF1 0x7FFFFF
#define INF2 0x7F
using namespace std;
struct Node{
    int target;
    int weight;
    int next;
};

Node rls[NUM];
int head[NUM];
int dis[NUM];
int cur;

void addnode(int source,int target,int weight){
    rls[cur].target = target;
    rls[cur].weight = weight;
    rls[cur].next = head[source];
    head[source] = cur++;


}

int spfa(int begin,int end){
    static bool inQueue[NUM];
    deque<int> Q;
    memset(inQueue,0, sizeof(inQueue));
    inQueue[begin] = 1;
    dis[begin] = 0;
    Q.push_back(begin);


    while (!Q.empty()){
        int item = Q.front();
        Q.pop_front();
        inQueue[item] = 0;

        for (int i = head[item]; i != -1; i = rls[i].next) {
            int target = rls[i].target;

            if (dis[item] + rls[i].weight > dis[target]){
                //relax
                dis[target] = dis[item] + rls[i].weight;
                if (!inQueue[target]){
                    if (Q.empty() || dis[target] < dis[Q.front()]){
                        Q.push_front(target);
                    } else{
                        Q.push_back(target);
                    }
                    inQueue[target] = 1;
                }
            }
        }
    }

    return dis[end];

}

int main(){
    int n,upper,lower;
    while(scanf("%d",&n)!=EOF){
        upper = -1;
        lower = INF1;
        cur = 0;
        memset(head,-1, sizeof(head));
        memset(dis,-1, sizeof(dis));

        for (int i = 1; i <= n; ++i) {
            int left,right,weight;
            scanf("%d %d %d",&left,&right,&weight);
            //f(right) - f(left-1),右移一位得f(right+1)-f(left)
            addnode(left,right+1,weight);

            upper = max(upper,right+1);
            lower = min(lower,left);
        }

        for (int i = lower; i <= upper; ++i) {

            addnode(i,i+1,0);
            //自己到自己
            addnode(i+1,i,-1);

        }

        printf("%d\n",spfa(lower,upper));


    }

}
