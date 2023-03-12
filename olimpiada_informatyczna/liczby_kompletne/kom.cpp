#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e8 + 100;
char arr[N];
vector<int> primes;

int main() {

    arr[0] = 0, arr[1] = 1;
    for(int i = 2; i < N; i++) arr[i] = true;
    for(int i = 2; i < N; i++) {
        //if(arr[i] == false) continue;
        //primes.push_back(i);
        for(int j = i; j < N; j += i)
            arr[j]++;
    }
    
    //for(int i = 0; i < 1000; ++i) cout << primes[i] << " "; cout << "\n";
    cout << "DONE\n";

    return 0;
}
