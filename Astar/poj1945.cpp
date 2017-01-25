//
// Created by Henry on 16/10/27.
//

#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

int dst;
struct Anode{
    int c1,c2,d;

    bool operator<(const Anode & a)const {
        return d > a.d;
    }

};
//int dis[20000];

int AstarBFS(int c1,int c2){

    Anode a;

    priority_queue<Anode > Q;

    a.c1 = c1;
    a.c2 = c2;
    a.d = 0;
    Q.push(a);

    while (!Q.empty()){
        a = Q.top();
        Q.pop();

        

    }
}