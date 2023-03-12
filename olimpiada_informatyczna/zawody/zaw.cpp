#include <iostream>
#include <map>
using namespace std;

constexpr int N = 5'020;

int edge_add(int, int, int);
int edge_val_fw(int, int);
int edge_val_bw(int, int);
int vertex_deg_fw(int);
int vertex_deg_bw(int);
int vertex_go_fw(int, int);
int vertex_go_bw(int, int);

int main() {

    return 0;
}

std::map<int, int> graph_fw[N];
std::map<int, int> graph_bw[N];

int edge_add(int u, int v, int d) {
    graph_fw[u][v] = d;
}

int edge_val_fw(int u, int v) {
    return graph_fw[u][v];
}

int edge_val_bw(int )