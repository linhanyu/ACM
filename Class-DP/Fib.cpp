//
// Created by Henry on 16/8/20.
//

#include <cstdio>
#include <iostream>
#define NUM 50


using namespace std;

typedef long long Long;

Long Fib(int n){
    if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }
    return Fib(n-1) + Fib(n-2);
}

int main(){
    for (int i = 1; i <= NUM; ++i) {
        cout<<Fib(i)<<" "<<endl;
    }
}