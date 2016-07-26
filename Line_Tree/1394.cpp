////
//// Created by Henry on 16/5/3.
////
//
//#include <iostream>
//#include <algorithm>
//
//#define L_child(a) (a<<1)
//#define R_child(a) ((a<<1)|1)
//#define Mid(a,b) ((a+b)>>1)
//
//#define NUM 5001
//
//using namespace std;
//
//
//int sum[NUM<<4];
//
//void Pushup(int root){
//    sum[root] = sum[L_child(root)] + sum[R_child(root)];
//}
//
//void build(int left,int right,int root){
//    sum[root] = 0;
//    if (left == right){
//        return;
//    }
//
//    int mid = Mid(left,right);
//
//    build(left,mid,L_child(root));
//    build(mid+1,right,R_child(root));
//}
//
//int query(int L_Bound,int R_bound,int left,int right,int root){
//    if (L_Bound<=left && right <= R_bound){
//        return sum[root];
//    }
//
//    int mid = Mid(left,right);
//    int res=0;
//
//    if (L_Bound <= mid){res += query(L_Bound,R_bound,left,mid,L_child(root));}
//    if (R_bound > mid){res += query(L_Bound,R_bound,mid+1,right,R_child(root));}
//    return res;
//}
//
//
//void update(int pos,int left,int right,int root){
//    if (left == right){
//        sum[root]++;
//        return;
//    }
//
//    int mid = Mid(left,right);
//
//    if(pos<=mid){update(pos,left,mid,L_child(root));}
//    else {update(pos,mid+1,right,R_child(root));}
//    Pushup(root);
//}
//
//int main(){
//    int n;
//    int nums[NUM],sum_,res;
//    while(cin>>n){
//        build(0,n-1,1);
//        sum_ =0;
//        for (int i = 0; i < n; ++i) {
//            scanf("%d",&nums[i]);
//            sum_ += query(nums[i],n-1,0,n-1,1);
//            update(nums[i],0,n-1,1);
//        }
//
//        res = sum_;
//        for (int i = 0; i < n; ++i) {
//            sum_ += n- nums[i] - nums[i] -1;
//            res = min(sum_,res);
//        }
//        cout<<res<<endl;
//
//    }
//
//
//}
