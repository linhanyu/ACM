//
// Created by Henry on 16/8/23.
//

#include <cstdio>
#include <memory>
#include <algorithm>
#include <map>

#define NUM 10000002

using namespace std;

int UFSet[NUM];

int Find(int rt){
    if (UFSet[rt] <= 0){
        return rt;
    } else{
        return UFSet[rt] = Find(UFSet[rt]);
    }
}
int counter;
void Merge(int rt1,int rt2){
    rt1 = Find(rt1);
    rt2 = Find(rt2);

    if (rt1 == rt2) return;

    if (UFSet[rt1] < UFSet[rt2]){

        UFSet[rt1] += UFSet[rt2];
        UFSet[rt2] = rt1;
        counter = min(counter,UFSet[rt1]);
    } else{

        UFSet[rt2] += UFSet[rt1];
        UFSet[rt1] = rt2;
        counter = min(counter,UFSet[rt2]);
    }

}

int countNode(int left,int right){
    int Max=0;
    map<int,int> counter;
    for (int i = left; i <= right ; ++i) {
        if (++counter[Find(i)] > Max){
            Max = counter[Find(i)];
        }
    }
    return Max;
}

int main(){
    int n,Min,Max;
    memset(UFSet,-1, sizeof(UFSet));

    while(scanf("%d",&n)!=EOF){
        if (n == 0) {
            puts("1");
            continue;
        }

        Min = NUM;
        Max = -1;
        counter = 0;

        for (int i = 0; i < n; ++i) {
            int a,b;
            scanf("%d %d",&a,&b);

            if(a > b) swap(a,b);
            //a<b
            Max = max(b,Max);
            Min = min(a,Min);
            Merge(a,b);
        }

        printf("%d\n",-counter);



        memset(UFSet+Min,-1,(Max - Min + 1) * sizeof(int));
    }
}