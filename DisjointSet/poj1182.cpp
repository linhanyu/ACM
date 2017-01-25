//
// Created by Henry on 16/9/22.
//
#include <memory>
#include <cstdio>
const int MAXN = 50000;
const int offset[] = {0,MAXN,MAXN*2};
int BUFFER[150010];


int Find (int root){
    if(BUFFER[root] < 0){
        return root;
    }else{
        return BUFFER[root] = Find(BUFFER[root]);
    }
}


bool same(int rt1,int rt2){
    return Find(rt1) == Find(rt2);
}
void Merge(int rt1,int rt2){
    if (rt1 == rt2) return;

    BUFFER[rt1] = rt2;
}


int main(){
    int n,k;
    scanf("%d %d",&n,&k);
        memset(BUFFER,-1, sizeof(BUFFER));

        int d,x,y,count;
        count = 0;
        while (k--){
            scanf("%d%d%d",&d,&x,&y);

            if (x > n || y > n){
                count++;
                continue;
            }

            if (d == 1){
                if(same(x,y + offset[1]) || same(x,y + offset[2])) {
                    count++;
                    continue;
                }


                for (int i = 0; i < 3; ++i) {
                    int rt1 = Find(x + offset[i]);
                    int rt2 = Find(y + offset[i]);

                    Merge(rt1,rt2);

                }



            } else{
                if(same(x,y) || same(x,y + offset[2])) {
                    count++;
                    continue;
                }


                for (int i = 0; i < 3; ++i) {
                    int rt1 = Find(x + offset[i]);
                    int rt2 = Find(y + offset[(i+1)%3]);

                    Merge(rt1,rt2);

                }
            }

        }

        printf("%d\n",count);

}