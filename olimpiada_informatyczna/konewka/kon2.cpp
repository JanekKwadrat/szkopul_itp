const int Delta = 524'288;
const int SMALL = -600'000;
int N, K;
int tallest[2 * Delta];
int increase[Delta];
int mature[2 * Delta];

int max(int x, int y) {
    if(x > y) return x;
    else return y;
}

void inicjuj(int n, int k, int* D) {
    N = n, K = k;
    for(int i = 0; i < N; ++i) tallest[i+Delta] = D[i];
    for(int i = N; i < Delta; ++i) tallest[i+Delta] = 0;
    for(int i = Delta-1; i >= 1; --i) tallest[i] = max(tallest[2*i], tallest[2*i+1]);
    for(int i = 1; i < Delta; ++i) increase[i] = 0;
    for(int i = 1; i < 2*Delta; ++i) mature[i] = 0;
}

void podlej(int a, int b) {
    a += Delta;
    b += Delta;
    tallest[a]++;
    if(a != b)
    tallest[b]++;
    while(a / 2 != b / 2) {
        if(a % 2 == 0) tallest[a+1]++, increase[a+1]++;
        if(b % 2 == 1) tallest[b-1]++, increase[b-1]++;
        if(a < Delta && b < Delta) {
            tallest[a] = max(tallest[2*a], tallest[2*a+1]) + increase[a];
            tallest[b] = max(tallest[2*b], tallest[2*b+1]) + increase[b];
        }
        a /= 2;
        b /= 2;
    }
    while(a >= 1) {
        if(a < Delta) tallest[a] = max(tallest[2*a], tallest[2*a+1]) + increase[a];
        a /= 2;
    }
}

int dojrzale(int a, int b) {
    while(tallest[1] >= K) {
        int i = 1;
        while(i < Delta) {
            tallest[2*i] += increase[i];
            tallest[2*i+1] += increase[i];
            if(2*i+1 < Delta) {
                increase[2*i] += increase[i];
                increase[2*i+1] += increase[i];
            }
            increase[i] = 0;
            if(tallest[2*i] >= K) i = 2*i;
            else i = 2*i+1;
        }
        tallest[i] = SMALL;
        mature[i] = 1;
        i /= 2;
        while(i >= 1) {
            tallest[i] = max(tallest[2*i], tallest[2*i+1]);
            mature[i] = mature[2*i] + mature[2*i+1];
            i /= 2;
        }
    }
    a += Delta;
    b += Delta;
    int ans = 0;
    ans += mature[a];
    if(a != b)
    ans += mature[b];
    while(a / 2 != b / 2) {
        if(a % 2 == 0) ans += mature[a+1];
        if(b % 2 == 1) ans += mature[b-1];
        a /= 2;
        b /= 2;
    }
    return ans;
}