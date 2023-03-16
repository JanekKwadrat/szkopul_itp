/* Jan Zakrzewski
   XXV Olimpiada Informatyczna, Etap III
   Zadanie `Wielomian (wie)' */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;
typedef unsigned long u32;

// zwraca tablicę wartości [P(1), P(q), P(q^2), ..., P(q^(n-1))]
// n = wielkość wielomianu i tablicy poly
// liczba n musi być potęgą liczby 2
// musi zachodzić q^n mod M = 1
// zakładamy nierówności n >= 1, 0 <= poly[i] < M, 0 <= q < M, M >= 2
u32* func(int n, u32* poly, u32 q, u32 M) {
    u32* ans = (u32*) malloc(n * sizeof(u32));
    if(n == 1) ans[0] = poly[0];
    else {
        u32* poly_even = (u32*) malloc(n/2 * sizeof(u32));
        u32* poly_odd  = (u32*) malloc(n/2 * sizeof(u32));
        for(int i = 0; i < n/2; ++i) {
            poly_even[i] = poly[2*i];
            poly_odd[i]  = poly[2*i+1];
        }
        u32* ans_even = func(n / 2, poly_even, (u64) q * q % M, M);
        u32* ans_odd  = func(n / 2, poly_odd,  (u64) q * q % M, M);
        u32* Q = (u32*) malloc(n * sizeof(u32));
        Q[0] = 1;
        for(int i = 1; i < n; ++i) Q[i] = (u64) Q[i-1] * q % M;
        for(int i = 0; i < n / 2; ++i) {
            ans[i]     = ((u64) Q[i]     * ans_odd[i] + ans_even[i]) % M;
            ans[i+n/2] = ((u64) Q[i+n/2] * ans_odd[i] + ans_even[i]) % M;
        }
        free(Q);
        free(ans_even);
        free(ans_odd);
        free(poly_even);
        free(poly_odd);
    }
    return ans;
}

u32 n, q, M;
u32* poly;
u32* ans;
u32 sum;

int main() {

    scanf("%u %u %u", &n, &M, &q);
    
    poly = (u32*) malloc(n * sizeof(u32));
    for(int i = 0; i < n; ++i) {
        scanf("%u", &poly[i]);
        poly[i] %= M;
    }
    
    ans = func(n, poly, q, M);    
    sum = 0;
    for(int i = 0; i < n; ++i) sum = ((u64) sum + ans[i]) % M;
    
    printf("%u\n", sum);
    for(int i = 1; i < n; ++i) printf("%u ", ans[i]);
    printf("%u\n", ans[0]);
    
    free(poly);
    free(ans);

    return 0;
}
