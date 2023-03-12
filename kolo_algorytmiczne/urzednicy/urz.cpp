#include <iostream>

constexpr int Max_n = 1'000'020;
int n, p, i, j;
int przelozony[Max_n];

int ancestor[Max_n];
int find(int itr) {
    if(itr == ancestor[itr])
        return itr;
    int jtr = find(ancestor[itr]);
    ancestor[itr] = jtr;
    return jtr;
}

bool available[Max_n] = {};
int ans = 0;

int main() {
    std::cin >> n;
    for(i = 1; i < n; ++i) {
        std::cin >> p;
        przelozony[i] = p - 1;
        ancestor[i] = i;
        available[i] = true;
    }

    for(i = n - 1; i >= 0; --i) {
        if(!available[i]) continue;
        if(i != ancestor[i]) continue;
        j = find(przelozony[i]);
        ancestor[j] = przelozony[j];
        ++ans;
        available[j] = false;
    }

    std::cout << ans << "\n";

    return 0;
}