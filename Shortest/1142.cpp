//
// Created by Henry on 16/5/1.
//
//
//#include <iostream>
//#include <queue>
//#include <memory>
//
//#define NUM 1010
//#define INF 0x7FFFFFFF
//#define INF_2 0x7F
//
//using namespace std;
//
//int dis[NUM];
//int rls[NUM][NUM];
//int sum[NUM];
//int n,m,a,b,c,bef_item;
//
//int DFS(int now){
//    int count=0;
//
//    if (now == 2){
//        return 1;
//    }
//
//    if (sum[now] > 0){
//        return sum[now];
//    }
//
//    for (int i = 1; i <= n; ++i) {
//        if (rls[now][i] < INF && dis[i] < dis[now] ){
//            count += DFS(i);
//        }
//    }
//
//    sum[now] = count;
//    return count;
//}
//
//struct cmp{
//    bool  operator() (int a,int b){
//        return dis[a] > dis[b];
//    }
//};
//
//int main(){
//    bool in_queue[NUM];
//
//    priority_queue<int,vector<int >,cmp> Q;
//    while(cin>>n && n){
//        cin>>m;
//        for (int i = 1; i <= n; ++i) {
//            rls[1][i] = INF;
//
//        }
//        for (int i = 2; i <= n; ++i) {
//            memcpy(&rls[i][1],&rls[1][1],n* sizeof(int));
//        }
//
//        memset(&in_queue[1],0, sizeof(bool)*n);
//        memset(&sum[1],0, sizeof(int)*n);
//        memset(&dis[1],INF_2, sizeof(int)*n);
//
//
//        while(m--){
//            cin>>a>>b>>c;
//            rls[a][b] = rls[b][a] = c;
//        }
//
//        //DIJ
//        Q.push(2);
//        dis[2] = 0;
//        while(!Q.empty()){
//            bef_item = Q.top();
//            Q.pop();
//            in_queue[bef_item] = false;
//
//            for (int i = 1; i <= n; ++i) {
//                if (dis[bef_item] < dis[i] - rls[bef_item][i]){
//                    dis[i] = dis[bef_item] + rls[bef_item][i];
//                    if (!in_queue[i]){
//                        in_queue[i] = true;
//                        Q.push(i);
//                    }
//                }
//            }
//        }
//
//        //DFS
//
//        cout<<DFS(1)<<endl;
//    }
//}