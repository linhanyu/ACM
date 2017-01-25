//
// Created by Henry on 16/9/4.
//
#include <cstdio>
#include <iostream>

#define MAXN 200

using namespace std;
int Buffer[MAXN];
int lower,higher;

bool flag = false;
void build(int pos){
    int n;
    cin>>n;
    if (n == -1) return ;

    flag = false;
    lower = min(lower,pos);
    higher = max(higher,pos);


    build(pos-1);
    build(pos+1);

    Buffer[pos] += n;

}

int main(){
    int cases = 0;
    while(true){
        flag = true;
        lower = MAXN;
        higher = -1;

        for (int i = 0; i < MAXN; ++i) {
            Buffer[i] = 0;
        }

        build(MAXN>>1);
        if (flag) break;
        ++cases;
        printf("Case %d:\n",cases);
        for (int i = lower; i < higher ; ++i) {
            printf("%d ",Buffer[i]);
        }
        printf("%d\n\n",Buffer[higher]);
    }
}
