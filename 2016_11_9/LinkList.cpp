//
// Created by Henry on 16/11/19.
//

#include <cstdio>
#include <cstdlib>
struct Data{
    int key;
};

struct Node{
    Data data;
    Node * next;
};

Node head;
int size;

Node * newNode(Data data){
    //添加节点
    Node * n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void Insert(Node * head,Data data){
    //插数据
    Node * n = newNode(data);
    n->next = head->next;
    head->next = n;
    size++;
}

Node * findpre(Node * head,Data data){
    //找数据
    Node * pre;
    Node * cur;
    pre = head;
    cur = head->next;

    while (cur != NULL && cur->data.key != data.key){
        pre = cur;
        cur = cur->next;
    }

    return pre;
}

void Delete(Node * head,Data data){
    //删数据
    Node * pre = findpre(head,data);

    if (pre->next != NULL){
        Node * cur = pre->next;
        pre->next = cur->next;
        delete cur;
    }
}

void prtList(Node * head){
    Node * cur = head->next;
    while (cur!=NULL){
        printf("%d ",cur->data.key);
        cur = cur->next;
    }
    puts("");
}

void BubbleSort(Node * head){
//排序
    if (head == NULL) return;

    for (int i = size-1; i > 0 ; --i) {
        Node * anchor = head;
        Node * cmp1 = anchor->next;
        Node * cmp2 = cmp1->next;


        for (int j = 0; j < i - 1; ++j) {
            if (cmp1->data.key > cmp2->data.key){
                anchor->next = cmp2;
                cmp1->next = cmp2->next;
                cmp2->next = cmp1;
            }

            anchor = anchor->next;
            cmp1 = anchor->next;
            cmp2 = cmp1->next;
        }
    }
}

void destory(Node * n){
    if (n == NULL) return;

    destory(n->next);
    delete n;
}

void init(){
    head.next = NULL;
    size = 0;
}

int main(){
    init();

    for (int i = 0; i < 10; ++i) {
        Data data;
        data.key = i;
        Insert(&head,data);
    }

    prtList(&head);

    Data data;
    data.key = 5;
    Delete(&head,data);

    prtList(&head);

    BubbleSort(&head);

    prtList(&head);

    destory(head.next);


}