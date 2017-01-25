//
// Created by Henry on 16/10/31.
//

//cnm = n-m+1/m cnm-1
#include <cstdio>
#include <vector>
#include <memory.h>
typedef long long LL;

using namespace std;

const int MAXN = 50000 + 10;
const int MAXP = 100;

int mfac[MAXP],mfacNum[MAXP],cfac[MAXP],cfacNum[MAXP];
int mcur,m,n;

vector<int > ans;

void deconstruct(int num,int ans[],int ansNum[],int & cur){
    cur = 0;

    for (int i = 2; i*i <=num ; ++i) {
        if (num  % i == 0){
            ans[cur] = i;
            ansNum[cur] = 0;

            while (num  % i == 0){
                ansNum[cur]++;
                num /= i;
            }

            cur++;
        }

    }
    if(num>1){
        ans[cur] = num;
        ansNum[cur++] = 1;
    }
}

bool check(int n,int j,int size){
    int a = n-j,b = j;

    for (int i = 0; i < size; ++i) {
        while (a % mfac[i] == 0){
            a /= mfac[i];
            cfacNum[i]++;
        }

        while (b % mfac[i] == 0){
            b /= mfac[i];
            cfacNum[i]--;
        }

    }

    for (int i = 0; i < size; ++i) {
        if (mfacNum[i] > cfacNum[i]){
            return false;
        }
    }

    return true;
}
//LL n,m;
//
//void init(){
//
//}

int main(){
    while (~scanf("%d %d",&n,&m)){
        ans.clear();

        deconstruct(m,mfac,mfacNum,mcur);
        memset(cfacNum,0, sizeof(cfacNum));

        for (int i = 1; i < n; ++i) {
            if (check(n,i,mcur)){
                ans.push_back(i+1);
            }
        }

        printf("%lu\n",ans.size());

        if (ans.size() == 0) puts("");

        for (long unsigned i = 0; i < ans.size(); ++i) {
             printf("%d%c",ans[i],i == ans.size() - 1 ? '\n' : ' ');
        }
    }
}

//LL c[MAXN];
//vector<LL > ansnum;
//void calC(int n,int m){
//    c[0] = 1;
//    for (int i = 1; i < (m>>1); ++i) {
//        c[i] = c[i-1]/i * (n-i+1);
//    }
//}

//void solve(){
//    ansnum.clear();
//    LL ans = 1;
//    LL cur = 1;
//
//    if (cur % m == 0){
//        ansnum.push_back(1);
//    }
//
//    n--;
//
//    for (LL i = 1; i <= n; ++i) {
//        cur = cur * (n - i + 1) / i;
//        if (cur % m == 0){
//            ansnum.push_back(i+1);
//        }
//    }
//
//    printf("%lu\n",ansnum.size());
//    for (int i = 0; i < ansnum.size(); ++i) {
//        printf("%lld%c",ansnum[i],i == ansnum.size() - 1 ? '\n' : ' ');
//    }
//
//}

