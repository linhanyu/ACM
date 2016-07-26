//
// Created by Henry on 16/4/26.
//

#include <iostream>
#include <list>
#include <string>
using namespace std;

int queue_pop(list<int> & ls){
    int temp = ls.back();
    ls.pop_back();
    return temp;
}


int stack_pop(list<int> & ls){
    int temp = ls.front();
    ls.pop_front();
    return temp;
}

//int main(){
//    list<int> container;
//    int n,num,temp;
//    char CMD[5];
//    int (*pop)(list<int > & ls);
//    cin>>num;
//    while(num--){
//        cin>>n;
//        cin>>CMD;
//        pop = strcmp(CMD,"FIFO")?stack_pop:queue_pop;
//        getchar();
//        while(n--) {
//            cin >> CMD;
//            if (strcmp(CMD,"IN")){
//                if (container.empty()){
//                    cout<<"None"<<endl;
//                } else {
//                    cout<<(*pop)(container)<<endl;
//                }
//
//            } else{
//                cin>>temp;
//                container.push_front(temp);
//            }
//            getchar();
//        }
//        container.clear();
//
//    }
//}