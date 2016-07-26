//
// Created by Henry on 16/4/26.
//
//
//#include <iostream>
//#include <map>
//#include <vector>
//#include <string>
//
//#define NUM 50000
//
//using namespace std;
//
//int main(){
//    map <string,bool > rls;
//    vector<string> strs;
//    string temp;
//
//    while(cin>>temp){
//        rls[temp] = true;
//        strs.push_back(temp);
//    }
//
//    for (int i = 0; i < strs.size(); ++i) {
//        temp = "";
//        for (int j = 0; j < strs[i].size(); ++j) {
//            temp+=strs[i][j];
//            if (rls[temp] && rls[strs[i].substr(j+1)]){
//                cout<<strs[i]<<endl;
//                break;
//            }
//        }
//    }
//
//}