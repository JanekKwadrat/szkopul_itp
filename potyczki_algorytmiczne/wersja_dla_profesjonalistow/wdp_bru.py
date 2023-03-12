def ile(n, s):
    ans = ''
    c = 0
    while True:
        #print(n)
        if n % 9 == 1: ans += s
        elif n % 9 != 0: ans += '{}[{}]'.format(chr(n % 9 + ord('0')), s)
        n //= 9
        if n < 1: break
        ans += '9['
        c += 1
    while True:
        if c <= 0: break
        c -= 1
        ans += ']'
    return ans

def rysuj(n):
    if n == 0: return ''
    ans = ''
    ans += 'F'
    ans += rysuj(n-1)
    ans += 'B'
    ans += ile(n-1, 'FB')
    ans += ile(n, 'D')
    return ans

n = int(input())
print(rysuj(n))
