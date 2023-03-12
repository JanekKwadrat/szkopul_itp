 // Jan Zakrzewski

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#define Max_n 1005
int n, m, k;
int i, j;
long long teren[Max_n][Max_n] = {};
int p, ans = 0;

int main(void) {
    scanf("%i %i %i", &n, &m, &k);
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= m; ++j) {
            scanf("%i", &teren[i][j]);
            teren[i][j] += teren[i-1][j];
            teren[i][j] += teren[i][j-1];
            teren[i][j] -= teren[i-1][j-1];
        }
    }
    for(i = k; i <= n; ++i) {
        for(j = k; j <= n; ++j) {
            p  = teren[i][j];
            p -= teren[i-k][j];
            p -= teren[i][j-k];
            p += teren[i-k][j-k];
            if(p > ans) ans = p;
        }
    }
    printf("%i\n", ans);
    return 0;
}

#ifdef __cplusplus
}
#endif