//
// Created by Henry on 17/1/22.
//

#include <cstdio>
#include <memory.h>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 26;

int t[MAXN];
char str[10000 + 10];
map<int,int > mp;


int main(){
    int n,cases=0;
    while (~scanf("%d",&n)){
        int cnt = 0;
        while(n--){
            memset(t,-1, sizeof(t));
            mp.clear();

            scanf("%s",str);
            int len = strlen(str);
            for (int i = 0; i < len; ++i) {
                t[str[i]-'a']++;
            }

            if (t[str[0]-'a'] == len-1){
                continue;
            }
            bool flg = true;
            for (int i = 0; i < 26; ++i) {
                if (~t[i] && mp[t[i]]++){
                    flg = false;
                    break;
                }
            }
            if (flg) cnt++;
        }

        printf("Case %d: %d\n",++cases,cnt);


    }
}