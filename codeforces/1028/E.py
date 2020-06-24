import math
import sys
input = sys.stdin.readline
n = int(input())
a = [int(_) for _ in input().split()]
piv = -1
for i in range(n):
    if a[i - 1] < a[i]:
        piv = i
        break
if min(a) == 0 and max(a) == 0:
    print('YES')
    print(' '.join(['1'] * n))
    exit(0)
elif piv == -1:
    print('NO')
    exit(0)
for i in range(n):
    prv = (n + piv - i + 1) % n
    cur = (n + piv - i) % n
    nxt = (n + piv - i - 1) % n
    if a[nxt] >= a[cur]:
        a[cur] += ((a[nxt] - a[cur]) // a[prv] + 1) * a[prv]
print('YES')
print(' '.join(map(str, a)))

