import math
import sys
input = sys.stdin.readline
t = int(input())
for cs in range(t):
    n, x = map(int, input().split())
    a = sorted([int(_) for _ in input().split()], reverse=True)
    ans = 0
    cur = 0
    while cur < n:
        take = 1
        while cur < n and take * a[cur] < x:
            take += 1
            cur += 1
        if cur < n and take * a[cur] >= x:
            ans += 1
        cur += 1
    print(ans)
