//
// Created by Henry on 16/12/8.
//

#include <cstdio>

const int m0[] = {3,7,9};
const int m1[] = {2,4,5,8};
const int m3 = 6;

bool shit(int v){
    for (int i = 0; i < 3; ++i) {
        if (v % m0[i] != 0) return false;
    }

    for (int i = 0; i < 4; ++i) {
        if (v % m1[i] != 1) return false;
    }

    return v % m3 == 3;
}

int fuck(int pos){
    return shit(pos) ? pos :fuck(pos+1);
}

int main(){
    printf("%d\n",fuck(1));
}