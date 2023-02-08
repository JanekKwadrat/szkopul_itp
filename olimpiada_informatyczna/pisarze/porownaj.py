#!/usr/bin/python3

import sys

f1, f2 = sys.argv[1], sys.argv[2]
with open(f1) as f: t1 = f.read()
with open(f2) as f: t2 = f.read()

words1 = t1.split()
words2 = t2.split()

score = 0
total = min(len(words1), len(words2))

for i in range(total):
    if words1[i] == words2[i]:
        score += 1

score /= total
score *= 100

print('Podobieństwo: {:.2f}%'.format(score))