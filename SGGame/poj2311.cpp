//
// Created by Henry on 16/11/8.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <set>
using namespace std;

const int MAXWH = 200;

int Buffer[MAXWH + 1][MAXWH + 1];

int grundy(int w,int h){
    if (~Buffer[w][h]) return Buffer[w][h];

    set<int > s;
    for (int i = 2; w - i >=2 ; ++i) {
        s.insert(grundy(i,h) ^ grundy(w-i,h));
    }

    for (int i = 2; h - i >=2 ; ++i) {
        s.insert(grundy(w,i) ^ grundy(w,h-i));
    }

    int res = 0;
    while (s.count(res))res++;

    return Buffer[w][h] = res;
}


int w,h;
void init(){
   memset(Buffer,-1, sizeof(Buffer));
}
int main(){
    init();
    while (~scanf("%d%d",&w,&h)){

        puts(grundy(w,h) ? "WIN":"LOSE");
    }
}