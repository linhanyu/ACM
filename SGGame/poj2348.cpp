//
// Created by Henry on 16/11/8.
//
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int a,b;
    while (~scanf("%d%d",&a,&b) && (a||b)){
        bool f = true;
        while (true){
            if (a>b) swap(a,b);
            //a<b

            if (b % a == 0 || (b-a > a)) break;

            b -= a;
            f = !f;
        }

        puts( f ? "Stan wins" : "Ollie wins");
    }
}
