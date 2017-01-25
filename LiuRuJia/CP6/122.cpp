//
// Created by Henry on 16/9/3.
//

#include <cstdio>
#include <cstring>
#include <queue>

#define NUM 20
#define BUFFERSIZE 260
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)

using namespace std;

struct Node{
    Node * left = NULL;
    Node * right = NULL;
    int val;
    bool haveValue = false;
};


Node * root;
bool failed;

void addNode(char seq[],int key){
    int len = strlen(seq);
    Node * cur = root;

    for (int i = 0; i < len-1; ++i) {
        if (seq[i] == 'L') {
            if (cur->left == NULL) cur->left = new Node();

            cur = cur->left;
        } else{
            if (cur->right == NULL) cur->right = new Node();

            cur = cur->right;

        }
    }

    if (cur->haveValue) failed = true;

    cur->haveValue = true;
    cur->val = key;
}

bool readInput(char seq[]){
    //2为逗号

    root = new Node();
    failed = false;

    for (;;) {
        if (scanf("%s",seq) !=1 ) return false;
        if (!strcmp(seq,"()")) break;


        int key;
        sscanf(seq+1,"%d",&key);
        addNode(strchr(seq,',')+1,key);
    }


    return true;

}


void bfs(){
    queue<Node *> Q;
    queue<int> result;
    Q.push(root);

    while(!Q.empty()){
        Node * source = Q.front();
        Q.pop();

        if (source->haveValue){
            result.push(source->val);
            if (source->left != NULL) Q.push(source->left);
            if (source->right != NULL) Q.push(source->right);
        } else{
            failed = true;
            break;
        }
    }

    if (failed) {
        puts("not complete");
        return;
    }

    printf("%d",result.front());
    result.pop();

    while(!result.empty()){
        printf(" %d",result.front());
        result.pop();
    }

    puts("");
}

int main(){
    char seq[NUM];
    while(readInput(seq)){
        if (failed){
            puts("not complete");
        } else{
            bfs();
        }
    }

}