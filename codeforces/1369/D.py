import math
import sys
input = sys.stdin.readline
maxVal = 2000001
mod = 1000000000 + 7
dp = [0] * maxVal
use = [False] * maxVal
for i in range(3, maxVal):
    if use[i - 1] or use[i - 2]:
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 2]
        use[i] = False
    else:
        dp[i] = 4 + dp[i - 1] + dp[i - 2] + dp[i - 2]
        use[i] = True
    dp[i] %= mod
t = int(input())
result = []
for i in range(t):
    n = int(input())
    result.append(dp[n])
print('\n'.join(map(str, result)))
