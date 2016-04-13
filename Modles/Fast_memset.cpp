//
// Created by Henry on 16/4/13.
//
#include <memory>
#include <iostream>
#include <ctime>

using namespace std;

#define NUM 1200

template <class T>
void fast_memset(T * array,int size,T val){
    int i=1;
    array[0] = val;
    while((i<<1)<size){

        memcpy(array+i,array,sizeof(T)*i);
        i<<=1;
    }

    memcpy(array+i,array ,sizeof(T)*(size-i));
}

int main(){
    int sperm[NUM][NUM];
    clock_t  start = clock();
    fast_memset(&sperm[0][0],NUM*NUM,20);
//    for (int i = 0; i < NUM; ++i) {
//        sperm[0][i];
//    }
//
//    for (int i = 1 ; i < NUM; ++i) {
//        memcpy(sperm[i],sperm[0], sizeof(sperm[0]));
//    }
    cout<<(clock() - start) << endl;
}