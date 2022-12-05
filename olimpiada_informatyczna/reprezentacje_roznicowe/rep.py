''' Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap I
    Zadanie Reprezentacje różnicowe (rep)
    Rozwiązenie w złożoności log^2 X + n log log X '''

def binsearch(arr, x):
    '''Returns the smallest `i` for which `arr[i][0] >= x` or `len(arr)` if there is no such `i`.'''
    if arr[0][0] >= x: return 0
    a, b = 0, len(arr)
    while b - a > 1:
        mid = (a + b) // 2
        if arr[mid][0] >= x: b = mid
        else: a = mid
        #print(a, b, arr[a][0] <= x and arr[b][0] > x)
    return b

X = 10**9
N = 70 # assuming a[N] - a[i] > X for any 0<=i<N
a = [1, 2]

r_seen = [False for _ in range(N * N)]
r_seen[1] = True
r = 2
for i in range(2, N):
    if i % 2 == 0: a.append(a[i-1] * 2)
    else: a.append(a[i-1] + r)
    for j in range(0, i):
        if a[i] - a[j] < N * N:
            r_seen[a[i] - a[j]] = True
    while r < N * N and r_seen[r]:
        r += 1
del r, r_seen

uneasy = []

for i in range(1, N):
    for j in range(0, i):
        x = a[i] - a[j]
        p, q = i, j
        if x <= X and (p - q > 1 or q % 2 == 1):
            uneasy.append((x, p, q))
uneasy = sorted(uneasy)

def repr(x):
    i = binsearch(uneasy, x)
    if i < len(uneasy) and uneasy[i][0] == x:
        return uneasy[i][1], uneasy[i][2]
    q = 2 * (x - i - 1)
    p = q + 1
    return p, q

t = int(input())
for _ in range(t):
    x = int(input())
    p, q = repr(x)
    print('{} {}'.format(p+1, q+1))
