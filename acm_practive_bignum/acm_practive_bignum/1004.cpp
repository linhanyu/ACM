#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
#define BASE 100000
#define BIT 5
#define UPBOUND 120
#define To_Int(a) (a-'0')

int fast_pow(int base, int mi) {
	int ans = 1;
	while (base)
	{
		if (mi &1)
		{
			ans *= base;
			mi--;
		} 
		base *= base;
		mi >>= 1;
	}
	return ans;
}

int To_Big_Int(char * tr, int len, int * bignum) {
	int j,i;
	for (j = 0,i=0;--len>=0;i++)
	{
		bignum[j] += To_Int(tr[len])*fast_pow(10,i);
		if (i==BIT-1)
		{
			j++;
			i = -1;
		}
	}
	return bignum[j]==0?j:j+1;
}

int g_deal(int * bignum, int len,int len_2) {
	int g = 0, j = 0;
	while (true)
	{
		if (j >= len && j>=len_2 && g == 0)
		{
			break;
		}
		bignum[j] += g;
		g = bignum[j] / BASE;
		bignum[j] %= BASE;
		j++;
	}
	return j;
}

int Big_Int_Add(int * bignum1,int size_1,const int * bignum2,int size_2) {
	for (int i = 0; i < size_2;i++)
	{
		bignum1[i] += bignum2[i];
	}
	return g_deal(bignum1,size_1,size_2);
}



void print_Big_Int(int len, int * bignum,ostream & os) {
	os << bignum[--len];
	while (len>0)
	{
		os << setw(BIT) << setfill('0') << bignum[--len];
	}
}
// int main() {
// 	char temp[105];
// 	char zero[2] = "0";
// 	int bignum[5000], temp_num[UPBOUND/BIT],big_num_len,temp_len;
// 
// 	int t;
// 	cin >> t;
// 	bool flag = false;
// 	while (t--) {
// 		if (flag)
// 		{
// 			cout << endl;
// 		}
// 		memset(bignum, 0, sizeof(bignum));
// 		memset(temp_num, 0, sizeof(temp_num));
// 		big_num_len = temp_len = 0;
// 		while (cin >> temp && strcmp(temp, zero)!=0) {
// 			temp_len = To_Big_Int(temp, strlen(temp), temp_num);
// 			big_num_len =Big_Int_Add(bignum, big_num_len, temp_num, temp_len);
// 			memset(temp_num, 0, sizeof(temp_num));
// 
// 		}
// 		print_Big_Int(big_num_len, bignum,cout);
// 		flag = true;
// 		cout << endl;
// 	}
// }