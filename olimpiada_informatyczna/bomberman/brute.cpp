// Jan Zakrzewski

#include <iostream>
#include <queue>
#include <tuple>

const int max_n = 1020;
int n, px, py, kx, ky;
char board[max_n][max_n];
char copy[max_n][max_n];
int dist[max_n][max_n];
std::queue<std::pair<int, int>> wave;
int answer = INT32_MAX;

int main() {
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n;
    for(int y = 0; y < n; ++y)
        std::cin >> board[y];

    for(int y = 0; y < n; ++y) for(int x = 0; x < n; ++x) {
        if(board[y][x] == 'P') {
            px = x;
            py = y;
        }
        if(board[y][x] == 'K') {
            kx = x;
            ky = y;
        }
    }

    for(int by = 0; by < n; ++by) {
        for(int bx = 0; bx < n; ++bx) {
            for(int y = 0; y < n; ++y) for(int x = 0; x < n; ++x) copy[y][x] = board[y][x];
            int x, y;
            x = bx, y = by;
            while(1) {
                if(copy[y][x] == 'X') break;
                if(x >= n) break;
                copy[y][x] = '.';
                //std::cout << bx << " " << by << "  " << x << " " << y << "  " << copy[y][x] << "\n";
                ++x;
            }
            x = bx, y = by;
            while(1) {
                if(copy[y][x] == 'X') break;
                if(x < 0) break;
                copy[y][x] = '.';
                --x;
            }
            x = bx, y = by;
            while(1) {
                if(copy[y][x] == 'X') break;
                if(y >= n) break;
                copy[y][x] = '.';
                ++y;
            }
            x = bx, y = by;
            while(1) {
                if(copy[y][x] == 'X') break;
                if(y < 0) break;
                copy[y][x] = '.';
                --y;
            }

            //std::cout << "\n";
            //for(int y = 0; y < n; ++y)
            //    std::cout << board[y] << "\n";

            for(int y = 0; y < n; ++y) for(int x = 0; x < n; ++x) dist[y][x] = INT32_MAX;
            dist[py][px] = 0;
            wave.push(std::pair<int, int>(py, px));
            while(!wave.empty()) {
                int y = wave.front().first;
                int x = wave.front().second;
                wave.pop();

                if(copy[y][x] == 'X' || copy[y][x] == '#') continue;
                if(y == ky && x == kx) {
                    if(dist[y][x] < answer) {
                        answer = dist[y][x];
                    }
                    while(!wave.empty()) wave.pop();
                    break;
                }

                if(y+1 < n && dist[y][x] + 1 < dist[y+1][x]) {
                    dist[y+1][x] = dist[y][x] + 1;
                    wave.push(std::pair<int, int>(y+1, x));
                }

                if(y-1 >= 0 && dist[y][x] + 1 < dist[y-1][x]) {
                    dist[y-1][x] = dist[y][x] + 1;
                    wave.push(std::pair<int, int>(y-1, x));
                }
                
                if(x+1 < n && dist[y][x] + 1 < dist[y][x+1]) {
                    dist[y][x+1] = dist[y][x] + 1;
                    wave.push(std::pair<int, int>(y, x+1));
                }
                
                if(x-1 >= 0 && dist[y][x] + 1 < dist[y][x-1]) {
                    dist[y][x-1] = dist[y][x] + 1;
                    wave.push(std::pair<int, int>(y, x-1));
                }
            }
        }
    }

    if(answer == INT32_MAX) std::cout << "NIE\n";
    else std::cout << answer << "\n";

    return 0;
}