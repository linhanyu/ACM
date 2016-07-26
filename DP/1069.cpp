//
// Created by Henry on 16/7/19.
//
#include <cstdio>
#include <memory>
#include <algorithm>

#define NUM 300
#define NEG -1

using namespace std;

struct Block{
    int x,y,z;

    bool operator<(const Block & bk) const {
        return x > bk.x;
    }

    void set_point(int x,int y,int z)
    {
        if(x>y) swap(x,y);
        this->x=x;
        this->y=y;
        this->z=z;
    }
};


int main(){
    int n,count,ans,cases = 1;
    Block blocks[NUM];
    int dp[NUM];
    int ord[3];

    while (scanf("%d",&n)!=EOF && n){

        count = 0;
        while(n--){
            scanf("%d %d %d",&ord[0],&ord[1],&ord[2]);
            for (int i = 0; i < 3; ++i) {
                blocks[count].set_point(ord[i],ord[(i+1)%3],ord[(i+2)%3]);
                count++;
            }
        }
        sort(blocks,blocks + count);
        //通过x排序,降维
        dp[0] = 0;
        ans = 0;

        for (int i = 0; i < count; ++i) {
            int mmax = 0;
            for (int j = 0; j < i; ++j) {
                if (blocks[i].y < blocks[j].y && blocks[i].x < blocks[j].x){
                    mmax = max(mmax,dp[j]);
                }
            }
            dp[i] = mmax + blocks[i].z;
            ans = max(dp[i],ans);
        }

        printf("Case %d: maximum height = %d\n",cases++,ans);

    }
}
