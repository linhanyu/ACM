//
// Created by Henry on 16/7/1.
//
#include <algorithm>
#include <iostream>


#define CUTOFF 9
#define NUM 50
using namespace std;

template <class T>
void insert_sort(T ar[],int size){
    //升序
    for (int i = 1,j; i < size; ++i) {
        T tmp = ar[i];
        for (j = i ; j > 0 && tmp < ar[j-1] ; j--)
            ar[j] = ar[j-1];
        ar[j] = tmp;
    }

}

template <class T>
T median_3(T ar[], int left,int right){
    int mid = (left+right)>>1;

    if(ar[left] > ar[mid]){
        swap(ar[left],ar[mid]);
    }

    if(ar[mid] > ar[right]){
        swap(ar[right],ar[mid]);
    }

    if(ar[left] > ar[mid]){
        swap(ar[left],ar[mid]);
    }

    swap(ar[mid],ar[--right]);
    return ar[right];

}

template <class T>
void fast_select(T ar[], int left,int right,int k){
    //第k小
    if (right-left>CUTOFF){
        int pivot = median_3(ar,left,right);
        int i=left,j=right-1;
        for (;;) {
            while(ar[++i] <pivot);
            while(ar[--j] >pivot);
            if (i<j){
                swap(ar[i],ar[j]);
            } else{
                break;

            }
        }

        swap(ar[right-1],ar[i]);
        if (k<i){
            fast_select(ar,left,i-1,k);
        } else if (k>i){
            fast_select(ar,i+1,right,k);
        }

    } else{
        insert_sort(ar+left,right-left+1);
    }

}

void prt_ar(int ar[],int size){
    for (int i = 0; i < size; ++i) {
        cout<<"\t"<<ar[i];
    }
    cout<<endl;

}

int main(){
    int a[NUM];


    for (int j = 0; j < NUM; ++j) {
        for (int i = 0; i < NUM; ++i) {

            a[i] = i%10;
        }
        fast_select(a,0,NUM-1,j);
        //第a[k-1]就是所求(第k小)
        cout<<a[j]<<endl;
    }


    return 0;
}