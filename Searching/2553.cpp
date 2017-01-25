//
// Created by Henry on 16/8/27.
//
#include <iostream>

#define NUM 33

using namespace std;

int Martrix[NUM];
int counter;
bool judge(int row,int col){
    for (int i = 0; i < row; ++i) {
        //0到row行
        int cur = 1,icol=0;
        while (cur != Martrix[i]) cur<<=1,icol++;
        //判断第i行,第icol列和row,col是否在同一列,同一主副对角线
        if (icol == col || icol+i == row+col || icol - i == col - row) return false;

    }

    return true;
}

void pressSearching(int n,int row){
    if(row == n){
        counter++;
        return;
    }
    for (int j = 0; j < n; ++j) {
        //0~n-1列
        Martrix[row] = 1<<j;
        if(judge(row,j)){
            pressSearching(n,row+1);
        }
    }

}

int form[] = {1,
              0,
              0,
              2,
              10,
              4,
              40,
              92,
              352,
              724,};

int main(){
    int n;
    for (int i = 1; i <= 33; ++i) {
        counter = 0;
        pressSearching(i,0);
        printf("%d,\n",counter);
    }
//    while(cin>>n && n){
//        printf("%d\n",form[n-1]);
//    }
}

//#include<stdio.h>
//int N,SchemeNum;
//void DFS(int Col,int MainDiag,int ContDiag)// Col 列放置皇后的情况，MainDiag 主对角线放置皇后的情况
//{                                          // ContDiag 次对角线放置皇后的情况
//    if(Col==(1<<N)-1) // 找到一种放置方案
//    {
//        ++SchemeNum;
//        return;
//    }
//    int emptycol=(((1<<N)-1)&~(Col|MainDiag|ContDiag)); //当前要放的行可以放的位置
//    while(emptycol)
//    {
//        int curcol=(emptycol)&((~emptycol)+1); //取第一位不为零的位
//        emptycol&=~curcol;                     //删除上一次放置的列
//        DFS(Col|curcol,(MainDiag|curcol)>>1,(ContDiag|curcol)<<1);// (ContDiag|curcol)<<1 最好&（1<<N）-1一下防止溢出
//    }
//}
//int main()
//{
//    while(scanf("%d",&N)==1&&N)
//    {
//        SchemeNum=0;
//        DFS(0,0,0);
//        printf("%d\n",SchemeNum);
//    }
//    return 0;
//}