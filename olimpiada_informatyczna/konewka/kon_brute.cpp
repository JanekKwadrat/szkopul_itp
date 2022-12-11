const int L = 3e5 + 20;
int N, K;
int tree[L];

void inicjuj(int n, int k, int* D) {
    N = n, K = k;
    for(int i = 0; i < N; ++i) tree[i] = D[i];
}

void podlej(int a, int b) {
    for(int i = a; i <= b; ++i) tree[i]++;
}

int dojrzale(int a, int b) {
    int ans = 0;
    for(int i = a; i <= b; ++i) if(tree[i] >= K) ans++;
    return ans;
}
