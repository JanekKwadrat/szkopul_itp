#include <stdio.h>

typedef long long i64;
typedef struct { i64 x, y; } Point;
#define N 100 * 1000 + 20

inline int cwiartka(Point A) {
    if(A.y == 0 && A.x > 0) return 1;
    if(A.y > 0 && A.x > 0) return 2;
    if(A.x == 0 && A.y > 0) return 3;
    if(A.x < 0 && A.y > 0) return 4;
    if(A.y == 0 && A.x < 0) return 5;
    if(A.y < 0 && A.x < 0) return 6;
    if(A.x == 0 && A.y < 0) return 7;
    if(A.x > 0 && A.y < 0) return 8;
    return 0;
}

int porownywarka(const Point B, const Point A) {
    if(cwiartka(A) > cwiartka(B)) return 1;
    if(cwiartka(A) < cwiartka(B)) return 0;
    if(A.y * B.x == B.y * A.x) return A.y * A.y > B.y * B.y;
    return A.y * B.x > B.y * A.x;
}

int n, i;
Point array[N];

#include <algorithm>
#include <vector>

int main(void) {

    scanf("%d", &n);
    for(i = 0; i < n; ++i) {
        scanf("%lld %lld", &array[i].x, &array[i].y);
        array[i].y *= -1;
    }

    std::sort(&array[0], &array[n], porownywarka);

    for(i = 0; i < n; ++i) {
        array[i].y *= -1;
        printf("%lld %lld\n", array[i].x, array[i].y);
    }

    return 0;
}