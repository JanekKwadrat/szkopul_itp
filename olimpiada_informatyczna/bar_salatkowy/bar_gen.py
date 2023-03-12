from random import randint, choice

n = randint(1, 1000)
a = ''.join([choice(['j', 'p']) for _ in range(n)])

print(n)
print(a)
