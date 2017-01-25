//
// Created by Henry on 16/7/9.
//

//#include <cstdio>
//#include <algorithm>
//
//#define L_child(a) (a<<1)
//#define R_child(a) ((a<<1)|1)
//#define Mid(a,b) ((a+b)>>1)
//#define NUM 222222
//
//using namespace std;
//
//int Max[NUM << 2];
//int w,x;
//
//void Push_Up(int rt){
//    Max[rt] = max(Max[L_child(rt)] ,Max[R_child(rt)]);
//}
//
//void build(int l,int r,int rt){
//    Max[rt] = w;
//    if (l == r){
//        return;
//    }
//
//    int mid = Mid(l,r);
//
//    build(l,mid,L_child(rt));
//    build(mid+1,r,R_child(rt));
//}
//
//int query(int rt,int left,int right){
//    if (left == right){
//        Max[rt] -= x;
//        return left;
//    }
//
//    int mid = Mid(left,right);
//    int ret;
//    if (Max[L_child(rt)] >= x){
//        ret = query(L_child(rt),left,mid);
//    } else{
//        ret = query(R_child(rt),mid+1,right);
//    }
//
//    Push_Up(rt);
//
//    return ret;
//}
//
//int main(){
//    int h,n;
//    while (scanf("%d %d %d",&h,&w,&n)!=EOF){
//        if (h > n) h = n;
//        build(1,h,1);
//        while(n--) {
//            scanf("%d", &x);
//            if (x > Max[1]) {
//                printf("-1\n");
//            } else {
//               printf("%d\n", query(1, 1, h));
//            }
//        }
//    }
//}