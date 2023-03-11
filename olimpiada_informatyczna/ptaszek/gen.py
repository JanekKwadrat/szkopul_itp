from random import randint

n = randint(7, 100)
d = [randint(1, 20) for _ in range(n)]
q = 1
k = [randint(1, 10) for _ in range(q)]

print(n)
print(' '.join([str(x) for x in d]))
print(q)
print('\n'.join([str(x) for x in k]))
