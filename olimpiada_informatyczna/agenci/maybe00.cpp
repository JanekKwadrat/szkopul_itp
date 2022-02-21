// Jan Zakrzewski

#include <iostream>
#include <set>

const int max_n = 5e5 + 20;

int n, k;
int ag;
bool agent[max_n]{};
std::set<int> roadmap[max_n];
bool seen[max_n]{};
int ans;

int parent[max_n];
int size[max_n];
void uf_init() {
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}
int find(int itr) {
    while(parent[itr] != itr) itr = parent[itr];
    return itr;
}
bool union_(int itr, int jtr) {
    itr = find(itr);
    jtr = find(jtr);
    if(itr == jtr) return false;
    if(size[itr] < size[jtr]) std::swap(itr, jtr);
    size[itr] += size[jtr];
    parent[jtr] = itr;
    return true;
}

inline int max(int x, int y) {return x > y ? x : y;}
int depth(int itr) {
    if(seen[itr]) return 0;
    seen[itr] = true;
    int answer = 0;
    for(auto oth : roadmap[itr])
        answer = max(answer, depth(oth));
    return answer + 1;
}

int main() {

    std::cin >> n >> k;

    for(int i = 0; i < k; ++i) {
        std::cin >> ag;
        --ag;
        agent[ag] = true;
    }

    uf_init

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        roadmap[u].insert(v);
        roadmap[v].insert(u);
    }

    ans = 2 * (n - 1) - depth(ag) + 1;
    std::cout << ans << "\n";

    return 0;
}