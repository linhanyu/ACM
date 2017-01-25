//
// Created by Henry on 16/11/22.
//
#include <cstdio>
#include <algorithm>

typedef long long LL;

using namespace std;

const int MAXN = 1e5 +10;

int A[MAXN],B[MAXN];
int n;

int BinarySearch_lower(int A[],int key,int left,int right){
    while (left <= right){
        int mid  = (left+right)>>1;
        if (key <= A[mid]) right = mid-1;
        else left = mid+1;
    }
//
//    return left;
//
//    for (int i = 0; i < n; ++i)
//    {
//        int l = i + 1, r = n;
//        while (l < r) //如果找到了某个值可以进位，那么b[i]和它之后的肯定也能进位
//        {
//            int mid = (l + r) / 2;
//            if (B[mid] >= k - B[i])
//                r = mid;
//            else l = mid + 1;
//        }
//        ans += n - l;
//    }
//
//    while (left < right) //如果找到了某个值可以进位，那么b[i]和它之后的肯定也能进位
//    {
//        int mid = (right + left) / 2;
//        if (A[mid] >= key)
//            right = mid;
//        else left = mid + 1;
//    }
    return left;

}

int main(){
    while(~scanf("%d",&n)){
        for (int i = 0; i < n; ++i) {
            scanf("%d",&A[i]);
        }

        int k = 1;
        LL ans = 0;

        for (int i = 0; i < 9; ++i) {
            k *= 10;
            for (int j = 0; j < n; ++j) {
                B[j] = A[j]%k;
            }

            sort(B,B+n);

            for (int j = 0; j < n-1; ++j) {

                //tar  >= k - B[j]
                ans += n - BinarySearch_lower(B,k - B[j],j+1,n-1);

            }
        }

        printf("%lld\n",ans);

    }
}
