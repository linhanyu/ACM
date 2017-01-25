//
// Created by Henry on 16/11/8.
//

#include <cstdio>

using namespace std;

int main(){
    int n;
    while (~scanf("%d",&n) && n){
        puts(n > 2 ? "Bob":"Alice");
    }
}