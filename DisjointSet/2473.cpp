//
// Created by Henry on 16/8/23.
//

#include <cstdio>

#define NUM1 1000000+10
#define NUM2 100000 + 10

int UFSet[NUM1];
int Hash[NUM2];

int Find(int rt){

    if (UFSet[rt] < 0){
        return rt;
    }
    return UFSet[rt] = Find(UFSet[rt]);

}


void Merge(int rt1,int rt2){
    rt1 = Find(rt1);
    rt2 = Find(rt2);

    if (rt1 == rt2) return;

    if (UFSet[rt1] < UFSet[rt2]){
        UFSet[rt1] += UFSet[rt2];
        UFSet[rt2]= rt1;
    } else{
        UFSet[rt2] += UFSet[rt1];
        UFSet[rt1]= rt2;
    }

}



void Init(int size){
    for (int i = 0; i < size; ++i) {
        Hash[i] = i;
        UFSet[i] = -1;
    }
}


int countTree(int size){
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (UFSet[i] <= -1){
            count++;
        }
    }
    return count;
}

int main(){
    int n,m,num1,num2,count = 0;
    char tmp[5];
    while (scanf("%d %d",&n,&m)!=EOF && (m || n)){
        Init(n);

        while (m--) {
            scanf("%s",tmp);
            if (tmp[0] == 'M') {
                scanf("%d %d", &num1, &num2);
                Merge(Hash[num1], Hash[num2]);
            } else {
                scanf("%d", &num1);

                int ancestor = Find(Hash[num1]);
                Hash[num1] = n;
                UFSet[n] = -1;
                UFSet[ancestor] ++;
                n++;

            }
        }

        printf("Case #%d: %d\n",++count,countTree(n));

    }
}