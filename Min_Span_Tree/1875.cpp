//
// Created by Henry on 16/5/2.
//
//
//#include <iostream>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//
//#define pow_2(a) ((a)*(a))
//#define NUM 100
//#define INF 1000000000
//
//#define PRICE 100
//
//using namespace std;
//
//
//double rls[NUM][NUM];
//
//int c;
//
//struct ord{
//    int x;
//    int y;
//    double cal_dis(ord & od){
//        return sqrt(pow_2(x-od.x) + pow_2(od.y - y));
//    }
//
//};
//
//double min_span_tree(int begin){
//    int Min_sub;
//    double Min,count = 0;
//    static double low_cost[NUM];
//    static bool in_tree[NUM];
//    bool flag;
//    for (int i = 0; i < c; ++i) {
//        low_cost[i] = rls[begin][i];
//    }
//    memset(in_tree,0, sizeof(bool) * c);
//    in_tree[begin] = true;
//
//    for (int i = 0; i < c-1; ++i) {
//        Min = INF;
//        flag = true;
//        for (int j = 0; j < c; ++j) {
//            if (!in_tree[j] && low_cost[j] < Min){
//                Min = low_cost[j];
//                Min_sub = j;
//                flag = false;
//            }
//        }
//
//        if (flag)
//            return -1;
//        count += Min;
//        in_tree[Min_sub] = true;
//
//        for (int j = 0; j < c; ++j) {
//            if (!in_tree[j] && rls[Min_sub][j] && rls[Min_sub][j] < low_cost[j]){
//                low_cost[j] = rls[Min_sub][j];
//            }
//        }
//    }
//
//    return count;
//}
//
//int main(){
//    int t;
//    ord ords[NUM];
//    bool flag;
//    double tmp,tmp_dis;
//    cin>>t;
//    while(t--){
//        cin>>c;
//        for (int i = 0; i < c; ++i) {
//            cin>>ords[i].x>>ords[i].y;
//        }
//
//        for (int i = 0; i < c; ++i) {
//            for (int j = 0; j < c; ++j) {
//
//                if (i == j){
//                    rls[i][j] = 0;
//                    continue;
//                }
//
//                tmp_dis = ords[i].cal_dis(ords[j]);
//                if (tmp_dis >= 10 && tmp_dis <= 1000){
//                    rls[i][j] = rls[j][i] =tmp_dis*PRICE;
//                } else{
//                    rls[i][j] = rls[j][i] =INF;
//
//                }
//            }
//        }
//
//        tmp = min_span_tree(0);
//        if (tmp < 0){
//            printf("oh!\n");
//        } else{
//            printf("%.1lf\n",tmp);
//        }
//
//
//
//
//
//    }
//}