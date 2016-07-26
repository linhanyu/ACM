//
// Created by Henry on 16/7/1.
//
//查询[a,b]的整数有几个
#include <memory>
#include <iostream>
#define NUM 10

using namespace std;

int large_ar[NUM+1];
//int small_ar[NUM];//quick and dirty

void build_ar(int ar[],int size){

    memset(large_ar,0, sizeof(large_ar));

    for (int i = 0; i < size; large_ar[ar[i++]+1]++);

//    memcpy(small_ar,large_ar, sizeof(large_ar));
    for (int i = 1; i <= NUM; large_ar[++i]+=large_ar[i]);
//    for (int i = NUM; i >= 0; small_ar[--i]+=small_ar[i]);

}

int query(int a,int b){
    return large_ar[b+1] - large_ar[a];
}
int main(){
    int a[NUM];
    for (int i = 0; i < NUM; ++i) {
        a[i] = i%3 ;
    }
    build_ar(a,NUM);

    cout<<query(0,2)<<endl;

    cout<<query(0,1)<<endl;

    cout<<query(1,2)<<endl;

    cout<<query(0,1)<<endl;

    cout<<query(0,0)<<endl;
}