// Jan Zakrzewski

#include <iostream>
#include <set>

const int max_n = 5e5 + 20;

int n, k;
bool agent[max_n]{};
std::set<int> roadmap[max_n];
bool seen[max_n]{};
int ans;

int degree[max_n]{};
int max_deg = 0;

inline int max(int x, int y) {return x > y ? x : y;}
inline int min(int x, int y) {return x < y ? x : y;}
int depth(int itr) {
    if(seen[itr]) return 0;
    seen[itr] = true;
    int answer = 0;
    for(auto oth : roadmap[itr]) {
        if(agent[oth]) continue;
        answer = max(answer, depth(oth));
    }
    return answer + 1;
}

int main() {

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> k;

    for(int i = 0; i < k; ++i) {
        int ag;
        std::cin >> ag;
        --ag;
        agent[ag] = true;
    }

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        ++degree[u];
        ++degree[v];
        roadmap[u].insert(v);
        roadmap[v].insert(u);
    }

    for(int i = 0; i < n; ++i) max_deg = max(max_deg, degree[i]);
    
    if(max_deg >= 3 || k == 1) {

        ans = 2 * (n - k);
        for(int ag = 0; ag < n; ++ag) {
            if(!agent[ag]) continue;
            ans -= depth(ag) - 1;
        }

    }
    else {
        ans = n - k;
        int itr, jtr;
        for(int i = 0; i < n; ++i) {
            if(degree[i] > 1) continue;
            itr = jtr;
            jtr = i;
        }
        int sth = agent[itr] ? 0 : depth(itr);
        int tth = agent[jtr] ? 0 : depth(jtr);
        ans += min(sth, tth);
    }
    std::cout << ans << "\n";

    return 0;
}