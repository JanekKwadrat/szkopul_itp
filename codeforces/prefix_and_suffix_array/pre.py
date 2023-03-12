#  Jan Zakrzewski
#  https://codeforces.com/contest/1794
#  Problem 'A. Prefix and Suffix Array'

t = int(input())

while t > 0:
   t -= 1

   n = int(input())
   a = input().split()
   x, y = [sth for sth in a if len(sth) == n-1]

   ok = x == y[::-1]
   if ok:
      

   if ok: print('YES')
   else: print('NO')
