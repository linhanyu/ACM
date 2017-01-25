//
// Created by Henry on 16/12/11.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>

#define lowbit(x) (x&(-x))

using namespace std;

const int Hoffset = 60*60;
const int Moffset = 60;
const int MAXN = 24 * Hoffset ;

struct per{
    int id,t;
    per(){}

    per(int id,int t):id(id),t(t){}
};


vector<per > p,ans;

void init(){
    p.clear();
    ans.clear();
}

struct cmp1{
    bool operator()(const per & p1,const per & p2) const{
        return p1.t < p2.t;
    }
};

struct cmp2{
    bool operator()(const per & p1,const per & p2) const{
        return p1.id < p2.id;
    }
};



int main(){
    int t;
    scanf("%d",&t);

    while (t--){
        init();

        int n,l;
        scanf("%d%d",&n,&l);
        for (int i = 1; i <= n; ++i) {
            int h,m,s;
            scanf("%d:%d:%d",&h,&m,&s);

            p.push_back(per(i,h * Hoffset + m * Moffset + s));
        }

        sort(p.begin(),p.end(),cmp1());

        int anchor = 0;
        ans.push_back(p[0]);
        for (int i = 1; i < p.size(); ++i) {
            if (p[i].t - p[anchor].t >= l ){
                anchor = i;
                ans.push_back(p[i]);
            }
        }

        sort(ans.begin(),ans.end(),cmp2());

        printf("%d\n",ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            printf("%d%c",ans[i],i != ans.size()-1 ? ' ' : '\n');
        }
    }
}