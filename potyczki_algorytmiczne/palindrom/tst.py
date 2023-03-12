from random import randint, choice

N = randint(199900, 200000)

s = ''.join(choice(['a', 'b']) for _ in range(N))

print(s)
