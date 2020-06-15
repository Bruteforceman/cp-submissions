import math
import sys
input = sys.stdin.readline
n = int(input())
a = [int(_) for _ in input().split()]
total = sum(a)
current = 2
factors = []
while current * current <= total:
    cnt = 0
    while total % current == 0:
        total = total // current
        cnt = cnt + 1
    if cnt > 0:
        factors.append(current)
    current = current + 1
if total > 1:
    factors.append(total)

ans = sum(a) * n * n
for i in factors:
    total, moves = 0, 0
    for j in a:
        total += j
        moves += min(total % i, i - (total % i))
    ans = min(ans, moves)
if len(factors) == 0: ans = -1
print(ans)
