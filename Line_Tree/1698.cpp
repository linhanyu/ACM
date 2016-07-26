//
// Created by Henry on 16/5/5.
//
//
//#include <iostream>
//#include <cstdio>
//
//#define L_son(a) (a<<1)
//#define R_son(a) ((a<<1)|1)
//#define maxn 100001
//#define Mid(a,b) ((a+b)>>1)
//
//using namespace std;
//
//int col[maxn<<2];
//int sum[maxn<<2];
//
//void push_up(int root){
//    sum[root] = sum[L_son(root)] + sum[R_son(root)];
//}
//
//void push_down(int root,int m){
//    if(col[root]){
//        col[L_son(root)] = col[R_son(root)] = col[root];
//        sum[L_son(root)] = (m-(m>>1)) * col[root];
//        sum[R_son(root)] = (m>>1) * col[root];
//        col[root] = 0;
//
//    }
//}
//
//void build(int left,int right,int root){
//    col[root] = 0;
//    sum[root] = 1;
//    if (left == right){
//        return;
//    }
//
//    int mid = Mid(left,right);
//    build(left,mid,L_son(root));
//    build(mid+1,right,R_son(root));
//    push_up(root);
//
//}
//
//void update(int L_bound,int R_bound,int c,int left,int right,int root){
//    if (L_bound<=left && right <= R_bound){
//        col[root] = c;
//        sum[root] = c*(right-left+1);
//        return;
//    }
//    push_down(root,right-left+1);
//    int mid =Mid(left,right);
//    if(L_bound <= mid){update(L_bound,R_bound,c,left,mid,L_son(root));}
//    if(R_bound > mid){update(L_bound,R_bound,c,mid+1,right,R_son(root));}
//    push_up(root);
//
//
//}
//
//int main(){
//    int t,n,q,l,r,c;
//    scanf("%d",&t);
//    for (int i = 1 ; i <= t; ++i) {
//        scanf("%d%d",&n,&q);
//        build(1,n,1);
//
//        while(q--){
//            scanf("%d%d%d",&l,&r,&c);
//            update(l,r,c,1,n,1);
//        }
//
//        printf("Case %d: The total value of the hook is %d.\n",i,sum[1]);
//    }
//}