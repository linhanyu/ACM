//
// Created by Henry on 16/6/5.
//
//
//#include <cstdio>
//#include <algorithm>
//#include <cstdlib>
//#include <cmath>
//
//#define NUM 100001
//#define SQUARE(x) ((x)*(x))
//#define INF 1e20
//using namespace std;
//
//struct ordinary{
//    double x;
//    double y;
//
//
//    double dis(ordinary & b){
//        return sqrt(SQUARE(x-b.x) + SQUARE(y-b.y));
//    }
//
//    bool operator>(ordinary & b){
//        return x > b.x;
//    }
//
//}ord[NUM];
//ordinary temp_ar[NUM];
//
//int cmp(const void * a,const void * b){
//    return (*(ordinary*)a).x > (*(ordinary*)b).x;
//}
//
//bool cmp_up(ordinary & a,ordinary & b){
//    return a.y < b.y;
//}
//double shortest_path(int left,int right){
////
////        double d=INF;
////        int mid=(left+right)/2;
////        int i,j,num=0;
////        if(left==right) return d;
////        if(right-left==1)// 只有两个点
////            return dis(hehe[left],hehe[right]);
////        double dl=lala(left,mid);//左边的点所有距离
////        double dr=lala(mid+1,right);//右边的所有距离
////        d=min(dl,dr);
////        for(i=left;i<right;i++)
////        {
////            if(fabs(hehe[mid].x-hehe[i].x)<=d)//从左边到右边，看有没有点到中线距离小于d，符合就有可能最短距离的点在中线各一侧
////                QWQ[num++]=hehe[i];
////        }
////        sort(QWQ,QWQ+num,cmdy);
////        for(i=0;i<num;i++)
////        {
////            for(j=i+1;j<num&&QWQ[j].y-QWQ[i].y<d;j++)
////            {
////                d=min(d,dis(QWQ[i],QWQ[j]));
////            }
////        }
////        return d;
//    if (right == left){
//        return INF;
//    }
//
//    if (right - left ==1){
//        return ord[left].dis(ord[right]);
//    }
//
//    int mid = (left+right)>>1;
//
//    double dis = min(shortest_path(left,mid),shortest_path(mid+1,right));
//
//    int curve = 0;
//    for (int i = left ; i <= right; ++i) {
//        if (fabs(ord[i].x - ord[mid].x) <= dis){
//            temp_ar[curve++] = ord[i];
//        }
//    }
//
//    sort(temp_ar,&temp_ar[curve],cmp_up);
//    for (int i = 0; i < curve; ++i) {
//        for (int j = i+1; j < curve; ++j) {
//            dis = min(temp_ar[i].dis(temp_ar[j]),dis);
//        }
//    }
////    for (int i = mid; i >= 0; --i) {
////        for (int j = mid+1; j <= right; ++j) {
////            dis = min(dis,ord[i].dis(ord[j]));
////        }
////    }
//
//    return dis;
//}
//
////template <class T>
////void M_Sort(T A[],T temp[],int left,int right,int right_end) {
////    int left_end = right-1;
////    int begin_pos = left;
////    int size = right_end - left +1;
////    int tmp_pos = left;
////
////    while (left<=left_end && right<=right_end) {
////        if (A[left] < A[right]) {
////            temp[tmp_pos++] = A[left++];
////        }else{
////            temp[tmp_pos++] = A[right++];
////        }
////    }
////
////    if (left<=left_end) {
////        memcpy(temp+tmp_pos, A+left, (left_end-left+1)*sizeof(T));
////    }
////
////    if (right<=right_end) {
////        memcpy(temp + tmp_pos, A+right, (right_end-right+1)*sizeof(T));
////    }
////
////    memcpy(A+begin_pos,temp+begin_pos, size*sizeof(T));
////}
//
//template <class T>
//void Merge(T ar[],int left,int mid,int right){
//    int left_curve = left;
//    int right_curve = mid+1;
//    int len = right-left+1;
//    int i;
//    for (i = 0; left_curve<=mid&& right_curve <= right; ++i) {
//        if (ar[left_curve] > ar[right_curve]){
//            temp_ar[i] = ar[right_curve++];
//        } else{
//            temp_ar[i] = ar[left_curve++];
//        }
//    }
//
//    if (left_curve <= mid){
//        memcpy(temp_ar+i,ar+left_curve, sizeof(T) * (mid-left_curve+1));
//    }
//
//    if (right_curve <= right){
//        memcpy(temp_ar+i,ar+right_curve, sizeof(T) * (right-right_curve+1));
//    }
//
//    memcpy(ar+left,temp_ar, sizeof(T) * len);
//}
//
//template <class T>
//void M_Sort(T ar[],int left,int right){
//    if (right - left <= 1){
//        if(ar[left] > ar[right])swap(ar[left],ar[right]);
//        return;
//    }
//
//    int mid = (right+left)>>1;
//
//    M_Sort(ar,0,mid);
//    M_Sort(ar,mid+1,right);
//    Merge(ar,left,mid,right);
//}
//
//
//template <class T>
//void MergeSort(T ar[],int size){
//    M_Sort(ar,0,size-1);
//}
//
//
//
//int main(){
//    int n;
//    while (scanf("%d",&n)!= EOF && n){
//        for (int i = 0; i < n; ++i) {
//            scanf("%lf%lf",&ord[i].x,&ord[i].y);
//        }
//        MergeSort(ord,n);
////        qsort(ord,n, sizeof(ordinary),cmp);
//
//        printf("%.2lf\n",shortest_path(0,n-1)/2);
//
//    }
//
//}

