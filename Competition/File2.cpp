//
// Created by Henry on 16/9/10.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <memory>
#include <map>

#define MID(a,b) ((a+b)>>1)
#define L(a) (a<<1)
#define R(a) (a<<1|1)
using namespace std;

const int MAXN = 100000 + 10;

int BUFFER[MAXN<<2];

int A[MAXN];
int n;

void PushUp(int rt){
    BUFFER[rt] = min(BUFFER[L(rt)],BUFFER[R(rt)]);
}

void build(int left,int right,int root){
    if (left == right){
        BUFFER[root] = A[left];
        return;
    }

    int m = MID(left,right);
    build(left,m,L(root));
    build(m+1,right,R(root));
    PushUp(root);
}

int query(int left,int right,int root,int RB,int LB){
    if (LB <= left && right <= RB){
        return BUFFER[root];
    }

    int m = MID(left,right);//少了个if...
    int a =query(left,m,L(root),RB,LB);
    int b =query(m+1,right,R(root),RB,LB);

    return min(a,b);
}

int main(){
    int cases;


    cin>>cases;
    while (cases--){
        cin>>n;
        for (int i = 0; i < n;++i) {
            cin>>A[i];
        }

        build(0,n-1,1);
        int m;
        cin>>m;
        while(m--){
            int l,r;
            cin>>l>>r;
            int min = query(0,n-1,1,r-1,l);
            if (min > A[l]){
                printf("%d\n",A[l]);
            } else{
                printf("%d\n",A[l] % min);
            }
        }




    }

}


//struct edge{
//    int u;
//    int v;
//
//    edge(int u,int v):u(u),v(v){}
//};
//
//const int MAXN = 200000 +10;
//const int MAXM = 5500 + 10;
//
//vector<int > rls[MAXN];
//vector<edge > edges;
//
//map<int,int > hashs;
//map<int,int > backhashs;
//
//bool crls[MAXM][MAXM];
//bool visited[MAXM];
//
//int dis[MAXN];
//int BUFFER[MAXN];
//int cases,n,m;
//int counter;
//
//void init(){
//    memset(crls,1, sizeof(crls));
//    hashs.clear();
//    backhashs.clear();
//    edges.clear();
//
//    for(int i=1;i<=n;i++){
//        rls[i].clear();
//        BUFFER[i] = -1;
//        dis[i] = -1;
//    }
//}
//
//
//int Find(int rt){
//    if(BUFFER[rt] < 0){
//        return rt;
//    } else{
//        return BUFFER[rt] = Find(BUFFER[rt]);
//    }
//}
//
//void Merge(int rt1,int rt2){
//    rt1 = Find(rt1);
//    rt2 = Find(rt2);
//
//    if (rt1 < rt2){
//        BUFFER[rt2] = rt1;
//    } else{
//        if (rt1 == rt2) BUFFER[rt2]--;
//        BUFFER[rt1] = rt2;
//    }
//}
//
//
//void addedge(int s){
//    int rt =Find(s);
//
//    counter = 0;
//    for (int i = 1; i <= n ; ++i) {
//        if (Find(i) == rt){
//            for (int j = 0; j < rls[i].size(); ++j) {
//                edges.push_back(edge(i,rls[i][j]));
//            }
//            backhashs[counter] = i;
//            hashs[i]= counter++;
//        }else{
//            dis[i] = 1;
//        }
//    }
//
//    for (int i = 0; i < edges.size(); ++i) {
//        crls[hashs[edges[i].u]][hashs[edges[i].v]] = crls[hashs[edges[i].v]][hashs[edges[i].u]] = false;
//    }
//
//}
//
//void BFS(int begin){
//    queue<int> Q;
//    Q.push(begin);
//    dis[backhashs[begin]] = 0;
//    visited[begin] = true;
//
//    while (!Q.empty()){
//        int source = Q.front();
//        Q.pop();
//
//        int i;
//        for (i = 0; i < counter ; ++i) {
//            if (crls[source][i] && !visited[i]){
//                visited[i] = true;
//                dis[backhashs[i]] = dis[backhashs[source]] + 1;
//                Q.push(i);
//            }
//        }
//    }
//}
//
//int main(){
//    int cases;
//    cin>>cases;
//    while(cases--){
//        cin>>n>>m;
//        init();
//
//        for (int i = 0; i < m; ++i) {
//            int u,v;
//            cin>>u>>v;
//            rls[u].push_back(v);
//            Merge(u,v);
//        }
//
//        int s;
//        cin>>s;
//
//        addedge(s);
//        BFS(hashs[s]);
//
//        bool flag = true;
//        for (int j = 1; j <= n; ++j) {
//            if (j == s) continue;
//
//            if(flag){
//                printf("%d",dis[j]);
//                flag = false;
//                continue;
//            }
//
//
//            printf(" %d",dis[j]);
//        }
//        puts("");
//
//    }
//}


//void init(){
//    int i;
//    for (i = 1; i <= n; ++i) {
//        dis[i] = -1;
//        visited[i] = false;
//        int j;
//        for (j = 1; j <=n; ++j) {
//            rls[i][j] = true;
//        }
//    }
//}
//
//
//void BFS(int begin){
//    queue<int> Q;
//    Q.push(begin);
//    dis[begin] = 0;
//    visited[begin] = true;
//
//    while (!Q.empty()){
//        int source = Q.front();
//        Q.pop();
//
//        int i;
//        for (i = 1; i <=n ; ++i) {
//            if (rls[source][i] && !visited[i]){
//                visited[i] = true;
//                dis[i] = dis[source] +1;
//                Q.push(i);
//            }
//        }
//    }
//}
//
//int main()
//{
//
//    cin>>cases;
//    while(cases--){
//        cin>>n>>m;
//        init();
//        int i;
//        for (i = 0; i < m; ++i) {
//            int u,v;
//            cin>>u>>v;
//            rls[u][v] = rls[v][u] = false;
//        }
//
//        int s;
//        cin>>s;
//        BFS(s);
//
//        for (i = 1; i < n; ++i) {
//            if(i == s) continue;
//            printf("%d ",dis[i]);
//        }
//        printf("%d\n",dis[n]);
//    }
//
//}
//unsigned long long k;
//unsigned long long counter;
//
////void Findweak(int u,int newnode){
////    for (int i = 0; i < BUFFER[u].size(); ++i) {
////        if (newnode * BUFFER[u][i] <= k) counter++;
////        Findweak(BUFFER[u][i],newnode);
////    }
////}
////
////void Union(int u,int v){
////    BUFFER[u].push_back(v);
////    if (!appear[u]){
////        appear[u] = appear[v] = true;
////        Findweak(u,u);
////    }
////}
////
////void BinarySearch(int A[],int left,int right,int key){
////    while(left <= right){
////        int mid = (left + right)>>1;
////        if (A[mid] > key){
////
////        }
////    }
////}
//
//long long dp[MAXN];
//int A[MAXN];
//int main() {
//    int cases,n;
//    cin>>cases;
//    while(cases--){
//        int u,v;
//        cin>>n>>k;
////        counter = 0;
////        Union(u,v);
//        dp[0] = 0;
//        for (int i = 0; i < n; ++i) {
//            cin>>A[i];
//        }
//
//        for (int i = 1; i < n ; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (A[i] * A[j] <= k) dp[i] += dp[j];
//            }
//        }
//
//    }
//
//}