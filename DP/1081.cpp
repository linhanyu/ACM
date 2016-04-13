//
// Created by twinklekuang on 16/4/9.
//

//#include <iostream>
//#include <algorithm>
//#define NUM 105
//#define INF 0x7FFFFFFF
//
//
//using namespace std;
//
//int t_array[NUM];
//
//int cal_max_subsequence(int n){
//    int dp=0,Max=-INF;
//    for (int i = 0; i < n ; ++i) {
//        dp = (dp+t_array[i] < 0?0:dp) + t_array[i];
//        Max = max(Max,dp);
//    }
//    return Max;
//
//}

//int main() {
//    int rectangle[NUM][NUM];
//    int n,Max;
//    while(cin>>n){
//        for (int i = 0; i < n ; ++i) {
//            for (int j = 0; j < n  ; ++j) {
//                cin>>rectangle[i][j];
//            }
//
//        }
//        Max = -INF;
//        for (int i = 0 ; i < n ; ++i) {
//            for (int j = i ; j < n ; ++j) {
//                memset(t_array,0, sizeof(int)*n);
//                for (int k = i; k <= j; ++k) {
//                    for (int l = 0; l < n; ++l) {
//                        t_array[l] += rectangle[k][l];
//                    }
//                }
//                Max = max(cal_max_subsequence(n),Max);
//
//            }
//        }
//
//        cout<<Max<<endl;
//
//    }
//}