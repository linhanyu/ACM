#include <iostream>
#include <vector>

using namespace std;


#define NUM 5010
template<class T>
void Insert_Sort(T * a, int size) {
	int i, j;
	T temp;
	for (i = 1; i < size; i++)
	{
		temp = a[i];
		for (j = i; j > 0 && temp < a[j - 1]; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}
struct  wood
{
	int len;
	int wei;

	void set_len_wei(int a, int b) { len = a; wei = b; }
	bool operator<(wood & wd) {
		return wei < wd.wei ? true : (wei == wd.wei ? len < wd.len : false);}
};

// int main() {
// 	wood forest[NUM];
// 	int t,n,len,wei,sum,maxium,temp;
// 	vector<int> maxtree;
// 	bool flag;
// 
// 	cin >> t;
// 	while (t--)
// 	{
// 		sum = 0;
// 		cin >> n;
// 		for (int i = 0; i < n; i++)
// 		{
// 			cin >> len >> wei;
// 			forest[i].set_len_wei(len, wei);
// 
// 		}
// 
// 		Insert_Sort(forest, n);
// 
// 		maxtree.push_back(32765);
// 		for (int i = 0,j; i < n; i++)
// 		{
// 			temp = forest[i].len;
// 			flag = true;
// 			maxium = 0;
// 			for (j = 0; j < maxtree.size(); j++)
// 			{
// 				if (maxtree[j] <= temp )
// 				{
// 					flag = false;
// 					if (maxtree[j] > maxtree[maxium] || maxium == 0) maxium = j;
// 
// 				} 
// 				
// 			}
// 
// 			if (flag)
// 			{
// 				maxtree.push_back(temp);
// 				sum++;
// 			} 
// 			else
// 			{
// 				maxtree[maxium] = temp;
// 			}
// 		}
// 		
// 		
// 		cout << sum << endl;
// 		maxtree.clear();
// 
// 
// 	}
// }