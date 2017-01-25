//
// Created by Henry on 16/8/22.
//

#include <cstdio>
#include <memory>

#define NUM 1001


int UFSet[NUM];

int Find(int root){
    if (UFSet[root] <= 0){
        return root;
    } else{
        return UFSet[root] = Find(UFSet[root]);
    }
}

void Merge(int root1,int root2){
    root1 = Find(root1);
    root2 = Find(root2);

    if (root1 == root2) return;

    if (UFSet[root1] < UFSet[root2]){
        //root1比root2阶大
        UFSet[root2] = root1;
    } else{
        if (UFSet[root1] == UFSet[root2]){
            UFSet[root2]--;
        }

        UFSet[root1] = root2;
    }
}

int countTree(int left,int right){
    int count = 0;
    for (int i = left; i <= right; ++i) {
        if (UFSet[i] <= 0){
            count++;
        }
    }
    return count;
}

int main(){
    int cases,n,m;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&m);
        memset(UFSet,0, sizeof(UFSet));

        for (int i = 0; i < m; ++i) {
            int a,b;
            scanf("%d %d",&a,&b);
            Merge(a,b);
        }

        printf("%d\n",countTree(1,n));
    }
}