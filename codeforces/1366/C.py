import sys
import math
input = sys.stdin.readline

t = int(input())
for cs in range(t):
    n, m = map(int, input().split())
    a = [[] for _ in range(n)]
    for i in range(n):
        a[i] = [int(x) for x in input().split()]
    can = [[] for _ in range(n + m)]
    for i in range(n):
        for j in range(m):
            d1 = i + j
            d2 = abs(n - 1 - i) + abs(m - 1 - j)
            if d1 < d2:
                can[d1].append(a[i][j])
            elif d1 != d2:
                can[d2].append(a[i][j])
    ans = 0
    for i in can:
        ans = ans + min(sum(i), len(i) - sum(i))
    print(ans)
