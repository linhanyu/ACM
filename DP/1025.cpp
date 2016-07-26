//
// Created by Henry on 16/7/16.
//
#include <cstdio>
#include <algorithm>

#define NUM 500005
#define MID(a,b) ((a+b)>>1)


using namespace std;

//int rls[NUM][NUM];
int dp[NUM],helper[NUM];
//
//int count_num(int i_begin,int j_begin){
//    if (i_begin>n || j_begin >n){
//        return 0;
//    }
//    int Max = 0;
//    for (int i = i_begin; i <= n ; ++i) {
//            if (dis[i] > j_begin){
//                if(rls[i][dis[i]]){
//                    Max = max(Max,rls[i][dis[i]]);
//                } else{
//                    Max = max(Max,rls[i][dis[i]] = count_num(i,dis[i]));
//                }
//            }
//    }
//    return Max + 1;
//}

int Binary_Search(int A[],int len,int key){
    int mid,left = 1,right = len;
    while(left <= right){
        mid = MID(left,right);
        if (key < A[mid]){
            right = mid-1;
        } else if(key > A[mid]){
            left = mid+1;
        } else{
            break;
        }
    }
    return left;
}

int main(){
    int count = 1,n;
//    printf("%d",n);
    while(scanf("%d",&n)!=EOF){
        for (int i = 0; i < n; ++i) {
            int tmp;
            scanf("%d", &tmp);
            scanf("%d", &dp[tmp]);
        }

        int len = 1,sub;
        helper[1] = dp[1];
        for (int i = 2; i <= n; ++i) {
            sub = Binary_Search(helper,len,dp[i]);
            helper[sub] = dp[i];
            if (sub > len){
                len++;
            }
        }
        if (len == 1){
            printf("Case %d:\nMy king, at most 1 road can be built.\n\n",count++);
        } else{
            printf("Case %d:\nMy king, at most %d roads can be built.\n\n",count++,len);
        }

    }
}