#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

constexpr int N = 50'050;
class Graph {
    vector<vector<int>> roads_out;
    vector<vector<int>> roads_in;
public:
    Graph(int nn) {
        roads_out.resize(nn);
        roads_in.resize(nn);
    }
    void add_edge(int u, int v) {
        roads_out[u].push_back(v);
        roads_in[v].push_back(u);
    }
    inline int degree_out(int u) { return roads_out[u].size(); }
    inline int degree_in(int u) { return roads_in[u].size(); }
    inline auto neighbors_out(int u) { return roads_out[u]; }
    inline auto neighbors_in(int u) { return roads_in[u]; }
};

int n, m;
Graph G(N);
vector<int> family(N);
vector<int> sizes(N);
Graph H(N);
vector<int> answer(N);

int main() {

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G.add_edge(a - 1, b - 1);
    }

    {
    vector<int> A;

    vector<bool> visited(N);
    stack<int> my_stack;

    fill(visited.begin(), visited.end(), false);
    
    for(int i = 0; i < n; ++i) {
        //if(G.degree_in(i) != 0) continue;
        my_stack.push(i);
        while(my_stack.size() > 0) {
            int u = my_stack.top(); my_stack.pop();
            if(visited[u]) continue; else visited[u] = true;
            A.push_back(u);
            for(int v : G.neighbors_out(u)) {
                my_stack.push(v);
            }
        }
    }

    //cout << "here0\n";
    //for(int u : A) cout << u + 1 << " "; cout << "\n";
    //cout << "here5\n";
    //cout << flush;

    fill(visited.begin(), visited.end(), false);
    for(int i = 0; i < n; ++i) {
        my_stack.push(A[i]);
        while(my_stack.size() > 0) {
            int u = my_stack.top(); my_stack.pop();
            if(visited[u]) continue; else visited[u] = true;
            //cout << u + 1 << " " << i << "\n";
            family[u] = i;
            for(int v : G.neighbors_in(u)) {
                my_stack.push(v);
            }
        }
    }    

    }

    //std::cout << "\n";

    //cout << "here1\n";

    fill(sizes.begin(), sizes.end(), 0);
    for(int u = 0; u < n; ++u) {
        ++sizes[family[u]];
        for(int v : G.neighbors_out(u)) {
            if(family[u] == family[v]) continue;
            H.add_edge(family[u], family[v]);
            //std::cout << family[u] << " " << family[v] << "\n";
        }
    }

    constexpr int None = -1'000;
    fill(answer.begin(), answer.end(), None);
    function<int(int)> my_lambda = [&](int u)->int{
        if(answer[u] != None) return answer[u];
        answer[u] = sizes[u] - 1;
        for(int v : H.neighbors_out(u)) {
            answer[u] += my_lambda(v) + 1;
        }
        return answer[u];
    };

    //family.resize(n);
    //sizes.resize(n);

    //for(int i : family) cout << i+1 << " "; cout << " \n";
    //for(int i : sizes) cout << i << " "; cout << " \n";

    //cout << my_lambda(5) << "\n";

    for(int i = 0; i < n; ++i) {
        cout << my_lambda(family[i]) << "\n";
    }

    return 0;
}
