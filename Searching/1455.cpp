//
// Created by Henry on 16/9/13.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>

#define MAXN 65

using namespace std;

int sticks[MAXN];
bool used[MAXN];
int n,l,last;



bool dfs(int remain,int sum){
    //remain剩余木棒数,sum表示凑成一根棍子还要的长度
    if (remain == 0 && sum == 0){
        return true;
    }

    if (sum == 0) sum=l;

    int start = 0;
    if (sum != l) start = last + 1;
    //在当前小棍被加入到组合方案时，如还没有组成该目标长度，那么接下来要测试的小棍要从当前小棍的下一个开始测试

    for (int i = start; i < n; ++i) {
        if(!used[i]&&sticks[i]<=sum) {
            if (i > 0 && !used[i - 1] && sticks[i - 1] == sticks[i])
                continue;//所给出的小棍长度可能有重复，如果含有某一小棍的组合方案被推翻了，那么和它同样长的小棍也没必要尝试

            used[i] = true;
            last = i;
            if (dfs(remain - 1, sum - sticks[i])) {
                return true;
            } else {
                used[i] = 0;
                if (sum == l || sticks[i] == sum)
                    return false;


            }
            //3.要凑成某一目标长度的棍子，其中组成它的第一根小棍，怎么也无法和其他小棍凑出这个长度，那么没必要推翻这第一根小棍，直接推翻这个目标长度就可以了。
            //4.如果加上一个小棍x凑成了目标长度，但剩下的小棍再也凑不出这个长度了。那么没必要推翻这个小棍x，去测试其他的小棍，直接推翻这个目标长度就可以了。
        }
    }

    return false;

}


int main(){
    while (cin>>n && n){
        int total = 0;
        for (int i = 0; i < n; ++i) {
            cin>>sticks[i];
            total += sticks[i];
        }

        memset(used,0, sizeof(used));
        sort(sticks,sticks + n,greater<int>());

        for (l = sticks[0]; l <= (total>>1) ; ++l) {
            if (total % l) continue;
            //选择的l必须整除total
            if (dfs(n,l)){
                cout<<l<<endl;
                break;
            }

        }

        if (l>(total>>1)){
            cout<<total<<endl;
        }

    }
}
