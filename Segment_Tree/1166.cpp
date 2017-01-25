//
// Created by Henry on 16/5/3.
//

//#include <cstdio>
//
//#define l_son(a) (a<<1)
//#define r_son(a) ((a<<1)|1)
//#define NUM 10
//#define maxn 50001
//#define mid(a,b) ((a+b)>>1)
//using namespace std;
//
//int sum[maxn<<4];
//
//void Pushup(int root){
//    sum[root] = sum[l_son(root)] + sum[r_son(root)];
//}
//
//void build(int left,int right,int root){
//    if (left == right){
//        scanf("%d",&sum[root]);
//        return;
//    }
//
//    int m = mid(left,right);
//    build(left,m,l_son(root));
//    build(m+1,right,r_son(root));
//    Pushup(root);
//}
//
//
//int search(int L_bound,int R_bound,int left,int right,int root){
//    if (L_bound <= left && right <= R_bound){
//        return sum[root];
//    }
//
//    int mid  = mid(left,right);
//    int res = 0;
//
//    if (L_bound <= mid ) {res += search(L_bound,R_bound,left,mid,l_son(root));}
//    if (R_bound > mid) {res += search(L_bound,R_bound,mid+1,right,r_son(root));}
//    return res;
//}
//
//void update(int tag,int val,int left,int right,int root){
//    if (left==right){
//        sum[root] += val;
//        return;
//    }
//
//    int mid = mid(left,right);
//    if (tag > mid){update(tag,val,mid+1,right,r_son(root));}
//    else {update(tag,val,left,mid,l_son(root));}
//
//    Pushup(root);
//}
//
//
//int main(){
//    int t,n,op1,op2;
//    char cmd[NUM];
//    scanf("%d",&t);
//    for (int l = 1; l <= t; ++l) {
//        printf("Case %d:\n",l);
//        scanf("%d",&n);
//        build(1,n,1);
//
//        while(scanf("%s",cmd)){
//            if (cmd[0] == 'E')break;
//
//            scanf("%d %d",&op1,&op2);
//            if (cmd[0] == 'A'){
//                update(op1,op2,1,n,1);
//            } else if (cmd[0] == 'S'){
//                update(op1,-op2,1,n,1);
//
//            } else{
//                printf("%d\n",search(op1,op2,1,n,1));
//            }
//
//
//        }
//
//
//    }
//}