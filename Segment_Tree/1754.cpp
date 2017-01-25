//
// Created by Henry on 16/5/3.
//

//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//#define NUM 200001
//#define L_child(a) (a<<1)
//#define R_child(a) ((a<<1)|1)
//#define Mid(a,b) ((a+b)>>1)
//int sum[NUM<<4];
//
//void updown(int root){
//    sum[root] = max(sum[L_child(root)],sum[R_child(root)]);
//}
//
//void build(int left,int right,int root){
//    if (left == right){
//        scanf("%d",&sum[root]);
//        return;
//    }
//
//    int mid = Mid(left,right);
//
//    build(left,mid,L_child(root));
//    build(mid+1,right,R_child(root));
//    updown(root);
//}
//
//int search(int L_bound,int R_bound,int left,int right,int root){
//    if (L_bound <= left && right <= R_bound ){
//        return sum[root];
//    }
//
//    int res=0;
//    int mid = Mid(left,right);
//
//    if (L_bound <= mid) {res = max(res,search(L_bound,R_bound,left,mid,L_child(root)));}
//    if (R_bound > mid) {res = max(res,search(L_bound,R_bound,mid+1,right,R_child(root)));}
//
//    return res;
//}
//
//void update(int tag,int val,int left,int right,int root){
//    if(left == right){
//        sum[root] = val;
//        return;
//    }
//
//    int mid = Mid(left,right);
//
//    if (tag <= mid) {update(tag,val,left,mid,L_child(root));}
//    else{update(tag,val,mid+1,right,R_child(root));}
//    updown(root);
//}
//
//int main(){
//    int n,m,op1,op2;
//    char cmd[2];
//    while(scanf("%d%d",&n,&m)!=EOF){
//        build(1,n,1);
//
//        while(m--){
//            scanf("%s %d %d",cmd,&op1,&op2);
//            if (cmd[0] == 'Q'){
//                printf("%d\n",search(op1,op2,1,n,1));
//            }else{
//                update(op1,op2,1,n,1);
//            }
//        }
//    }
//}