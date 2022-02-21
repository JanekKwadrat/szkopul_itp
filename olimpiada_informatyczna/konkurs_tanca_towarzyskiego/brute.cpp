// Jan Zakrzewski

#include <iostream>
#include <vector>

const int max_q = 1e6 + 20;

int q, x;
char c;
int top;

std::vector<int> interests[max_q];

int main() {

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    interests[0].push_back(1);
    interests[1].push_back(0);
    top = 2;

    std::cin >> q;
    
    while(q--) {
        std::cin >> c >> x;
        --x;
        if(c == 'W') {
            interests[x].push_back(top);
            interests[top].push_back(x);
            ++top;
        }
        else if(c == 'Z') {
            for(int k : interests[x]) {
                interests[top].push_back(k);
                interests[k].push_back(top);
            }
            ++top;
        }
        else if(c == '?') std::cout << interests[x].size() << "\n";
    }

    return 0;
}