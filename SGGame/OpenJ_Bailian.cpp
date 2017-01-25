//
// Created by Henry on 16/11/8.
//

//NIM

#include <cstdio>
#include <algorithm>

const int MAXN = 10000 + 10;

using namespace std;

int n,p[MAXN];
int main(){
    int pre,cur,t,n,ans;
    scanf("%d",&t);
    while (t--){
        ans = 0;

        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            scanf("%d",&p[i]);
        }
        if (n&1) p[n++] = 0;

        sort(p,p+n);

        for (int i = 0; i+1 < n; i+= 2) {
            ans ^= p[i+1] - p[i] - 1;
        }

        puts(ans ? "Georgia will win" : "Bob will win");
    }
}