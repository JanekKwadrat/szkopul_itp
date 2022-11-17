import math

def hash29(s: str)->int:
    MOD = 4294967291
    P = 29
    ans = 0
    for c in s:
        x = ord(c) - ord('a') + 1
        ans = (ans * P + x) % MOD
    return ans

def get_hashed(text: str)->list[int]:
    text = ''.join(c for c in text if c.isalpha() or c == ' ')
    text = text.lower()

    words = text.split()
    hashed = [hash29(s) for s in words]
    return hashed

def get_probs(hashed_tuple):
    n = len(hashed_tuple)
    
    hashed_all = []
    for i in range(n): hashed_all += hashed_tuple[i]
    hashed_all = set(hashed_all)

    probs_tuple = tuple(dict.fromkeys(hashed_all, 0) for i in range(n))
    for i in range(n):
        for h in hashed_tuple[i]: probs_tuple[i][h] += 1
        for h in hashed_tuple[i]: probs_tuple[i][h] /= len(hashed_tuple[i])
    
    for h in hashed_all:
        t = sum(probs_tuple[i][h] for i in range(n)) + 0.00001
        for i in range(n): probs_tuple[i][h] /= t

    return probs_tuple

'''def get_scores(hashed_tuple):
    probs_tuple = get_probs(hashed_tuple)
    
    n = len(probs_tuple)
    scores_tuple = tuple(dict() for i in range(n))
    
    for i in range(n):
        for h in probs_tuple[i]:
            scores_tuple[i][h] = math.log(probs_tuple[i][h] * n) if probs_tuple[i][h] > 0 else -1e30
            scores_tuple[i][h] *= 1e9 / math.log(n)
            scores_tuple[i][h] = max(-1e9, min(1e9, scores_tuple[i][h]))
            scores_tuple[i][h] = int(scores_tuple[i][h])
    return scores_tuple'''

mickiewicz, prus, sienkiewicz = '', '', ''
with open('pis_dlazaw/Mickiewicz.txt') as f: mickiewicz = f.read()
with open('pis_dlazaw/Prus.txt') as f: prus = f.read()
with open('pis_dlazaw/Sienkiewicz.txt') as f: sienkiewicz = f.read()

mickiewicz_hashed = get_hashed(mickiewicz)
prus_hashed = get_hashed(prus)
sienkiewicz_hashed = get_hashed(sienkiewicz)

mickiewicz_probs, prus_probs, sienkiewicz_probs = get_probs((mickiewicz_hashed, prus_hashed, sienkiewicz_hashed))
for k, v in mickiewicz_probs:
    if v > 0.90:
        print(k, v)