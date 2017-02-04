//
// Created by Henry on 17/1/29.
//

#include<cstdio>
#include <cstdlib>
#include <algorithm>


using namespace std;

#define lowbit(x) (x&-x)

const int INF = 0x3f3f3f3f;

int num[100000 + 10];

int h_dis(int x,int y){
    int ans = 0;
    x ^= y;
    while (x){
        ans++;
        x -= lowbit(x);
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int n;
        scanf("%d",&n);

        for (int i = 0; i < n; ++i) {
            scanf("%X",&num[i]);
        }

        int ans = INF;
        for (int i = 0; i < 100000; ++i) {
            int x = rand()%n,y = rand()%n;
            while (x == y) y = rand()%n;
            ans = min(ans,h_dis(num[x],num[y]));

        }

        printf("%d\n",ans);
    }

}