//
// Created by Henry on 16/5/5.
//

#include <iostream>
#include <cstdio>

#define L_son(a) (a<<1)
#define R_son(a) ((a<<1)|1)
#define maxn 100001
#define Mid(a,b) ((a+b)>>1)


//long long sum[maxn<<2];
//long long late_sign[maxn<<2];
//
//using namespace std;
//
//void push_up(int root){
//    sum[root] = sum[L_son(root)] + sum[R_son(root)];
//}
//
//void push_down(int root,int m){
//    if (late_sign[root]){
//        late_sign[L_son(root)] += late_sign[root];
//        late_sign[R_son(root)] += late_sign[root];
//        sum[L_son(root)] += late_sign[root]*(m-(m>>1));
//        sum[R_son(root)] += late_sign[root]*(m>>1);
//
//        late_sign[root] = 0;
//    }
//}
//
//void build(int left,int right,int root){
//    late_sign[root] = 0;
//    if (left == right){
//        scanf("%lld",&sum[root]);
//        return;
//    }
//
//    int mid = Mid(left,right);
//    build(left,mid,L_son(root));
//    build(mid+1,right,R_son(root));
//    push_up(root);
//}
//
//void update(int L_bound,int R_bound,int left,int right,int root,int val){
//    if (L_bound<= left && right <= R_bound ){
//        sum[root] += (long long)val * (right-left+1);
//        late_sign[root] += val;
//        return;
//    }
//
//    push_down(root,right-left+1);
//    int mid = Mid(left,right);
//    if (L_bound<=mid) {update(L_bound,R_bound,left,mid,L_son(root),val);}
//    if (R_bound>mid) {update(L_bound,R_bound,mid+1,right,R_son(root),val);}
//    push_up(root);
//}
//
//long long query(int L_bound,int R_bound,int left,int right,int root){
//    if (L_bound<= left && right <= R_bound){
//        return sum[root];
//    }
//
//    push_down(root,right-left+1);
//    long long res=0;
//    int mid = Mid(left,right);
//    if (L_bound <= mid ){res += query(L_bound,R_bound,left,mid,L_son(root));}
//    if (R_bound > mid ){res += query(L_bound,R_bound,mid+1,right,R_son(root));}
//    return res;
//
//}
//
//int main(){
//    int n,q,op1,op2,op3;
//    char cmd[2];
//    while(scanf("%d%d",&n,&q)!=EOF){
//        build(1,n,1);
//        while(q--){
//            scanf("%s",cmd);
//            if (cmd[0] == 'Q'){
//                scanf("%d %d",&op1,&op2);
//                printf("%lld\n",query(op1,op2,1,n,1));
//            } else{
//
//                scanf("%d %d %d",&op1,&op2,&op3);
//                update(op1,op2,1,n,1,op3);
//            }
//        }
//    }
//}
