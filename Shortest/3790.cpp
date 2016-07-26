//
// Created by Henry on 16/4/30.
//

//#include<iostream>
//#include<cstdio>
//#include <queue>
//#include <vector>
//
//#define NUM 1001
//#define INF2 0x7F
//
//#define INF 0x7FFFF
//
//using namespace std;
//
//int cost[NUM];
//int dis[NUM];
//int v_cost[NUM][NUM],v_dis[NUM][NUM];
//
//
//
//struct cmp{
//    bool operator() (int a,int b){
//        if (dis[a] == dis[b]){
//            return cost[a] > cost[b];
//        } else{
//            return dis[a] > dis[b];
//        }
//
//    }
//};
//
//int main(){
//    int v_cost[NUM][NUM],v_dis[NUM][NUM];
//
//    int n,m,a,b,d,p,s,t,bef_item;
//    bool in_queue[NUM];
//
//    priority_queue<int,vector<int>,cmp> Q;
//
//    while(scanf("%d%d",&n,&m)!=EOF && (m||n)){
//        n++;
//        for (int i = 1; i < n; ++i) {
//            for (int j = 1; j < n; ++j) {
//                v_cost[j][i] = INF;
//                v_dis[j][i] = INF;
//            }
//
//        }
//
//
//        memset(in_queue,0, sizeof(bool)*n);
//        memset(cost,0x7F, sizeof(int)*n);
//        memset(dis,0x7F, sizeof(int)*n);
//
//        for (int i = 0; i < m; ++i) {
//            scanf("%d%d%d%d", &a, &b, &d, &p);
//            if (v_dis[a][b]>d){
//                v_dis[a][b] = v_dis[b][a] = d;
//                v_cost[a][b] = v_cost[b][a] = p;
//
//            } else if (v_dis[a][b] == d){
//                v_cost[a][b] = v_cost[b][a] = p;
//
//            }
//
//        }
//
//        scanf("%d%d",&s,&t);
//        Q.push(s);
//        in_queue[s] = true;
//        dis[s] = 0;
//        cost[s] = 0;
//
//        while(!Q.empty()){
//            bef_item = Q.top();
//            Q.pop();
//            in_queue[bef_item] = false;
//
//            for (int i = 1; i < n; ++i) {
//                    if (dis[bef_item]  < dis[i] - v_dis[bef_item][i]){
//                        dis[i] = dis[bef_item] + v_dis[bef_item][i];
//                        cost[i] = cost[bef_item] + v_cost[bef_item][i];
//                        if (!in_queue[i]){
//                            Q.push(i);
//                            in_queue[i] = true;
//                        }
//                    } else if (dis[bef_item] == dis[i] - v_dis[bef_item][i]){
//                        cost[i] = min(cost[bef_item] + v_cost[bef_item][i],cost[i]);
//                        if (!in_queue[i]){
//                            Q.push(i);
//                            in_queue[i] = true;
//                        }
//                    }
//
//            }
//
//        }
//        printf("%d %d\n",dis[t],cost[t]);
//
//    }
//}