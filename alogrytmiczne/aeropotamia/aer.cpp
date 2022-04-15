#include <iostream>
#include <vector>
#include <set>

using std::cin, std::cout;

class Graph {

    std::vector<std::set<int>> slide_fw;
    std::vector<std::set<int>> slide_bw;

    public:

    inline bool edge(int u, int v) {
        return slide_fw[u].count(v);
    }

    inline void make_edge(int u, int v) {
        slide_fw[u].insert(v);
        slide_bw[v].insert(u);
    }

    inline int degree_fw(int u) { return slide_fw[u].size(); }
    inline int degree_bw(int v) { return slide_bw[v].size(); }

    inline auto itr_fw(int u) { return &slide_fw[u]; }
    inline auto itr_bw(int v) { return &slide_fw[v]; }

} G;

int n, k;

int main() {

    cin >> n >> k;
    for(int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        G.make_edge(a, b);
    }

    

    return 0;
}