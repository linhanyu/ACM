//
// Created by Henry on 16/5/2.
//
//
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//
//#define prime_size 2000002
#define NUM 601
#define INF 0x7FFFFFFF
//using namespace std;
//
//bool is_prime[prime_size];
int rls[NUM][NUM],n;
//
//void init_prime(){
//    memset(is_prime,1, sizeof(is_prime));
//    is_prime[0] = is_prime[1] = false;
//
//    for (int i = 2; i < prime_size; ++i) {
//        if (is_prime[i]){
//            for (int j = i<<1; j < prime_size; j += i) {
//                is_prime[j] = false;
//            }
//        }
//    }
//}
//

int min_span_tree(int begin,int n){
    static int low_cost[NUM];
    static bool in_tree[NUM];
    int Min,count=0,Min_sub;
    bool flag;
    for(int i=0;i<n;i++){
        low_cost[i] = rls[begin][i];
    }

    memset(in_tree,0, sizeof(bool)*n);
    in_tree[begin] = true;

    for (int i = 0; i < n-1; ++i) {
        Min = INF;
        flag  = true;
        for (int j = 0; j < n; ++j) {
            if (!in_tree[j] && low_cost[j]<Min) {
                Min = low_cost[j];
                Min_sub = j;
                flag = false;
            }
        }

        if (flag) return -1;
        count += Min;
        in_tree[Min_sub] = true;

        for (int j = 0; j < n; ++j) {
            if (!in_tree[j] && Min_sub!=j && rls[Min_sub][j] < low_cost[j]) {
                low_cost[j] = rls[Min_sub][j];
            }
        }

    }

    return count;
}
//
//
//
//
//int main(){
//    init_prime();
//    int t;
//    int city[NUM];
//    cin>>t;
//    while(t--){
//        cin>>n;
//        for (int i = 0; i < n; ++i) {
//            cin>>city[i];
//        }
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (i==j){
//                    rls[i][j] = 0;
//                    continue;
//                }
//
//                if (is_prime[city[i]] || is_prime[city[j]] || is_prime[city[i]+city[j]]){
//                    rls[i][j] = rls[j][i] = min(min(city[i],city[j]),abs(city[i]-city[j]));
//                } else{
//                    rls[i][j] = rls[j][i] = INF;
//                }
//
//            }
//        }
//
//        cout<<min_span_tree(0)<<endl;
//
//
//    }
//}