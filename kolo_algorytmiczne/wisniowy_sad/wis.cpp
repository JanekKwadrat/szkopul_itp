// Jan Zakrzewski

typedef long long i64;

typedef struct {
	i64 x, y;
} Point;

inline i64 _abs(i64 x) {
	if(x > 0) return x;
	else return -1 * x; 
}

inline i64 signed_double_triangle_area(Point const a, Point const b, Point const c) {
	return (a.x-b.x) * (a.y-c.y) - (a.y-b.y) * (a.x-c.x);
}

inline i64 _gcd(i64 a, i64 b) {
	while(1) {
		if(b == 0) return a;
		a %= b;
		if(a == 0) return b;
		b %= a;
	}
}

#include <stdio.h>
#include <stdlib.h>

int n, i, j;
#define Max_n 2000
Point A[Max_n];
i64 twoS = 0, B = 0;
i64 twoW;

int main(void) {

	scanf("%lld", &n);
	for(i = 0; i < n; ++i) scanf("%lld %lld", &A[i].x, &A[i].y);

	for(i = 2; i < n; ++i)
		twoS += signed_double_triangle_area(A[0], A[i-1], A[i]);

	for(i = 0; i < n; ++i) {
		j = i + 1;
		if(j >= n) j -= n;
		B += _gcd(_abs(A[i].x - A[j].x), _abs(A[i].y - A[j].y));
	}

	twoS = _abs(twoS);
	twoW = twoS - B + 2;
	printf("%lld\n", twoW / 2);

	return 0;
}	