#include <iostream>
#include <vector>

using namespace std;
//
//int main() {
//	long long n;
//	long long temp;
//	vector<int> ls;
//	while (cin>>n)
//	{
//		long long sum = 0;
//		ls.push_back(0);
//
//		while (n--)
//		{
//			cin >> temp;
//			int sub_scrip = 0;
//			bool create = true;
//			for (int i = 0; i < ls.size(); i++)
//			{
//				if (temp < ls[i])
//				{
//					create = false;
//					if (ls[i] < ls[sub_scrip] || sub_scrip==0) sub_scrip = i;
//
//				}
//			}
//
//			if (create)
//			{
//				ls.push_back(temp);
//				sum++;
//			}
//			else
//			{
//				ls[sub_scrip] = temp;
//			}
//
//
//		}
//
//		cout << sum<<endl;
//		ls.clear();
//
//	}
//}