//
// Created by Henry on 16/4/30.
//

//
//#include <cstdio>
//#include <algorithm>
//#include <iostream>
//#include <memory>
//#include <queue>
//
//#define NUM 120
//#define INF 0x7F
//#define INF2 0x7FFFFF
//using namespace std;
//
//int dis[NUM];
//
//struct cmp{
//    bool operator() (int a,int b){
//        return dis[a] > dis[b];
//    }
//};
//
//int main(){
//    int n,m,a,b,c,item;
//    int rls[NUM][NUM];
//    priority_queue<int ,vector<int>,cmp> Q;
//    bool in_queue[NUM],has_Relation[NUM][NUM],explored[NUM];
//
//    while (cin>>n>>m && (n||m)){
//        memset(rls,INF, sizeof(rls));
//        memset(in_queue,0, sizeof(in_queue));
//        memset(has_Relation,0, sizeof(has_Relation));
//        memset(explored,0, sizeof(explored));
//
//        for (int i = 0; i < m; ++i) {
//            cin>>a>>b>>c;
//            if (c<rls[a][b]) {
//                rls[a][b] = rls[b][a] = c;
//                has_Relation[a][b] = has_Relation[b][a] = true;
//            }
//        }
//
//        Q.push(1);
//        in_queue[1] = true;
//        dis[1] = 0;
//        explored[1] = true;
//
//        while(!Q.empty()){
//            item = Q.top();
//            Q.pop();
//            in_queue[item] = false;
//
//            for (int i = 1; i <= n; ++i) {
//                if (has_Relation[item][i] && (!explored[i] || dis[item] + rls[item][i]<dis[i])){
//                    dis[i] = dis[item] + rls[item][i];
//                    explored[i] = true;
//                    if (!in_queue[i]){
//                        Q.push(i);
//                        in_queue[i] = true;
//                    }
//                }
//            }
//        }
//
//        cout<<dis[n]<<endl;
//    }
//}