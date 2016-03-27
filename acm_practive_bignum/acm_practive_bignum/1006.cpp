// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <iomanip>
// #include <vector>
// 
// using namespace std;
// #define NUM 1001
// #define BASE 100000000
// #define BIT 8
// #define UPBOUND 120
// #define To_Int(a) (a-'0')
// 
// struct Big_Int
// {
// 	vector<unsigned int> nums;
// 	void operator=(int a) {
// 		nums.push_back(a);
// 	}
// };
// 
// void g_deal(Big_Int & Big_int) {
// 	unsigned int g = 0, j = 0;
// 	while (true)
// 	{
// 		if (j >= Big_int.nums.size() && g == 0) {
// 
// 			break;
// 		}
// 		if (j >= Big_int.nums.size())
// 		{
// 			Big_int.nums.push_back(0);
// 		}
// 
// 		Big_int.nums[j] += g;
// 		g = Big_int.nums[j] / BASE;
// 		Big_int.nums[j] %= BASE;
// 		j++;
// 	}
// }
// void Add_Intger(Big_Int & Big_int_1, Big_Int & Big_int_2) {
// 	for (unsigned int i = 0; i < Big_int_2.nums.size(); i++)
// 	{
// 		if (i == Big_int_1.nums.size())
// 		{
// 			Big_int_1.nums.push_back(Big_int_2.nums[i]);
// 		}
// 		else
// 		{
// 			Big_int_1.nums[i] += Big_int_2.nums[i];
// 		}
// 	}
// 	g_deal(Big_int_1);
// 
// }
// 
// void each_add(Big_Int & be_add_Big_Int, Big_Int * add_Big_Int, int num) {
// 	while (num--)
// 	{
// 		Add_Intger(be_add_Big_Int, add_Big_Int[num]);
// 	}
// }
// 
// void print_Big_Num(Big_Int & bi, ostream & os) {
// 	os << bi.nums[bi.nums.size() - 1];
// 	for (int i = bi.nums.size() - 2; i >= 0; i--)
// 	{
// 		os << setw(BIT) << setfill('0') << bi.nums[i];
// 	}
// }
// int main() {
// 	Big_Int Fibo[NUM];
// 	int n,t;
// 	Fibo[1] = 1;
// 	Fibo[2] = 1;
// 	Fibo[3] = 2;
// 	Fibo[4] = 3;
// 	for (int i = 5; i < NUM;i++)
// 	{
// 		each_add(Fibo[i], (&Fibo[i])-2,2);
// 	}
// 	cin >> t;
// 	while (t--) {
// 		cin >> n;
// 		print_Big_Num(Fibo[n],cout);
// 		cout << endl;
// 	}
// }