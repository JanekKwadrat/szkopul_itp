#include <iostream>
#include <vector>
#include <map>
#include <queue>

using std::cin, std::cout;
constexpr int Max_n = 3020;

long long ans_nmb = 0;
std::vector<int> ans_slides;

class Graph {

    std::vector<std::map<int, int>> slide_fw;
    std::vector<std::map<int, int>> slide_bw;
    std::vector<long long> slide_cost;

    public:

    Graph() {
        slide_fw = std::vector<std::map<int, int>>(3020);
        slide_bw = std::vector<std::map<int, int>>(3020);
        slide_cost = std::vector<long long>(3020);
    }

    inline bool edge(int u, int v) {
        return (bool) slide_fw[u].count(v);
    }

    inline void make_edge(int u, int v, int i, long long c) {
        if(edge(u, v)) {
            if(c < slide_cost[slide_fw[u][v]]) remove_edge(u, v);
            else {
                ans_nmb += c;
                ans_slides.push_back(i);
            }
        }

        slide_fw[u][v] = i;
        slide_bw[v][u] = i;

        slide_cost[i] = c;
    }

    inline void remove_edge(int u, int v) {
        if(!edge(u, v)) return;

        int i = slide_fw[u][v];
        ans_nmb += slide_cost[i];
        ans_slides.push_back(i);
        
        slide_fw[u].erase(v);
        slide_bw[v].erase(u);
    }

    inline int degree_fw(int u) { return slide_fw[u].size(); }
    inline int degree_bw(int v) { return slide_bw[v].size(); }

    inline auto itr_fw(int u) { return &slide_fw[u]; }
    inline auto itr_bw(int v) { return &slide_bw[v]; }

} G;

int n, k;
std::queue<int> island_queue;
std::vector<int> island_priority(Max_n);

int epoch = 0;
std::vector<int> island_done(Max_n, -1);

int main() {

    cin >> n >> k;
    for(int i = 1; i <= k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G.make_edge(a, b, i, c);
    }

    for(int i = 1; i <= n; ++i) {
        island_priority[i] = G.degree_fw(i);
        if(G.degree_fw(i) == 0) island_queue.push(i);
    }

    while(island_queue.size() > 0) {
        int u = island_queue.front();
        island_queue.pop();
        //cout << "yaw: " << u << "\n";
        for(auto el : *G.itr_bw(u)) {
            //cout << el.first << " " << u << "\n";
            --island_priority[el.first];
            if(island_priority[el.first] <= 0) island_queue.push(el.first);
        }

        ++epoch;
        std::vector<int> to_remove;
        for(auto el : *G.itr_fw(u)) {
            int v = el.first;

            std::queue<int> doing;
            doing.push(v);
            while(doing.size() > 0) {
                int w = doing.front();
                doing.pop();
                if(w != v) to_remove.push_back(w);
                //cout << w << ": ";
                //if(island_done[w] == epoch) continue;

                for(auto fl : *G.itr_fw(w)) {
                    //cout << fl.first << " ";             
                    island_done[fl.first] = epoch;
                    doing.push(fl.first);
                }
                //cout << ", ";
            }
        }
        //cout << "\n";
        for(int v : to_remove) {
            //cout << u << " " << v << "\n";
            G.remove_edge(u, v);
        }
    }

    cout << ans_nmb << "\n";
    for(int u : ans_slides) cout << u << " ";
    cout << "\n";

    return 0;
}