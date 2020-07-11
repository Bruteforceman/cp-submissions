import math
import sys
input = sys.stdin.readline
t = 1
for cs in range(t):
    n = int(input())
    a = [int(_) for _ in input().split()]
    if n == 1:
        print(a[0])
        continue
    pre = [0] * n
    suf = [0] * n
    for i in range(n):
        if i >= 2:
            pre[i] = pre[i - 2] + a[i]
        else:
            pre[i] = a[i]
    for i in range(n - 1, -1, -1):
        if i + 2 < n:
            suf[i] = suf[i + 2] + a[i]
        else:
            suf[i] = a[i]
    ans = max(pre[0], pre[1])
    for i in range(n):
        if i > 0:
            ans = max(ans, pre[i - 1] + suf[i])
        if i >= 3:
            ans = max(ans, pre[i - 3] + suf[i])
    print(ans)
