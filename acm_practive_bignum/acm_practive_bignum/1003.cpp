#include <iostream>
#include <sstream>

using namespace std;
#define NUM 1002
// int num[1000000];

// int main() {
// 	int n;
// 	cin >> n;
// 	string temp,temp2;
// 	while (n--)
// 	{
// 		getline(cin,temp);
// 		stringstream sst(temp);
// 		while(!temp.empty())
// 		{
// 			sst >> temp2;
// 
// 		}
// 
// 	}
// }
// using namespace std;
// 
// int sum;
// 
// int coin_type[3] = { 5,2,1 };
// 
// int coins(int type, int res,int coin_num) {
// 	if (type == 3)
// 	{
// 		return 0;
// 	}
// 	if (res == 0 && coin_num==0)
// 	{
// 		return 1;
// 	}
// 
// 	if (coin_num < 0)
// 	{
// 		return 0;
// 	}
// 
// 	
// 
// 	int sum1,sum2;
// 
// 	sum1 = coins(type+1, res, coin_num);
// 	sum2 = coins(type, res - coin_type[type], coin_num-1);
// 	return sum1 + sum2;
// 
// }
// 
// int main() {
// 	int t,m,n;
// 	cin >> t;
// 	while (t--)
// 	{
// 		sum = 0;
// 		cin >> n >> m;
// 		cout << coins(0, m, n)<<endl;
// 		
// 	}
// }