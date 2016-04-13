//
// Created by twinklekuang on 16/4/9.
//

#include <iostream>
#include <queue>

#define NUM 100

using namespace std;

struct ord{
    int x;
    int y;
};

int dis[NUM][NUM];
ord Buffer[NUM];

struct cmp{
    bool operator() (int & a,int & b){
        return dis[Buffer[a].x][Buffer[a].y] > dis[Buffer[b].x][Buffer[b].y];

    }
};



//int main(){
//    int t,n;
//    int Rectan[NUM][NUM];
//    priority_queue<int ,vector<int>,cmp> Q;
//    cin>>t;
//    while(t--){
//        cin>>n;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                cin>>Rectan[i][j];
//            }
//        }
//
//        for (int i = 0; i < n-1; ++i) {
//            for (int j = 0; j < n-i-1; ++j) {
//                Rectan[i][j] += Rectan[n-j][n-i];
//            }
//        }
//
//        Q.push(0);
//        while (!Q.empty()){
//
//        }
//    }
//}