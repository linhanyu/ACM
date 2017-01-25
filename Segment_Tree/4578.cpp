//
// Created by Henry on 16/5/7.
////
//
//#include <cstdio>
//#include <queue>
//
//
//#define Mid(a,b) ((a+b)>>1)
//#define L_child(a) (a<<1)
//#define R_child(a) ((a<<1)|1)
//#define maxn  100001
//#define  MULTY true
//#define  ADD false
//#define pow(a) (a-1)
//
//using namespace std;
//struct col{
//    bool op;
//    int val;
//};
//int sum[3][maxn<<2];
//
//queue<col > cols[maxn<<2];
//
//
//
//void pushup(int root){
//    for (int i = 0; i < 3; ++i)
//    sum[i][root] = sum[i][L_child(root)] + sum[i][R_child(root)];
//}
//
//int powd(int val,int pow){
//    for (int i = 1; i < pow; ++i) {
//        val *= val;
//    }
//    return val;
//}
//
//void push_down(int root,int m){
//    int l_child = L_child(root),r_child = R_child(root),val;
//    while(!cols[root].empty()){
//        col & temp = cols[root].front();
//        val = temp.val;
//        if (temp.op == MULTY){
//            cols[l_child].push(temp);
//            cols[r_child].push(temp);
//            for (int i = 0; i < 3; ++i) {
//                sum[i][l_child] *= val;
//                sum[i][r_child] *= val;
//            }
//        } else{
//
//        }
//        cols[root].pop()
//    }
//}
//
//
//
//
//
//void build(int left,int right,int root){
//    for (int i = 0; i < 3; ++i) {
//        sum[i][root] = 0;
//    }
//
//    if (left == right){
//        return;
//    }
//
//    int mid = Mid(left,right);
//    build(left,mid,L_child(root));
//    build(mid + 1,right,R_child(root));
//
//}
//
//
//
//int main(){
//
//}