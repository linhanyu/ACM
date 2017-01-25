//
// Created by Henry on 16/10/20.
//

#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std;

const int MAXN = 1010;

char ansseq[MAXN],rawseq[MAXN],tmpseq[MAXN],assseq[MAXN];;

int shuffle(int n){
    int cnt,flg,seq1,seq2;
    memcpy(tmpseq,rawseq, sizeof(rawseq));


    cnt = 0;
    do{
        seq1 = 0,seq2 = n>>1,
        memcpy(assseq,tmpseq, sizeof(rawseq));
        int i = 0;
        while(i<n){

            tmpseq[i++] = assseq[seq2++];
            tmpseq[i++] = assseq[seq1++];
        }
        cnt++;
    }while ((flg = strcmp(tmpseq,ansseq)) && strcmp(tmpseq,rawseq));

    return flg == 0 ? cnt : -1 ;
}



int main(){
    int n,len;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&len);
        len<<=1;

        scanf("%s",rawseq);
        scanf("%s",rawseq + (len>>1));
        scanf("%s",ansseq);

        printf("%d %d\n",i,shuffle(len));
    }
}