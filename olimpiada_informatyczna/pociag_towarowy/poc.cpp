/*
	Jan Zakrzewski
	XXX Olimpiada Informatyczna, Etap I
	Rozwiązanie zadania 'Pociąg towarowy (poc)'
*/

#include <iostream>
using namespace std;

constexpr int N = 300'020;

int n, m, k;
int train[N];
int sth[N];
int max_array[N];
int min_array[N];
int counter[N] = {0};

char ans[2*N];

// [left_array[i], right_array[i]] - good?


/*

9 4 3

train = 1 3 2 1 2 3 1 3 2
max =   0 1 2 2 3 3 3 3 3
min =   0 0 0 0 0 1 2 2 3
		
		1 1 0 1 1 1 1 0 1

		1 1 1 1 1 3 1 1 2
		  3 3 3 3 1 2 2
			1 1 1 2
				2

1 2 2 3 4 4 4 4 4

1 3 1 2


*/

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i) cin >> train[i];
	for(int i = 0; i < m; ++i) cin >> sth[i];
	{
		int itr, i;
		max_array[0] = 0;
		for(itr = 0, i = 1; i < n; ++i) {
			if(itr < m-1 && train[i-1] == sth[itr]) ++itr;
			max_array[i] = itr;
		}
		min_array[n-1] = m-1;
		for(itr = m-1, i = n-2; i >= 0; --i) {
			if(itr > 0 && train[i+1] == sth[itr]) --itr;
			min_array[i] = itr;
		}
	}
	
	{
		counter[sth[0]] = 1;
		ans[0] = counter[train[0]] > 0 ? '1' : '0';
		ans[1] = ' ';
		for(int i = 1; i < n; ++i) {
			if(max_array[i] - max_array[i-1] > 0) ++counter[sth[max_array[i]]];
			if(min_array[i] - min_array[i-1] > 0) --counter[sth[min_array[i-1]]];
			
			ans[2*i] = counter[train[i]] > 0 ? '1' : '0';
			ans[2*i+1] = ' ';
		}
		ans[2*n] = '\0';
	}

	cout << ans << "\n";

	return 0;
}