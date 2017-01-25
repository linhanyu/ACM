//
// Created by Henry on 16/8/22.
//
#include <cstdio>
#include <memory>
#include <algorithm>

#define NUM 100001

using namespace std;

bool Appear[NUM];
int UFSet[NUM];

int Find(int root){
    if (UFSet[root] <= 0){
        return root;
    } else{
        return UFSet[root] = Find(UFSet[root]);
    }
}

bool Merge(int rt1,int rt2){
    rt1 = Find(rt1);
    rt2 = Find(rt2);
    if (rt1 == rt2) return true;

    if (UFSet[rt1] < UFSet[rt2]){
        UFSet[rt2] = rt1;
    } else{
        if (UFSet[rt1] == UFSet[rt2]){
            UFSet[rt2]--;
        }
        UFSet[rt1] = rt2;
    }

    return false;
}

int countTree(int left,int right){
    int count = 0;
    for (int i = left; i <= right; ++i) {
        if (Appear[i] && UFSet[i] <= 0){
            count ++;
        }
    }
    return count;
}

int main(){
    int a,b,n=0,m=0,Min=NUM,Max=-1;
    bool flag = true;
    while(scanf("%d %d",&a,&b)!=EOF && a!=-1 && b!=-1){
        memset(Appear,0, sizeof(Appear));
        memset(UFSet,0, sizeof(UFSet));

        if(a==0 && b==0 ) {
            puts("Yes");
            continue;
        }


        if (!Appear[a]){
            n++;
            Appear[a] = true;
        }

        if (!Appear[b]){
            n++;
            Appear[b] = true;
        }
        m++;

        Min=min(min(Min,a),b);
        Max=max(max(Max,a),b);
        if (Merge(a,b)) flag = false;

        while(scanf("%d %d",&a,&b)!=EOF && (a || b)){
            if (!Appear[a]){
                n++;
                Appear[a] = true;
            }

            if (!Appear[b]){
                n++;
                Appear[b] = true;
            }
            m++;

            Min=min(min(Min,a),b);
            Max=max(max(Max,a),b);
            if (Merge(a,b)) flag = false;
        }

        if (flag && countTree(Min,Max) == 1){
            puts("Yes");
        } else{
            puts("No");
        }

        n=m=0;
        Min=NUM,Max=-1;
        flag = true;
    }
}