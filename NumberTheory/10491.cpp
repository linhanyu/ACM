//
// Created by Henry on 16/10/31.
//

#include <cstdio>

int main(){
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c)){
        printf("%.5lf\n",(double)(b*b-b+a*b)/(a+b)/(a+b-c-1));

    }
}