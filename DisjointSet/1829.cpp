//
// Created by Henry on 16/8/22.
//

#include <cstdio>
#include <memory>
#define NUM 2001

int UFSet[NUM],rank[NUM];
bool collary;

int Find(int rt){
    if (UFSet[rt] == 0){
        return rt;
    }

    int Father = Find(UFSet[rt]);
    rank[rt]  = (rank[rt] + rank[UFSet[rt]]) & 1;
    return UFSet[rt] = Father;
}

void Merge(int rt1,int rt2){
    int r1 = Find(rt1);
    int r2 = Find(rt2);

    if (r1 == r2) {
        if (rank[rt1] == rank[rt2]){
            collary = true;
        }
        return;
    }

    UFSet[r1] = r2;
    rank[r1] = (rank[rt1] + rank[rt2] + 1) & 1;
}

int countTree(int left,int right){
    int count = 0;
    for (int i = 1; i <= right; ++i) {
        if (UFSet[i] <= 0){
            count++;

        }
    }
    return count;
}
int main(){
    int cases,n,m;
    scanf("%d",&cases);
    for (int i = 1; i <= cases; ++i) {
        collary = false;
        memset(UFSet,0, sizeof(UFSet));
        memset(rank,0, sizeof(rank));
        printf("Scenario #%d:\n",i);

        scanf("%d %d",&n,&m);

        while(m--){
            int a,b;
            scanf("%d %d",&a,&b);
            if (!collary) Merge(a,b);
        }

        if (collary){
            printf("Suspicious bugs found!\n");
        } else{
            printf("No suspicious bugs found!\n");


        }

        puts("");
    }
}