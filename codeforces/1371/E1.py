import math
import sys
input = sys.stdin.readline
n, p = map(int, input().split())
a = sorted([int(_) for _ in input().split()])
inf = 10**18
bad = dict()
low, high = 1, inf
for i in range(n):
    j = (i + 1) % p
    for k in range(j, i, p):
        if a[i] >= k:
            bad[a[i] - k] = True
    if j == 0:
        high = min(high, a[i])
    low = max(low, a[i] - i)
result = []
for i in range(low, high):
    if bad.get(i, False) == False:
        result.append(i)
print(len(result))
print(' '.join(map(str, result)))

