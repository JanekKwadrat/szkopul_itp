#  Jan Zakrzewski
#  https://codeforces.com/contest/1794
#  Problem 'A. Prefix and Suffix Array'

t = int(input())

while t > 0:
    t -= 1

    n = int(input())
    a = input().split()
    b = [x[::-1] for x in a]

    a = sorted(a)
    b = sorted(b)

    ok = True
    for i in range(2 * n - 2):
        if a[i] != b[i]:
            ok = False

    if ok: print('YES')
    else: print('NO')
