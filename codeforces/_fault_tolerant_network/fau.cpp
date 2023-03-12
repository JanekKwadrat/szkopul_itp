#include <iostream>
#include <algorithm>

long long cost(long long x, long long y) {
    long long ans = x - y;
    if(ans < 0) ans *= -1;
    return ans;
}

long long max(long long x, long long y) {
    return x > y ? x : y;
}

long long min(long long x, long long y) {
    return x < y ? x : y;
}


constexpr long long Max_n = 2e5 + 20;

long long a[Max_n];
long long b[Max_n];

long long t, n;

long long nearby(long long x, long long * arr) {
    long long itr = (long long)(std::lower_bound(arr, arr + n, x) - arr);
    return min(cost(x, itr), cost(x, itr+1));
}

long long enda0, enda1;
long long endb0, endb1;
long long sth;
long long ans = INT64_MAX, subans;

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;

        for(long long i = 0; i < n; ++i) std::cin >> a[i];
        enda0 = a[0];
        enda1 = a[n-1];
        std::sort(a, a + n);

        for(long long i = 0; i < n; ++i) std::cin >> b[i];
        endb0 = b[0];
        endb1 = b[n-1];
        std::sort(b, b + n);

        subans = 0;
        subans += nearby(enda0, b);
        subans += nearby(enda1, b);
        subans += nearby(endb0, a);
        subans += nearby(endb1, a);
        ans = min(ans, subans);

        subans = 0;
        subans += cost(enda0, endb0);
        subans += nearby(enda1, b);
        subans += nearby(endb1, a);
        ans = min(ans, subans);

        subans = 0;
        subans += cost(enda0, endb1);
        subans += nearby(enda1, b);
        subans += nearby(endb0, a);
        ans = min(ans, subans);

        subans = 0;
        subans += cost(enda1, endb0);
        subans += nearby(enda0, b);
        subans += nearby(endb1, a);
        ans = min(ans, subans);

        subans = 0;
        subans += cost(enda1, endb1);
        subans += nearby(enda0, b);
        subans += nearby(endb0, a);
        ans = min(ans, subans);

        subans = 0;
        subans += cost(enda0, endb0);
        subans += cost(enda1, endb0);
        ans = min(ans, subans);

        subans = 0;
        subans += cost(enda0, endb0);
        subans += cost(enda1, endb1);
        ans = min(ans, subans);

        subans = 0;
        subans += cost(enda0, endb1);
        subans += cost(enda1, endb0);
        ans = min(ans, subans);

        subans = 0;
        subans += cost(enda0, endb1);
        subans += cost(enda1, endb1);
        ans = min(ans, subans);

        std::cout << ans << "\n";
    }
    return 0;
}