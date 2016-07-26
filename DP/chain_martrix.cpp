//
// Created by Henry on 16/7/14.
//
#include <queue>

#define INF 0x77777777
using namespace std;
//struct martrix_creater;
//struct martrix;
//
//struct martrix_creater{
//    queue<martrix *> q;
//
//    void gc(){
//        while(!q.empty()){
//            martrix * m = q.front();
//            q.pop();
//            delete m;
//        }
//
//    }
//
//    martrix & _new(){
//        martrix * m = new martrix();
//        q.push(m);
//        return &m;
//    }
//    ~martrix_creater(){
//        gc();
//    }
//};
//martrix_creater c;
//struct martrix{
//    int length;
//
//    martrix & operator*(martrix & m){
//        martrix & m_c = c._new();
//
//    }
//};
#define TABLE_SIZE 500

int s[TABLE_SIZE][TABLE_SIZE];

int Matrix_chain_order(int p[],int size){
    int n = size-1;
    int m[TABLE_SIZE][TABLE_SIZE];
    //m:1~n,1~n s:1~n-1,2~m
    //quick and dirty
    for (int i = 1; i <= n; ++i) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i <= n - l+1; ++i) {
            int j = i+l-1;
            m[i][j] = INF;
            for (int k = i; k <= j-1; ++k) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[2][5];
}

void Print_parens(int i,int j){
    if (i==j){
        printf("A%d",i);
    } else{
        printf("(");
        Print_parens(i,s[i][j]);
        Print_parens(s[i][j]+1,j);
        printf(")");
    }
}

int main(){
    int p[] = {30,35,15,5,10,20,25};
    printf("%d",Matrix_chain_order(p,7));
    Print_parens(1,6);
}
//int main(){
//
//}