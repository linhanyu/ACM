//
// Created by Henry on 16/8/18.
//

//BinaryTree of Array implement

#include <memory>
const int SIZE = 2048;

typedef int Data;

Data Buffer[SIZE];
//Data需定义<运算符
int LChild(int rt){
    return rt<<1;
}

int RChild(int rt){
    return rt<<1|1;
}


void init(){
    memset(Buffer,0, sizeof(Buffer));
    //默认未被分配的Node数值为0.data不能为0
    //若为node型数据,定义STATE来表示分配状态
//    for (int i = 0; i < SIZE; ++i) {
//        Buffer[i].STATE = EMPTY;
//    }
}

void Insert(Data data,int rt){
    if (Buffer[rt] && data != Buffer[rt]){
        //有值
        Insert(data,data < Buffer[rt] ? LChild(rt) : RChild(rt));
        return;
    }

    Buffer[rt] = data;
    return;
}

void PrintTree(int rt){
    if (Buffer[rt]){
        printf("%d\n",Buffer[rt]);
        PrintTree(LChild(rt));
        PrintTree(RChild(rt));
    }
}

int main(){
    init();
    for (int i = 1; i <= 10; ++i) {
        Insert(i%3 +1,1);
    }

    PrintTree(1);
}

