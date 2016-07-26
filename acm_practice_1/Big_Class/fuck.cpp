//
// Created by Henry on 16/7/7.
//
#include <cstdio>

#define NUM 10
//或者 const int 10
void insert_sort(int a[],int size){
    for (int j,i = 1; i < size; ++i) {
        int tmp = a[i];
        for (j = i; j >0 && a[j-1] > tmp ; --j) {
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}

void prt_ar(int a[],int size){

    for (int i = 0; i < size; ++i) {
        printf("%d",a[i]);
    }
}

int main(){
    int a[NUM],b[NUM],c[NUM];

    for (int i = 0; i < 10; ++i) {
        a[i] = i%3;
    }

    insert_sort(a,NUM);
    prt_ar(a,NUM);
}