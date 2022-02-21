#include <iostream>
#include <iomanip>
#include <queue>
#include <tuple>

const int max_n = 1020;
const int infty = 1e7;
int n;
char board[max_n][max_n];
int dist[max_n][max_n];
int distoth[max_n][max_n];
int Px, Py, Kx, Ky;
std::queue<std::pair<int, int>> wave;

int min_hor_val[max_n][max_n];
int min_hor_itr[max_n][max_n];

int min_ver_val[max_n][max_n];
int min_ver_itr[max_n][max_n];

int minoth_hor_val[max_n][max_n];
int minoth_hor_itr[max_n][max_n];

int minoth_ver_val[max_n][max_n];
int minoth_ver_itr[max_n][max_n];

int answer = infty;

int main() {
    std::cin >> n;
    for(int y = 0; y < n; ++y)
        std::cin >> board[y];
    
    for(int y = 0; y < n; ++y) for(int x = 0; x < n; ++x) {
        if(board[y][x] == 'P') Px = x, Py = y;
        if(board[y][x] == 'K') Kx = x, Ky = y;
    }

    for(int y = 0; y < n; ++y) for(int x = 0; x < n; ++x) dist[y][x] = infty;

    wave.push(std::pair<int, int>(Py, Px));
    dist[Py][Px] = 0;
    while(!wave.empty()) {
        int y = wave.front().first;
        int x = wave.front().second;
        wave.pop();

        if(board[y][x] == 'X' || board[y][x] == '#') continue;

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

    for(int y = 0; y < n; ++y) {
        int val, itr;
        val = infty;
        itr = -1;
        for(int x = 0; x < n; ++x) {
            if(board[y][x] == 'X') val = infty;
            else {
                if(dist[y][x] < val) {
                    val = dist[y][x];
                    itr = x;
                }
                min_hor_val[y][x] = val;
                min_hor_itr[y][x] = itr;
            }
        }
        val = infty;
        itr = -1;
        for(int x = n-1; x >= 0; --x) {
            if(board[y][x] == 'X') val = infty;
            else {
                if(min_hor_val[y][x] < val) {
                    val = min_hor_val[y][x];
                    itr = min_hor_itr[y][x];
                }
                min_hor_val[y][x] = val;
                min_hor_itr[y][x] = itr;
            }
        }
    }

    for(int x = 0; x < n; ++x) {
        int val, itr;
        val = infty;
        itr = -1;
        for(int y = 0; y < n; ++y) {
            if(board[y][x] == 'X') val = infty;
            else {
                if(dist[y][x] < val) {
                    val = dist[y][x];
                    itr = y;
                }
                min_ver_val[y][x] = val;
                min_ver_itr[y][x] = itr;
            }
        }
        val = infty;
        itr = -1;
        for(int y = n-1; y >= 0; --y) {
            if(board[y][x] == 'X') val = infty;
            else {
                if(min_hor_val[y][x] < val) {
                    val = min_ver_val[y][x];
                    itr = min_ver_itr[y][x];
                }
                min_ver_val[y][x] = val;
                min_ver_itr[y][x] = itr;
            }
        }
    }

    for(int y = 0; y < n; ++y) for(int x = 0; x < n; ++x) distoth[y][x] = infty;

    wave.push(std::pair<int, int>(Ky, Kx));
    distoth[Ky][Kx] = 0;
    while(!wave.empty()) {
        int y = wave.front().first;
        int x = wave.front().second;
        wave.pop();

        if(board[y][x] == 'X' || board[y][x] == '#') continue;

        if(y+1 < n && distoth[y][x] + 1 < distoth[y+1][x]) {
            distoth[y+1][x] = distoth[y][x] + 1;
            wave.push(std::pair<int, int>(y+1, x));
        }

        if(y-1 >= 0 && distoth[y][x] + 1 < distoth[y-1][x]) {
            distoth[y-1][x] = distoth[y][x] + 1;
            wave.push(std::pair<int, int>(y-1, x));
        }
        
        if(x+1 < n && distoth[y][x] + 1 < distoth[y][x+1]) {
            distoth[y][x+1] = distoth[y][x] + 1;
            wave.push(std::pair<int, int>(y, x+1));
        }
                
        if(x-1 >= 0 && distoth[y][x] + 1 < distoth[y][x-1]) {
            distoth[y][x-1] = distoth[y][x] + 1;
            wave.push(std::pair<int, int>(y, x-1));
        }
    }

    for(int y = 0; y < n; ++y) {
        int val, itr;
        val = infty;
        itr = -1;
        for(int x = 0; x < n; ++x) {
            if(board[y][x] == 'X') val = infty;
            else {
                if(distoth[y][x] < val) {
                    val = distoth[y][x];
                    itr = x;
                }
                minoth_hor_val[y][x] = val;
                minoth_hor_itr[y][x] = itr;
            }
        }
        val = infty;
        itr = -1;
        for(int x = n-1; x >= 0; --x) {
            if(board[y][x] == 'X') val = infty;
            else {
                if(minoth_hor_val[y][x] < val) {
                    val = minoth_hor_val[y][x];
                    itr = minoth_hor_itr[y][x];
                }
                minoth_hor_val[y][x] = val;
                minoth_hor_itr[y][x] = itr;
            }
        }
    }

    for(int x = 0; x < n; ++x) {
        int val, itr;
        val = infty;
        itr = -1;
        for(int y = 0; y < n; ++y) {
            if(board[y][x] == 'X') val = infty;
            else {
                if(distoth[y][x] < val) {
                    val = distoth[y][x];
                    itr = y;
                }
                minoth_ver_val[y][x] = val;
                minoth_ver_itr[y][x] = itr;
            }
        }
        val = infty;
        itr = -1;
        for(int y = n-1; y >= 0; --y) {
            if(board[y][x] == 'X') val = infty;
            else {
                if(minoth_hor_val[y][x] < val) {
                    val = minoth_ver_val[y][x];
                    itr = minoth_ver_itr[y][x];
                }
                minoth_ver_val[y][x] = val;
                minoth_ver_itr[y][x] = itr;
            }
        }
    }

    for(int by = 0; by < n; ++by) for(int bx = 0; bx < n; ++bx) {
        if(board[by][bx] == 'X') continue;
        if(!answer) std::cout << by << " " << bx << "\n";
        if(min_hor_itr[bx][by] == -1 || minoth_hor_itr[bx][by] == -1 || min_ver_itr[bx][by] == -1 || minoth_ver_itr[bx][by] == -1) continue;
        answer = std::min(answer, dist[by][min_hor_itr[by][bx]] + abs(min_hor_itr[by][bx] - minoth_hor_itr[by][bx]) + distoth[by][minoth_hor_itr[by][bx]]);
        answer = std::min(answer, dist[min_ver_itr[by][bx]][bx] + abs(min_ver_itr[by][bx] - minoth_ver_itr[by][bx]) + distoth[minoth_ver_itr[by][bx]][bx]);
        answer = std::min(answer, dist[by][min_hor_itr[by][bx]] + abs(bx - min_hor_itr[by][bx]) + abs(by - minoth_ver_itr[by][bx]) + distoth[minoth_ver_itr[by][bx]][bx]);
        answer = std::min(answer, dist[min_ver_itr[by][bx]][bx] + abs(by - min_ver_itr[by][bx]) + abs(bx - minoth_hor_itr[by][bx]) + distoth[by][minoth_hor_itr[by][bx]]);
    }
    
    if(answer == infty) std::cout << "NIE\n";
    else std::cout << answer << "\n";

    /*for(int y = 0; y < n; ++y) {
        for(int x = 0; x < n; ++x)
            std::cout << std::setw(7) << (board[y][x] == 'X' ? -1 : dist[y][x]) << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
    for(int y = 0; y < n; ++y) {
        for(int x = 0; x < n; ++x)
            std::cout << std::setw(7) << (board[y][x] == 'X' ? -1 : min_hor_val[y][x]) << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
    for(int y = 0; y < n; ++y) {
        for(int x = 0; x < n; ++x)
            std::cout << std::setw(7) << (board[y][x] == 'X' ? -1 : min_hor_itr[y][x]) << " ";
        std::cout << "\n";
    }*/

    return 0;
}