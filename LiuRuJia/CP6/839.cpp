//
// Created by Henry on 16/9/3.
//

#include <iostream>
#include <cstdio>
using namespace std;

bool solve(int & W){
    int W1,D1,W2,D2;
    cin>>W1>>D1>>W2>>D2;
    bool b1= true,b2= true;

    if (W1 == 0) b1 = solve(W1);
    if (W2 == 0) b2 = solve(W2);
    W = W1+W2;

    return b1 && b2 && (D1*W1==D2*W2);
}

int main(){
    int cases;
    cin>>cases;
    while (cases--){
        int n;
        if (solve(n)) puts("YES");
        else puts("NO");

        if (cases) puts("");
    }
}