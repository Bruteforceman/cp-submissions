import sys
import math
input = sys.stdin.readline
n = int(input())
a = [0] + [int(_) for _ in input().split()]
dp = [0] * (n + 1)
last = dict()
total, ans, last[0] = 0, 0, 0
for i in range(1, n + 1):
    total += a[i]
    if last.get(total, -1) == -1:
        dp[i] = 0
    else:
        dp[i] = 1 + dp[last[total]]
    last[total] = i
    if i == n:
        ans = max(ans, dp[i])
    else:
        ans = max(ans, dp[i] + 1)
print(n - ans)
