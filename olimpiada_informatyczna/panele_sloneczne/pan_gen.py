from random import randint

n = randint(8, 10)
print(n)

for i in range(n):
    a_min, a_max = randint(1, 10**7), randint(1, 10**7)
    a_min, a_max = min(a_min, a_max), max(a_min, a_max)
    b_min, b_max = randint(1, 10**7), randint(1, 10**7)
    b_min, b_max = min(b_min, b_max), max(b_min, b_max)
    print(a_min, a_max, b_min, b_max)