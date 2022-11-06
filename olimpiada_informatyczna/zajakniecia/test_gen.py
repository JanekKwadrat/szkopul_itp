import random

N1, N2 = 15, 20
K = 2

n = random.randint(N1, N2)
m = random.randint(N1, N2)
a = [random.randint(1, K) for _ in range(n)]
b = [random.randint(1, K) for _ in range(m)]

print(n, m)
print(" ".join([str(x) for x in a]))
print(" ".join([str(x) for x in b]))