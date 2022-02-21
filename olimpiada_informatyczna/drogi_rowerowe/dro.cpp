#include <iostream>
#include <set>

const int max_n = 5e4 + 20;

int n, m;
std::set<int> roadmap[max_n];

int stack[max_n];
int stack_top = 0;

int seen[max_n];
bool done[max_n];

int parent[max_n];
int size[max_n];
int find(int itr) {
    while(parent[itr] != itr)
        itr = parent[itr];
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

void dfs(int itr) {
    std::cout << "dfs(" << itr + 1 << ")\n";
    done[itr] = true;
    stack[stack_top++] = itr;
    if(seen[find(itr)]) {
        for(int i = stack_top - 2;; --i)
            if(!union_(itr, stack[i])) break;
    }
    else {
        ++seen[find(itr)];
        for(int u : roadmap[itr]) dfs(u);
        --seen[find(itr)];
    }
    --stack_top;
}

int main() {

    std::cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        roadmap[u].insert(v);
    }

    for(int i = 0; i < n; ++i) seen[i] = 0;
    for(int i = 0; i < n; ++i) done[i] = false;
    for(int i = 0; i < n; ++i) parent[i] = i;
    for(int i = 0; i < n; ++i) size[i] = 1;

    for(int i = 0; i < n; ++i) {
        if(!done[i]) dfs(7);
        std::cout << "\n";
    }

    for(int i = 0; i < n; ++i) {
        std::cout << "i = " << i + 1 << ", find(i) = " << find(i) + 1 << "\n";
    }

    return 0;
}

/*
14 18
1 2
1 6
2 3
2 4
3 12
4 1
4 5
5 7
6 9
8 4
8 6
10 9
10 6
11 1
11 10
12 13
12 14
14 11
*/