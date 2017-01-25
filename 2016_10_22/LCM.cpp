//
// Created by Henry on 16/10/18.
//

#include <cstdio>
#include <algorithm>

using namespace std;


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
//
//int LCM(int a,int b){
//    return a / GCD(a,b) * b;
//}
int MAX(int a,int b){
    if (a < b) return b;
    return a;
}



int LCM(int a,int b){
    int lcm = MAX(a,b);
    for (; ; lcm++) {
        if (lcm % a == 0 && lcm % b == 0){
            return lcm;
        }
    }
}
int main(){
    int a,b;

    while(scanf("%d %d",&a,&b)){
        //    if (a < b) swap(a,b);
        printf("%d\n",LCM(a,b));
//        printf("%s\n",su[tmp] ? "YES":"NO");
    }

}