#include <iostream>
#include <algorithm>

#define  NUM 1000
#define  CUTOFF 9
using namespace std;

enum COMPETER{TIAN=0,QI};

void Insert_sort(int * a, int size) {
	int i, j;
	int temp;
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

int median_3(int left, int right, int *a)
{
	int mid = (left + right) >> 1;
	if (a[left] > a[mid])
	{
		swap(a[left], a[mid]);
	}
	if (a[mid] > a[right])
	{
		swap(a[right], a[mid]);
	}
	if (a[left] > a[mid])
	{
		swap(a[left], a[mid]);
	}

	swap(a[mid], a[right - 1]);
	return a[right - 1];


}

void Q_Sort(int * a, int left, int right) {
	if (CUTOFF + left < right)
	{
		int pivot = median_3(left, right, a);
		int i = left;
		int j = right - 1;

		while (true)
		{
			while (a[++i] < pivot);
			while (a[--j] > pivot);

			if (i < j)
			{
				swap(a[i], a[j]);
			}
			else
			{
				break;
			}

		}

		swap(a[i], a[right - 1]);
		Q_Sort(a, left, i - 1);
		Q_Sort(a, i + 1, right);
	}
	else
	{
		Insert_sort(a + left, right - left + 1);

	}


}

int main() {
	int n=60,m,sum;
	int horse[2][NUM];

	while (n--)
	{
		cin >> m;
		if (m==0)
		{
			break;
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++) {
				cin>>horse[i][j];
			}
		}

		Q_Sort(horse[QI], 0, m - 1);
		Q_Sort(horse[TIAN], 0, m - 1);
		sum = 0;

		int  s_q,s_t, f_q, f_t,win,lose;
		win = lose = 0;
		s_q = s_t = 0;
		f_q = f_t = m-1;
		for (int i=0;i<m;i++)
		{
			
			 if (horse[TIAN][f_t] > horse[QI][f_q]){
				f_t--;
				f_q--;
				win++;
			}else if (horse[TIAN][f_t] < horse[QI][f_q])
			{
				s_t++;
				f_q--;
				lose++;
			}else {

				if (horse[TIAN][s_t] > horse[QI][s_q] )
				{
					win++;
					s_t++;
					s_q++;
				} 
				else if(horse[TIAN][s_t] < horse[QI][s_q])
				{
					s_t++;
					f_q--;
					lose++;
				}
				else 
				{
					if (horse[TIAN][s_t] < horse[QI][f_q]) {
						lose++;
					}
					s_t++;
					f_q--;
				}
				
				
				
			}


		}

		cout << (win - lose) * 200<<endl;
	}
}