//
// Created by Henry on 16/5/1.
//


//#include <iostream>
//#include <cstdio>
//#include <cmath>
//
//#define NUM 102
//#define pow_2(a) ((a)*(a))
//#define INF 10000000
//
//using namespace std;
//
//double rls[NUM][NUM];
//int n;
//
//double min_spantree(int begin){
//    int Min_subscrip;
//    double lowcast[NUM],Min,count=0;
//    bool in_tree[NUM];
//
//    for (int i = 0; i < n; ++i) {
//        lowcast[i] = rls[begin][i];
//        in_tree[i] = false;
//
//    }
//
//    in_tree[begin] = true;
//
//    for (int i = 0; i < n - 1; ++i) {
//        Min = INF;
//        for (int j = 0; j < n; ++j) {
//            if (!in_tree[j] && lowcast[j]<Min){
//                Min_subscrip = j;
//                Min = lowcast[j];
//            }
//        }
//
//        count += Min;
//        in_tree[Min_subscrip] = true;
//
//        for (int j = 0; j < n; ++j) {
//            if (!in_tree[j] && rls[Min_subscrip][j] &&rls[Min_subscrip][j]<lowcast[j]){
//                lowcast[j] = rls[Min_subscrip][j];
//            }
//        }
//    }
//
//    return count;
//
//
//}
//
//
//struct ord{
//    double x;
//    double y;
//    double cal_dis(ord & b){
//        return sqrt(pow_2(b.y-y) + pow_2(b.x - x));
//    }
//
//};
//
//int main(){
//    ord ords[NUM];
//    while (cin>>n ){
//
//        for (int i = 0; i < n; ++i) {
//            cin>>ords[i].x>>ords[i].y;
//        }
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                rls[i][j] = ords[i].cal_dis(ords[j]);
//            }
//         }
//
//        printf("%.2lf\n",min_spantree(0));
//
//    }
//
//}