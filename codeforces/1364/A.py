import sys
import math
input = sys.stdin.readline
t = int(input())
for i in range(t):
    n, x = map(int, input().split())
    a = [int(_) for _ in input().split()]
    total = 0
    ans = -1
    for i in range(n):
        total += a[i]
        if total % x != 0:
            ans = max(ans, i + 1)
    total = 0
    for i in range(n - 1, -1, -1):
        total += a[i]
        if total % x != 0:
            ans = max(ans, n - i)
    print(ans)
