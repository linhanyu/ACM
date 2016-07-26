//
// Created by Henry on 16/7/22.
//

#include <cstdio>
#include <algorithm>
#include <memory>

#define MID(a,b) ((a+b)>>1)
#define NUM 1001

using namespace std;

struct Mouse{
    int weight;
    int speed;
    int index;

    bool operator<(const Mouse & m) const{
        if(speed == m.speed){
            return weight < m.weight;
        }
        return speed > m.speed;
    }
};

int Binary_Search(Mouse A[],int left,int right,int key){
    while (left <= right){
        int mid = MID(left,right);
        if (key < A[mid].weight) right = mid-1;
        else if (key > A[mid].weight) left = mid + 1;
        else break;
    }
    return left;
}

int pre[NUM];
Mouse mouse[NUM];
void print_rec(int index){
    if (index == 0){
        return;
    }
    print_rec(pre[index]);
    printf("%d\n",mouse[index].index);
}

int main(){
    int dp[NUM];
    int count = 1;
    while (scanf("%d %d",&mouse[count].weight,&mouse[count].speed)!=EOF) {
        mouse[count].index = count;
        count++;
    }
//    for (int i = 0; i < 9; ++i) {
//        scanf("%d %d",&mouse[count].weight,&mouse[count].speed);
//        mouse[count].index = count;
//        count++;
//    }

    sort(mouse+1,mouse + count);

    for (int i = 0; i <= NUM; ++i) {
        dp[i] = 0;
    }

    pre[0] = -1;
    mouse[0].weight = 0;
    int max_index = 0;
    for (int i = 1; i <= count; ++i) {
        for (int j = 0; j < i; ++j) {
            if (mouse[i].weight > mouse[j].weight && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                pre[i] = j;
                if (dp[max_index] < dp[i]){
                    max_index = i;
                }
            }
        }
    }

    printf("%d\n",dp[max_index]);
    print_rec(max_index);
//    while (max_index){
//        printf("%d\n",mouse[max_index].index);
//        max_index = pre[max_index];
//    }
//    stack[0] = mouse[0].weight;
//    for (int i = 1; i < count; ++i) {
//        if (mouse[i].weight > stack[cur]){
//            stack[cur++] = mouse[i].weight;
//        } else {
//            int tmp = Binary_Search(mouse, 0, i, mouse[i].weight);
//            stack[tmp] = mouse[i].weight;
//        }
//    }
//
//    printf("%d",cur);

}