import random

MAX = 100
P = 12

n = random.randint(1, 10)
D = random.randint(1, MAX)
#W = random.randint(1, MAX)
#M = random.randint(1, MAX)

L = [(random.randint(1, P), random.randint(1, P)) for i in range(n+1)]
L = sorted(L, key=lambda x: x[0]/x[1])

W = L[-1][0]+1
M = L[-1][1]

x = []
d = []

x0 = 0
d0 = 0

for i in range(n):
    d0 = random.randint(1, MAX)
    x0 = random.randint(x0 + d0, x0 + d0 + MAX)
    x.append(x0)
    d.append(d0)

print(n, D, W, M)
for i in range(n):
    print(x[i], d[i], L[i][0], L[i][1])