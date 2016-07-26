//
// Created by Henry on 16/7/21.
//

#include <cstdio>
#include <memory>
#include <algorithm>

using namespace std;

#define MAXN 1001
#define MID(a,b) ((a+b)>>1)
//int Binary_Search(int A[],int left,int right,int key){
//    //最大子列版二分搜索
//    while(left <= right){
//        int mid = MID(left,right);
//        if (key > A[mid]){
//            left = mid + 1;
//        } else if(key < A[mid]){
//            right = mid - 1;
//        } else{
//            break;
//        }
//    }
//    return left;
//}

int main(){
    int n,tmp,Max;
    int A[MAXN],dp[MAXN];
    while(scanf("%d",&n)!=EOF && n ){
        memset(dp,0,(n+1)* sizeof(int));
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&A[i]);
        }
        A[0] = 0;
        Max = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i ; ++j) {
                if (A[i] > A[j] && dp[i] < A[i]+dp[j]){
                    dp[i] = A[i] + dp[j];
                    Max = max(Max,dp[i]);
                }
            }
        }

        printf("%d\n",Max);
    }
}