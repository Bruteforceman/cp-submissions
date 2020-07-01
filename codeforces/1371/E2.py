import math
import sys
input = sys.stdin.readline
n, p = map(int, input().split())
a = sorted([int(_) for _ in input().split()])
inf = 10**18
bad = dict()
low, high = 1, inf
opt = [0] * p
for i in range(n):
    j = (i + 1) % p
    if a[i] >= j:
        var = (a[i] - j) % p
        opt[var] = max(opt[var], a[i] - j) 
    if j == 0:
        high = min(high, a[i])
    low = max(low, a[i] - i)
for i in range(p):
    cur = opt[i]
    while cur >= low:
        bad[cur] = True
        cur -= p
result = []
for i in range(low, high):
    if bad.get(i, False) == False:
        result.append(i)
print(len(result))
print(' '.join(map(str, result)))

