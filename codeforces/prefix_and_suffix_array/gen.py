import random

t = 1
print(t)

while t > 0:
    t -= 1

    n = random.randint(3, 5)
    a = ''.join([random.choice(list('abcd')) for _ in range(n)])
    print(n)
    print(a)