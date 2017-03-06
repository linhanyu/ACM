//
// Created by Henry on 17/3/5.
//

#include <cstdio>
#include <algorithm>
typedef long long LL;

using namespace std;

const int MOD = 365*24*60*60;
const int MAXN = 100000 + 10;
struct node{
    LL a,b;
    double cost;

    bool operator<(const node & n)const{
        return cost > n.cost;
    }

}s[MAXN];

void calCost(node & n,LL tot){
    n.cost = n.b*1.0/n.a;
}
int main(){
    int n;
    while (~scanf("%d",&n) && n){
        LL tot = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d",&s[i].a,&s[i].b);
            tot += s[i].b;
        }

        for (int i = 0; i < n; ++i) {
            calCost(s[i],tot);
        }

        sort(s,s + n);
        LL ans = 0,tadd = 0;
        for (int i = 0; i < n; ++i) {
            tot -= s[i].b;

            ans = (ans + s[i].b*ans + s[i].a)%MOD;
        }

        printf("%lld\n",ans);
    }
}