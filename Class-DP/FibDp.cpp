//
// Created by Henry on 16/8/20.
//

#include <cstdio>
#include <iostream>
#define NUM 10


using namespace std;

typedef long long Long;

Long memory[NUM];

void init(int n){
    memory[1] = 0;
    memory[2] = 1;

    for (int i = 3; i <= n ; ++i) {
        memory[i] = memory[i-1] + memory[i-2];
    }
}

Long Fib(int n){
    return memory[n];
}

int main(){
    init(NUM);
    for (int i = 1; i <= NUM; ++i) {
        cout<<Fib(i)<<" "<<endl;
    }
}