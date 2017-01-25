//
// Created by Henry on 16/11/29.
//

#include <cstdio>
#include <cmath>
#define POW2(a) ((a)*(a))

const int MAXN = 100000 + 10;

int n,m;
double a,b,h;
double s1[MAXN],s2[MAXN];

void readseq(double s[],int size){
    for (int i = 0; i < size; ++i) {
        scanf("%lf",&s[i]);
    }
}



double dis(int cur1,int cur2){
    return sqrt(POW2(s1[cur1] - s2[cur2]) + h);
}


int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        scanf("%lf%lf%d%d",&a,&b,&n,&m);

        h = POW2(a-b);
        readseq(s1,n);
        readseq(s2,m);

        int cur1,cur2;
        double len;
        len = cur1 = cur2  = 0;

        while (cur1 < n && cur2 < m){
            len += dis(cur1,cur2);
            if (cur1 == n-1) cur2++;
            else if (cur2 == m-1) cur1++;
            else{
                double d1,d2;
                d1 = dis(cur1,cur2 + 1);
                d2 = dis(cur1 + 1,cur2);

                if (d1 < d2) cur2++;
                else cur1++;
            }
        }

        printf("Case #%d: %.2lf\n",cases,len);

    }
}