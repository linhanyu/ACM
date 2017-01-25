//
// Created by Henry on 16/8/20.
//

#include <cstdio>
#include <iostream>
#define NUM 50


using namespace std;

typedef long long Long;

Long memory[NUM];

Long Fib(int n){
    if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }

    if (memory[n]){
        return memory[n];
    }
    return memory[n] = (Fib(n-1) + Fib(n-2));
}

int main(){
    memset(memory,0, sizeof(memory));
    for (int i = 1; i <= NUM; ++i) {
        cout<<Fib(i)<<" "<<endl;
    }
}