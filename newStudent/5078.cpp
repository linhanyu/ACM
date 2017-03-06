//
// Created by Henry on 17/3/5.
//

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double INF = 1e10;
const int MAXN = 1024;
struct node {
    double x;
    double y;
    int t;

    bool operator<(const node &n2) const{
        return t < n2.t;
    }
}s[MAXN];

double cal(node & n1,node & n2){
    return sqrt(pow(n2.x-n1.x,2) + pow(n2.y-n1.y,2))/(n2.t - n1.t);
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int n;
        scanf("%d",&n);
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%lf%lf",&s[i].t,&s[i].x,&s[i].y);
        }
        sort(s,s+n);
        for (int i = 1; i < n; ++i) {
            ans = max(ans,cal(s[i-1],s[i]));
        }

        printf("%.10lf\n",ans);
    }
}