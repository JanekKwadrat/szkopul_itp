from email import charset


def fetch_freqs(book: str):
    words = book.split()
    words = [s[0:4] for s in words if len(s) >= 4]
    total = len(words)
    freqs = dict()
    for s in words:
        if s in freqs: freqs[s] += 1
        else: freqs[s] = 1
    for s in freqs:
        freqs[s] =  freqs[s] * 1000000 // total
    return freqs

def fetch_chars(book: str):
    chars = { ' ': 0, '.': 0, ',': 0, '"': 0, '?': 0, '!': 0, 'A': 0, 'a': 0 }
    for c in 'abcdefghijklmnopqrstuvwxyz': chars[c] = 0
    for c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ': chars[c] = 0
    for c in book:
        #if ord(c) >= ord('A') and ord(c) <= ord('Z'): c = 'A'
        #if ord(c) >= ord('a') and ord(c) <= ord('z'): c = 'a'
        if c in chars: chars[c] += 1
        #else: chars[c] = 1
    for c in chars:
        chars[c] = chars[c] * 1000000 // len(book)
    return chars

def sum_freqs(freqs):
    ans = 0
    for s in freqs:
        ans += freqs[s]
    return ans

def threshold_freqs(freqs, threshold):
    new_freqs = dict()
    for s in freqs:
        if freqs[s] >= threshold:
            new_freqs[s] = freqs[s]
    return new_freqs

with open('pis_dlazaw/Sienkiewicz.txt') as f: Sienkiewicz = f.read()
with open('pis_dlazaw/Mickiewicz.txt') as f: Mickiewicz = f.read()
with open('pis_dlazaw/Prus.txt') as f: Prus = f.read()

freqs_Sienkiewicz = fetch_freqs(Sienkiewicz)
freqs_Mickiewicz = fetch_freqs(Mickiewicz)
freqs_Prus = fetch_freqs(Prus)

###
chars_Sienkiewicz = fetch_chars(Sienkiewicz)
chars_Mickiewicz = fetch_chars(Mickiewicz)
chars_Prus = fetch_chars(Prus)
chars_all = dict()
for s in chars_Sienkiewicz:
    chars_all[s] = (chars_Sienkiewicz[s], chars_Mickiewicz[s], chars_Prus[s])
    chars_all[s] = tuple(x / sum(chars_all[s]) - 1/3 for x in chars_all[s])
    chars_all[s] = tuple(int(x * 1000) for x in chars_all[s])


T1, T2 = [int(x) for x in input().split()]

freqs_Sienkiewicz = threshold_freqs(freqs_Sienkiewicz, T1)
freqs_Mickiewicz = threshold_freqs(freqs_Mickiewicz, T1)
freqs_Prus = threshold_freqs(freqs_Prus, T1)

prune = set()
for s in freqs_Sienkiewicz:
    if s in freqs_Mickiewicz:
        prune.add(s)
    if s in freqs_Prus:
        prune.add(s)
for s in freqs_Mickiewicz:
    if s in freqs_Prus:
        prune.add(s)

for s in prune:
    freqs_Sienkiewicz.pop(s, None)
    freqs_Mickiewicz.pop(s, None)
    freqs_Prus.pop(s, None)

freqs_Sienkiewicz = threshold_freqs(freqs_Sienkiewicz, T2)
freqs_Mickiewicz = threshold_freqs(freqs_Mickiewicz, T2)
freqs_Prus = threshold_freqs(freqs_Prus, T2)

print()

print('Sienkiewicz, {} / 1\'000\'000'.format(sum_freqs(freqs_Sienkiewicz)))
print(sorted(list(freqs_Sienkiewicz)))
print(chars_Sienkiewicz)
print()

print('Mickiewicz, {} / 1\'000\'000'.format(sum_freqs(freqs_Mickiewicz)))
print(sorted(list(freqs_Mickiewicz)))
print(chars_Mickiewicz)
print()

print('Prus, {} / 1\'000\'000'.format(sum_freqs(freqs_Prus)))
print(sorted(list(freqs_Prus)))
print(chars_Prus)
print()

print('Sienkiewicz = \'{}\''.format(''.join(list(freqs_Sienkiewicz))))
print('Mickiewicz = \'{}\''.format(''.join(list(freqs_Mickiewicz))))
print('Prus = \'{}\''.format(''.join(list(freqs_Prus))))
print()

print(chars_all)
print()