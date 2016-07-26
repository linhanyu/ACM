//
// Created by Henry on 16/7/1.
//
#include <algorithm>
#include <iostream>
#define NUM 10

using namespace std;

template <class T>
void fast_min_max(T & Min,T & Max,T ar[],int size){
    int i;

    if(size & 1){
        Min = Max = ar[0];
        i=2;
    } else {
        Max = ar[ar[1] > ar[0]];
        Min = ar[ar[1] < ar[0]];
        i=3;
    }

    for (; i < size; i+=2) {
        if (ar[i] < ar[i-1]){
            Max = max(ar[i-1],Max);
            Min = min(ar[i],Min);
        } else{
            Max = max(ar[i],Max);
            Min = min(ar[i-1],Min);
        }
    }
}

int main(){
    int ar[NUM];
    for (int i = NUM-1; i >= 0; --i) {
        ar[i] = i%5+1;
    }
    int max,min;
    fast_min_max(min,max,ar,NUM);
    cout<<min<<"\t"<<max<<endl;
}