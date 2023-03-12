// Jan Zakrzewski

typedef long long i64;

typedef struct {
    i64 x, y;
} Point;

typedef struct {
    i64 p, q;
} Q;

inline int not_equal(Q const a, Q const b) {
    return a.p * b.q != b.p * a.q;
}

inline int not_zero(Q const a) {
    return a.p != 0 || a.q != 0;
}

inline void get_Q(Q * a, Point const u, Point const v) {
    a->p = u.x - v.x;
    a->q = u.y - v.y;
}

#include <stdio.h>
#include <stdlib.h>

int n, i;
#define Max_n 1000020
Point A0, A;
Q B, C;
int ans = 1;

int main(void) {

    scanf("%d", &n);
    scanf("%lld %lld", &A0.x, &A0.y);

    B.p = 0, B.q = 0;
    for(i = 1; i < n; ++i) {
        scanf("%lld %lld", &A.x, &A.y);
        get_Q(&C, A0, A);
        if(!not_zero(C)) continue;
        if(not_equal(B, C)) { ans = 0; continue; }
        if(!not_zero(B)) B = C;
    }

    if(ans) printf("TAK\n");
    else printf("NIE\n");

    return 0;
}