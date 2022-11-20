/*
	Jan Zakrzewski
	XXX Olimpiada Informatyczna, I etap
	Rozwiązanie zadania 'Kolorowy wąż (kol)'
*/

#include <iostream>
#include <algorithm>
using namespace std;

constexpr int M = 2'020;
constexpr int NONE = -1'000'000'000;

int m, p, n;

int color[M * M];
int pointer[M * M];
int snake[M * M];
int head, tail;

int fruit[M * M];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> m >> p >> n;
	
	fill(fruit, fruit + M * M, NONE);
	fill(pointer, pointer + M * M, NONE);

	color[0] = 0;
	pointer[0] = 0;
	head = 0, tail = 0;

	for(int i = 0; i < p; ++i) {
		int y, x, c;
		cin >> y >> x >> c;
		--x, --y;
		fruit[x + y * M] = c;
	}

	for(int i = 0; i < n; ++i) {
		char L;
		cin >> L;
		if(L == 'Z') {
			int y, x;
			cin >> y >> x;
			--x, --y;
			if(pointer[x + y * M] == NONE) cout << "-1\n";
			else {
				int ptr = pointer[x + y * M] - pointer[tail];
				cout << color[ptr] << "\n";
			}
		} else {
			int d;
			switch(L) {
				case 'G': d = -M; break;
				case 'D': d =  M; break;
				case 'L': d = -1; break;
				case 'P': d =  1; break;
			}
			if(fruit[head + d] == NONE) {
				if(tail == head) snake[tail] = d;
				int _tail = tail;
				tail = tail + snake[tail];
				snake[head] = d;
				pointer[head + d] = pointer[head] + 1;
				head += d;
				if(_tail != head) pointer[_tail] = NONE;
			} else {
				snake[head] = d;
				pointer[head + d] = pointer[head] + 1;
				head += d;
				int ptr = pointer[head] - pointer[tail];
				color[ptr] = fruit[head];
				fruit[head] = NONE;
			}
		}

		/*for(int i = 0; i < m; ++i) {
			for(int j = 0; j < m; ++j) {
				if(fruit[j + i * M] != NONE) cout << (char)('A' + fruit[j + i * M]) << " ";
				else if(pointer[j + i * M] == NONE) cout << ". ";
				else cout << pointer[j + i * M] << " ";
			}
			cout << "\n";
		}
		/*
		for(int i = 0; i < len; ++i) cout << (char)('A' + color[i]) << " ";
		cout << "\n";
		cout << head << " " << tail << "\n";
		cout << pointer[head] << " " << pointer[tail] << "\n";
		*/
	}

	return 0;
}