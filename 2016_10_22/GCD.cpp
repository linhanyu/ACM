//
// Created by Henry on 16/10/18.
//

#include <cstdio>
#include <algorithm>

using namespace std;

//int GCD(int a,int b){ return b ? GCD(b,a%b) : a; }

//int GCD(int a,int b){
//    if (b == 0) return a;
//
//    return GCD(b,a%b);
//}

//int GCD(int a,int b){
//    int c;
//    if (a < b) swap(a,b);
//
//    while (b){
//        c = a%b;
//        a = b;
//        b = c;
//    }
//
//    return a;
//}

int GCD(int a,int b){
    int c;
    if (a < b){
        c = a;
        a = b;
        b = c;
    }

    while (b!=0){
        c = a%b;
        a = b;
        b = c;
    }

    return a;
}

int main(){
    int a,b;

    while(scanf("%d %d",&a,&b)){
        //    if (a < b) swap(a,b);
        printf("%d\n",GCD(a,b));
//        printf("%s\n",su[tmp] ? "YES":"NO");
    }

}