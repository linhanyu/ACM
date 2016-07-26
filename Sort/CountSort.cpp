//
// Created by Henry on 16/6/30.
//

#include <memory>
#include <iostream>


#define NUM 10

using namespace std;

class count_sort {
    int * helper_ar;
    int helper_ar_size;
    int * tmp_ar;
    int tmp_size;

public:
    count_sort(){
        new(this)count_sort(1,1);
    }

    count_sort(int size_tmp,int size_helper){
        helper_ar = new int[size_helper];
        tmp_ar = new int[size_tmp];
        helper_ar_size = size_helper;
        tmp_size = size_tmp;
    }


    void Count_Sort(int a[], int size, int low_bound, int upper_bound);

    ~count_sort(){
        delete [] helper_ar;
    }
};

void count_sort::Count_Sort(int *a, int size, int low_bound, int upper_bound) {
    int range = upper_bound - low_bound + 1;

    //变长数组
    if (size > tmp_size){
        delete [] tmp_ar;
        tmp_size = size;
        tmp_ar = new int[size];
    }


    if(range > helper_ar_size){
        delete [] helper_ar;
        helper_ar_size = range;
        helper_ar = new int[helper_ar_size];
    }

    memset(helper_ar,0, sizeof(int) * range);//暴力初始

    for (int i = 0; i < size;helper_ar[a[i++]-low_bound]++);//魔幻计数
    for (int i = 0; i < range;helper_ar[++i] += helper_ar[i]);//奇妙dp

    for (int i = size-1; i >= 0 ;i--) {
        tmp_ar[--helper_ar[a[i]-low_bound]] = a[i];
    }

    memcpy(a,tmp_ar, sizeof(int) * size);//撸回去


}

void prt_ar(int ar[],int size){
    for (int i = 0; i < size; ++i) {
        cout<<"\t"<<ar[i];
    }
    cout<<endl;

}

//int main(){
//    count_sort c ;
//    int a[NUM];
//    for (int i = 0; i < NUM; ++i) {
//        a[i] = i%3 +1;
//    }
//    c.Count_Sort(a,NUM,0,4);
//    prt_ar(a,NUM);
//}