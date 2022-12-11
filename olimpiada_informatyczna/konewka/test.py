from random import randint, choice

N = 10
K = randint(20, 30)
q = 10

print(N, K)

for i in range(N):
    print(randint(1, int(1.1 * K)), end = ' ')
print()

print(q)

for i in range(q):
    c = choice(['p', 'd'])
    a = randint(0, N-1)
    b = randint(0, N-1)
    a, b = min(a, b), max(a, b)
    print(c, a, b)

