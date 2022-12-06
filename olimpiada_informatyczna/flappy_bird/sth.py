from random import randint, sample

N = randint(4, 8)
X = randint(10, 20)

x = sample(range(1, X+1), N)
x = sorted(x)

ab = [tuple(sorted(sample(range(-4, 4+1), 2))) for _ in range(N)]

print(N, X)
for i in range(N):
    print(x[i], *ab[i])